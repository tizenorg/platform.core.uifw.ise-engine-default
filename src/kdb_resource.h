/*
 *  ise-engine-default
 *
 * Copyright (c) 2000 - 2011 Samsung Electronics Co., Ltd. All rights reserved.
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

#ifndef __KDB_RESOURCE_H__
#define __KDB_RESOURCE_H__

#define MAXCHARS_3x4	24
#define MAXKEYS_3x4		10
#define MAXKEYS_QWERTY 0xFF

typedef enum {
	I_HQR,			/* Regional Qwerty */
	I_HQD,			/* Descrite Qwerty */
	I_HPD,			/* 3x4 keypad */
	I_HKD,			/* 5x4 keypad */
	I_EXP
} IMKeypad;

typedef enum {
	IM_LANGUAGE_ENGLISH = 0,
	IM_LANGUAGE_FRENCH,
	IM_LANGUAGE_SPANISH,
	IM_LANGUAGE_DUTCH,
	IM_LANGUAGE_GERMAN,
	IM_LANGUAGE_GREEK,
	IM_LANGUAGE_ITALIAN,
	IM_LANGUAGE_PORTUGUESE,
	IM_LANGUAGE_TURKISH,
	IM_LANGUAGE_ARABIC,
	IM_LANGUAGE_RUSSIAN,
	IM_LANGUAGE_AFRIKAANS,
	IM_LANGUAGE_ASSAMESE,
	IM_LANGUAGE_AZERBAIJANI,
	IM_LANGUAGE_BASQUE,
	IM_LANGUAGE_BENGALI,
	IM_LANGUAGE_BULGARIAN,
	IM_LANGUAGE_CATALAN,
	IM_LANGUAGE_CZECH,
	IM_LANGUAGE_DANISH,
	IM_LANGUAGE_ESTONIAN,
	IM_LANGUAGE_FINNISH,
	IM_LANGUAGE_GALICIAN,
	IM_LANGUAGE_GEORGIAN,
	IM_LANGUAGE_GUJARATI,
	IM_LANGUAGE_HAUSA,
	IM_LANGUAGE_HEBREW,
	IM_LANGUAGE_HINDI,
	IM_LANGUAGE_HUNGARIAN,
	IM_LANGUAGE_ICELANDIC,
	IM_LANGUAGE_IRISH,
	IM_LANGUAGE_KANNADA,
	IM_LANGUAGE_KAZAKH,
	IM_LANGUAGE_LATVIAN,
	IM_LANGUAGE_LITHUANIAN,
	IM_LANGUAGE_MACEDONIAN,
	IM_LANGUAGE_MALAYALAM,
	IM_LANGUAGE_MALAY,
	IM_LANGUAGE_MARATHI,
	IM_LANGUAGE_MONGOLIAN,
	IM_LANGUAGE_NEPALI,
	IM_LANGUAGE_NORWEGIAN,
	IM_LANGUAGE_POLISH,
	IM_LANGUAGE_PUNJABI,
	IM_LANGUAGE_ROMANIAN,
	IM_LANGUAGE_SERBIAN,
	IM_LANGUAGE_SINHALA,
	IM_LANGUAGE_SLOVAK,
	IM_LANGUAGE_SLOVENIAN,
	IM_LANGUAGE_SWEDISH,
	IM_LANGUAGE_TAMIL,
	IM_LANGUAGE_TELUGU,
	IM_LANGUAGE_THAI,
	IM_LANGUAGE_UKRAINIAN,
	IM_LANGUAGE_URDU,
	IM_LANGUAGE_UZBEK,
	IM_LANGUAGE_VIETNAMESE,
	IM_LANGUAGE_WELSH,
	IM_LANGUAGE_XHOSA,
	IM_LANGUAGE_YORUBA,
	IM_LANGUAGE_ZULU,
	IM_LANGUAGE_CNT
} IMLangauge;

