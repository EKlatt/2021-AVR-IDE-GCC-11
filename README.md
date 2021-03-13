# MyIDE created from AVR-GCC 10.1.0 
## (works similar to WINAVR)
This is the beta version of MyIDE intended for advanced Arduino-IDE<br>
users. MyIDE is not a replacement for WINAVR. It is just a new approach.<br>
MyIDE consists of <br>
* AVR-GCC 10.1.0 for Windows 64 bit
* Programmer's Notepad 2
* GNU utilities for Win32.<br>

MyIDE is intended for programmers who want to understand<br>
the basics behind the scene (Arduino-IDE).
## Main goal: Writing code in native C++
The main goal is to develop **C++ programs** using the **AVR-toolchain**<br>
from Zak Kemble.<br>
You may write your source code also in C and Assembler (S-files).<br>

## Understanding a micro controller
The AVR assembler simulator by Gerhard Schmidt is included.<br>
This software emulates e.g. ATmega micro controllers.<br>
You may create assembler code, running the integrated assembler and simulate it.<br>
So you really may understand what goes on within your micro controller.<br>

## AVR assembler
This assembler is included in "Atmel Studio 7.0". Filename "avrasm2.exe".<br>
I included it in MyIDE if you want to develop in assembler.
This is assembler is used within "Atmel Studio 7.0" for assembler source files "*.asm".<br>
You need to distingish between AVR assembler and GCU-GCC assembler.<br>
If you want to create assembler applications try AVR assembler.<br>

## Automatically detection of source:<br>
The "makefile" automatically detects all types of source-files.<br>
In fact more than one source-file will be detected.<br>
## Ready to use makefile:<br>
There is a ready to use makefile, which needs to be copied into project-folder.<br>
You only need to change the **PORT** according to your USB-connection.
## Installation of MyIDE:<br>
Follow the instructions in INSTALL.md
## What to do after installation
No further installation is needed.<br>
No settings of environment-values are nessesary.<br>
The makefile will find all tools automatically.<br>
This is done because Programmer's Notepad sends its directory-path to the makefile.<br>
Hence do not change the structure of MyIDE.<br>
Below the MyIDE main folder needs to be the following subfolders: <br>
> archives, libraries, makefile, PNP, toolchain, utils<br>

## Thanks to the developers<br>
I appreciate the work of Zak Kemble and his toolchain:<br>
https://blog.zakkemble.net/avr-gcc-builds/<br>
The contents will be find in the folder "..\MyIDE\toolchain".<br>
This great implementation contains e.g. avr-gcc.exe but alse make.exe,<br>
avrdude.com, avrdude.conf and all the libraries.<br>
<br>
This MyIDE runs within the Windows-Shell.<br>
The MyIDE-folder "..\MyIDE\utils" contains Unix-tools derived from:<br>
http://unxutils.sourceforge.net Karl M. Syring<br>
Hence UNIX-commands like ls.exe may be used within make.exe.<br>
<br>
As Editor I choosed portable Programmer's Notepad:<br>
The MyIDE-folder "..\MyIDE\PNP" contains the folders and files derived from:<br>
https://github.com/simonsteele/pn/releases/download/v2.4.2/portable-pn2421440.zip<br>
I made some additions in UserTools.xml in order to add options in the TOOLS-menue.<br>
<br>
Have fun.

