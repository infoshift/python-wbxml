#ifndef PYTHON_WBXML__SRC__WBXML_HELPERS__H
#define PYTHON_WBXML__SRC__WBXML_HELPERS__H


#include "libwbxml/wbxml.h"
#include "libwbxml/wbxml_mem.h"


static WBXMLVersion get_version(const WB_TINY *lang)
{
    if (WBXML_STRCMP(lang, "1.0") == 0)
        return WBXML_VERSION_10;
    if (WBXML_STRCMP(lang, "1.1") == 0)
        return WBXML_VERSION_11;
    if (WBXML_STRCMP(lang, "1.2") == 0)
        return WBXML_VERSION_12;
    if (WBXML_STRCMP(lang, "1.3") == 0)
        return WBXML_VERSION_13;

    return WBXML_VERSION_UNKNOWN;
}


static WBXMLLanguage get_lang(const WB_TINY *lang)
{
#if defined( WBXML_SUPPORT_WML )
    if (WBXML_STRCMP(lang, "WML10") == 0)
        return WBXML_LANG_WML10;
    if (WBXML_STRCMP(lang, "WML11") == 0)
        return WBXML_LANG_WML11;
    if (WBXML_STRCMP(lang, "WML12") == 0)
        return WBXML_LANG_WML12;
    if (WBXML_STRCMP(lang, "WML13") == 0)
        return WBXML_LANG_WML13;
#endif /* WBXML_SUPPORT_WML */

#if defined( WBXML_SUPPORT_WTA )
    if (WBXML_STRCMP(lang, "WTA10") == 0)
        return WBXML_LANG_WTA10;
    if (WBXML_STRCMP(lang, "WTAWML12") == 0)
        return WBXML_LANG_WTAWML12;
    if (WBXML_STRCMP(lang, "CHANNEL11") == 0)
        return WBXML_LANG_CHANNEL11;
    if (WBXML_STRCMP(lang, "CHANNEL12") == 0)
        return WBXML_LANG_CHANNEL12;
#endif /* WBXML_SUPPORT_WTA */

#if defined( WBXML_SUPPORT_SI )
    if (WBXML_STRCMP(lang, "SI10") == 0)
        return WBXML_LANG_SI10;
#endif /* WBXML_SUPPORT_SI */

#if defined( WBXML_SUPPORT_SL )
    if (WBXML_STRCMP(lang, "SL10") == 0)
        return WBXML_LANG_SL10;
#endif /* WBXML_SUPPORT_SL */

#if defined( WBXML_SUPPORT_CO )
    if (WBXML_STRCMP(lang, "CO10") == 0)
        return WBXML_LANG_CO10;
#endif /* WBXML_SUPPORT_CO */

#if defined( WBXML_SUPPORT_PROV )
    if (WBXML_STRCMP(lang, "PROV10") == 0)
        return WBXML_LANG_PROV10;
#endif /* WBXML_SUPPORT_PROV */

#if defined( WBXML_SUPPORT_EMN )
    if (WBXML_STRCMP(lang, "EMN10") == 0)
        return WBXML_LANG_EMN10;
#endif /* WBXML_SUPPORT_EMN */

#if defined( WBXML_SUPPORT_DRMREL )
    if (WBXML_STRCMP(lang, "DRMREL10") == 0)
        return WBXML_LANG_DRMREL10;
#endif /* WBXML_SUPPORT_DRMREL */

#if defined( WBXML_SUPPORT_OTA_SETTINGS )
    if (WBXML_STRCMP(lang, "OTA") == 0)
        return WBXML_LANG_OTA_SETTINGS;
#endif /* WBXML_SUPPORT_OTA_SETTINGS */

#if defined( WBXML_SUPPORT_SYNCML )
    if (WBXML_STRCMP(lang, "SYNCML10") == 0)
        return WBXML_LANG_SYNCML_SYNCML10;
    if (WBXML_STRCMP(lang, "DEVINF10") == 0)
        return WBXML_LANG_SYNCML_DEVINF10;
    if (WBXML_STRCMP(lang, "SYNCML11") == 0)
        return WBXML_LANG_SYNCML_SYNCML11;
    if (WBXML_STRCMP(lang, "DEVINF11") == 0)
        return WBXML_LANG_SYNCML_DEVINF11;
    if (WBXML_STRCMP(lang, "METINF11") == 0)
        return WBXML_LANG_SYNCML_METINF11;
    if (WBXML_STRCMP(lang, "SYNCML12") == 0)
        return WBXML_LANG_SYNCML_SYNCML12;
    if (WBXML_STRCMP(lang, "DEVINF12") == 0)
        return WBXML_LANG_SYNCML_DEVINF12;
    if (WBXML_STRCMP(lang, "METINF12") == 0)
        return WBXML_LANG_SYNCML_METINF12;
    if (WBXML_STRCMP(lang, "DMDDF12") == 0)
        return WBXML_LANG_SYNCML_DMDDF12;
#endif /* WBXML_SUPPORT_SYNCML */

#if defined( WBXML_SUPPORT_WV )
    if (WBXML_STRCMP(lang, "CSP11") == 0)
        return WBXML_LANG_WV_CSP11;
    if (WBXML_STRCMP(lang, "CSP12") == 0)
        return WBXML_LANG_WV_CSP12;
#endif /* WBXML_SUPPORT_WV */

#if defined( WBXML_SUPPORT_AIRSYNC )
    if (WBXML_STRCMP(lang, "AIRSYNC") == 0)
        return WBXML_LANG_AIRSYNC;
    if (WBXML_STRCMP(lang, "ACTIVESYNC") == 0)
        return WBXML_LANG_ACTIVESYNC;
#endif /* WBXML_SUPPORT_AIRSYNC */

#if defined( WBXML_SUPPORT_CONML )
    if (WBXML_STRCMP(lang, "CONML") == 0)
        return WBXML_LANG_CONML;
#endif /* WBXML_SUPPORT_CONML */

    return WBXML_LANG_UNKNOWN;
}


