/*
 * Language handle functions
 *
 * Copyright (c) 2011-2012, Joachim Metz <jbmetz@users.sourceforge.net>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _LANGUAGE_HANDLE_H )
#define _LANGUAGE_HANDLE_H

#include <common.h>
#include <types.h>

#include <libcstring.h>
#include <liberror.h>

#if defined( __cplusplus )
extern "C" {
#endif

/* TODO
enum LANGUAGE_HANDLE_FEATURE_FLAGS
{
};
*/

enum LANGUAGE_HANDLE_IDENTIFIERS
{
	LANGUAGE_HANDLE_IDENTIFIER_UNDEFINED	= 0x0000,
	LANGUAGE_HANDLE_IDENTIFIER_AR		= 0x0001,
	LANGUAGE_HANDLE_IDENTIFIER_BG		= 0x0002,
	LANGUAGE_HANDLE_IDENTIFIER_CA		= 0x0003,
	LANGUAGE_HANDLE_IDENTIFIER_ZA_HANS	= 0x0004,
	LANGUAGE_HANDLE_IDENTIFIER_CS		= 0x0005,
	LANGUAGE_HANDLE_IDENTIFIER_DA		= 0x0006,
	LANGUAGE_HANDLE_IDENTIFIER_DE		= 0x0007,
	LANGUAGE_HANDLE_IDENTIFIER_EL		= 0x0008,
	LANGUAGE_HANDLE_IDENTIFIER_EN		= 0x0009,
	LANGUAGE_HANDLE_IDENTIFIER_ES		= 0x000a,
	LANGUAGE_HANDLE_IDENTIFIER_FI		= 0x000b,
	LANGUAGE_HANDLE_IDENTIFIER_FR		= 0x000c,
	LANGUAGE_HANDLE_IDENTIFIER_HE		= 0x000d,
	LANGUAGE_HANDLE_IDENTIFIER_HU		= 0x000e,
	LANGUAGE_HANDLE_IDENTIFIER_IS		= 0x000f,
	LANGUAGE_HANDLE_IDENTIFIER_IT		= 0x0010,
	LANGUAGE_HANDLE_IDENTIFIER_JA		= 0x0011,
	LANGUAGE_HANDLE_IDENTIFIER_KO		= 0x0012,
	LANGUAGE_HANDLE_IDENTIFIER_NL		= 0x0013,
	LANGUAGE_HANDLE_IDENTIFIER_NO		= 0x0014,
	LANGUAGE_HANDLE_IDENTIFIER_PL		= 0x0015,
	LANGUAGE_HANDLE_IDENTIFIER_PT		= 0x0016,
	LANGUAGE_HANDLE_IDENTIFIER_RM		= 0x0017,
	LANGUAGE_HANDLE_IDENTIFIER_RO		= 0x0018,
	LANGUAGE_HANDLE_IDENTIFIER_RU		= 0x0019,
	LANGUAGE_HANDLE_IDENTIFIER_HR		= 0x001a,
	LANGUAGE_HANDLE_IDENTIFIER_SK		= 0x001b,
	LANGUAGE_HANDLE_IDENTIFIER_SQ		= 0x001c,
	LANGUAGE_HANDLE_IDENTIFIER_SV		= 0x001d,
	LANGUAGE_HANDLE_IDENTIFIER_TH		= 0x001e,
	LANGUAGE_HANDLE_IDENTIFIER_TR		= 0x001f,
	LANGUAGE_HANDLE_IDENTIFIER_UR		= 0x0020,
	LANGUAGE_HANDLE_IDENTIFIER_ID		= 0x0021,
	LANGUAGE_HANDLE_IDENTIFIER_UK		= 0x0022,
	LANGUAGE_HANDLE_IDENTIFIER_BE		= 0x0023,
	LANGUAGE_HANDLE_IDENTIFIER_SL		= 0x0024,
	LANGUAGE_HANDLE_IDENTIFIER_ET		= 0x0025,
	LANGUAGE_HANDLE_IDENTIFIER_LV		= 0x0026,
	LANGUAGE_HANDLE_IDENTIFIER_LT		= 0x0027,
	LANGUAGE_HANDLE_IDENTIFIER_TG		= 0x0028,
	LANGUAGE_HANDLE_IDENTIFIER_FA		= 0x0029,
	LANGUAGE_HANDLE_IDENTIFIER_VI		= 0x002a,
	LANGUAGE_HANDLE_IDENTIFIER_HY		= 0x002b,
	LANGUAGE_HANDLE_IDENTIFIER_AZ		= 0x002c,
	LANGUAGE_HANDLE_IDENTIFIER_EU		= 0x002d,
	LANGUAGE_HANDLE_IDENTIFIER_HSB		= 0x002e,
	LANGUAGE_HANDLE_IDENTIFIER_MK		= 0x002f,

