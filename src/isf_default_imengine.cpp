/*
 *  ise-engine-default
 *
 * Copyright (c) 2012-2013 Samsung Electronics Co., Ltd. All rights reserved.
 *
 * Contact: Li zhang <li2012.zhang@samsung.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#define Uses_SCIM_UTILITY
#define Uses_SCIM_IMENGINE
#define Uses_SCIM_LOOKUP_TABLE
#define Uses_SCIM_CONFIG_BASE
#define Uses_SCIM_CONFIG_PATH

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <scim.h>
#include "kdb_resource.h"
#include "isf_default_imengine.h"

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>

#ifdef HAVE_GETTEXT
#include <libintl.h>
#define _(String) dgettext(GETTEXT_PACKAGE,String)
#define N_(String) (String)
#else
#define _(String) (String)
#define N_(String) (String)
#define bindtextdomain(Package,Directory)
#define textdomain(domain)
#define bind_textdomain_codeset(domain,codeset)
#endif

#define DEFAULT_UUID "org.tizen.ise-engine-default"
#define DEFAULT_NAME "Multilingual Keyboard"

#define UTF8_SIZE                       6

#ifndef ISF_DEFAULT_ICON_FILE
#define ISF_DEFAULT_ICON_FILE           (ISF_ICONDIR "/isf-default.png")
#endif

static ConfigPointer _scim_config(0);
static int m_keypad_layout;

extern "C" {
	void scim_module_init(void) {
		bindtextdomain(GETTEXT_PACKAGE, ISF_DEFAULT_LOCALEDIR);
		bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
	}

	void scim_module_exit(void) {
		_scim_config.reset();
	}

	uint32 scim_imengine_module_init(const ConfigPointer & config) {
		_scim_config = config;
		return 1;
	}

	IMEngineFactoryPointer scim_imengine_module_create_factory(uint32
			engine) {
		DefaultFactory *factory = 0;

		try {
			factory = new DefaultFactory(_scim_config);
		}
		catch(...) {
			delete factory;
			factory = 0;
		}

		return factory;
	}
}

DefaultFactory::DefaultFactory(const ConfigPointer & config)
: m_config(config) {
	m_uuid = DEFAULT_UUID;
	m_name = _(DEFAULT_NAME);

	set_languages
	("nl_NL,nl_BE,en_US,en_GB,en_AU,en_CA,en_NZ,en_IE,en_ZA,en_JM,"
			"en_BZ,en_TT,en_ZW,en_PH,fr_FR,fr_BE,fr_CA,fr_CH,fr_LU,fr_MC,"
			"de_DE,de_CH,de_AT,de_LU,de_LI,it_IT,it_CH,pt_BR,pt_PT,es_ES,"
			"es_MX,es_GT,es_CR,es_PA,es_DO,es_VE,es_CO,es_PE,es_AR,"
			"es_EC,es_CL,es_UY,es_PY,es_BO,es_SV,es_HN,es_NI,es_PR,eu_ES,"
			"ca_ES,da_DK,af_AF,is_IS,fi_FI,ms_MY,ms_BN,no_NO,sv_SE,sv_FI,"
			"cs_CZ,hu_HU,pl_PL,ro_RO,sr_RS,sk_SK,sl_SI,et_EE,lv_LV,lt_LT,el_GR,"
			"bg_BG,kk_KZ,mk_MK,ru_RU,sr_RS,uk_UA,tr_TR,uz_UZ,th_TH,he_IL,"
			"ar_SA,ar_IQ,ar_EG,ar_LY,ar_DZ,ar_MA,ar_TN,ar_OM,ar_YE,ar_SY,ar_JO,"
			"ar_LB,ar_KW,ar_AE,ar_BH,ar_QA,ur_PK,vi_VN,hi_IN,te_IN,mr_IN,ta_IN,"
			"bn_IN,gu_IN,ml_IN,pa_IN,ka_GE,az_IR,gl_ES,ha_BJ,ga_IE,si_LK,cy_UK,"
			"xh_ZA,yo_NG,zu_ZA");

	m_reload_signal_connection =
			m_config->
			signal_connect_reload(slot(this, &DefaultFactory::reload_config));
	reload_config(m_config);
}

DefaultFactory::~DefaultFactory() {
	m_reload_signal_connection.disconnect();
}

void DefaultFactory::load_resource() {
}

WideString DefaultFactory::get_name() const {
	return utf8_mbstowcs(m_name);
}

WideString DefaultFactory::get_authors() const {
	return utf8_mbstowcs(String
			(_("Copyright (C) Samsung Electronics Co., Ltd.")));
}

WideString DefaultFactory::get_credits() const {
	return WideString();
}

WideString DefaultFactory::get_help() const {
	String help = "";
	help = String(_("\n\n"
			"    Press Space or Return to commit\n"
			"    the inputed string and exit this mode."));

	return utf8_mbstowcs(help);
}

String DefaultFactory::get_uuid() const {
	return m_uuid;
}

String DefaultFactory::get_icon_file() const {
	return String(ISF_DEFAULT_ICON_FILE);
}

void DefaultFactory::reload_config(const ConfigPointer & config) {
	if (config.null()) return;
	int hw_detected = config->read(String (ISF_CONFIG_HARDWARE_KEYBOARD_DETECT), 1);
	if (hw_detected == 1)
		m_keypad_layout = I_HQD;
}

IMEngineInstancePointer
DefaultFactory::create_instance(const String & encoding, int id) {
	return new DefaultInstance(this, encoding, id);
}

/* Initialize member variables */
unsigned int DefaultInstance::m_prevkeyval = 0;
int DefaultInstance::m_counter = 0;

