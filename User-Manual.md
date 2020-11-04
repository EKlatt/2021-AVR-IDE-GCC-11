## MyIDE User-Manual
**By Enno Klatt<br>**
MyIDE is a development tool for advanced Arduino-IDE users.<br>
MyIDE is intended for programmers who want to understand the basics<br>
behind the scene (Arduino-IDE). Therefore MyIDE contains only<br>
the basic components like:<br>
* AVR-GCC 10.1.0 for Windows 64 bit
* Programmer's Notepad 2
* GNU utilities for Win32.<br>
No debugging tools are added.<br>
# Installation
See details in "Install.md".<br>
You may move the location of MyIDE where you want.<br>
No settings of environment-values are nessesary.<br>
The makefile will find all tools automatically.<br>
This is done because Programmer's Notepad sends its installation-path to the makefile.<br>
Hence do not change the structure of MyIDE.<br>
Below the MyIDE main folder needs to be the following subfolders: <br>
>MyIDE ----+---------+-----------+-------------+--------------+ <br>
>          |         |           |             |              | <br>
>      archives  libraries      PNP         toolchain       utils<br>
>          |         |           |             |              |<br>
>         core.a     + - lcd     + - clips     + -- avr     ls.exe<br>
>                    |           |             |<br>
>                    + - USART   + - ctags     + -- bin<br>		   
>                                |             |<br>
>	                             + - presets   + -- include<br>
>                                |             |<br>       
>	                             + - schemes   + -- lib<br>
>	                             |             |<br>
>	                             + - settings  + -- libexec<br>
>                                              |<br>
>	                                           + -- share<br><br>
											  
# Included tools
**AVR-GCC 10.1.0** for Windows 64 bit (by Zak Kemble)<br>
Tool	|	Version
----------|----------
GCC	|	10.1.0
Binutils	|	2.34
AVR-LibC	|	SVN with extras
GDB	|	9.2 (not currently supported)
AVRDUDE	|	6.3
Make	|	4.2.1<br>

I called the above tools "toolchain" located in folder "toolchain".<br>
The advantage of "Zak Kemble's" edition is the presence of all<br>
needed tools like AVRDUDE and Make.exe.<br>
**Programmer's Notepad 2**<br>

As Editor I choosed portable Programmer's Notepad:<br>
I made some additions in UserTools.xml<br>
These additions will be found in the Tools-Menue:<br>
Task	|	Command
------------------|------------------
compile and link	|	[MyIDE] make all F5.<br>
flash choose	|	[MyIDE] make program F6.<br>
clean	|	[MyIDE] make clean F7.<br>
listing	|	[MyIDE] ls F8.<br>

Progammer's Notepad is located in folder "../MyIDE/PNP".<br>
In order to get the above mentioned enhancements, you need to do:<br>
1. Locate ..\MyIDE\PNP\settings
2. Rename the file "UserTools.xml" to "UserTools.xml.old"
3. Rename the file "UserTools.xml.new" to "UserTools.xml"<br>






 