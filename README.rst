python-wbxml
============

Python wrapper for libwbxml.

.. code-block:: python

  >>> import wbxml
  >>> wbxml.xml_to_wbxml(xml) #converts xml to wbxml
  >>> wbxml.wbxml_to_xml(w) # converts wbxml to xml

Installation
------------

Just type in your shell:

.. code-block:: bash

  $ pip install wbxml

If your ``wbxml.h`` is not in the ``/usr/include`` directory:

.. code-block:: bash
  
  $ pip install --global-option=build_ext --global-option="-I<include_dir>" wbxml 


Requirements
------------

You need to have `libwbxml <https://github.com/libwbxml/libwxml>`_ installed.

In Ubuntu 14.04 install:

.. code-block:: bash

  $ sudo apt-get install libwbxml2-dev


Contribute
----------

#. Fork repo
#. Code your changes
#. Submit pull request
#. Profit!
