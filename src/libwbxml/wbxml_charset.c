/*
 * libwbxml, the WBXML Library.
 * Copyright (C) 2002-2008 Aymerick Jehanne <aymerick@jehanne.org>
 * Copyright (C) 2011 Michael Bell <michael.bell@opensync.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * LGPL v2.1: http://www.gnu.org/copyleft/lesser.txt
 *
 * Contact: aymerick@jehanne.org
 * Home: http://libwbxml.aymerick.com
 */

/**
 * @file wbxml_charset.c
 * @ingroup wbxml_charset
 *
 * @author Aymerick Jehanne <aymerick@jehanne.org>
 * @date 04/03/24
 *
 * @brief Charset Functions
 */

#include "wbxml_charset.h"
#include "wbxml_internals.h"

/* Structures */

/** WBXML Charset */
typedef struct WBXMLCharsetEntry_s {
    const WB_TINY       *name;     /**< Charset Name */
    WBXMLCharsetMIBEnum  mib_enum; /**< Charset MIBEnum Value */
} WBXMLCharsetEntry;


/* Globals */

/**
 * @brief Charset table
 * @note  From https://www.iana.org/assignments/character-sets/character-sets.txt
 */
static const WBXMLCharsetEntry wbxml_charset_entries[] =
{
    { "US-ASCII",                                      WBXML_CHARSET_US_ASCII },
    { "ISO-8859-1",                                    WBXML_CHARSET_ISO_8859_1 },
    { "ISO-8859-2",                                    WBXML_CHARSET_ISO_8859_2 },
    { "ISO-8859-3",                                    WBXML_CHARSET_ISO_8859_3 },
    { "ISO-8859-4",                                    WBXML_CHARSET_ISO_8859_4 },
    { "ISO-8859-5",                                    WBXML_CHARSET_ISO_8859_5 },
    { "ISO-8859-6",                                    WBXML_CHARSET_ISO_8859_6 },
    { "ISO-8859-7",                                    WBXML_CHARSET_ISO_8859_7 },
    { "ISO-8859-8",                                    WBXML_CHARSET_ISO_8859_8 },
    { "ISO-8859-9",                                    WBXML_CHARSET_ISO_8859_9 },
    { "ISO-8859-10",                                   WBXML_CHARSET_ISO_8859_10 },
    { "Shift_JIS",                                     WBXML_CHARSET_SHIFT_JIS },
    { "Extended_UNIX_Code_Packed_Format_for_Japanese", WBXML_CHARSET_EXTENDED_UNIX_CODE_PACKED_FORMAT_FOR_JAPANESE },
    { "Extended_UNIX_Code_Fixed_Width_for_Japanese",   WBXML_CHARSET_EXTENDED_UNIX_CODE_FIXED_WIDTH_FOR_JAPANESE },
    { "BS_4730",                                       WBXML_CHARSET_BS_4730 },
    { "SEN_850200_C",                                  WBXML_CHARSET_SEN_850200_C },
    { "IT",                                            WBXML_CHARSET_IT },
    { "ES",                                            WBXML_CHARSET_ES },
    { "DIN_66003",                                     WBXML_CHARSET_DIN_66003 },
    { "NS_4551-1",                                     WBXML_CHARSET_NS_4551_1 },
    { "NF_Z_62-010",                                   WBXML_CHARSET_NF_Z_62_010 },
    { "ISO-10646-UTF-1",                               WBXML_CHARSET_ISO_10646_UTF_1 },
    { "ISO-646.basic",                                 WBXML_CHARSET_ISO_646_BASIC },
    { "INVARIANT",                                     WBXML_CHARSET_INVARIANT },
    { "ISO-646.irv",                                   WBXML_CHARSET_ISO_646_IRV },
    { "NATS-SEFI",                                     WBXML_CHARSET_NATS_SEFI },
    { "NATS-SEFI-ADD",                                 WBXML_CHARSET_NATS_SEFI_ADD },
    { "NATS-DANO",                                     WBXML_CHARSET_NATS_DANO },
    { "NATS-DANO-ADD",                                 WBXML_CHARSET_NATS_DANO_ADD },
    { "SEN_850200_B",                                  WBXML_CHARSET_SEN_850200_B },
    { "KS_C_5601-1987",                                WBXML_CHARSET_KS_C_5601_1987 },
    { "ISO-2022-KR",                                   WBXML_CHARSET_ISO_2022_KR },
    { "EUC-KR",                                        WBXML_CHARSET_EUC_KR },
    { "ISO-2022-JP",                                   WBXML_CHARSET_ISO_2022_JP },
    { "ISO-2022-JP-2",                                 WBXML_CHARSET_ISO_2022_JP_2 },
    { "JIS_C6220-1969-jp",                             WBXML_CHARSET_JIS_C6220_1969_JP },
    { "JIS_C6220-1969-ro",                             WBXML_CHARSET_JIS_C6220_1969_RO },
    { "PT",                                            WBXML_CHARSET_PT },
    { "greek7-old",                                    WBXML_CHARSET_GREEK7_OLD },
    { "latin-greek",                                   WBXML_CHARSET_LATIN_GREEK },
    { "NF_Z_62-010_(1973)",                            WBXML_CHARSET_NF_Z_62_010_1973 },
    { "Latin-greek-1",                                 WBXML_CHARSET_LATIN_GREEK_1 },
    { "ISO-5427",                                      WBXML_CHARSET_ISO_5427 },
    { "JIS_C6226-1978",                                WBXML_CHARSET_JIS_C6226_1978 },
    { "BS_viewdata",                                   WBXML_CHARSET_BS_VIEWDATA },
    { "INIS",                                          WBXML_CHARSET_INIS },
    { "INIS-8",                                        WBXML_CHARSET_INIS_8 },
    { "INIS-cyrillic",                                 WBXML_CHARSET_INIS_CYRILLIC },
    { "ISO-5427",                                      WBXML_CHARSET_ISO_5427_1981 },
    { "ISO-5428",                                      WBXML_CHARSET_ISO_5428 },
    { "GB_1988-80",                                    WBXML_CHARSET_GB_1988_80 },
    { "GB_2312-80",                                    WBXML_CHARSET_GB_2312_80 },
    { "NS_4551-2",                                     WBXML_CHARSET_NS_4551_2 },
    { "videotex-suppl",                                WBXML_CHARSET_VIDEOTEX_SUPPL },
    { "PT2",                                           WBXML_CHARSET_PT2 },
    { "ES2",                                           WBXML_CHARSET_ES2 },
    { "MSZ_7795.3",                                    WBXML_CHARSET_MSZ_7795_3 },
    { "JIS_C6226-1983",                                WBXML_CHARSET_JIS_C6226_1983 },
    { "greek7",                                        WBXML_CHARSET_GREEK7 },
    { "ASMO_449",                                      WBXML_CHARSET_ASMO_449 },
    { "iso-ir-90",                                     WBXML_CHARSET_ISO_IR_90 },
    { "JIS_C6229-1984-a",                              WBXML_CHARSET_JIS_C6229_1984_A },
    { "JIS_C6229-1984-b",                              WBXML_CHARSET_JIS_C6229_1984_B },
    { "JIS_C6229-1984-b-add",                          WBXML_CHARSET_JIS_C6229_1984_B_ADD },
    { "JIS_C6229-1984-hand",                           WBXML_CHARSET_JIS_C6229_1984_HAND },
    { "JIS_C6229-1984-hand-add",                       WBXML_CHARSET_JIS_C6229_1984_HAND_ADD },
    { "JIS_C6229-1984-kana",                           WBXML_CHARSET_JIS_C6229_1984_KANA },
    { "ISO-2033-1983",                                 WBXML_CHARSET_ISO_2033_1983 },
    { "ANSI_X3.110-1983",                              WBXML_CHARSET_ANSI_X3_110_1983 },
    { "T.61-7bit",                                     WBXML_CHARSET_T_61_7BIT },
    { "T.61-8bit",                                     WBXML_CHARSET_T_61_8BIT },
    { "ECMA-cyrillic",                                 WBXML_CHARSET_ECMA_CYRILLIC },
    { "CSA_Z243.4-1985-1",                             WBXML_CHARSET_CSA_Z243_4_1985_1 },
    { "CSA_Z243.4-1985-2",                             WBXML_CHARSET_CSA_Z243_4_1985_2 },
    { "CSA_Z243.4-1985-gr",                            WBXML_CHARSET_CSA_Z243_4_1985_GR },
    { "ISO-8859-6-E",                                  WBXML_CHARSET_ISO_8859_6_E },
    { "ISO-8859-6-I",                                  WBXML_CHARSET_ISO_8859_6_I },
    { "T.101-G2",                                      WBXML_CHARSET_T_101_G2 },
    { "ISO-8859-8-E",                                  WBXML_CHARSET_ISO_8859_8_E },
    { "ISO-8859-8-I",                                  WBXML_CHARSET_ISO_8859_8_I },
    { "CSN_369103",                                    WBXML_CHARSET_CSN_369103 },
    { "JUS_I.B1.002",                                  WBXML_CHARSET_JUS_I_B1_002 },
    { "IEC_P27-1",                                     WBXML_CHARSET_IEC_P27_1 },
    { "JUS_I.B1.003-serb",                             WBXML_CHARSET_JUS_I_B1_003_SERB },
    { "JUS_I.B1.003-mac",                              WBXML_CHARSET_JUS_I_B1_003_MAC },
    { "greek-ccitt",                                   WBXML_CHARSET_GREEK_CCITT },
    { "NC_NC00-10:81",                                 WBXML_CHARSET_NC_NC00_10 },
    { "ISO-6937-2-25",                                 WBXML_CHARSET_ISO_6937_2_25 },
    { "GOST_19768-74",                                 WBXML_CHARSET_GOST_19768_74 },
    { "ISO-8859-supp",                                 WBXML_CHARSET_ISO_8859_SUPP },
    { "ISO-10367-box",                                 WBXML_CHARSET_ISO_10367_BOX },
    { "latin-lap",                                     WBXML_CHARSET_LATIN_LAP },
    { "JIS_X0212-1990",                                WBXML_CHARSET_JIS_X0212_1990 },
    { "DS_2089",                                       WBXML_CHARSET_DS_2089 },
    { "us-dk",                                         WBXML_CHARSET_US_DK },
    { "dk-us",                                         WBXML_CHARSET_DK_US },
    { "KSC5636",                                       WBXML_CHARSET_KSC5636 },
    { "UNICODE-1-1-UTF-7",                             WBXML_CHARSET_UNICODE_1_1_UTF_7 },
    { "ISO-2022-CN",                                   WBXML_CHARSET_ISO_2022_CN },
    { "ISO-2022-CN-EXT",                               WBXML_CHARSET_ISO_2022_CN_EXT },
    { "UTF-8",                                         WBXML_CHARSET_UTF_8 },
    { "ISO-8859-13",                                   WBXML_CHARSET_ISO_8859_13 },
    { "ISO-8859-14",                                   WBXML_CHARSET_ISO_8859_14 },
    { "ISO-8859-15",                                   WBXML_CHARSET_ISO_8859_15 },
    { "ISO-8859-16",                                   WBXML_CHARSET_ISO_8859_16 },
    { "GBK",                                           WBXML_CHARSET_GBK },
    { "GB18030",                                       WBXML_CHARSET_GB18030 },
    { "OSD_EBCDIC_DF04_15",                            WBXML_CHARSET_OSD_EBCDIC_DF04_15 },
    { "OSD_EBCDIC_DF03_IRV",                           WBXML_CHARSET_OSD_EBCDIC_DF03_IRV },
    { "OSD_EBCDIC_DF04_1",                             WBXML_CHARSET_OSD_EBCDIC_DF04_1 },
    { "ISO-11548-1",                                   WBXML_CHARSET_ISO_11548_1 },
    { "KZ-1048",                                       WBXML_CHARSET_KZ_1048 },
    { "ISO-10646-UCS-2",                               WBXML_CHARSET_ISO_10646_UCS_2 },
    { "ISO-10646-UCS-4",                               WBXML_CHARSET_ISO_10646_UCS_4 },
    { "ISO-10646-UCS-Basic",                           WBXML_CHARSET_ISO_10646_UCS_BASIC },
    { "ISO-10646-Unicode-Latin1",                      WBXML_CHARSET_ISO_10646_UNICODE_LATIN1 },
    { "ISO-10646-J-1",                                 WBXML_CHARSET_ISO_10646_J_1 },
    { "ISO-Unicode-IBM-1261",                          WBXML_CHARSET_ISO_UNICODE_IBM_1261 },
    { "ISO-Unicode-IBM-1268",                          WBXML_CHARSET_ISO_UNICODE_IBM_1268 },
    { "ISO-Unicode-IBM-1276",                          WBXML_CHARSET_ISO_UNICODE_IBM_1276 },
    { "ISO-Unicode-IBM-1264",                          WBXML_CHARSET_ISO_UNICODE_IBM_1264 },
    { "ISO-Unicode-IBM-1265",                          WBXML_CHARSET_ISO_UNICODE_IBM_1265 },
    { "UNICODE-1-1",                                   WBXML_CHARSET_UNICODE_1_1 },
    { "SCSU",                                          WBXML_CHARSET_SCSU },
    { "UTF-7",                                         WBXML_CHARSET_UTF_7 },
    { "UTF-16BE",                                      WBXML_CHARSET_UTF_16BE },
    { "UTF-16LE",                                      WBXML_CHARSET_UTF_16LE },
    { "UTF-16",                                        WBXML_CHARSET_UTF_16 },
    { "CESU-8",                                        WBXML_CHARSET_CESU_8 },
    { "UTF-32",                                        WBXML_CHARSET_UTF_32 },
    { "UTF-32BE",                                      WBXML_CHARSET_UTF_32BE },
    { "UTF-32LE",                                      WBXML_CHARSET_UTF_32LE },
    { "BOCU-1",                                        WBXML_CHARSET_BOCU_1 },
    { "ISO-8859-1-Windows-3.0-Latin-1",                WBXML_CHARSET_ISO_8859_1_WINDOWS_3_0_LATIN_1 },
    { "ISO-8859-1-Windows-3.1-Latin-1",                WBXML_CHARSET_ISO_8859_1_WINDOWS_3_1_LATIN_1 },
    { "ISO-8859-2-Windows-Latin-2",                    WBXML_CHARSET_ISO_8859_2_WINDOWS_LATIN_2 },
    { "ISO-8859-9-Windows-Latin-5",                    WBXML_CHARSET_ISO_8859_9_WINDOWS_LATIN_5 },
    { "hp-roman8",                                     WBXML_CHARSET_HP_ROMAN8 },
    { "Adobe-Standard-Encoding",                       WBXML_CHARSET_ADOBE_STANDARD_ENCODING },
    { "Ventura-US",                                    WBXML_CHARSET_VENTURA_US },
    { "Ventura-International",                         WBXML_CHARSET_VENTURA_INTERNATIONAL },
    { "DEC-MCS",                                       WBXML_CHARSET_DEC_MCS },
    { "IBM850",                                        WBXML_CHARSET_IBM850 },
    { "PC8-Danish-Norwegian",                          WBXML_CHARSET_PC8_DANISH_NORWEGIAN },
    { "IBM862",                                        WBXML_CHARSET_IBM862 },
    { "PC8-Turkish",                                   WBXML_CHARSET_PC8_TURKISH },
    { "IBM-Symbols",                                   WBXML_CHARSET_IBM_SYMBOLS },
    { "IBM-Thai",                                      WBXML_CHARSET_IBM_THAI },
    { "HP-Legal",                                      WBXML_CHARSET_HP_LEGAL },
    { "HP-Pi-font",                                    WBXML_CHARSET_HP_PI_FONT },
    { "HP-Math8",                                      WBXML_CHARSET_HP_MATH8 },
    { "Adobe-Symbol-Encoding",                         WBXML_CHARSET_ADOBE_SYMBOL_ENCODING },
    { "HP-DeskTop",                                    WBXML_CHARSET_HP_DESKTOP },
    { "Ventura-Math",                                  WBXML_CHARSET_VENTURA_MATH },
    { "Microsoft-Publishing",                          WBXML_CHARSET_MICROSOFT_PUBLISHING },
    { "Windows-31J",                                   WBXML_CHARSET_WINDOWS_31J },
    { "GB2312",                                        WBXML_CHARSET_GB2312 },
    { "Big5",                                          WBXML_CHARSET_BIG5 },
    { "macintosh",                                     WBXML_CHARSET_MACINTOSH },
    { "IBM037",                                        WBXML_CHARSET_IBM037 },
    { "IBM038",                                        WBXML_CHARSET_IBM038 },
    { "IBM273",                                        WBXML_CHARSET_IBM273 },
    { "IBM274",                                        WBXML_CHARSET_IBM274 },
    { "IBM275",                                        WBXML_CHARSET_IBM275 },
    { "IBM277",                                        WBXML_CHARSET_IBM277 },
    { "IBM278",                                        WBXML_CHARSET_IBM278 },
    { "IBM280",                                        WBXML_CHARSET_IBM280 },
    { "IBM281",                                        WBXML_CHARSET_IBM281 },
    { "IBM284",                                        WBXML_CHARSET_IBM284 },
    { "IBM285",                                        WBXML_CHARSET_IBM285 },
    { "IBM290",                                        WBXML_CHARSET_IBM290 },
    { "IBM297",                                        WBXML_CHARSET_IBM297 },
    { "IBM420",                                        WBXML_CHARSET_IBM420 },
    { "IBM423",                                        WBXML_CHARSET_IBM423 },
    { "IBM424",                                        WBXML_CHARSET_IBM424 },
    { "IBM437",                                        WBXML_CHARSET_IBM437 },
    { "IBM500",                                        WBXML_CHARSET_IBM500 },
    { "IBM851",                                        WBXML_CHARSET_IBM851 },
    { "IBM852",                                        WBXML_CHARSET_IBM852 },
    { "IBM855",                                        WBXML_CHARSET_IBM855 },
    { "IBM857",                                        WBXML_CHARSET_IBM857 },
    { "IBM860",                                        WBXML_CHARSET_IBM860 },
    { "IBM861",                                        WBXML_CHARSET_IBM861 },
    { "IBM863",                                        WBXML_CHARSET_IBM863 },
    { "IBM864",                                        WBXML_CHARSET_IBM864 },
    { "IBM865",                                        WBXML_CHARSET_IBM865 },
    { "IBM868",                                        WBXML_CHARSET_IBM868 },
    { "IBM869",                                        WBXML_CHARSET_IBM869 },
    { "IBM870",                                        WBXML_CHARSET_IBM870 },
    { "IBM871",                                        WBXML_CHARSET_IBM871 },
    { "IBM880",                                        WBXML_CHARSET_IBM880 },
    { "IBM891",                                        WBXML_CHARSET_IBM891 },
    { "IBM903",                                        WBXML_CHARSET_IBM903 },
    { "IBM904",                                        WBXML_CHARSET_IBM904 },
    { "IBM905",                                        WBXML_CHARSET_IBM905 },
    { "IBM918",                                        WBXML_CHARSET_IBM918 },
    { "IBM1026",                                       WBXML_CHARSET_IBM1026 },
    { "EBCDIC-AT-DE",                                  WBXML_CHARSET_EBCDIC_AT_DE },
    { "EBCDIC-AT-DE-A",                                WBXML_CHARSET_EBCDIC_AT_DE_A },
    { "EBCDIC-CA-FR",                                  WBXML_CHARSET_EBCDIC_CA_FR },
    { "EBCDIC-DK-NO",                                  WBXML_CHARSET_EBCDIC_DK_NO },
    { "EBCDIC-DK-NO-A",                                WBXML_CHARSET_EBCDIC_DK_NO_A },
    { "EBCDIC-FI-SE",                                  WBXML_CHARSET_EBCDIC_FI_SE },
    { "EBCDIC-FI-SE-A",                                WBXML_CHARSET_EBCDIC_FI_SE_A },
    { "EBCDIC-FR",                                     WBXML_CHARSET_EBCDIC_FR },
    { "EBCDIC-IT",                                     WBXML_CHARSET_EBCDIC_IT },
    { "EBCDIC-PT",                                     WBXML_CHARSET_EBCDIC_PT },
    { "EBCDIC-ES",                                     WBXML_CHARSET_EBCDIC_ES },
    { "EBCDIC-ES-A",                                   WBXML_CHARSET_EBCDIC_ES_A },
    { "EBCDIC-ES-S",                                   WBXML_CHARSET_EBCDIC_ES_S },
    { "EBCDIC-UK",                                     WBXML_CHARSET_EBCDIC_UK },
    { "EBCDIC-US",                                     WBXML_CHARSET_EBCDIC_US },
    { "UNKNOWN-8BIT",                                  WBXML_CHARSET_UNKNOWN_8BIT },
    { "MNEMONIC",                                      WBXML_CHARSET_MNEMONIC },
    { "MNEM",                                          WBXML_CHARSET_MNEM },
    { "VISCII",                                        WBXML_CHARSET_VISCII },
    { "VIQR",                                          WBXML_CHARSET_VIQR },
    { "KOI8-R",                                        WBXML_CHARSET_KOI8_R },
    { "HZ-GB-2312",                                    WBXML_CHARSET_HZ_GB_2312 },
    { "IBM866",                                        WBXML_CHARSET_IBM866 },
    { "IBM775",                                        WBXML_CHARSET_IBM775 },
    { "KOI8-U",                                        WBXML_CHARSET_KOI8_U },
    { "IBM00858",                                      WBXML_CHARSET_IBM00858 },
    { "IBM00924",                                      WBXML_CHARSET_IBM00924 },
    { "IBM01140",                                      WBXML_CHARSET_IBM01140 },
    { "IBM01141",                                      WBXML_CHARSET_IBM01141 },
    { "IBM01142",                                      WBXML_CHARSET_IBM01142 },
    { "IBM01143",                                      WBXML_CHARSET_IBM01143 },
    { "IBM01144",                                      WBXML_CHARSET_IBM01144 },
    { "IBM01145",                                      WBXML_CHARSET_IBM01145 },
    { "IBM01146",                                      WBXML_CHARSET_IBM01146 },
    { "IBM01147",                                      WBXML_CHARSET_IBM01147 },
    { "IBM01148",                                      WBXML_CHARSET_IBM01148 },
    { "IBM01149",                                      WBXML_CHARSET_IBM01149 },
    { "Big5-HKSCS",                                    WBXML_CHARSET_BIG5_HKSCS },
    { "IBM1047",                                       WBXML_CHARSET_IBM1047 },
    { "PTCP154",                                       WBXML_CHARSET_PTCP154 },
    { "Amiga-1251",                                    WBXML_CHARSET_AMIGA_1251 },
    { "KOI7-switched",                                 WBXML_CHARSET_KOI7_SWITCHED },
    { "BRF",                                           WBXML_CHARSET_BRF },
    { "TSCII",                                         WBXML_CHARSET_TSCII },
    { "CP51932",                                       WBXML_CHARSET_CP51932 },
    { "windows-874",                                   WBXML_CHARSET_WINDOWS_874 },
    { "windows-1250",                                  WBXML_CHARSET_WINDOWS_1250 },
    { "windows-1251",                                  WBXML_CHARSET_WINDOWS_1251 },
    { "windows-1252",                                  WBXML_CHARSET_WINDOWS_1252 },
    { "windows-1253",                                  WBXML_CHARSET_WINDOWS_1253 },
    { "windows-1254",                                  WBXML_CHARSET_WINDOWS_1254 },
    { "windows-1255",                                  WBXML_CHARSET_WINDOWS_1255 },
    { "windows-1256",                                  WBXML_CHARSET_WINDOWS_1256 },
    { "windows-1257",                                  WBXML_CHARSET_WINDOWS_1257 },
    { "windows-1258",                                  WBXML_CHARSET_WINDOWS_1258 },
    { "TIS-620",                                       WBXML_CHARSET_TIS_620 },
    { "CP50220",                                       WBXML_CHARSET_CP50220 }
};


