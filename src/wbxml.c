#include <python2.7/Python.h>

#include "libwbxml/wbxml.h"
#include "wbxml_helpers.h"


static PyObject* WBXMLParseError;

static PyObject* xml_to_wbxml(PyObject* self, PyObject* args, PyObject* kwargs) {

    // initialize return code & error strings
    WBXMLError ret = WBXML_OK;
    char error_context[1024] = {0};
    char error_string[1024] = {0};

    // interpret arguments
    char* keywords[] = {"xml", "version", "preserve_whitespaces", "string_table", "publicid", NULL};
    WB_UTINY *xml;
    WB_ULONG xml_len;
    char* language = NULL;
    int language_len = 0;
    char* version = "1.3";
    int version_len = 3;
    int preserve_whitespaces = 0;
    unsigned int string_table = 0;
    unsigned int publicid = 1;
    if (!PyArg_ParseTupleAndKeywords(
        args, kwargs,
        "s#|s#iII", keywords,
        &xml, &xml_len,
        &version, &version_len,
        &preserve_whitespaces, &string_table, &publicid
    )) {
        return NULL;
    }

    // initialize converter
    WBXMLConvXML2WBXML *conv = NULL;
    ret = wbxml_conv_xml2wbxml_create(&conv);
    if (ret != WBXML_OK) {
        snprintf(error_context, sizeof(error_context), "execution of `wbxml_conv_xml2wbxml_create` failed");
        goto clean_up;
    }
    // configure converter
    wbxml_conv_xml2wbxml_set_version(conv, get_version(version));
    if (preserve_whitespaces) {
        wbxml_conv_xml2wbxml_enable_preserve_whitespaces(conv);
    }
    if (!string_table) {
        wbxml_conv_xml2wbxml_disable_string_table(conv);
    }
    if (!publicid) {
        wbxml_conv_xml2wbxml_disable_public_id(conv);
    }

    // convert
    WB_UTINY *wbxml;
    WB_ULONG wbxml_len = 0;
    ret = wbxml_conv_xml2wbxml_run(conv, xml, xml_len, &wbxml, &wbxml_len);
    if (ret != WBXML_OK) {
        snprintf(error_context, sizeof(error_context), "execution of `wbxml_conv_wbxml2xml_run` failed with wbxml_len=%d", xml_len);
        goto clean_up;
    }

    // the end!
    clean_up:

    if (conv != NULL) {
        wbxml_conv_xml2wbxml_destroy(conv);
    }

    // raise exception
    if (ret != WBXML_OK) {
        if (error_context[0] == '\0') {
            snprintf(error_string, sizeof(error_string), "%s", (const char*)wbxml_errors_string(ret));
        } else {
            snprintf(error_string, sizeof(error_string), "%s (%s)", (const char*)wbxml_errors_string(ret), error_context);
        }
        PyErr_SetString(WBXMLParseError, error_string);
        return NULL;
    }

    // success
    PyObject *value = PyString_FromStringAndSize((const char*)wbxml, wbxml_len);//
    if (wbxml != NULL) {
        wbxml_free(wbxml);
    }
    return value;
}


char* keywords[] = {"wbxml", "version", "preserve_whitespaces", "string_table", "publicid", NULL};

static char xml_to_wbxml_docs[] =
  "Converts XML to WBXML.\n\n"
  "Args:\n"
  "    xml (str): The XML string to be converted\n"
  "    version (str, optional): Which version of the WBXML standard to consider (can be any of: '1.0', '1.1', '1.2', '1.3')\n"
  "    preserve_whitespaces (bool, optional): Whether whitespaces should be preserved or not\n"
  "    string_table (bool, optional): Whether a string tables should be used in the resulting WBXML document\n"
  "    publicid (bool, optional): Whether the WBXML Public ID should be included in the resulting WBXML document or not\n\n"
  "Returns:\n"
  "    str: WBXML-formatted result\n";

