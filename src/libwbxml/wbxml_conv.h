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
 * @file wbxml_conv.h
 * @ingroup wbxml_conv
 *
 * @author Aymerick Jehanne <aymerick@jehanne.org>
 * @date 03/02/23
 *
 * @brief WBXML Convertion Library (XML to WBXML, and WBXML to XML)
 */

#ifndef WBXML_CONV_H
#define WBXML_CONV_H

#include "wbxml.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** @addtogroup wbxml_conv
 *  @{
 */

/** WBXML Versions (WBXML tokens) */
typedef enum WBXMLVersion_e {
    WBXML_VERSION_UNKNOWN = -1, /**< Unknown WBXML Version */
    WBXML_VERSION_10 = 0x00,    /**< WBXML 1.0 Token */
    WBXML_VERSION_11 = 0x01,    /**< WBXML 1.1 Token */
    WBXML_VERSION_12 = 0x02,    /**< WBXML 1.2 Token */
    WBXML_VERSION_13 = 0x03     /**< WBXML 1.3 Token */
} WBXMLVersion;


/*
 * Possible Compilation Flags:
 * ---------------------------
 *
 *      WBXML_SUPPORT_WML
 *      WBXML_SUPPORT_WTA
 *      WBXML_SUPPORT_SI
 *      WBXML_SUPPORT_SL
 *      WBXML_SUPPORT_CO
 *      WBXML_SUPPORT_PROV
 *      WBXML_SUPPORT_EMN
 *      WBXML_SUPPORT_DRMREL
 *      WBXML_SUPPORT_OTA_SETTINGS
 *      WBXML_SUPPORT_SYNCML
 *      WBXML_SUPPORT_WV
 *      WBXML_SUPPORT_AIRSYNC
 *      WBXML_SUPPORT_CONML
 */


/** Supported WBXML Languages */
typedef enum WBXMLLanguage_e {
    WBXML_LANG_UNKNOWN = 0,     /**< Unknown / Not Specified */

    /* WAP */
#if defined( WBXML_SUPPORT_WML )
    WBXML_LANG_WML10 = 1101,           /**< WML 1.0 */
    WBXML_LANG_WML11 = 1102,           /**< WML 1.1 */
    WBXML_LANG_WML12 = 1103,           /**< WML 1.2 */
    WBXML_LANG_WML13 = 1104,           /**< WML 1.3 */
#endif /* WBXML_SUPPORT_WML */

#if defined( WBXML_SUPPORT_WTA )
    WBXML_LANG_WTA10     = 1201,           /**< WTA 1.0 */
    WBXML_LANG_WTAWML12  = 1202,        /**< WTAWML 1.2 */
    WBXML_LANG_CHANNEL11 = 1203,       /**< CHANNEL 1.1 */
    WBXML_LANG_CHANNEL12 = 1204,       /**< CHANNEL 1.2 */
#endif /* WBXML_SUPPORT_WTA */

#if defined( WBXML_SUPPORT_SI )
    WBXML_LANG_SI10 = 1301,            /**< SI 1.0 */
#endif /* WBXML_SUPPORT_SI */

#if defined( WBXML_SUPPORT_SL )
    WBXML_LANG_SL10 = 1401,            /**< SL 1.0 */
#endif /* WBXML_SUPPORT_SL */

#if defined( WBXML_SUPPORT_CO )
    WBXML_LANG_CO10 = 1501,            /**< CO 1.0 */
#endif /* WBXML_SUPPORT_CO */

#if defined( WBXML_SUPPORT_PROV )
    WBXML_LANG_PROV10 = 1601,          /**< PROV 1.0 */
#endif /* WBXML_SUPPORT_PROV */

#if defined( WBXML_SUPPORT_EMN )
    WBXML_LANG_EMN10 = 1701,           /**< EMN 1.0 */
#endif /* WBXML_SUPPORT_EMN */

#if defined( WBXML_SUPPORT_DRMREL )
    WBXML_LANG_DRMREL10 = 1801,        /**< DRMREL 1.0 */
#endif /* WBXML_SUPPORT_DRMREL */

#if defined( WBXML_SUPPORT_OTA_SETTINGS )
    /* Ericsson / Nokia OTA Settings v7.0 */
    WBXML_LANG_OTA_SETTINGS = 1901,    /**< OTA Settings */
#endif /* WBXML_SUPPORT_OTA_SETTINGS */

    /* SyncML */
#if defined( WBXML_SUPPORT_SYNCML )
    WBXML_LANG_SYNCML_SYNCML10 = 2001, /**< SYNCML 1.0 */
    WBXML_LANG_SYNCML_DEVINF10 = 2002, /**< DEVINF 1.0 */
    WBXML_LANG_SYNCML_METINF10 = 2003, /**< METINF 1.0 */

    WBXML_LANG_SYNCML_SYNCML11 = 2101, /**< SYNCML 1.1 */
    WBXML_LANG_SYNCML_DEVINF11 = 2102, /**< DEVINF 1.1 */
    WBXML_LANG_SYNCML_METINF11 = 2103, /**< METINF 1.1 */

    WBXML_LANG_SYNCML_SYNCML12 = 2201, /**< SYNCML 1.2 */
    WBXML_LANG_SYNCML_DEVINF12 = 2202, /**< DEVINF 1.2 */
    WBXML_LANG_SYNCML_METINF12 = 2203, /**< METINF 1.2 */
    WBXML_LANG_SYNCML_DMDDF12  = 2204, /**< DMDDF  1.2 */
#endif /* WBXML_SUPPORT_SYNCML */

    /* Wireless-Village */
#if defined( WBXML_SUPPORT_WV )
    WBXML_LANG_WV_CSP11 = 2301,        /**< WV CSP 1.1 */
    WBXML_LANG_WV_CSP12 = 2302,        /**< WV CSP 1.2 */
#endif /* WBXML_SUPPORT_WV */

    /* Microsoft AirSync */
#if defined( WBXML_SUPPORT_AIRSYNC )
    WBXML_LANG_AIRSYNC    = 2401,      /**< AirSync */
    WBXML_LANG_ACTIVESYNC = 2402,      /**< ActiveSync */
#endif /* WBXML_SUPPORT_AIRSYNC */

    /* Nokia ConML */
#if defined( WBXML_SUPPORT_CONML )
    WBXML_LANG_CONML = 2501            /**< ConML */
#endif /* WBXML_SUPPORT_CONML */
} WBXMLLanguage;


/** Supported WBXML Charsets MIBEnum */
typedef enum WBXMLCharsetMIBEnum_e {
    WBXML_CHARSET_UNKNOWN                                       = 0,
    WBXML_CHARSET_US_ASCII                                      = 3,
    WBXML_CHARSET_ISO_8859_1                                    = 4,
    WBXML_CHARSET_ISO_8859_2                                    = 5,
    WBXML_CHARSET_ISO_8859_3                                    = 6,
    WBXML_CHARSET_ISO_8859_4                                    = 7,
    WBXML_CHARSET_ISO_8859_5                                    = 8,
    WBXML_CHARSET_ISO_8859_6                                    = 9,
    WBXML_CHARSET_ISO_8859_7                                    = 10,
    WBXML_CHARSET_ISO_8859_8                                    = 11,
    WBXML_CHARSET_ISO_8859_9                                    = 12,
    WBXML_CHARSET_ISO_8859_10                                   = 13,
    WBXML_CHARSET_SHIFT_JIS                                     = 17,
    WBXML_CHARSET_EXTENDED_UNIX_CODE_PACKED_FORMAT_FOR_JAPANESE = 18,
    WBXML_CHARSET_EXTENDED_UNIX_CODE_FIXED_WIDTH_FOR_JAPANESE   = 19,
    WBXML_CHARSET_BS_4730                                       = 20,
    WBXML_CHARSET_SEN_850200_C                                  = 21,
    WBXML_CHARSET_IT                                            = 22,
    WBXML_CHARSET_ES                                            = 23,
    WBXML_CHARSET_DIN_66003                                     = 24,
    WBXML_CHARSET_NS_4551_1                                     = 25,
    WBXML_CHARSET_NF_Z_62_010                                   = 26,
    WBXML_CHARSET_ISO_10646_UTF_1                               = 27,
    WBXML_CHARSET_ISO_646_BASIC                                 = 28,
    WBXML_CHARSET_INVARIANT                                     = 29,
    WBXML_CHARSET_ISO_646_IRV                                   = 30,
    WBXML_CHARSET_NATS_SEFI                                     = 31,
    WBXML_CHARSET_NATS_SEFI_ADD                                 = 32,
    WBXML_CHARSET_NATS_DANO                                     = 33,
    WBXML_CHARSET_NATS_DANO_ADD                                 = 34,
    WBXML_CHARSET_SEN_850200_B                                  = 35,
    WBXML_CHARSET_KS_C_5601_1987                                = 36,
    WBXML_CHARSET_ISO_2022_KR                                   = 37,
    WBXML_CHARSET_EUC_KR                                        = 38,
    WBXML_CHARSET_ISO_2022_JP                                   = 39,
    WBXML_CHARSET_ISO_2022_JP_2                                 = 40,
    WBXML_CHARSET_JIS_C6220_1969_JP                             = 41,
    WBXML_CHARSET_JIS_C6220_1969_RO                             = 42,
    WBXML_CHARSET_PT                                            = 43,
    WBXML_CHARSET_GREEK7_OLD                                    = 44,
    WBXML_CHARSET_LATIN_GREEK                                   = 45,
    WBXML_CHARSET_NF_Z_62_010_1973                              = 46,
    WBXML_CHARSET_LATIN_GREEK_1                                 = 47,
    WBXML_CHARSET_ISO_5427                                      = 48,
    WBXML_CHARSET_JIS_C6226_1978                                = 49,
    WBXML_CHARSET_BS_VIEWDATA                                   = 50,
    WBXML_CHARSET_INIS                                          = 51,
    WBXML_CHARSET_INIS_8                                        = 52,
    WBXML_CHARSET_INIS_CYRILLIC                                 = 53,
    WBXML_CHARSET_ISO_5427_1981                                 = 54,
    WBXML_CHARSET_ISO_5428                                      = 55,
    WBXML_CHARSET_GB_1988_80                                    = 56,
    WBXML_CHARSET_GB_2312_80                                    = 57,
    WBXML_CHARSET_NS_4551_2                                     = 58,
    WBXML_CHARSET_VIDEOTEX_SUPPL                                = 59,
    WBXML_CHARSET_PT2                                           = 60,
    WBXML_CHARSET_ES2                                           = 61,
    WBXML_CHARSET_MSZ_7795_3                                    = 62,
    WBXML_CHARSET_JIS_C6226_1983                                = 63,
    WBXML_CHARSET_GREEK7                                        = 64,
    WBXML_CHARSET_ASMO_449                                      = 65,
    WBXML_CHARSET_ISO_IR_90                                     = 66,
    WBXML_CHARSET_JIS_C6229_1984_A                              = 67,
    WBXML_CHARSET_JIS_C6229_1984_B                              = 68,
    WBXML_CHARSET_JIS_C6229_1984_B_ADD                          = 69,
    WBXML_CHARSET_JIS_C6229_1984_HAND                           = 70,
    WBXML_CHARSET_JIS_C6229_1984_HAND_ADD                       = 71,
    WBXML_CHARSET_JIS_C6229_1984_KANA                           = 72,
    WBXML_CHARSET_ISO_2033_1983                                 = 73,
    WBXML_CHARSET_ANSI_X3_110_1983                              = 74,
    WBXML_CHARSET_T_61_7BIT                                     = 75,
    WBXML_CHARSET_T_61_8BIT                                     = 76,
    WBXML_CHARSET_ECMA_CYRILLIC                                 = 77,
    WBXML_CHARSET_CSA_Z243_4_1985_1                             = 78,
    WBXML_CHARSET_CSA_Z243_4_1985_2                             = 79,
    WBXML_CHARSET_CSA_Z243_4_1985_GR                            = 80,
    WBXML_CHARSET_ISO_8859_6_E                                  = 81,
    WBXML_CHARSET_ISO_8859_6_I                                  = 82,
    WBXML_CHARSET_T_101_G2                                      = 83,
    WBXML_CHARSET_ISO_8859_8_E                                  = 84,
    WBXML_CHARSET_ISO_8859_8_I                                  = 85,
    WBXML_CHARSET_CSN_369103                                    = 86,
    WBXML_CHARSET_JUS_I_B1_002                                  = 87,
    WBXML_CHARSET_IEC_P27_1                                     = 88,
    WBXML_CHARSET_JUS_I_B1_003_SERB                             = 89,
    WBXML_CHARSET_JUS_I_B1_003_MAC                              = 90,
    WBXML_CHARSET_GREEK_CCITT                                   = 91,
    WBXML_CHARSET_NC_NC00_10                                    = 92,
    WBXML_CHARSET_ISO_6937_2_25                                 = 93,
    WBXML_CHARSET_GOST_19768_74                                 = 94,
    WBXML_CHARSET_ISO_8859_SUPP                                 = 95,
    WBXML_CHARSET_ISO_10367_BOX                                 = 96,
    WBXML_CHARSET_LATIN_LAP                                     = 97,
    WBXML_CHARSET_JIS_X0212_1990                                = 98,
    WBXML_CHARSET_DS_2089                                       = 99,
    WBXML_CHARSET_US_DK                                         = 100,
    WBXML_CHARSET_DK_US                                         = 101,
    WBXML_CHARSET_KSC5636                                       = 102,
    WBXML_CHARSET_UNICODE_1_1_UTF_7                             = 103,
    WBXML_CHARSET_ISO_2022_CN                                   = 104,
    WBXML_CHARSET_ISO_2022_CN_EXT                               = 105,
    WBXML_CHARSET_UTF_8                                         = 106,
    WBXML_CHARSET_ISO_8859_13                                   = 109,
    WBXML_CHARSET_ISO_8859_14                                   = 110,
    WBXML_CHARSET_ISO_8859_15                                   = 111,
    WBXML_CHARSET_ISO_8859_16                                   = 112,
    WBXML_CHARSET_GBK                                           = 113,
    WBXML_CHARSET_GB18030                                       = 114,
    WBXML_CHARSET_OSD_EBCDIC_DF04_15                            = 115,
    WBXML_CHARSET_OSD_EBCDIC_DF03_IRV                           = 116,
    WBXML_CHARSET_OSD_EBCDIC_DF04_1                             = 117,
    WBXML_CHARSET_ISO_11548_1                                   = 118,
    WBXML_CHARSET_KZ_1048                                       = 119,
    WBXML_CHARSET_ISO_10646_UCS_2                               = 1000,
    WBXML_CHARSET_ISO_10646_UCS_4                               = 1001,
    WBXML_CHARSET_ISO_10646_UCS_BASIC                           = 1002,
    WBXML_CHARSET_ISO_10646_UNICODE_LATIN1                      = 1003,
    WBXML_CHARSET_ISO_10646_J_1                                 = 1004,
    WBXML_CHARSET_ISO_UNICODE_IBM_1261                          = 1005,
    WBXML_CHARSET_ISO_UNICODE_IBM_1268                          = 1006,
    WBXML_CHARSET_ISO_UNICODE_IBM_1276                          = 1007,
    WBXML_CHARSET_ISO_UNICODE_IBM_1264                          = 1008,
    WBXML_CHARSET_ISO_UNICODE_IBM_1265                          = 1009,
    WBXML_CHARSET_UNICODE_1_1                                   = 1010,
    WBXML_CHARSET_SCSU                                          = 1011,
    WBXML_CHARSET_UTF_7                                         = 1012,
    WBXML_CHARSET_UTF_16BE                                      = 1013,
    WBXML_CHARSET_UTF_16LE                                      = 1014,
    WBXML_CHARSET_UTF_16                                        = 1015,
    WBXML_CHARSET_CESU_8                                        = 1016,
    WBXML_CHARSET_UTF_32                                        = 1017,
    WBXML_CHARSET_UTF_32BE                                      = 1018,
    WBXML_CHARSET_UTF_32LE                                      = 1019,
    WBXML_CHARSET_BOCU_1                                        = 1020,
    WBXML_CHARSET_ISO_8859_1_WINDOWS_3_0_LATIN_1                = 2000,
    WBXML_CHARSET_ISO_8859_1_WINDOWS_3_1_LATIN_1                = 2001,
    WBXML_CHARSET_ISO_8859_2_WINDOWS_LATIN_2                    = 2002,
    WBXML_CHARSET_ISO_8859_9_WINDOWS_LATIN_5                    = 2003,
    WBXML_CHARSET_HP_ROMAN8                                     = 2004,
    WBXML_CHARSET_ADOBE_STANDARD_ENCODING                       = 2005,
    WBXML_CHARSET_VENTURA_US                                    = 2006,
    WBXML_CHARSET_VENTURA_INTERNATIONAL                         = 2007,
    WBXML_CHARSET_DEC_MCS                                       = 2008,
    WBXML_CHARSET_IBM850                                        = 2009,
    WBXML_CHARSET_PC8_DANISH_NORWEGIAN                          = 2012,
    WBXML_CHARSET_IBM862                                        = 2013,
    WBXML_CHARSET_PC8_TURKISH                                   = 2014,
    WBXML_CHARSET_IBM_SYMBOLS                                   = 2015,
    WBXML_CHARSET_IBM_THAI                                      = 2016,
    WBXML_CHARSET_HP_LEGAL                                      = 2017,
    WBXML_CHARSET_HP_PI_FONT                                    = 2018,
    WBXML_CHARSET_HP_MATH8                                      = 2019,
    WBXML_CHARSET_ADOBE_SYMBOL_ENCODING                         = 2020,
    WBXML_CHARSET_HP_DESKTOP                                    = 2021,
    WBXML_CHARSET_VENTURA_MATH                                  = 2022,
    WBXML_CHARSET_MICROSOFT_PUBLISHING                          = 2023,
    WBXML_CHARSET_WINDOWS_31J                                   = 2024,
    WBXML_CHARSET_GB2312                                        = 2025,
    WBXML_CHARSET_BIG5                                          = 2026,
    WBXML_CHARSET_MACINTOSH                                     = 2027,
    WBXML_CHARSET_IBM037                                        = 2028,
    WBXML_CHARSET_IBM038                                        = 2029,
    WBXML_CHARSET_IBM273                                        = 2030,
    WBXML_CHARSET_IBM274                                        = 2031,
    WBXML_CHARSET_IBM275                                        = 2032,
    WBXML_CHARSET_IBM277                                        = 2033,
    WBXML_CHARSET_IBM278                                        = 2034,
    WBXML_CHARSET_IBM280                                        = 2035,
    WBXML_CHARSET_IBM281                                        = 2036,
    WBXML_CHARSET_IBM284                                        = 2037,
    WBXML_CHARSET_IBM285                                        = 2038,
    WBXML_CHARSET_IBM290                                        = 2039,
    WBXML_CHARSET_IBM297                                        = 2040,
    WBXML_CHARSET_IBM420                                        = 2041,
    WBXML_CHARSET_IBM423                                        = 2042,
    WBXML_CHARSET_IBM424                                        = 2043,
    WBXML_CHARSET_IBM437                                        = 2011,
    WBXML_CHARSET_IBM500                                        = 2044,
    WBXML_CHARSET_IBM851                                        = 2045,
    WBXML_CHARSET_IBM852                                        = 2010,
    WBXML_CHARSET_IBM855                                        = 2046,
    WBXML_CHARSET_IBM857                                        = 2047,
    WBXML_CHARSET_IBM860                                        = 2048,
    WBXML_CHARSET_IBM861                                        = 2049,
    WBXML_CHARSET_IBM863                                        = 2050,
    WBXML_CHARSET_IBM864                                        = 2051,
    WBXML_CHARSET_IBM865                                        = 2052,
    WBXML_CHARSET_IBM868                                        = 2053,
    WBXML_CHARSET_IBM869                                        = 2054,
    WBXML_CHARSET_IBM870                                        = 2055,
    WBXML_CHARSET_IBM871                                        = 2056,
    WBXML_CHARSET_IBM880                                        = 2057,
    WBXML_CHARSET_IBM891                                        = 2058,
    WBXML_CHARSET_IBM903                                        = 2059,
    WBXML_CHARSET_IBM904                                        = 2060,
    WBXML_CHARSET_IBM905                                        = 2061,
    WBXML_CHARSET_IBM918                                        = 2062,
    WBXML_CHARSET_IBM1026                                       = 2063,
    WBXML_CHARSET_EBCDIC_AT_DE                                  = 2064,
    WBXML_CHARSET_EBCDIC_AT_DE_A                                = 2065,
    WBXML_CHARSET_EBCDIC_CA_FR                                  = 2066,
    WBXML_CHARSET_EBCDIC_DK_NO                                  = 2067,
    WBXML_CHARSET_EBCDIC_DK_NO_A                                = 2068,
    WBXML_CHARSET_EBCDIC_FI_SE                                  = 2069,
    WBXML_CHARSET_EBCDIC_FI_SE_A                                = 2070,
    WBXML_CHARSET_EBCDIC_FR                                     = 2071,
    WBXML_CHARSET_EBCDIC_IT                                     = 2072,
    WBXML_CHARSET_EBCDIC_PT                                     = 2073,
    WBXML_CHARSET_EBCDIC_ES                                     = 2074,
    WBXML_CHARSET_EBCDIC_ES_A                                   = 2075,
    WBXML_CHARSET_EBCDIC_ES_S                                   = 2076,
    WBXML_CHARSET_EBCDIC_UK                                     = 2077,
    WBXML_CHARSET_EBCDIC_US                                     = 2078,
    WBXML_CHARSET_UNKNOWN_8BIT                                  = 2079,
    WBXML_CHARSET_MNEMONIC                                      = 2080,
    WBXML_CHARSET_MNEM                                          = 2081,
    WBXML_CHARSET_VISCII                                        = 2082,
    WBXML_CHARSET_VIQR                                          = 2083,
    WBXML_CHARSET_KOI8_R                                        = 2084,
    WBXML_CHARSET_HZ_GB_2312                                    = 2085,
    WBXML_CHARSET_IBM866                                        = 2086,
    WBXML_CHARSET_IBM775                                        = 2087,
    WBXML_CHARSET_KOI8_U                                        = 2088,
    WBXML_CHARSET_IBM00858                                      = 2089,
    WBXML_CHARSET_IBM00924                                      = 2090,
    WBXML_CHARSET_IBM01140                                      = 2091,
    WBXML_CHARSET_IBM01141                                      = 2092,
    WBXML_CHARSET_IBM01142                                      = 2093,
    WBXML_CHARSET_IBM01143                                      = 2094,
    WBXML_CHARSET_IBM01144                                      = 2095,
    WBXML_CHARSET_IBM01145                                      = 2096,
    WBXML_CHARSET_IBM01146                                      = 2097,
    WBXML_CHARSET_IBM01147                                      = 2098,
    WBXML_CHARSET_IBM01148                                      = 2099,
    WBXML_CHARSET_IBM01149                                      = 2100,
    WBXML_CHARSET_BIG5_HKSCS                                    = 2101,
    WBXML_CHARSET_IBM1047                                       = 2102,
    WBXML_CHARSET_PTCP154                                       = 2103,
    WBXML_CHARSET_AMIGA_1251                                    = 2104,
    WBXML_CHARSET_KOI7_SWITCHED                                 = 2105,
    WBXML_CHARSET_BRF                                           = 2106,
    WBXML_CHARSET_TSCII                                         = 2107,
    WBXML_CHARSET_CP51932                                       = 2108,
    WBXML_CHARSET_WINDOWS_874                                   = 2109,
    WBXML_CHARSET_WINDOWS_1250                                  = 2250,
    WBXML_CHARSET_WINDOWS_1251                                  = 2251,
    WBXML_CHARSET_WINDOWS_1252                                  = 2252,
    WBXML_CHARSET_WINDOWS_1253                                  = 2253,
    WBXML_CHARSET_WINDOWS_1254                                  = 2254,
    WBXML_CHARSET_WINDOWS_1255                                  = 2255,
    WBXML_CHARSET_WINDOWS_1256                                  = 2256,
    WBXML_CHARSET_WINDOWS_1257                                  = 2257,
    WBXML_CHARSET_WINDOWS_1258                                  = 2258,
    WBXML_CHARSET_TIS_620                                       = 2259,
    WBXML_CHARSET_CP50220                                       = 2260,
} WBXMLCharsetMIBEnum;


/**
 * @brief Type of XML Generation
 * @note Canonical Form is defined here: http://www.jclark.com/xml/canonxml.html
 */
typedef enum WBXMLGenXMLType_e {
    WBXML_GEN_XML_COMPACT   = 0,  /**< Compact XML generation */
    WBXML_GEN_XML_INDENT    = 1,  /**< Indented XML generation */
    WBXML_GEN_XML_CANONICAL = 2   /**< Canonical XML generation */
} WBXMLGenXMLType;


/**
 * @brief Parameters when generating an XML document
 */
typedef struct WBXMLGenXMLParams_s {
    WBXMLGenXMLType gen_type;    /**< WBXML_GEN_XML_COMPACT | WBXML_GEN_XML_INDENT | WBXML_GEN_XML_CANONICAL (Default: WBXML_GEN_XML_INDENT) */
    WBXMLLanguage lang;          /**< Force document Language (overwrite document Public ID) */
    WBXMLCharsetMIBEnum charset; /**< Set document Language (does not overwrite document character set) */
    WB_UTINY indent;             /**< Indentation Delta, when using WBXML_GEN_XML_INDENT Generation Type (Default: 0) */
    WB_BOOL keep_ignorable_ws;   /**< Keep Ignorable Whitespaces (Default: FALSE) */
} WBXMLGenXMLParams;

/**
 * @brief Parameters when generating a WBXML document
 */
typedef struct WBXMLGenWBXMLParams_s {
    WBXMLVersion wbxml_version; /**< WBXML Version */
    WB_BOOL keep_ignorable_ws;  /**< Keep Ignorable Whitespaces (Default: FALSE) */
    WB_BOOL use_strtbl;         /**< Generate String Table (Default: TRUE) */
    WB_BOOL produce_anonymous;  /**< Produce an anonymous document (Default: FALSE) */
} WBXMLGenWBXMLParams;

/**
 * Wrapper around wbxml_conv_wbxml2_withlen()
 *
 * This macro is provided for backward compatibility. You can use it if you are
 * sure that the output XML document will be encoded in a charset that is NULL
 * terminated and that can't contains any NULL character in it. For example
 * this macro works for US-ASCII or UTF-8 encoded documents, but not for UTF-16
 * encoded documents.
 */
#define wbxml_conv_wbxml2xml(a,b,c,d) wbxml_conv_wbxml2xml_withlen(a,b,c,NULL,d)

/**
 * @brief Convert WBXML to XML
 * @param wbxml     [in] WBXML Document to convert
 * @param wbxml_len [in] Length of WBXML Document
 * @param xml       [out] Resulting XML Document
 * @param xml_len   [out] XML Document length
 * @param params    [in] Parameters (if NULL, default values are used)
 * @return WBXML_OK if conversion succeeded, an Error Code otherwise
 */
WBXML_DECLARE(WBXMLError) wbxml_conv_wbxml2xml_withlen(WB_UTINY  *wbxml,
                                                       WB_ULONG   wbxml_len,
                                                       WB_UTINY **xml,
                                                       WB_ULONG  *xml_len,
                                                       WBXMLGenXMLParams *params) LIBWBXML_DEPRECATED;

/**
 * Wrapper around wbxml_conv_xml2wbxml_withlen()
 *
 * This macro is provided for backward compatibility. You can use it if you are
 * sure that the input XML document is encoded in a charset that is NULL terminated
 * and that can't contains any NULL character in it. For example this macro
 * works for US-ASCII or UTF-8 encoded documents, but not for UTF-16 encoded
 * documents.
 */
#define wbxml_conv_xml2wbxml(a,b,c,d) wbxml_conv_xml2wbxml_withlen(a,WBXML_STRLEN(a),b,c,d)

/**
 * @brief Convert XML to WBXML
 * @param xml       [in] XML Document to convert
 * @param xml_len   [in] Length of XML Document
 * @param wbxml     [out] Resulting WBXML Document
 * @param wbxml_len [out] Length of resulting WBXML Document
 * @param params    [in] Parameters (if NULL, default values are used)
 * @return WBXML_OK if conversion succeeded, an Error Code otherwise
 */
WBXML_DECLARE(WBXMLError) wbxml_conv_xml2wbxml_withlen(WB_UTINY  *xml,
                                                       WB_ULONG   xml_len,
                                                       WB_UTINY **wbxml,
                                                       WB_ULONG  *wbxml_len,
                                                       WBXMLGenWBXMLParams *params) LIBWBXML_DEPRECATED;

/**
 * @description This is a container for the WBXML to XML conversion parameters.
 *              An object style is used because it is much better expandable
 *              in terms of downward binary compatibility.
 */
typedef struct WBXMLConvWBXML2XML_s WBXMLConvWBXML2XML;

/**
 * @brief Create a new WBXML to XML converter with the default configuration.
 * @param conv [out] a reference to the pointer of the new converter
 * @return WBXML_OK if conversion succeeded, an Error Code otherwise
 */
WBXML_DECLARE(WBXMLError) wbxml_conv_wbxml2xml_create(WBXMLConvWBXML2XML **conv);

/**
 * @brief Set the XML generation type (default: WBXML_GEN_XML_INDENT).
 * @param conv     [in] the converter
 * @param gen_type [in] generation type
 */
WBXML_DECLARE(void) wbxml_conv_wbxml2xml_set_gen_type(WBXMLConvWBXML2XML *conv, WBXMLGenXMLType gen_type);

/**
 * @brief Set the used WBXML language.
 *        The language is usually detected by the specified public ID in the document.
 *        If the public ID is set then it overrides the language.
 * @param conv [in] the converter
 * @param lang [in] language (e.g. SYNCML12)
 */
WBXML_DECLARE(void) wbxml_conv_wbxml2xml_set_language(WBXMLConvWBXML2XML *conv, WBXMLLanguage lang);

/**
 * @brief Set the used character set.
 *        The default character set is UTF-8.
 *        If the document specifies a character set by it own
 *        then this character set overrides the parameter charset.
 * @param conv    [in] the converter
 * @param charset [in] the character set
 */
WBXML_DECLARE(void) wbxml_conv_wbxml2xml_set_charset(WBXMLConvWBXML2XML *conv, WBXMLCharsetMIBEnum charset);

/**
 * @brief Set the indent of the generated XML document (please see EXPAT default).
 * @param conv   [in] the converter
 * @param indent [in] the number of blanks
 */
WBXML_DECLARE(void) wbxml_conv_wbxml2xml_set_indent(WBXMLConvWBXML2XML *conv, WB_UTINY indent);

/**
 * @brief Enable whitespace preservation (default: FALSE).
 * @param conv     [in] the converter
 */
WBXML_DECLARE(void) wbxml_conv_wbxml2xml_enable_preserve_whitespaces(WBXMLConvWBXML2XML *conv);

/**
 * @brief Convert WBXML to XML
 * @param conv      [in] the converter
 * @param wbxml     [in] WBXML Document to convert
 * @param wbxml_len [in] Length of WBXML Document
 * @param xml       [out] Resulting XML Document
 * @param xml_len   [out] XML Document length
 * @return WBXML_OK if conversion succeeded, an Error Code otherwise
 */
WBXML_DECLARE(WBXMLError) wbxml_conv_wbxml2xml_run(WBXMLConvWBXML2XML *conv,
                                                   WB_UTINY  *xml,
                                                   WB_ULONG   xml_len,
                                                   WB_UTINY **wbxml,
                                                   WB_ULONG  *wbxml_len);

/**
 * @brief Destroy the converter object.
 * @param [in] the converter
 */
WBXML_DECLARE(void) wbxml_conv_wbxml2xml_destroy(WBXMLConvWBXML2XML *conv);

/**
 * @description This is a container for the XML to WBXML conversion parameters.
 *              An object style is used because it is much better expandable
 *              in terms of downward binary compatibility.
 */
typedef struct WBXMLConvXML2WBXML_s WBXMLConvXML2WBXML;

/**
 * @brief Create a new WBXML to XML converter with the default configuration.
 * @param conv [out] a reference to the pointer of the new converter
 * @return WBXML_OK if conversion succeeded, an Error Code otherwise
 */
WBXML_DECLARE(WBXMLError) wbxml_conv_xml2wbxml_create(WBXMLConvXML2WBXML **conv);

/**
 * @brief Set the WBXML version (default: 1.3).
 * @param conv   [in] the converter
 * @param indent [in] the number of blanks
 */
WBXML_DECLARE(void) wbxml_conv_xml2wbxml_set_version(WBXMLConvXML2WBXML *conv,
                                                     WBXMLVersion wbxml_version);

/**
 * @brief Enable whitespace preservation (default: FALSE/DISABLED).
 * @param conv     [in] the converter
 */
WBXML_DECLARE(void) wbxml_conv_xml2wbxml_enable_preserve_whitespaces(WBXMLConvXML2WBXML *conv);

/**
 * @brief Disable string table (default: TRUE/ENABLED).
 * @param conv     [in] the converter
 */
WBXML_DECLARE(void) wbxml_conv_xml2wbxml_disable_string_table(WBXMLConvXML2WBXML *conv);

/**
 * @desription: Disable public ID (default: TRUE/ENABLED).
 *              Usually you don't want to produce WBXML documents which are
 *              really anonymous. You want a known public ID or a DTD name
 *              to determine the document type. Some specifications like
 *              Microsoft's ActiveSync explicitely require fully anonymous
 *              WBXML documents. If you need this then you must disable
 *              the public ID mechanism.
 * @param conv     [in] the converter
 */
WBXML_DECLARE(void) wbxml_conv_xml2wbxml_disable_public_id(WBXMLConvXML2WBXML *conv);

/**
 * @brief Convert XML to WBXML
 * @param conv      [in] the converter
 * @param xml       [in] XML Document to convert
 * @param xml_len   [in] Length of XML Document
 * @param wbxml     [out] Resulting WBXML Document
 * @param wbxml_len [out] Length of resulting WBXML Document
 * @return WBXML_OK if conversion succeeded, an Error Code otherwise
 */
WBXML_DECLARE(WBXMLError) wbxml_conv_xml2wbxml_run(WBXMLConvXML2WBXML *conv,
                                                   WB_UTINY  *xml,
                                                   WB_ULONG   xml_len,
                                                   WB_UTINY **wbxml,
                                                   WB_ULONG  *wbxml_len);

/**
 * @brief Destroy the converter object.
 * @param [in] the converter
 */
WBXML_DECLARE(void) wbxml_conv_xml2wbxml_destroy(WBXMLConvXML2WBXML *conv);

/** @} */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* WBXML_CONV_H */