static const char *gplangname[IM_LANGUAGE_CNT] = {
	"English",
	"French",
	"Spanish",
	"Dutch",
	"German",
	"Greek",
	"Italian",
	"Portuguese",
	"Turkish",
	"Arabic (Egypt)",
	"Russian",
	"Afrikaans",
	"Assamese",
	"Azerbaijani",
	"Basque",
	"Bengali",
	"Bulgarian",
	"Catalan",
	"Czech",
	"Danish",
	"Estonian",
	"Finnish",
	"Galician",
	"Georgian",
	"Gujarati",
	"Hausa",
	"Hebrew",
	"Hindi",
	"Hungarian",
	"Icelandic",
	"Irish",
	"Kannada",
	"Kazakh",
	"Latvian",
	"Lithuanian",
	"Macedonian",
	"Malayalam",
	"Malay",
	"Marathi",
	"Mongolian",
	"Nepali",
	"Norwegian",
	"Polish",
	"Punjabi",
	"Romanian",
	"Serbian",
	"Sinhala",
	"Slovak",
	"Slovenian",
	"Swedish",
	"Tamil",
	"Telugu",
	"Thai",
	"Ukrainian",
	"Urdu",
	"Uzbek",
	"Vietnamese",
	"Welsh",
	"Xhosa",
	"Yoruba",
	"Zulu",
};


const signed char HQDConversion[] = {
  /* 0, 1,  2,  3,  4,  5,  6,  7,  8,  9,  A,  B,  C,  D,  E,  F */
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 0x00
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 0x10
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 0x20
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 0x30
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 0x40
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 0x50
	-1, 10, 23, 21, 12,  2, 13, 14, 15,  7, 16, 17, 18, 25, 24,  8,	// 0x60
	 9,  0,  3, 11,  4,  6, 22,  1, 20,  5, 19, -1, -1, -1, -1, -1,	// 0x70
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 0x80
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 0x90
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 0xA0
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 0xB0
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 0xC0
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 0xD0
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 0xE0
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  0  // 0xF0
};

