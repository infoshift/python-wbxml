#include <python2.7/Python.h>
#include <wbxml.h>

static PyObject* WBXMLParseError;

static PyObject* xml_to_wbxml(PyObject* self, PyObject* args, PyObject* kwargs) {

  static char* keywords[] = {"xml", "version", "disable_string_table", "preserve_whitespaces", "disable_public_id", NULL};

  static int version = 0;
  static int disable_string_table = 0;
  static int preserve_whitespaces = 0;
  static int disable_public_id = 0;

  WBXMLError ret = WBXML_OK;
  WB_UTINY *xml = NULL;
  WB_UTINY *wbxml = NULL;
  WB_ULONG xml_len = 0;
  WB_ULONG wbxml_len = 0;
  WBXMLConvXML2WBXML *conv = NULL;


  if(!PyArg_ParseTupleAndKeywords(args, kwargs, "s#|iiii", keywords, &xml, &xml_len, &version, &disable_string_table, &preserve_whitespaces, &disable_public_id)) {
    return NULL;
  }

  ret = wbxml_conv_xml2wbxml_create(&conv);
  if (ret != WBXML_OK)
  {
    if (conv != NULL)
        wbxml_conv_xml2wbxml_destroy(conv);
    PyErr_SetString(WBXMLParseError, (const char*)wbxml_errors_string(ret));
    return NULL;
  }

  if (version)
    wbxml_conv_xml2wbxml_set_version(conv, version);

  if (disable_public_id)
    wbxml_conv_xml2wbxml_disable_public_id(conv);

  if (preserve_whitespaces)
    wbxml_conv_xml2wbxml_enable_preserve_whitespaces(conv);

  if (disable_string_table)
    wbxml_conv_xml2wbxml_disable_string_table(conv);

  ret = wbxml_conv_xml2wbxml_run(conv, xml, xml_len, &wbxml, &wbxml_len);
  if (ret != WBXML_OK)
  {
    if (conv != NULL)
        wbxml_conv_xml2wbxml_destroy(conv);
    if (wbxml != NULL)
        wbxml_free(wbxml);
    PyErr_SetString(WBXMLParseError, (const char*)wbxml_errors_string(ret));
    return NULL;
  }

  PyObject *value = PyString_FromStringAndSize((const char*)wbxml, wbxml_len);

  if(wbxml != NULL)
    wbxml_free(wbxml);

  if (conv != NULL)
    wbxml_conv_xml2wbxml_destroy(conv);

  return value;
}

static char xml_to_wbxml_docs[] =
  "xml_to_wbxml(): converts xml to wbxml.\n";

static PyObject* wbxml_to_xml(PyObject* self, PyObject* args, PyObject* kwargs) {

  static char* keywords[] = {"wbxml", "preserve_whitespaces", "indent", "language", "charset", "gen_type", NULL};

  static int preserve_whitespaces = 0;
  static int indent = 1;
  static int language = 0;
  static int charset = 0;
  static int gen_type = WBXML_GEN_XML_INDENT;

  WBXMLError ret = WBXML_OK;
  WB_UTINY *xml = NULL;
  WB_UTINY *wbxml = NULL;
  WB_ULONG xml_len = 0;
  WB_ULONG wbxml_len = 0;
  WBXMLConvWBXML2XML *conv = NULL;


  if(!PyArg_ParseTupleAndKeywords(args, kwargs, "s#|iiiii", keywords, &wbxml, &wbxml_len, &preserve_whitespaces, &indent, &language, &charset, &gen_type)) {
    return NULL;
  }

  ret = wbxml_conv_wbxml2xml_create(&conv);
  if (ret != WBXML_OK)
  {
    if (conv != NULL)
        wbxml_conv_wbxml2xml_destroy(conv);
    PyErr_SetString(WBXMLParseError, (const char*)wbxml_errors_string(ret));
    return NULL;
  }

  if (preserve_whitespaces)
    wbxml_conv_wbxml2xml_enable_preserve_whitespaces(conv);

  wbxml_conv_wbxml2xml_set_indent(conv, indent);

  if(language)
    wbxml_conv_wbxml2xml_set_language(conv, language);

  if(charset)
    wbxml_conv_wbxml2xml_set_charset(conv, charset);

  if(gen_type)
    wbxml_conv_wbxml2xml_set_gen_type(conv, gen_type);

  ret = wbxml_conv_wbxml2xml_run(conv, wbxml, wbxml_len, &xml, &xml_len);
  if (ret != WBXML_OK)
  {
    if (conv != NULL)
        wbxml_conv_wbxml2xml_destroy(conv);
    if (xml != NULL)
        wbxml_free(xml);
    PyErr_SetString(WBXMLParseError, (const char*)wbxml_errors_string(ret));
    return NULL;
  }

  PyObject *value = PyString_FromStringAndSize((const char*)xml, xml_len);

  if(xml != NULL)
    wbxml_free(xml);

  if (conv != NULL)
    wbxml_conv_wbxml2xml_destroy(conv);

  return value;
}