/* Private Functions Prototypes */
static WB_BOOL search_null_block(const WB_TINY *in_buf,
                                 WB_ULONG       in_buf_len,
                                 WB_ULONG       block_len,
                                 WB_ULONG      *out_pos);


/***************************************************
 *    Public Functions
 */

WBXML_DECLARE(WB_BOOL) wbxml_charset_get_mib(const WB_TINY       *name,
                                             WBXMLCharsetMIBEnum *mib_enum)
{
    WB_ULONG i = 0;

    for (i = 0; i < WBXML_TABLE_SIZE(wbxml_charset_entries); i++) {
        if (WBXML_STRCASECMP(name, wbxml_charset_entries[i].name) == 0) {
            if (mib_enum != NULL) {
                *mib_enum = wbxml_charset_entries[i].mib_enum;
            }

            return TRUE;
        }
    }

    return FALSE;
}


WBXML_DECLARE(WB_BOOL) wbxml_charset_get_name(WBXMLCharsetMIBEnum   mib_enum,
                                              const WB_TINY       **name)
{
    WB_ULONG i = 0;

    for (i = 0; i < WBXML_TABLE_SIZE(wbxml_charset_entries); i++) {
        if (mib_enum == wbxml_charset_entries[i].mib_enum) {
            if (name != NULL) {
                *name = wbxml_charset_entries[i].name;
            }

            return TRUE;
        }
    }

    return FALSE;
}