static const unsigned short
 g_QWERTY_LOWER_CASE_LETTER[IM_LANGUAGE_CNT][MAXKEYS_QWERTY] = {
	{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
	 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
	 'z', 'x', 'c', 'v', 'b', 'n', 'm',},	/*English */
	{'a', 'z', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
	 'q', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
	 'm', 'w', 'x', 'c', 'v', 'b', 'n',},	/* LANGUAGE_FRENCH */
	{0x0071, 0x0077, 0x0065, 0x0072, 0x0074, 0x0079, 0x0075, 0x0069, 0x006F,
	 0x0070, 0x0061, 0x0073, 0x0064, 0x0066, 0x0067, 0x0068, 0x006A, 0x006B,
	 0x006C, 0x007A, 0x0078, 0x0063, 0x0076, 0x0062, 0x006E, 0x006D,},	/* LANGUAGE_SPANISH */
	{0x0071, 0x0077, 0x0065, 0x0072, 0x0074, 0x0079, 0x0075, 0x0069, 0x006F,
	 0x0070, 0x0061, 0x0073, 0x0064, 0x0066, 0x0067, 0x0068, 0x006A, 0x006B,
	 0x006C, 0x007A, 0x0078, 0x0063, 0x0076, 0x0062, 0x006E, 0x006D,},	/* LANGUAGE_DUTCH */
	{0x0071, 0x0077, 0x0065, 0x0072, 0x0074, 0x007A, 0x0075, 0x0069, 0x006F,
	 0x0070, 0x0061, 0x0073, 0x0064, 0x0066, 0x0067, 0x0068, 0x006A, 0x006B,
	 0x006C, 0x0079, 0x0078, 0x0063, 0x0076, 0x0062, 0x006E, 0x006D,},	/* LANGUAGE_GERMAN */
	{0x0071, 0x03C2, 0x03B5, 0x03C1, 0x03C4, 0x03C5, 0x03B8, 0x03B9, 0x03BF,
	 0x03C0, 0x03B1, 0x03C3, 0x03B4, 0x03C6, 0x03B3, 0x03B7, 0x03BE, 0x03BA,
	 0x03BB, 0x03B6, 0x03C7, 0x03C8, 0x03C9, 0x03B2, 0x03BD, 0x03BC,},	/* LANGUAGE_GREEK */
	{0x0071, 0x0077, 0x0065, 0x0072, 0x0074, 0x0079, 0x0075, 0x0069, 0x006F,
	 0x0070, 0x0061, 0x0073, 0x0064, 0x0066, 0x0067, 0x0068, 0x006A, 0x006B,
	 0x006C, 0x007A, 0x0078, 0x0063, 0x0076, 0x0062, 0x006E, 0x006D,},	/* LANGUAGE_ITALIAN */
	{0x0071, 0x0077, 0x0065, 0x0072, 0x0074, 0x0079, 0x0075, 0x0069, 0x006F,
	 0x0070, 0x0061, 0x0073, 0x0064, 0x0066, 0x0067, 0x0068, 0x006A, 0x006B,
	 0x006C, 0x007A, 0x0078, 0x0063, 0x0076, 0x0062, 0x006E, 0x006D,},	/* LANGUAGE_PORTUGUESE */
	{0x0071, 0x0077, 0x0065, 0x0072, 0x0074, 0x0079, 0x0075, 0x0069, 0x006F,
	 0x0070, 0x0061, 0x0073, 0x0064, 0x0066, 0x0067, 0x0068, 0x006A, 0x006B,
	 0x006C, 0x007A, 0x0078, 0x0063, 0x0076, 0x0062, 0x006E, 0x006D,},	/* LANGUAGE_TURKISH */
	{0,},			/* LANGUAGE_ARABIC */
	{0,},			/* LANGUAGE_RUSSIAN */
	{0,},			/* LANGUAGE_AFRIKAANS */
	{0,},			/* LANGUAGE_ASSAMESE */
	{0,},			/* LANGUAGE_AZERBAIJANI, */
	{0,},			/* LANGUAGE_BASQUE, */
	{0,},			/* LANGUAGE_BENGALI, */
	{0,},			/* LANGUAGE_BULGARIAN, */
	{0,},			/* LANGUAGE_CATALAN, */
	{0,},			/* LANGUAGE_CZECH, */
	{0,},			/* LANGUAGE_DANISH, */
	{0,},			/* LANGUAGE_ESTONIAN, */
	{0,},			/* LANGUAGE_FINNISH, */
	{0,},			/* LANGUAGE_GALICIAN, */
	{0,},			/* LANGUAGE_GEORGIAN, */
	{0,},			/* LANGUAGE_GUJARATI, */
	{0,},			/* LANGUAGE_HAUSA, */
	{0,},			/* LANGUAGE_HEBREW, */
	{0,},			/* LANGUAGE_HINDI, */
	{0,},			/* LANGUAGE_HUNGARIAN, */
	{0,},			/* LANGUAGE_ICELANDIC, */
	{0,},			/* LANGUAGE_IRISH, */
	{0,},			/* LANGUAGE_KANNADA, */
	{0,},			/* LANGUAGE_KAZAKH, */
	{0,},			/* LANGUAGE_LATVIAN, */
	{0,},			/* LANGUAGE_LITHUANIAN, */
	{0,},			/* LANGUAGE_MACEDONIAN, */
	{0,},			/* LANGUAGE_MALAYALAM, */
	{0,},			/* LANGUAGE_MALAY, */
	{0,},			/* LANGUAGE_MARATHI, */
	{0,},			/* LANGUAGE_MONGOLIAN, */
	{0,},			/* LANGUAGE_NEPALI */
	{0,},			/* LANGUAGE_NORWEGIAN, */
	{0,},			/* LANGUAGE_POLISH, */
	{0,},			/* LANGUAGE_PUNJABI, */
	{0,},			/* LANGUAGE_ROMANIAN, */
	{0,},			/* LANGUAGE_SERBIAN, */
	{0,},			/* LANGUAGE_SINHALA, */
	{0,},			/* LANGUAGE_SLOVAK, */
	{0,},			/* LANGUAGE_SLOVENIAN, */
	{0,},			/* LANGUAGE_SWEDISH, */
	{0,},			/* LANGUAGE_TAMIL, */
	{0,},			/* LANGUAGE_TELUGU, */
	{0,},			/* LANGUAGE_THAI, */
	{0,},			/* LANGUAGE_UKRAINIAN, */
	{0,},			/* LANGUAGE_URDU, */
	{0,},			/* LANGUAGE_UZBEK, */
	{0,},			/* LANGUAGE_VIETNAMESE, */
	{0,},			/* LANGUAGE_WELSH, */
	{0,},			/* LANGUAGE_XHOSA, */
	{0,},			/* LANGUAGE_YORUBA, */
	{0,},			/* LANGUAGE_ZULU, */
};

