## MyIDE User-Manual
**By Enno Klatt<br>**
MyIDE is a development tool for advanced Arduino-IDE users.<br>
MyIDE is intended for programmers who want to understand<br>
the basics behind the scene (Arduino-IDE).
Therefore MyIDE contains only the basic components like:<br>
* AVR-GCC 10.1.0 for Windows 64 bit
* Programmer's Notepad 2
* GNU utilities for Win32.<br>
No debugging tools are added.
# Installation
See "Install.md"<br>
No further installation is needed.<br>
No settings of environment-values are nessesary.<br>
The makefile will find all tools automatically.<br>
This is done because Programmer's Notepad sends its directory-path to the makefile.<br>
Hence do not change the structure of MyIDE.<br>
Below the MyIDE main folder needs to be the following subfolders: <br>
- archives, libraries, makefile, PNP, toolchain, utils<br>
# Included tools
AVR-GCC 10.1.0 for Windows 64 bit (by Zak Kemble)<br>
Tool	|	Version
----------|----------
GCC	|	10.1.0
Binutils	|	2.34
AVR-LibC	|	SVN with extras
GDB	|	9.2
AVRDUDE	|	6.3
Make	|	4.2.1<br>