	LANGUAGE_HANDLE_IDENTIFIER_TN		= 0x0032,

	LANGUAGE_HANDLE_IDENTIFIER_XH		= 0x0034,

	LANGUAGE_HANDLE_IDENTIFIER_ZU		= 0x0035,
	LANGUAGE_HANDLE_IDENTIFIER_AF		= 0x0036,
	LANGUAGE_HANDLE_IDENTIFIER_KA		= 0x0037,
	LANGUAGE_HANDLE_IDENTIFIER_FO		= 0x0038,
	LANGUAGE_HANDLE_IDENTIFIER_HI		= 0x0039,
	LANGUAGE_HANDLE_IDENTIFIER_MT		= 0x003a,
	LANGUAGE_HANDLE_IDENTIFIER_SE		= 0x003b,
	LANGUAGE_HANDLE_IDENTIFIER_GA		= 0x003c,
	LANGUAGE_HANDLE_IDENTIFIER_MS		= 0x003e,
	LANGUAGE_HANDLE_IDENTIFIER_KK		= 0x003f,
	LANGUAGE_HANDLE_IDENTIFIER_KY		= 0x0040,
	LANGUAGE_HANDLE_IDENTIFIER_SW		= 0x0041,
	LANGUAGE_HANDLE_IDENTIFIER_TK		= 0x0042,
	LANGUAGE_HANDLE_IDENTIFIER_UZ		= 0x0043,
	LANGUAGE_HANDLE_IDENTIFIER_TT		= 0x0044,
	LANGUAGE_HANDLE_IDENTIFIER_BN		= 0x0045,
	LANGUAGE_HANDLE_IDENTIFIER_PA		= 0x0046,
	LANGUAGE_HANDLE_IDENTIFIER_GU		= 0x0047,
	LANGUAGE_HANDLE_IDENTIFIER_OR		= 0x0048,
	LANGUAGE_HANDLE_IDENTIFIER_TA		= 0x0049,
	LANGUAGE_HANDLE_IDENTIFIER_TE		= 0x004a,
	LANGUAGE_HANDLE_IDENTIFIER_KN		= 0x004b,
	LANGUAGE_HANDLE_IDENTIFIER_ML		= 0x004c,
	LANGUAGE_HANDLE_IDENTIFIER_AS		= 0x004d,
	LANGUAGE_HANDLE_IDENTIFIER_MR		= 0x004e,
	LANGUAGE_HANDLE_IDENTIFIER_SA		= 0x004f,
	LANGUAGE_HANDLE_IDENTIFIER_MN		= 0x0050,
	LANGUAGE_HANDLE_IDENTIFIER_BO		= 0x0051,
	LANGUAGE_HANDLE_IDENTIFIER_CY		= 0x0052,
	LANGUAGE_HANDLE_IDENTIFIER_KM		= 0x0053,
	LANGUAGE_HANDLE_IDENTIFIER_LO		= 0x0054,

	LANGUAGE_HANDLE_IDENTIFIER_GL		= 0x0056,
	LANGUAGE_HANDLE_IDENTIFIER_KOK		= 0x0057,

	LANGUAGE_HANDLE_IDENTIFIER_SYR		= 0x005a,
	LANGUAGE_HANDLE_IDENTIFIER_SI		= 0x005b,

	LANGUAGE_HANDLE_IDENTIFIER_IU		= 0x005d,
	LANGUAGE_HANDLE_IDENTIFIER_AM		= 0x005e,
	LANGUAGE_HANDLE_IDENTIFIER_TZM		= 0x005f,

