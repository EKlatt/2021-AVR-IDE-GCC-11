<meta name="MyIDE" content="2020 WINAVR clone" />
<meta name="keywords" content="MyIDE, WinAVR, Arduino, C++"/>
<meta name="author" content="Enno Klatt" />
<meta name="robots" content="index"/>
# MyIDE created from AVR-GCC 10.1.0 
## (works similar to WINAVR)
This is the beta version of MyIDE intended for advanced Arduino-IDE<br>
users. MyIDE is not a replacement for WINAVR. It consists of <br>
* AVR-GCC 10.1.0 for Windows 64 bit
* Programmer's Notepad 2
* GNU utilities for Win32.<br>
MyIDE is intended for programmers who want to understand<br>
the basics behind the scene (Arduino-IDE).
## Main goal: Writing code in native C++
The main goal is to develop C++ programs using the AVR-toolchain<br>
from Zak Kemble.<br>
You may write your source code also in C and Assembler (S-files).<br>
## Automatically detection of source:<br>
The "makefile" automatically detects all types of source-files.<br>
In fact more than one source-file will be detected.<br>
## Ready to use makefile:<br>
There is a ready to use makefile, which needs to be copied into project-folder.
You only need to change the PORT according to your USB-connection.
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

## Thanks to the developpers! 
I appreciate the work of Zak Kemble and his toolchain:<br>
https://blog.zakkemble.net/avr-gcc-builds/<br>
The contents will be find in the folder ..\MyIDE\toolchain.<br>
This great implementation contains e.g. avr-gcc.exe but alse make.exe,<br>
avrdude.com, avrdude.conf and all the libraries.<br>
<br>
This MyIDE runs within the Windows-Shell.<br>
The MyIDE-folder ..\MyIDE\utils contains Unix-tools derived from:<br>
http://unxutils.sourceforge.net Karl M. Syring<br>
Hence UNIX-commands like ls.exe may be used within make.exe.<br>
<br>
As Editor I choosed portable Programmer's Notepad:<br>
https://github.com/simonsteele/pn/releases/download/v2.4.2/portable-pn2421440.zip<br>
<br>
I made some additions in UserTools.xml<br>
<br>
Have fun.

