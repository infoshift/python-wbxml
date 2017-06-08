from setuptools import setup, Extension

with open('README.rst', 'r') as file:
    long_description = file.read()

import glob
wbxml = Extension('wbxml',
                  libraries=['expat'],
                  sources=glob.glob('src/libwbxml/*.c') + ['src/wbxml.c'])

setup(name='wbxml',
      version='0.1.1',
      author='Jezeniel Zapanta',
      author_email='jezeniel@infoshiftinc.com',
      description='Python wrapper for libwbxml',
      long_description=long_description,
      license='MIT',
      keywords=['wbxml', 'xml', 'mobile'],
      url='https://github.com/infoshift/python-wbxml',
      classifiers=[
          'Intended Audience :: Developers',
          'Topic :: Software Development :: Libraries',
          'License :: OSI Approved :: MIT License',
          'Programming Language :: Python :: 2.7'
      ],
      ext_modules=[wbxml])