static PyObject* wbxml_to_xml(PyObject* self, PyObject* args, PyObject* kwargs) {

    // initialize return code & error strings
    WBXMLError ret = WBXML_OK;
    char error_context[1024] = {0};
    char error_string[1024] = {0};

    // interpret arguments
    char* keywords[] = {"wbxml", "charset", "language", "generation_type", "preserve_whitespaces", "indent", NULL};
    WB_UTINY *wbxml;
    WB_ULONG wbxml_len;
    char* charset = NULL;
    int charset_len = 0;
    char* language = NULL;
    int language_len = 0;
    char* generation_type = "indent";
    int generation_type_len = 0;
    int preserve_whitespaces = 0;
    unsigned int indent = 4;
    if (!PyArg_ParseTupleAndKeywords(
        args, kwargs,
        "s#|s#s#s#iI", keywords,
        &wbxml, &wbxml_len,
        &charset, &charset_len,
        &language, &language_len,
        &generation_type, &generation_type_len,
        &preserve_whitespaces, &indent
    )) {
        return NULL;
    }

    // initialize converter
    WBXMLConvWBXML2XML *conv = NULL;
    ret = wbxml_conv_wbxml2xml_create(&conv);
    if (ret != WBXML_OK) {
        snprintf(error_context, sizeof(error_context), "execution of `wbxml_conv_wbxml2xml_create` failed");
        goto clean_up;
    }
    // configure converter
    if (charset && charset_len) {
        wbxml_conv_wbxml2xml_set_charset(conv, get_charset(charset));
    }
    if (language && language_len) {
        wbxml_conv_wbxml2xml_set_language(conv, get_lang(language));
    }
    if (generation_type && generation_type_len) {
        wbxml_conv_wbxml2xml_set_gen_type(conv, get_gen_type(generation_type));
    }
    if (preserve_whitespaces) {
        wbxml_conv_wbxml2xml_enable_preserve_whitespaces(conv);
    }
    wbxml_conv_wbxml2xml_set_indent(conv, (WB_TINY) indent);

    // convert
    WB_UTINY *xml;
    WB_ULONG xml_len = 0;
    ret = wbxml_conv_wbxml2xml_run(conv, wbxml, wbxml_len, &xml, &xml_len);
    if (ret != WBXML_OK) {
        snprintf(error_context, sizeof(error_context), "execution of `wbxml_conv_wbxml2xml_run` failed with wbxml_len=%d", wbxml_len);
        goto clean_up;
    }

    // the end!
    clean_up:

    if (conv != NULL) {
        wbxml_conv_wbxml2xml_destroy(conv);
    }

    // exception
    if (ret != WBXML_OK) {
        if (error_context[0] == '\0') {
            snprintf(error_string, sizeof(error_string), "%s", (const char*)wbxml_errors_string(ret));
        } else {
            snprintf(error_string, sizeof(error_string), "%s (%s)", (const char*)wbxml_errors_string(ret), error_context);
        }
        PyErr_SetString(WBXMLParseError, error_string);
        return NULL;
    }

    // success
    PyObject *value = PyString_FromStringAndSize((const char*)xml, xml_len);
    return value;
}

static char wbxml_to_xml_docs[] =
  "Converts WBXML to XML.\n\n"
  "Args:\n"
  "    wbxml (str): The WBXML string to be converted\n"
  "    charset (str, optional): Which charset to use (can be any of: 'ASCII', 'ISO-8859-1', 'ISO-8859-2', 'ISO-8859-3', 'ISO-8859-4', 'ISO-8859-5', 'ISO-8859-6', 'ISO-8859-7', 'ISO-8859-8', 'ISO-8859-9', 'ISO-10646-UCS-2')\n"
  "    language (str, optional): Which WBXML language to use for conversion (can be any of: 'WML10', 'WML11', 'WML12', 'WML13', 'WTA10', 'WTAWML12', 'CHANNEL11', 'CHANNEL12', 'SI10', 'SL10', 'CO10', 'PROV10', 'EMN10', 'DRMREL10', 'OTA', 'SYNCML10', 'DEVINF10', 'SYNCML11', 'DEVINF11', 'METINF11', 'SYNCML12', 'DEVINF12', 'METINF12', 'DMDDF12', 'CSP11', 'CSP12', 'AIRSYNC', 'ACTIVESYNC', 'CONML')\n"
  "    generation_type (str, optional): How compact the generated XML should be  (can be any of: 'compact', 'canonical', 'indent')\n"
  "    preserve_whitespaces (bool, optional): Whether whitespaces should be preserved or not\n"
  "    int (int, optional): Number of spaces to use to indent the output XML\n\n"
  "Returns:\n"
  "    str: XML-formatted result\n";


static PyMethodDef wbxml_funcs[] = {
    {
        "xml_to_wbxml",
        (PyCFunction)xml_to_wbxml,
        METH_VARARGS | METH_KEYWORDS,
        xml_to_wbxml_docs
    },
    {
        "wbxml_to_xml",
        (PyCFunction)wbxml_to_xml,
        METH_VARARGS | METH_KEYWORDS,
        wbxml_to_xml_docs
    },
    {NULL}
};

PyMODINIT_FUNC initwbxml(void) {
  PyObject* module;

  module = Py_InitModule3("wbxml",
      wbxml_funcs,
      "Python wrapper for libwbxml");

  if(module == NULL) {
    return;
  }

  WBXMLParseError = PyErr_NewException("wbxml.WBXMLParseError", NULL, NULL);
  Py_INCREF(WBXMLParseError);
  PyModule_AddObject(module, "WBXMLParseError", WBXMLParseError);
}