static char wbxml_to_xml_docs[] =
  "wbxml_to_xml(): converts wbxml to xml.\n";


static PyMethodDef wbxml_funcs[] = {
  {"xml_to_wbxml", (PyCFunction)xml_to_wbxml,
    METH_VARARGS | METH_KEYWORDS, xml_to_wbxml_docs},
  {"wbxml_to_xml", (PyCFunction)wbxml_to_xml,
    METH_VARARGS | METH_KEYWORDS, wbxml_to_xml_docs},
  {NULL}
};

PyMODINIT_FUNC initwbxml(void) {
  PyObject* module;

  module = Py_InitModule3("wbxml",
      wbxml_funcs,
      "Python wrapper for libwbxml");

  if(module == NULL) {
    return NULL;
  }

  WBXMLParseError = PyErr_NewException("wbxml.WBXMLParseError", NULL, NULL);
  Py_INCREF(WBXMLParseError);
  PyModule_AddObject(module, "WBXMLParseError", WBXMLParseError);

  PyModule_AddObject(module, "WBXML_LANG_WML10", PyInt_FromLong(WBXML_LANG_WML10));
  PyModule_AddObject(module, "WBXML_LANG_WML11", PyInt_FromLong(WBXML_LANG_WML11));
  PyModule_AddObject(module, "WBXML_LANG_WML12", PyInt_FromLong(WBXML_LANG_WML12));
  PyModule_AddObject(module, "WBXML_LANG_WML13", PyInt_FromLong(WBXML_LANG_WML13));
  PyModule_AddObject(module, "WBXML_LANG_WTA10", PyInt_FromLong(WBXML_LANG_WTA10));
  PyModule_AddObject(module, "WBXML_LANG_WTAWML12", PyInt_FromLong(WBXML_LANG_WTAWML12));
  PyModule_AddObject(module, "WBXML_LANG_CHANNEL11", PyInt_FromLong(WBXML_LANG_CHANNEL11));
  PyModule_AddObject(module, "WBXML_LANG_CHANNEL12", PyInt_FromLong(WBXML_LANG_CHANNEL12));
  PyModule_AddObject(module, "WBXML_LANG_SI10", PyInt_FromLong(WBXML_LANG_SI10));
  PyModule_AddObject(module, "WBXML_LANG_SL10", PyInt_FromLong(WBXML_LANG_SL10));
  PyModule_AddObject(module, "WBXML_LANG_CO10", PyInt_FromLong(WBXML_LANG_CO10));
  PyModule_AddObject(module, "WBXML_LANG_PROV10", PyInt_FromLong(WBXML_LANG_PROV10));
  PyModule_AddObject(module, "WBXML_LANG_EMN10", PyInt_FromLong(WBXML_LANG_EMN10));
  PyModule_AddObject(module, "WBXML_LANG_DRMREL10", PyInt_FromLong(WBXML_LANG_DRMREL10));
  PyModule_AddObject(module, "WBXML_LANG_OTA_SETTINGS", PyInt_FromLong(WBXML_LANG_OTA_SETTINGS));
  PyModule_AddObject(module, "WBXML_LANG_SYNCML_SYNCML10", PyInt_FromLong(WBXML_LANG_SYNCML_SYNCML10));
  PyModule_AddObject(module, "WBXML_LANG_SYNCML_DEVINF10", PyInt_FromLong(WBXML_LANG_SYNCML_DEVINF10));
  PyModule_AddObject(module, "WBXML_LANG_SYNCML_SYNCML11", PyInt_FromLong(WBXML_LANG_SYNCML_SYNCML11));
  PyModule_AddObject(module, "WBXML_LANG_SYNCML_DEVINF11", PyInt_FromLong(WBXML_LANG_SYNCML_DEVINF11));
  PyModule_AddObject(module, "WBXML_LANG_SYNCML_METINF11", PyInt_FromLong(WBXML_LANG_SYNCML_METINF11));
  PyModule_AddObject(module, "WBXML_LANG_SYNCML_SYNCML12", PyInt_FromLong(WBXML_LANG_SYNCML_SYNCML12));
  PyModule_AddObject(module, "WBXML_LANG_SYNCML_DEVINF12", PyInt_FromLong(WBXML_LANG_SYNCML_DEVINF12));
  PyModule_AddObject(module, "WBXML_LANG_SYNCML_METINF12", PyInt_FromLong(WBXML_LANG_SYNCML_METINF12));
  PyModule_AddObject(module, "WBXML_LANG_SYNCML_DMDDF12", PyInt_FromLong(WBXML_LANG_SYNCML_DMDDF12));
  PyModule_AddObject(module, "WBXML_LANG_WV_CSP11", PyInt_FromLong(WBXML_LANG_WV_CSP11));
  PyModule_AddObject(module, "WBXML_LANG_WV_CSP12", PyInt_FromLong(WBXML_LANG_WV_CSP12));
  PyModule_AddObject(module, "WBXML_LANG_AIRSYNC", PyInt_FromLong(WBXML_LANG_AIRSYNC));
  PyModule_AddObject(module, "WBXML_LANG_ACTIVESYNC", PyInt_FromLong(WBXML_LANG_ACTIVESYNC));
  PyModule_AddObject(module, "WBXML_LANG_CONML", PyInt_FromLong(WBXML_LANG_CONML));
  PyModule_AddObject(module, "WBXML_LANG_UNKNOWN", PyInt_FromLong(WBXML_LANG_UNKNOWN));

  PyModule_AddObject(module, "WBXML_CHARSET_US_ASCII", PyInt_FromLong(WBXML_CHARSET_US_ASCII));
  PyModule_AddObject(module, "WBXML_CHARSET_ISO_8859_1", PyInt_FromLong(WBXML_CHARSET_ISO_8859_1));
  PyModule_AddObject(module, "WBXML_CHARSET_ISO_8859_2", PyInt_FromLong(WBXML_CHARSET_ISO_8859_2));
  PyModule_AddObject(module, "WBXML_CHARSET_ISO_8859_3", PyInt_FromLong(WBXML_CHARSET_ISO_8859_3));
  PyModule_AddObject(module, "WBXML_CHARSET_ISO_8859_4", PyInt_FromLong(WBXML_CHARSET_ISO_8859_4));
  PyModule_AddObject(module, "WBXML_CHARSET_ISO_8859_5", PyInt_FromLong(WBXML_CHARSET_ISO_8859_5));
  PyModule_AddObject(module, "WBXML_CHARSET_ISO_8859_6", PyInt_FromLong(WBXML_CHARSET_ISO_8859_6));
  PyModule_AddObject(module, "WBXML_CHARSET_ISO_8859_7", PyInt_FromLong(WBXML_CHARSET_ISO_8859_7));
  PyModule_AddObject(module, "WBXML_CHARSET_ISO_8859_8", PyInt_FromLong(WBXML_CHARSET_ISO_8859_8));
  PyModule_AddObject(module, "WBXML_CHARSET_ISO_8859_9", PyInt_FromLong(WBXML_CHARSET_ISO_8859_9));
  PyModule_AddObject(module, "WBXML_CHARSET_ISO_10646_UCS_2", PyInt_FromLong(WBXML_CHARSET_ISO_10646_UCS_2));
  PyModule_AddObject(module, "WBXML_CHARSET_SHIFT_JIS", PyInt_FromLong(WBXML_CHARSET_SHIFT_JIS));
  PyModule_AddObject(module, "WBXML_CHARSET_BIG5", PyInt_FromLong(WBXML_CHARSET_BIG5));
  PyModule_AddObject(module, "WBXML_CHARSET_UTF_8", PyInt_FromLong(WBXML_CHARSET_UTF_8));
  PyModule_AddObject(module, "WBXML_CHARSET_UTF_16", PyInt_FromLong(WBXML_CHARSET_UTF_16));
  PyModule_AddObject(module, "WBXML_CHARSET_UNKNOWN", PyInt_FromLong(WBXML_CHARSET_UNKNOWN));

  PyModule_AddObject(module, "WBXML_VERSION_10", PyInt_FromLong(WBXML_VERSION_10));
  PyModule_AddObject(module, "WBXML_VERSION_11", PyInt_FromLong(WBXML_VERSION_11));
  PyModule_AddObject(module, "WBXML_VERSION_12", PyInt_FromLong(WBXML_VERSION_12));
  PyModule_AddObject(module, "WBXML_VERSION_13", PyInt_FromLong(WBXML_VERSION_13));
  PyModule_AddObject(module, "WBXML_VERSION_UNKNOWN", PyInt_FromLong(WBXML_VERSION_UNKNOWN));

}
