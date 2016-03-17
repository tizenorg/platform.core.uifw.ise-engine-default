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

#ifndef __ISF_DEFAULT_IMENGINE_H__
#define __ISF_DEFAULT_IMENGINE_H__

using namespace scim;

static const int DEFAULT_CMD_KEYPAD = 0x10;
static const int DEFAULT_CMD_LANGUAGE = 0x20;
static const int DEFAULT_CMD_SHIFTMODE = 0x30;
static const int DEFAULT_CMD_STATE = 0x40;
static const int DEFAULT_CMD_INPUTMODE = 0x50;
static const int DEFAULT_CMD_COMPLETION = 0x60;
static const int DEFAULT_CMD_SINGLECOMMIT = 0x70;

typedef enum {
	Shift_None,
	Shift_Click,
	Shift_Click_Lock,
} Mode_Shift;

class DefaultFactory:public IMEngineFactoryBase {
	String m_uuid;
	String m_name;

	ConfigPointer m_config;
	Connection m_reload_signal_connection;

	friend void *load_resource_thread_func(void *args);

 public:
	DefaultFactory(const ConfigPointer & config);

	virtual ~DefaultFactory();

	/**
	 * @brief Load resource for ISE.
	 * @return void.
	 */
	virtual void load_resource();

	/**
	 * @brief Get the name of this input method engine.
	 *
	 * This name should be a localized string.
	 *
	 * @return A WideString containing the name.
	 */
	virtual WideString get_name() const;

	/**
	 * @brief Get the authors information of this input method engine.
	 *
	 * This string should be a localized string.
	 *
	 * @return A WideString containing a list of the authors' name.
	 */
	virtual WideString get_authors() const;

	/**
	 * @brief Get the credits information of this input method engine.
	 *
	 * This string should be a localized string.
	 *
	 * @return A WideString containing the credits information.
	 */
	virtual WideString get_credits() const;

	/**
	 * @brief Get the help information of this input method engine.
	 *
	 * This string should be a localized string.
	 *
	 * @return A WideString containing the help information.
	 */
	virtual WideString get_help() const;

	/**
	 * @brief Get the UUID of this input method engine.
	 *
	 * Each input method engine has an unique UUID to
	 * distinguish itself from other engines.
	 *
	 * You may use uuidgen command shipped with e2fsprogs package to generate this UUID.
	 *
	 * @return A String containing an unique UUID.
	 */
	virtual String get_uuid() const;

	/**
	 * @brief Get the icon file path of this input method engine.
	 *
	 * @return A String containing the icon file path on the local filesystem.
	 */
	virtual String get_icon_file() const;

	/**
	 * @brief Create a new IMEngineInstance object.
	 *
	 * This method creates a new scim::IMEngineInstanceBase object with the given encoding and id.
	 *
	 * @param encoding - the encoding supported by the client.
	 * @param id - the instance id, should be unique.
	 * @return A smart pointer points to this new IMEngineInstance object.
	 */
	virtual IMEngineInstancePointer create_instance(const String & encoding,
							int id = -1);

 private:
	void reload_config(const ConfigPointer & config);
};

class DefaultInstance:public IMEngineInstanceBase {
	CommonLookupTable m_lookup_table;
	int m_lookup_table_def_page_size;
	Mode_Shift m_shift_pressed;
	bool m_caps_lock;
	static unsigned int m_prevkeyval;
	static int m_counter;
	unsigned int m_lang;
	unsigned int m_precharval;
	WideString m_preedit;

 public:
	DefaultInstance(DefaultFactory * factory,
			 const String & encoding, int id = -1);

	virtual ~DefaultInstance();
	/**
	 * @brief Process a key event.
	 *
	 * @param key - the key event to be processed.
	 * @return true if the event is processed, otherwise the event
	 *		 is not processed and should be forward to client application.
	 */
	virtual bool process_key_event(const KeyEvent & key);

	/**
	 * @brief Move the preedit caret in the preedit string.
	 *
	 * @param pos - the new position that user requested.
	 */
	virtual void move_preedit_caret(unsigned int pos);

	/**
	 * @brief Select a candidate in current lookup table.
	 *
	 * When user click a candidate directly,
	 * this method will be invoked by FrontEnd.
	 *
	 * @param index - the index in current page of the selected candidate.
	 */
	virtual void select_candidate(unsigned int item);

	/**
	 * @brief Update the page size of current lookup table.
	 *
	 * In the next time, the lookup table should page down by
	 * this size.
	 *
	 * @param page_size - the new size of current page.
	 */
	virtual void update_lookup_table_page_size(unsigned int page_size);

	/**
	 * @brief Flip the lookup table to the previous page.
	 *
	 * The method will be invoked by FrontEnd when user click
	 * the lookup table page up button.
	 */
	virtual void lookup_table_page_up();

	/**
	 * @brief Flip the lookup table to the next page.
	 *
	 * The method will be invoked by FrontEnd when user click
	 * the lookup table page down button.
	 */
	virtual void lookup_table_page_down();

	/**
	 * @brief Reset this engine instance.
	 *
	 * All status of this engine instance should be reset,
	 * including the working encoding.
	 */
	virtual void reset();

	/**
	 * @brief Flush this engine instance.
	 *
	 * It will hide preedit string, invoke select_canidate function,
	 * clear xt9 engine, and hide lookup table
	 */
	virtual void flush();

	 /**
	 * @brief Focus in this engine instance.
	 */
	virtual void focus_in();

	 /**
	 * @brief Focus out this engine instance.
	 */
	virtual void focus_out();

	 /**
	 * @brief Trigger a property.
	 *
	 * This function should do some action according
	 * to the triggered property.
	 * For example toggle the input mode, etc.
	 *
	 * @param property the key of the triggered property.
	 */
	virtual void trigger_property(const String & property);

	 /**
	 * @brief Process the events sent from a Client Helper process.
	 *
	 * @param helper_uuid The UUID of the Helper process which sent the events.
	 * @param trans The transaction which contains the events.
	 */
	virtual void process_helper_event(const String & helper_uuid,
					  const Transaction & trans);
	/**
	* @brief invoke by setting.
	*/
	virtual void reset_option();

 private:
	/**
	 * @brief Process a key release event.
	 *
	 * @param key - the key event to be processed.
	 */
	bool _process_keyrelease(const KeyEvent & key_raw);

	/**
	 * @brief Process a key press event.
	 *
	 * @param key - the key event to be processed.
	 */
	bool _process_keypress(const KeyEvent & key);

	/**
	 * @brief keyboard process
	 *
	 * transfer key index to qwerty char set
	 */
	bool keypad_process_qwerty(KeyEvent & key);

	bool special_key_filter(KeyEvent & key);
};
#endif