WBXML_DECLARE(WBXMLError) wbxml_charset_conv(const WB_TINY        *in_buf,
                                             WB_ULONG             *io_bytes,
                                             WBXMLCharsetMIBEnum   in_charset,
                                             WBXMLBuffer         **out_buf,
                                             WBXMLCharsetMIBEnum   out_charset)
{
    /**************************************************
     * First, check for simple US-ASCII / UTF-8 cases
     */

    /* Are we dealing with US-ASCII or UTF-8 ? */
    if (((in_charset  == WBXML_CHARSET_US_ASCII) || (in_charset  == WBXML_CHARSET_UTF_8)) &&
        ((out_charset == WBXML_CHARSET_US_ASCII) || (out_charset == WBXML_CHARSET_UTF_8)))
    {
        /* Create a static buffer */
        if ((*out_buf = wbxml_buffer_sta_create_from_cstr(in_buf)) == NULL) {
            return WBXML_ERROR_NOT_ENOUGH_MEMORY;
        }

        /* US-ASCII and UTF-8 are NULL terminated */
        *io_bytes -= WBXML_STRLEN(in_buf) + 1;

        return WBXML_OK;
    }

    /**************************************
     * Ok guys, we really have to convert
     */

#if defined( HAVE_ICONV )

    {
        /**********************
         * The iconv way
         */

        const WB_TINY * inbuf_pos    = NULL;
        WB_TINY      **__restrict__ inbuf_ref = NULL;
        const WB_TINY * charset_to   = NULL;
        const WB_TINY * charset_from = NULL;
        WB_TINY       * tmp_buf      = NULL;
        WB_TINY       * tmp_ptr      = NULL;
        WB_ULONG        tmp_buf_len  = 0;
        WB_ULONG        tmp_len_left = 0;
        WBXMLError      ret          = WBXML_OK;
        iconv_t         cd           = 0;
        WB_UTINY        last_char    = 0;

        /* Get Charsets names */
        if (!wbxml_charset_get_name(in_charset, &charset_from)) {
            return WBXML_ERROR_CHARSET_UNKNOWN;
        }

        if (!wbxml_charset_get_name(out_charset, &charset_to)) {
            return WBXML_ERROR_CHARSET_UNKNOWN;
        }

        /* Init iconv */
        if ((cd = iconv_open(charset_to, charset_from)) == (iconv_t)(-1))
        {
            /* Init failed */
            return WBXML_ERROR_CHARSET_CONV_INIT;
        }

        /* Allocate maximum result buffer (4 bytes unicode) */
        tmp_len_left = tmp_buf_len = 4 * (sizeof(WB_TINY) * (*io_bytes));

        if ((tmp_buf = wbxml_malloc(tmp_buf_len)) == NULL) {
            iconv_close(cd);
            return WBXML_ERROR_NOT_ENOUGH_MEMORY;
        }

        tmp_ptr = tmp_buf;

        /* The input buffer is const but not the pointer itself.
           The original const *inbuf should not be modified for a potential later usage.
         */
        inbuf_pos = in_buf;
        inbuf_ref = (WB_TINY **__restrict__) &inbuf_pos;

        /* Convert ! */
        (void) iconv(cd,
                     inbuf_ref,
                     (size_t*)io_bytes,
                     &tmp_buf,
                     (size_t*)&tmp_len_left);

        /** @todo Check errno (but it doesn't seems to work on windows) */

        if (tmp_buf_len > tmp_len_left) {
            /* Create result buffer */
            if ((*out_buf = wbxml_buffer_create(tmp_ptr,
                                                tmp_buf_len - tmp_len_left,
                                                tmp_buf_len - tmp_len_left)) == NULL)
            {
                /* Not enough memory */
                ret = WBXML_ERROR_NOT_ENOUGH_MEMORY;
            }

            /* Remove trailing NULL char */
            wbxml_buffer_remove_trailing_zeros(*out_buf);
        }
        else
        {
            /* Not converted */
            ret = WBXML_ERROR_CHARSET_CONV;
        }

        /* Shutdown iconv */
        iconv_close(cd);

        /* Clean-up */
        wbxml_free(tmp_ptr);

        return ret;
    }

#else

    {
        /***************************************************
         * Add your own charset conversion function here !
         */

        return WBXML_ERROR_NO_CHARSET_CONV;
    }

#endif /* HAVE_ICONV */
}