	LANGUAGE_HANDLE_IDENTIFIER_NE		= 0x0061,
	LANGUAGE_HANDLE_IDENTIFIER_FY		= 0x0062,
	LANGUAGE_HANDLE_IDENTIFIER_PS		= 0x0063,
	LANGUAGE_HANDLE_IDENTIFIER_FIL		= 0x0064,
	LANGUAGE_HANDLE_IDENTIFIER_DV		= 0x0065,

	LANGUAGE_HANDLE_IDENTIFIER_HA		= 0x0068,

	LANGUAGE_HANDLE_IDENTIFIER_YO		= 0x006a,
	LANGUAGE_HANDLE_IDENTIFIER_QUZ		= 0x006b,
	LANGUAGE_HANDLE_IDENTIFIER_NSO		= 0x006c,
	LANGUAGE_HANDLE_IDENTIFIER_BA		= 0x006d,
	LANGUAGE_HANDLE_IDENTIFIER_LB		= 0x006e,
	LANGUAGE_HANDLE_IDENTIFIER_KL		= 0x006f,
	LANGUAGE_HANDLE_IDENTIFIER_IG		= 0x0070,

	LANGUAGE_HANDLE_IDENTIFIER_II		= 0x0078,

	LANGUAGE_HANDLE_IDENTIFIER_ARN		= 0x007a,

	LANGUAGE_HANDLE_IDENTIFIER_MOH		= 0x007c,

	LANGUAGE_HANDLE_IDENTIFIER_BR		= 0x007e,

	LANGUAGE_HANDLE_IDENTIFIER_UG		= 0x0080,
	LANGUAGE_HANDLE_IDENTIFIER_MI		= 0x0081,
	LANGUAGE_HANDLE_IDENTIFIER_OC		= 0x0082,
	LANGUAGE_HANDLE_IDENTIFIER_CO		= 0x0083,
	LANGUAGE_HANDLE_IDENTIFIER_GSW		= 0x0084,
	LANGUAGE_HANDLE_IDENTIFIER_SAH		= 0x0085,
	LANGUAGE_HANDLE_IDENTIFIER_QUT		= 0x0086,
	LANGUAGE_HANDLE_IDENTIFIER_RW		= 0x0087,
	LANGUAGE_HANDLE_IDENTIFIER_WO		= 0x0088,

	LANGUAGE_HANDLE_IDENTIFIER_PRS		= 0x008c,

	LANGUAGE_HANDLE_IDENTIFIER_GD		= 0x0091,
};

