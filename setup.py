from distutils.core import setup, Extension

wbxml = Extension('wbxml',
                  libraries=['wbxml2'],
                  sources=['src/wbxml.c'])

setup(name='wbxml',
      version='0.1.0',
      description='Python wrapper for libwbxml',
      author='Jezeniel Zapanta',
      author_email='jezeniel@infoshiftinc.com',
      keywords=['wbxml', 'wap', 'xml'],
      ext_modules=[wbxml])