static const unsigned short
 g_QWERTY_UPPER_CASE_LETTER[IM_LANGUAGE_CNT][MAXKEYS_QWERTY] = {
	{0x0051, 0x0057, 0x0045, 0x0052, 0x0054, 0x0059, 0x0055, 0x0049, 0x004f,
	 0x0050, 0x0041, 0x0053, 0x0044, 0x0046, 0x0047, 0x0048, 0x004a, 0x004b,
	 0x004c, 0x005a, 0x0058, 0x0043, 0x0056, 0x0042, 0x004e, 0x004d,},	/*English */
	{0x0041, 0x005a, 0x0045, 0x0052, 0x0054, 0x0059, 0x0055, 0x0049, 0x004f,
	 0x0050, 0x0051, 0x0053, 0x0044, 0x0046, 0x0047, 0x0048, 0x004a, 0x004b,
	 0x004c, 0x004d, 0x0057, 0x0058, 0x0043, 0x0056, 0x0042, 0x004e,},	/* LANGUAGE_FRENCH */
	{0x0051, 0x0057, 0x0045, 0x0052, 0x0054, 0x0059, 0x0055, 0x0049, 0x004f,
	 0x0050, 0x0041, 0x0053, 0x0044, 0x0046, 0x0047, 0x0048, 0x004a, 0x004b,
	 0x004c, 0x005a, 0x0058, 0x0043, 0x0056, 0x0042, 0x004e, 0x004d,},	/* LANGUAGE_SPANISH */
	{0x0051, 0x0057, 0x0045, 0x0052, 0x0054, 0x0059, 0x0055, 0x0049, 0x004f,
	 0x0050, 0x0041, 0x0053, 0x0044, 0x0046, 0x0047, 0x0048, 0x004a, 0x004b,
	 0x004c, 0x005a, 0x0058, 0x0043, 0x0056, 0x0042, 0x004e, 0x004d,},	/* LANGUAGE_DUTCH */
	{0x0051, 0x0057, 0x0045, 0x0052, 0x0054, 0x005a, 0x0055, 0x0049, 0x004f,
	 0x0050, 0x0041, 0x0053, 0x0044, 0x0046, 0x0047, 0x0048, 0x004a, 0x004b,
	 0x004c, 0x0059, 0x0058, 0x0043, 0x0056, 0x0042, 0x004e, 0x004d,},	/* LANGUAGE_GERMAN */
	{0x003B, 0x03c2, 0x0395, 0x03a1, 0x03a4, 0x03a5, 0x0398, 0x0399, 0x039f,
	 0x03a0, 0x0391, 0x03a3, 0x0394, 0x03a6, 0x0393, 0x0397, 0x039e, 0x039a,
	 0x039b, 0x0396, 0x03a7, 0x03a8, 0x03a9, 0x0392, 0x039d, 0x039c,},	/* LANGUAGE_GREEK */
	{0x0051, 0x0057, 0x0045, 0x0052, 0x0054, 0x0059, 0x0055, 0x0049, 0x004f,
	 0x0050, 0x0041, 0x0053, 0x0044, 0x0046, 0x0047, 0x0048, 0x004a, 0x004b,
	 0x004c, 0x005a, 0x0058, 0x0043, 0x0056, 0x0042, 0x004e, 0x004d,},	/* LANGUAGE_ITALIAN */
	{0x0051, 0x0057, 0x0045, 0x0052, 0x0054, 0x0059, 0x0055, 0x0049, 0x004f,
	 0x0050, 0x0041, 0x0053, 0x0044, 0x0046, 0x0047, 0x0048, 0x004a, 0x004b,
	 0x004c, 0x005a, 0x0058, 0x0043, 0x0056, 0x0042, 0x004e, 0x004d,},	/* LANGUAGE_PORTUGUESE */
	{0x0051, 0x0057, 0x0045, 0x0052, 0x0054, 0x0059, 0x0055, 0x0049, 0x004f,
	 0x0050, 0x0041, 0x0053, 0x0044, 0x0046, 0x0047, 0x0048, 0x004a, 0x004b,
	 0x004c, 0x005a, 0x0058, 0x0043, 0x0056, 0x0042, 0x004e, 0x004d,},	/* LANGUAGE_TURKISH */
	{0,},			/* LANGUAGE_ARABIC */
	{0,},			/* LANGUAGE_RUSSIAN */
	{0,},			/* LANGUAGE_AFRIKAANS */
	{0,},			/* LANGUAGE_ASSAMESE */
	{0,},			/* LANGUAGE_AZERBAIJANI, */
	{0,},			/* LANGUAGE_BASQUE, */
	{0,},			/* LANGUAGE_BENGALI, */
	{0,},			/* LANGUAGE_BULGARIAN, */
	{0,},			/* LANGUAGE_CATALAN, */
	{0,},			/* LANGUAGE_CZECH, */
	{0,},			/* LANGUAGE_DANISH, */
	{0,},			/* LANGUAGE_ESTONIAN, */
	{0,},			/* LANGUAGE_FINNISH, */
	{0,},			/* LANGUAGE_GALICIAN, */
	{0,},			/* LANGUAGE_GEORGIAN, */
	{0,},			/* LANGUAGE_GUJARATI, */
	{0,},			/* LANGUAGE_HAUSA, */
	{0,},			/* LANGUAGE_HEBREW, */
	{0,},			/* LANGUAGE_HINDI, */
	{0,},			/* LANGUAGE_HUNGARIAN, */
	{0,},			/* LANGUAGE_ICELANDIC, */
	{0,},			/* LANGUAGE_IRISH, */
	{0,},			/* LANGUAGE_KANNADA, */
	{0,},			/* LANGUAGE_KAZAKH, */
	{0,},			/* LANGUAGE_LATVIAN, */
	{0,},			/* LANGUAGE_LITHUANIAN, */
	{0,},			/* LANGUAGE_MACEDONIAN, */
	{0,},			/* LANGUAGE_MALAYALAM, */
	{0,},			/* LANGUAGE_MALAY, */
	{0,},			/* LANGUAGE_MARATHI, */
	{0,},			/* LANGUAGE_MONGOLIAN, */
	{0,},			/* LANGUAGE_NEPALI */
	{0,},			/* LANGUAGE_NORWEGIAN, */
	{0,},			/* LANGUAGE_POLISH, */
	{0,},			/* LANGUAGE_PUNJABI, */
	{0,},			/* LANGUAGE_ROMANIAN, */
	{0,},			/* LANGUAGE_SERBIAN, */
	{0,},			/* LANGUAGE_SINHALA, */
	{0,},			/* LANGUAGE_SLOVAK, */
	{0,},			/* LANGUAGE_SLOVENIAN, */
	{0,},			/* LANGUAGE_SWEDISH, */
	{0,},			/* LANGUAGE_TAMIL, */
	{0,},			/* LANGUAGE_TELUGU, */
	{0,},			/* LANGUAGE_THAI, */
	{0,},			/* LANGUAGE_UKRAINIAN, */
	{0,},			/* LANGUAGE_URDU, */
	{0,},			/* LANGUAGE_UZBEK, */
	{0,},			/* LANGUAGE_VIETNAMESE, */
	{0,},			/* LANGUAGE_WELSH, */
	{0,},			/* LANGUAGE_XHOSA, */
	{0,},			/* LANGUAGE_YORUBA, */
	{0,},			/* LANGUAGE_ZULU, */
};

#endif
