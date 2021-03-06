.. sectnum::

###########
OpenWize'Up
###########

***********
Requirement
***********

See section ``Requirement`` at `OpenWize Documentation`_ page.


***********
First steps
***********

Cloning this repository
=======================
::

   git clone --recurse-submodules https://github.com/GRDF/OpenWize-Up.git


Repository structure
====================
::

   OpenWize-Up
   ├── docs  
   ├── sources : contains source code specific to OpenWize'Up application and Wize'Up board
   │   ├── app    : OpenWize'Up application
   │   ├── board  : Wize'Up board specific
   │   ├── bsp    : Wize'Up board support package
   │   └── device : Mainly the ADF7030-1 device driver 
   ├── third-party : contains all "external" source code, including OpenWize itself
   │   ├── .OpenWize : OpenWize repository as a submodule (hidden)
   │   ├── firmware  : symbolic link on  OpenWize STM32 HAL submodule 
   │   ├── libraries : symbolic link on  OpenWize Tinycrypt submodule 
   │   ├── rtos      : symbolic link on  OpenWize FreRTOS submodule 
   │   └── testing   : symbolic link on  OpenWize CMock submodule 
   └── tools
       └── build_support : cmake files to help building OpenWize'Up



Prepare to build
================

See section ``Prepare to build`` at `OpenWize Documentation`_ page.


OpenWize'Up application
=======================


Build the application
---------------------
::

   cd Openwize-Up
   mkdir _build

:: 

   cmake -DCMAKE_BUILD_TYPE=Debug ../. 
   make App_WizeUp -j
   make install
   
:: 

   _install/
      └── bin
          ├── App_WizeUp      : The "elf" file (i.e. with debug symboles)
          ├── App_WizeUp.bin  : Pure binary file
          ├── App_WizeUp.lst  : Disassembly listing
          └── App_WizeUp.map  : Symboles and files mapping


.. references
 
.. _`OpenWize Documentation`: https://github.com/GRDF/OpenWize/blob/main/docs/OpenWize.rst
.. _`STM32CubeIDE`: https://www.st.com/en/development-tools/stm32cubeide.html#get-software
.. _`Wize Lan Protocol Specifications`: https://www.wize-alliance.com/Downloads/Technical