WBXML_DECLARE(WBXMLError) wbxml_charset_conv_term(const WB_TINY        *in_buf,
                                                  WB_ULONG             *io_bytes,
                                                  WBXMLCharsetMIBEnum   in_charset,
                                                  WBXMLBuffer         **out_buf,
                                                  WBXMLCharsetMIBEnum   out_charset)
{
    WB_ULONG   buf_len  = 0;
    WB_ULONG   new_len  = 0;
    WB_ULONG   term_len = 0;
    WBXMLError ret      = WBXML_OK;

    /* Find length of input buffer */
    switch (in_charset)
    {
    case WBXML_CHARSET_ISO_10646_UCS_2 :
    case WBXML_CHARSET_UTF_16 :
        /* Terminated by two NULL char ("\0\0") */
        term_len = 2;

        if (!search_null_block(in_buf, *io_bytes, 2, &buf_len)) {
            return WBXML_ERROR_CHARSET_STR_LEN;
        }

        /* Add termination bytes length */
        buf_len += term_len;
        break;

    default :
        /* Terminated by a simple NULL char ('\0') */
        term_len = 1;

        buf_len = WBXML_STRLEN(in_buf) + term_len;
        break;
    }

    /* Check length found */
    if (buf_len > *io_bytes) {
        return WBXML_ERROR_CHARSET_STR_LEN;
    }

    /* Use a temporary length var (because it is decreased) */
    new_len = buf_len;

    /* Convert ! */
    ret = wbxml_charset_conv(in_buf,
                             &new_len,
                             in_charset,
                             out_buf,
                             out_charset);

    /* Set input buffer length */
    *io_bytes = buf_len;

    return ret;
}


/***************************************************
 *    Private Functions
 */

/**
 * Binary search of a sequence of NULL bytes in a buffer
 *
 * @param in_buf     Buffer to search in
 * @param in_buf_len Length of input buffer
 * @param block_len  Length of the NULL sequence
 * @param out_pos    Index of Sequence into Buffer
 * @return TRUE if found, FALSE otherwise
 */
static WB_BOOL search_null_block(const WB_TINY *in_buf,
                                 WB_ULONG       in_buf_len,
                                 WB_ULONG       block_len,
                                 WB_ULONG      *out_pos)
{
    WB_ULONG pos = 0;
    WB_ULONG i = 0;

    for (pos = 0; pos + block_len <= in_buf_len; pos += block_len) {
        for (i = 0; i < block_len; i++) {
            if (memcmp(in_buf + pos + i, "\0", 1)) {
                i = block_len;
            } else {
                if (i == block_len -1) {
                    *out_pos = pos;
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}
