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
- archives, libraries, makefile, PNP, toolchain, utils<br>
## First trial:<br>
For a first trial copy the folder ..\MyIDE\examples e.g. to your desktop.<br>
Open Programmer's Notepad pn.exe located in ...\MyIDE\PNP\pn.exe.<br>
Create a Project: > File > New > Project; Name it MyIDE_Blink_C.<br>
As "Folder" move to your location of ..\examples\MyIDE_Blink_C and open it.<br>
Press ALT+F6 to open Projects and Rightclick on MyIDE_Blink_C and chose "Add Magic Folder...".<br>
Look for ..\examples\MyIDE_Blink_C and choose it. Accept the following options.<br>
## Open a Project-file:<br>
It is absolutely nessesary to open a file within the present project.<br> 
The directory of the file is needed for further actions.<br>
Expand MyIDE_Blink_C and open Example.cpp.<br>
## Getting the makefile:<br>
Use menue  > Tools > [MyIDE] get makefile and click on it.<br>
Rightclick on folder-symbol  "MyIDE_Blink_C" and Refresh.<br>
Open makefile and edit AVRDUDE_PORT.<br>
<br>
Ready to go!<br>
* If you want to compile and link choose > Tools > [MyIDE] make all F5.<br>
* If you want to flash choose            > Tools > [MyIDE] make program F6.<br>
* If you want to clean > Tools           > [MyIDE] make clean F7.<br>
* If you want a listing > Tools          > [MyIDE] ls F8.<br>

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

