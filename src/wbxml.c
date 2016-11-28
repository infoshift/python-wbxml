#include <Python.h>
#include <wbxml.h>

struct wbxml_state {
    PyObject *WBXMLParseError;
};

#if PY_MAJOR_VERSION >= 3
#define GETSTATE(m) ((struct wbxml_state*)PyModule_GetState(m))
#else
#define GETSTATE(m) (&_state)
static struct wbxml_state _state;
#endif

static PyObject* xml_to_wbxml(PyObject* self, PyObject* args) {
  WBXMLError ret;
  WB_UTINY *xml;
  WB_UTINY *wbxml;
  WB_ULONG xml_len = 0;
  WB_ULONG wbxml_len = 0;
  WBXMLGenWBXMLParams params;

  if(!PyArg_ParseTuple(args, "s#", &xml, &xml_len)) {
    return NULL;
  }

  params.wbxml_version = WBXML_VERSION_13;
  params.use_strtbl = TRUE;
  params.keep_ignorable_ws = FALSE;
  params.produce_anonymous = TRUE;

  ret = wbxml_conv_xml2wbxml_withlen(xml, xml_len, &wbxml, &wbxml_len, &params);
  if(ret != WBXML_OK) {
    struct wbxml_state *st = GETSTATE(self);
    PyErr_SetString(st->WBXMLParseError, (const char*)wbxml_errors_string(ret));
    return NULL;
  }

  PyObject *value = PyBytes_FromStringAndSize((const char*)wbxml, wbxml_len);

  if(wbxml != NULL) {
    wbxml_free(wbxml);
  }

  return value;
}

static char xml_to_wbxml_docs[] =
  "xml_to_wbxml(): converts xml to wbxml.\n";

static PyObject* wbxml_to_xml(PyObject* self, PyObject* args) {
  WBXMLError ret;
  WB_UTINY *wbxml;
  WB_UTINY *xml;
  WB_ULONG xml_len = 0;
  WB_ULONG wbxml_len = 0;
  WBXMLGenXMLParams params;

  if(!PyArg_ParseTuple(args, "s#", &wbxml, &wbxml_len)) {
    return NULL;
  }

  params.gen_type = WBXML_GEN_XML_INDENT;
  params.lang = WBXML_LANG_UNKNOWN;
  params.indent = 2;
  params.keep_ignorable_ws = FALSE;

  ret = wbxml_conv_wbxml2xml_withlen(wbxml, wbxml_len, &xml, &xml_len, &params);
  if(ret != WBXML_OK) {
    struct wbxml_state *st = GETSTATE(self);
    PyErr_SetString(st->WBXMLParseError, (const char*)wbxml_errors_string(ret));
    return NULL;
  }

  PyObject *value = PyUnicode_FromStringAndSize((const char*)xml, xml_len);

  if(xml != NULL) {
    wbxml_free(xml);
  }

  return value;
}

static char wbxml_to_xml_docs[] =
  "wbxml_to_xml(): converts wbxml to xml.\n";


static PyMethodDef wbxml_funcs[] = {
  {"xml_to_wbxml", (PyCFunction)xml_to_wbxml,
    METH_VARARGS, xml_to_wbxml_docs},
  {"wbxml_to_xml", (PyCFunction)wbxml_to_xml,
    METH_VARARGS, wbxml_to_xml_docs},
  {NULL}
};

static char wbxml_module_docs[] =
  "Python wrapper for libwbxml";

#if PY_MAJOR_VERSION >= 3

static int wbxml_traverse(PyObject *m, visitproc visit, void *arg) {
  Py_VISIT(GETSTATE(m)->WBXMLParseError);
  return 0;
}

static int wbxml_clear(PyObject *m) {
  Py_CLEAR(GETSTATE(m)->WBXMLParseError);
  return 0;
}

static struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "wbxml",
        wbxml_module_docs,
        sizeof(struct wbxml_state),
        wbxml_funcs,
        NULL,
        wbxml_traverse,
        wbxml_clear,
        NULL
};

#define INITERROR return NULL

PyObject *
PyInit_wbxml(void)

#else
#define INITERROR return

PyMODINIT_FUNC initwbxml(void)
#endif
{
  PyObject* module;

#if PY_MAJOR_VERSION >= 3
  module = PyModule_Create(&moduledef);
#else
  module = Py_InitModule3("wbxml",
      wbxml_funcs,
      wbxml_module_docs);
#endif

  if(module == NULL) {
    INITERROR;
  }

  struct wbxml_state *st = GETSTATE(module);

  st->WBXMLParseError = PyErr_NewException("wbxml.WBXMLParseError", NULL, NULL);
  if (st->WBXMLParseError == NULL) {
    Py_DECREF(module);
    INITERROR;
  }

#if PY_MAJOR_VERSION >= 3
    return module;
#endif
}