#ifdef TODO
	{ 0x0401, "ar-SA",		"Arabic, Saudi Arabia" },
	{ 0x0402, "bg-BG",		"Bulgarian, Bulgaria" },
	{ 0x0403, "ca-ES",		"Catalan, Spain" },
	{ 0x0404, "zh-TW",		"Chinese, Taiwan, Province of China" },
	{ 0x0405, "cs-CZ",		"Czech, Czech Republic" },
	{ 0x0406, "da-DK",		"Danish, Denmark" },
	{ 0x0407, "de-DE",		"German, Germany" },
	{ 0x0408, "el-GR",		"Modern Greek (1453-), Greece" },
	{ 0x0409, "en-US",		"English, United States" },
	{ 0x040a, "es-ES_tradnl",	"Spanish" },
	{ 0x040b, "fi-FI",		"Finnish, Finland" },
	{ 0x040c, "fr-FR",		"French, France" },
	{ 0x040d, "he-IL",		"Hebrew, Israel" },
	{ 0x040e, "hu-HU",		"Hungarian, Hungary" },
	{ 0x040f, "is-IS",		"Icelandic, Iceland" },
	{ 0x0410, "it-IT",		"Italian, Italy" },
	{ 0x0411, "ja-JP",		"Japanese, Japan" },
	{ 0x0412, "ko-KR",		"Korean, Republic of Korea" },
	{ 0x0413, "nl-NL",		"Dutch, Netherlands" },
	{ 0x0414, "nb-NO",		"Norwegian Bokmål, Norway" },
	{ 0x0415, "pl-PL",		"Polish, Poland" },
	{ 0x0416, "pt-BR",		"Portuguese, Brazil" },
	{ 0x0417, "rm-CH",		"Romansh, Switzerland" },
	{ 0x0418, "ro-RO",		"Romanian, Romania" },
	{ 0x0419, "ru-RU",		"Russian, Russian Federation" },
	{ 0x041a, "hr-HR",		"Croatian, Croatia" },
	{ 0x041b, "sk-SK",		"Slovak, Slovakia" },
	{ 0x041c, "sq-AL",		"Albanian, Albania" },
	{ 0x041d, "sv-SE",		"Swedish, Sweden" },
	{ 0x041e, "th-TH",		"Thai, Thailand" },
	{ 0x041f, "tr-TR",		"Turkish, Turkey" },
	{ 0x0420, "ur-PK",		"Urdu, Pakistan" },
	{ 0x0421, "id-ID",		"Indonesian, Indonesia" },
	{ 0x0422, "uk-UA",		"Ukrainian, Ukraine" },
	{ 0x0423, "be-BY",		"Belarusian, Belarus" },
	{ 0x0424, "sl-SI",		"Slovenian, Slovenia" },
	{ 0x0425, "et-EE",		"Estonian, Estonia" },
	{ 0x0426, "lv-LV",		"Latvian, Latvia" },
	{ 0x0427, "lt-LT",		"Lithuanian, Lithuania" },
	{ 0x0428, "tg-Cyrl-TJ",		"Tajik, Cyrillic, Tajikistan" },
	{ 0x0429, "fa-IR",		"Persian, Islamic Republic of Iran" },
	{ 0x042a, "vi-VN",		"Vietnamese, Viet Nam" },
	{ 0x042b, "hy-AM",		"Armenian, Armenia" },
	{ 0x042c, "az-Latn-AZ",		"Azerbaijani, Latin, Azerbaijan" },
	{ 0x042d, "eu-ES",		"Basque, Spain" },
	{ 0x042e, "wen-DE",		"Sorbian languages, Germany" },
	{ 0x042f, "mk-MK",		"Macedonian, The Former Yugoslav Republic of Macedonia" },
	{ 0x0430, "st-ZA",		"Southern Sotho, South Africa" },
	{ 0x0431, "ts-ZA",		"Tsonga, South Africa" },
	{ 0x0432, "tn-ZA",		"Tswana, South Africa" },
	{ 0x0433, "ven-ZA",		"South Africa" },
	{ 0x0434, "xh-ZA",		"Xhosa, South Africa" },
	{ 0x0435, "zu-ZA",		"Zulu, South Africa" },
	{ 0x0436, "af-ZA",		"Afrikaans, South Africa" },
	{ 0x0437, "ka-GE",		"Georgian, Georgia" },
	{ 0x0438, "fo-FO",		"Faroese, Faroe Islands" },
	{ 0x0439, "hi-IN",		"Hindi, India" },
	{ 0x043a, "mt-MT",		"Maltese, Malta" },
	{ 0x043b, "se-NO",		"Northern Sami, Norway" },
	{ 0x043e, "ms-MY",		"Malay (macrolanguage), Malaysia" },
	{ 0x043f, "kk-KZ",		"Kazakh, Kazakhstan" },
	{ 0x0440, "ky-KG",		"Kirghiz, Kyrgyzstan" },
	{ 0x0441, "sw-KE",		"Swahili (macrolanguage), Kenya" },
	{ 0x0442, "tk-TM",		"Turkmen, Turkmenistan" },
	{ 0x0443, "uz-Latn-UZ",		"Uzbek, Latin, Uzbekistan" },
	{ 0x0444, "tt-RU",		"Tatar, Russian Federation" },
	{ 0x0445, "bn-IN",		"Bengali, India" },
	{ 0x0446, "pa-IN",		"Panjabi, India" },
	{ 0x0447, "gu-IN",		"Gujarati, India" },
	{ 0x0448, "or-IN",		"Oriya, India" },
	{ 0x0449, "ta-IN",		"Tamil, India" },
	{ 0x044a, "te-IN",		"Telugu, India" },
	{ 0x044b, "kn-IN",		"Kannada, India" },
	{ 0x044c, "ml-IN",		"Malayalam, India" },
	{ 0x044d, "as-IN",		"Assamese, India" },
	{ 0x044e, "mr-IN",		"Marathi, India" },
	{ 0x044f, "sa-IN",		"Sanskrit, India" },
	{ 0x0450, "mn-MN",		"Mongolian, Mongolia" },
	{ 0x0451, "bo-CN",		"Tibetan, China" },
	{ 0x0452, "cy-GB",		"Welsh, United Kingdom" },
	{ 0x0453, "km-KH",		"Central Khmer, Cambodia" },
	{ 0x0454, "lo-LA",		"Lao, Lao People's Democratic Republic" },
	{ 0x0455, "my-MM",		"Burmese, Myanmar" },
	{ 0x0456, "gl-ES",		"Galician, Spain" },
	{ 0x0457, "kok-IN",		"Konkani (macrolanguage), India" },
	{ 0x0458, "mni",		"Manipuri" },
	{ 0x0459, "sd-IN",		"Sindhi, India" },
	{ 0x045a, "syr-SY",		"Syriac, Syrian Arab Republic" },
	{ 0x045b, "si-LK",		"Sinhala, Sri Lanka" },
	{ 0x045c, "chr-US",		"Cherokee, United States" },
	{ 0x045d, "iu-Cans-CA",		"Inuktitut, Unified Canadian Aboriginal Syllabics, Canada" },
	{ 0x045e, "am-ET",		"Amharic, Ethiopia" },
	{ 0x045f, "tmz",		"Tamanaku" },
	{ 0x0461, "ne-NP",		"Nepali, Nepal" },
	{ 0x0462, "fy-NL",		"Western Frisian, Netherlands" },
	{ 0x0463, "ps-AF",		"Pushto, Afghanistan" },
	{ 0x0464, "fil-PH",		"Filipino, Philippines" },
	{ 0x0465, "dv-MV",		"Dhivehi, Maldives" },
	{ 0x0466, "bin-NG",		"Bini, Nigeria" },
	{ 0x0467, "fuv-NG",		"Nigerian Fulfulde, Nigeria" },
	{ 0x0468, "ha-Latn-NG",		"Hausa, Latin, Nigeria" },
	{ 0x0469, "ibb-NG",		"Ibibio, Nigeria" },
	{ 0x046a, "yo-NG",		"Yoruba, Nigeria" },
	{ 0x046b, "quz-BO",		"Cusco Quechua, Bolivia" },
	{ 0x046c, "nso-ZA",		"Pedi, South Africa" },
	{ 0x046d, "ba-RU",		"Bashkir, Russian Federation" },
	{ 0x046e, "lb-LU",		"Luxembourgish, Luxembourg" },
	{ 0x046f, "kl-GL",		"Kalaallisut, Greenland" },
	{ 0x0470, "ig-NG",		"Igbo, Nigeria" },
	{ 0x0471, "kr-NG",		"Kanuri, Nigeria" },
	{ 0x0472, "gaz-ET",		"West Central Oromo, Ethiopia" },
	{ 0x0473, "ti-ER",		"Tigrinya, Eritrea" },
	{ 0x0474, "gn-PY",		"Guarani, Paraguay" },
	{ 0x0475, "haw-US",		"Hawaiian, United States" },
	{ 0x0477, "so-SO",		"Somali, Somalia" },
	{ 0x0478, "ii-CN",		"Sichuan Yi, China" },
	{ 0x0479, "pap-AN",		"Papiamento, Netherlands Antilles" },
	{ 0x047a, "arn-CL",		"Mapudungun, Chile" },
	{ 0x047c, "moh-CA",		"Mohawk, Canada" },
	{ 0x047e, "br-FR",		"Breton, France" },
	{ 0x0480, "ug-CN",		"Uighur, China" },
	{ 0x0481, "mi-NZ",		"Maori, New Zealand" },
	{ 0x0482, "oc-FR",		"Occitan (post 1500), France" },
	{ 0x0483, "co-FR",		"Corsican, France" },
	{ 0x0484, "gsw-FR",		"Swiss German, France" },
	{ 0x0485, "sah-RU",		"Yakut, Russian Federation" },
	{ 0x0486, "qut-GT",		"Guatemala" },
	{ 0x0487, "rw-RW",		"Kinyarwanda, Rwanda" },
	{ 0x0488, "wo-SN",		"Wolof, Senegal" },
	{ 0x048c, "prs-AF",		"Dari, Afghanistan" },
	{ 0x048d, "plt-MG",		"Plateau Malagasy, Madagascar" },
	{ 0x0491, "gd-GB",		"Scottish Gaelic, United Kingdom" },

	{ 0x0801, "ar-IQ",		"Arabic, Iraq" },
	{ 0x0804, "zh-CN",		"Chinese, China" },
	{ 0x0807, "de-CH",		"German, Switzerland" },
	{ 0x0809, "en-GB",		"English, United Kingdom" },
	{ 0x080a, "es-MX",		"Spanish, Mexico" },
	{ 0x080c, "fr-BE",		"French, Belgium" },
	{ 0x0810, "it-CH",		"Italian, Switzerland" },
	{ 0x0813, "nl-BE",		"Dutch, Belgium" },
	{ 0x0814, "nn-NO",		"Norwegian Nynorsk, Norway" },
	{ 0x0816, "pt-PT",		"Portuguese, Portugal" },
	{ 0x0818, "ro-MO",		"Romanian, Macao" },
	{ 0x0819, "ru-MO",		"Russian, Macao" },
	{ 0x081a, "sr-Latn-CS",		"Serbian, Latin, Serbia and Montenegro" },
	{ 0x081d, "sv-FI",		"Swedish, Finland" },
	{ 0x0820, "ur-IN",		"Urdu, India" },
	{ 0x082c, "az-Cyrl-AZ",		"Azerbaijani, Cyrillic, Azerbaijan" },
	{ 0x082e, "dsb-DE",		"Lower Sorbian, Germany" },
	{ 0x083b, "se-SE",		"Northern Sami, Sweden" },
	{ 0x083c, "ga-IE",		"Irish, Ireland" },
	{ 0x083e, "ms-BN",		"Malay (macrolanguage), Brunei Darussalam" },
	{ 0x0843, "uz-Cyrl-UZ",		"Uzbek, Cyrillic, Uzbekistan" },
	{ 0x0845, "bn-BD",		"Bengali, Bangladesh" },
	{ 0x0846, "pa-PK",		"Panjabi, Pakistan" },
	{ 0x0850, "mn-Mong-CN",		"Mongolian, Mongolian, China" },
	{ 0x0851, "bo-BT",		"Tibetan, Bhutan" },
	{ 0x0859, "sd-PK",		"Sindhi, Pakistan" },
	{ 0x085d, "iu-Latn-CA",		"Inuktitut, Latin, Canada" },
	{ 0x085f, "tzm-Latn-DZ",	"Central Atlas Tamazight, Latin, Algeria" },
	{ 0x0861, "ne-IN",		"Nepali, India" },
	{ 0x086b, "quz-EC",		"Cusco Quechua, Ecuador" },
	{ 0x0873, "ti-ET",		"Tigrinya, Ethiopia" },

	{ 0x0c01, "ar-EG",		"Arabic, Egypt" },
	{ 0x0c04, "zh-HK",		"Chinese, Hong Kong" },
	{ 0x0c07, "de-AT",		"German, Austria" },
	{ 0x0c09, "en-AU",		"English, Australia" },
	{ 0x0c0a, "es-ES",		"Spanish, Spain" },
	{ 0x0c0c, "fr-CA",		"French, Canada" },
	{ 0x0c1a, "sr-Cyrl-CS",		"Serbian, Cyrillic, Serbia and Montenegro" },
	{ 0x0c3b, "se-FI",		"Northern Sami, Finland" },
	{ 0x0c5f, "tmz-MA",		"Tamanaku, Morocco" },
	{ 0x0c6b, "quz-PE",		"Cusco Quechua, Peru" },

	{ 0x1001, "ar-LY",		"Arabic, Libyan Arab Jamahiriya" },
	{ 0x1004, "zh-SG",		"Chinese, Singapore" },
	{ 0x1007, "de-LU",		"German, Luxembourg" },
	{ 0x1009, "en-CA",		"English, Canada" },
	{ 0x100a, "es-GT",		"Spanish, Guatemala" },
	{ 0x100c, "fr-CH",		"French, Switzerland" },
	{ 0x101a, "hr-BA",		"Croatian, Bosnia and Herzegovina" },
	{ 0x103b, "smj-NO",		"Lule Sami, Norway" },
	{ 0x1401, "ar-DZ",		"Arabic, Algeria" },
	{ 0x1404, "zh-MO",		"Chinese, Macao" },
	{ 0x1407, "de-LI",		"German, Liechtenstein" },
	{ 0x1409, "en-NZ",		"English, New Zealand" },
	{ 0x140a, "es-CR",		"Spanish, Costa Rica" },
	{ 0x140c, "fr-LU",		"French, Luxembourg" },
	{ 0x141a, "bs-Latn-BA",		"Bosnian, Latin, Bosnia and Herzegovina" },
	{ 0x143b, "smj-SE",		"Lule Sami, Sweden" },
	{ 0x1801, "ar-MA",		"Arabic, Morocco" },
	{ 0x1809, "en-IE",		"English, Ireland" },
	{ 0x180a, "es-PA",		"Spanish, Panama" },
	{ 0x180c, "fr-MC",		"French, Monaco" },
	{ 0x181a, "sr-Latn-BA",		"Serbian, Latin, Bosnia and Herzegovina" },
	{ 0x183b, "sma-NO",		"Southern Sami, Norway" },
	{ 0x1c01, "ar-TN",		"Arabic, Tunisia" },
	{ 0x1c09, "en-ZA",		"English, South Africa" },
	{ 0x1c0a, "es-DO",		"Spanish, Dominican Republic" },
	{ 0x1c0c, "fr-West",		"French" },
	{ 0x1c1a, "sr-Cyrl-BA",		"Serbian, Cyrillic, Bosnia and Herzegovina" },
	{ 0x1c3b, "sma-SE",		"Southern Sami, Sweden" },

	{ 0x2001, "ar-OM",		"Arabic, Oman" },
	{ 0x2009, "en-JM",		"English, Jamaica" },
	{ 0x200a, "es-VE",		"Spanish, Venezuela" },
	{ 0x200c, "fr-RE",		"French, Réunion" },
	{ 0x201a, "bs-Cyrl-BA",		"Bosnian, Cyrillic, Bosnia and Herzegovina" },
	{ 0x203b, "sms-FI",		"Skolt Sami, Finland" },
	{ 0x2401, "ar-YE",		"Arabic, Yemen" },
	{ 0x2409, "en-CB",		"English" },
	{ 0x240a, "es-CO",		"Spanish, Colombia" },
	{ 0x240c, "fr-CG",		"French, Congo" },
	{ 0x241a, "sr-Latn-RS",		"Serbian, Latin, Serbia" },
	{ 0x243b, "smn-FI",		"Inari Sami, Finland" },
	{ 0x2801, "ar-SY",		"Arabic, Syrian Arab Republic" },
	{ 0x2809, "en-BZ",		"English, Belize" },
	{ 0x280a, "es-PE",		"Spanish, Peru" },
	{ 0x280c, "fr-SN",		"French, Senegal" },
	{ 0x281a, "sr-Cyrl-RS",		"Serbian, Cyrillic, Serbia" },
	{ 0x2c01, "ar-JO",		"Arabic, Jordan" },
	{ 0x2c09, "en-TT",		"English, Trinidad and Tobago" },
	{ 0x2c0a, "es-AR",		"Spanish, Argentina" },
	{ 0x2c0c, "fr-CM",		"French, Cameroon" },
	{ 0x2c1a, "sr-Latn-ME",		"Serbian, Latin, Montenegro" },

	{ 0x3001, "ar-LB",		"Arabic, Lebanon" },
	{ 0x3009, "en-ZW",		"English, Zimbabwe" },
	{ 0x300a, "es-EC",		"Spanish, Ecuador" },
	{ 0x300c, "fr-CI",		"French, Côte d'Ivoire" },
	{ 0x301a, "sr-Cyrl-ME",		"Serbian, Cyrillic, Montenegro" },
	{ 0x3401, "ar-KW",		"Arabic, Kuwait" },
	{ 0x3409, "en-PH",		"English, Philippines" },
	{ 0x340a, "es-CL",		"Spanish, Chile" },
	{ 0x340c, "fr-ML",		"French, Mali" },
	{ 0x3801, "ar-AE",		"Arabic, United Arab Emirates" },
	{ 0x3809, "en-ID",		"English, Indonesia" },
	{ 0x380a, "es-UY",		"Spanish, Uruguay" },
	{ 0x380c, "fr-MA",		"French, Morocco" },
	{ 0x3c01, "ar-BH",		"Arabic, Bahrain" },
	{ 0x3c09, "en-HK",		"English, Hong Kong" },
	{ 0x3c0a, "es-PY",		"Spanish, Paraguay" },
	{ 0x3c0c, "fr-HT",		"French, Haiti" },

	{ 0x4001, "ar-QA",		"Arabic, Qatar" },
	{ 0x4009, "en-IN",		"English, India" },
	{ 0x400a, "es-BO",		"Spanish, Bolivia" },
	{ 0x4409, "en-MY",		"English, Malaysia" },
	{ 0x440a, "es-SV",		"Spanish, El Salvador" },
	{ 0x4809, "en-SG",		"English, Singapore" },
	{ 0x480a, "es-HN",		"Spanish, Honduras" },
	{ 0x4c0a, "es-NI",		"Spanish, Nicaragua" },

	{ 0x500a, "es-PR",		"Spanish, Puerto Rico" },
	{ 0x540a, "es-US",		"Spanish, United States" },

	{ 0x641a, "bs-Cyrl",		"Bosnian, Cyrillic" },
	{ 0x681a, "bs-Latn",		"Bosnian, Latin" },
	{ 0x6c1a, "sr-Cyrl",		"Serbian, Cyrillic" },

	{ 0x701a, "sr-Latn",		"Serbian, Latin" },
	{ 0x703b, "smn",		"Inari Sami" },
	{ 0x742c, "az-Cyrl",		"Azerbaijani, Cyrillic" },
	{ 0x743b, "sms",		"Skolt Sami" },
	{ 0x7804, "zh",			"Chinese" },
	{ 0x7814, "nn",			"Norwegian Nynorsk" },
	{ 0x781a, "bs",			"Bosnian" },
	{ 0x782c, "az-Latn",		"Azerbaijani, Latin" },
	{ 0x783b, "sma",		"Southern Sami" },
	{ 0x7843, "uz-Cyrl",		"Uzbek, Cyrillic" },
	{ 0x7850, "mn-Cyrl",		"Mongolian, Cyrillic" },
	{ 0x785d, "iu-Cans",		"Inuktitut, Unified Canadian Aboriginal Syllabics" },
	{ 0x7c04, "zh-Hant",		"Chinese, Han (Traditional variant)" },
	{ 0x7c14, "nb",			"Norwegian Bokmål" },
	{ 0x7c1a, "sr",			"Serbian" },
	{ 0x7c28, "tg-Cyrl",		"Tajik, Cyrillic" },
	{ 0x7c2e, "dsb",		"Lower Sorbian" },
	{ 0x7c3b, "smj",		"Lule Sami" },
	{ 0x7c43, "uz-Latn",		"Uzbek, Latin" },
	{ 0x7c50, "mn-Mong",		"Mongolian, Mongolian" },
	{ 0x7c5d, "iu-Latn",		"Inuktitut, Latin" },
	{ 0x7c5f, "tzm-Latn",		"Central Atlas Tamazight, Latin" },
	{ 0x7c68, "ha-Latn",		"Hausa, Latin" },
#endif

typedef struct language_handle language_handle_t;

struct language_handle
{
	/* The feature flags
	 */
	uint32_t feature_flags;

	/* The (language) identifier
	 */
	uint16_t identifier;
};

int language_handle_initialize(
     language_handle_t **language_handle,
     uint32_t feature_flags,
     liberror_error_t **error );

int language_handle_free(
     language_handle_t **language_handle,
     liberror_error_t **error );

int language_handle_get_identifier(
     language_handle_t *language_handle,
     uint16_t *language_identifier,
     liberror_error_t **error );

int language_handle_copy_from_string(
     language_handle_t *language_handle,
     const libcstring_system_character_t *string,
     size_t string_length,
     liberror_error_t **error );

int language_handle_copy_to_string(
     language_handle_t *language_handle,
     libcstring_system_character_t *string,
     size_t string_size,
     liberror_error_t **error );

/* TODO add list function */

#if defined( __cplusplus )
}
#endif

#endif