DefaultInstance::DefaultInstance(DefaultFactory * factory,
		const String & encoding, int id)
:IMEngineInstanceBase(factory, encoding, id) {
	char label[2] = {0, 0};
	std::vector < WideString > labels;

	m_shift_pressed = Shift_None;
	m_caps_lock = false;
	m_lang = IM_LANGUAGE_ENGLISH;
	m_precharval = 0;
	m_keypad_layout = I_HQD;

	for (int i = 1; i < 10; ++i) {
		label[0] = '0' + i;
		labels.push_back(utf8_mbstowcs(String(label)));
	}

	m_lookup_table.set_candidate_labels(labels);
	m_lookup_table_def_page_size = (int)labels.size();
	m_lookup_table.set_page_size(m_lookup_table_def_page_size);
}

DefaultInstance::~DefaultInstance() {
}

bool DefaultInstance::process_key_event(const KeyEvent & key) {
	bool ret = true;

	if (key.is_key_press()) {
		ret = _process_keypress(key);
	} else if (key.is_key_release()) {
		/* ignore key release. */
		ret = _process_keyrelease(key);
	} else {
		/* do nothing */
		ret = false;
	}

	return ret;
}

void DefaultInstance::move_preedit_caret(unsigned int pos) {
}

void DefaultInstance::select_candidate(unsigned int index) {
}

void DefaultInstance::update_lookup_table_page_size(unsigned int page_size) {
	SCIM_DEBUG_IMENGINE(2) << "update_lookup_table_page_size.\n";
	m_lookup_table.set_page_size(page_size);
}

void DefaultInstance::lookup_table_page_up() {
}

void DefaultInstance::lookup_table_page_down() {
}

void DefaultInstance::reset() {
	flush();
}

void DefaultInstance::flush() {
}

void DefaultInstance::focus_in() {
	hide_lookup_table();
}

void DefaultInstance::focus_out() {
	flush();
}

void DefaultInstance::trigger_property(const String & property) {
}

bool DefaultInstance::_process_keyrelease(const KeyEvent & key) {
	return false;
}

bool DefaultInstance::_process_keypress(const KeyEvent & key_raw) {
	KeyEvent key = key_raw;
	unsigned int keyvalue = key.code;

	if (key.is_control_down() || key.is_alt_down())
		return false;

	if (key.code == SCIM_KEY_NullKey || key.code == SCIM_KEY_Cancel) {
		m_prevkeyval = keyvalue;
		return false;
	}

	if (m_lang >= IM_LANGUAGE_CNT) {
		return false;
	}

	if (I_HQD == m_keypad_layout) {
		m_prevkeyval = keyvalue;
		return keypad_process_qwerty(key);
	} else {
		/* Need to check */
	}

	m_prevkeyval = keyvalue;
	return false;
}

bool DefaultInstance::keypad_process_qwerty(KeyEvent & key) {
	unsigned char buf[UTF8_SIZE + 1] = {0,};

	/* in case of Alphabet chars */
	if (key.code >= 0xfd00)
		return false;//ISF handle function keys
	else if (key.code >= 0x4E00 && key.code <= 0x9FBF)
		return true;//Don't deal with Chinese characters

	utf8_wctomb(buf, key.code, UTF8_SIZE);

	if (!key.code) return false;

	commit_string(utf8_mbstowcs((char *)buf));
	return true;
}

bool DefaultInstance::special_key_filter(KeyEvent & key) {
	return false;
}

void DefaultInstance::process_helper_event(const String & helper_uuid,
		const Transaction & trans) {
	int cmd = 0;
	uint32 value = 0;

	if (!(const_cast < Transaction & >(trans)).get_command(cmd)) return;
	if (!(const_cast < Transaction & >(trans)).get_data(value)) return;

	if (DEFAULT_CMD_LANGUAGE == cmd) {
		m_lang = value;
		if (m_lang >= IM_LANGUAGE_CNT) {
			m_lang = IM_LANGUAGE_ENGLISH;
		}
	} else if (DEFAULT_CMD_COMPLETION == cmd) {

	} else if (DEFAULT_CMD_SHIFTMODE == cmd) {
		m_shift_pressed = (Mode_Shift)value;
	} else if (DEFAULT_CMD_KEYPAD == cmd) {
		m_keypad_layout = value;
	}
}

void DefaultInstance::reset_option () {
}