static WBXMLCharsetMIBEnum get_charset(const WB_TINY *charset)
{
    /* The good old ASCII */

    if (WBXML_STRCMP(charset, "ASCII") == 0)
        return WBXML_CHARSET_US_ASCII;

    /* ISO-8859 character sets */

    if (WBXML_STRCMP(charset, "ISO-8859-1") == 0)
        return WBXML_CHARSET_ISO_8859_1;
    if (WBXML_STRCMP(charset, "ISO-8859-2") == 0)
        return WBXML_CHARSET_ISO_8859_2;
    if (WBXML_STRCMP(charset, "ISO-8859-3") == 0)
        return WBXML_CHARSET_ISO_8859_3;
    if (WBXML_STRCMP(charset, "ISO-8859-4") == 0)
        return WBXML_CHARSET_ISO_8859_4;
    if (WBXML_STRCMP(charset, "ISO-8859-5") == 0)
        return WBXML_CHARSET_ISO_8859_5;
    if (WBXML_STRCMP(charset, "ISO-8859-6") == 0)
        return WBXML_CHARSET_ISO_8859_6;
    if (WBXML_STRCMP(charset, "ISO-8859-7") == 0)
        return WBXML_CHARSET_ISO_8859_7;
    if (WBXML_STRCMP(charset, "ISO-8859-8") == 0)
        return WBXML_CHARSET_ISO_8859_8;
    if (WBXML_STRCMP(charset, "ISO-8859-9") == 0)
        return WBXML_CHARSET_ISO_8859_9;
    if (WBXML_STRCMP(charset, "ISO-10646-UCS-2") == 0)
        return WBXML_CHARSET_ISO_10646_UCS_2;

    /* Chinese character set */

    if (WBXML_STRCMP(charset, "SHIFT_JIS") == 0)
        return WBXML_CHARSET_SHIFT_JIS;

    /* Japanese character set */

    if (WBXML_STRCMP(charset, "BIG5") == 0)
        return WBXML_CHARSET_BIG5;

    /* Unicode character sets */

    if (WBXML_STRCMP(charset, "UTF-8") == 0)
        return WBXML_CHARSET_UTF_8;
    if (WBXML_STRCMP(charset, "UTF-16") == 0)
        return WBXML_CHARSET_UTF_16;

    return WBXML_CHARSET_UNKNOWN;
}

static WBXMLGenXMLType get_gen_type(const WB_TINY *charset)
{
    if (WBXML_STRCMP(charset, "compact") == 0)
        return WBXML_GEN_XML_COMPACT;
    if (WBXML_STRCMP(charset, "canonical") == 0)
        return WBXML_GEN_XML_CANONICAL;
    if (WBXML_STRCMP(charset, "indent") == 0)
        return WBXML_GEN_XML_INDENT;
    return WBXML_GEN_XML_INDENT;
}


#endif // PYTHON_WBXML__SRC__WBXML_HELPERS__H
