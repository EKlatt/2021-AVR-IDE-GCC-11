# MyIDE User-Manual
**By Enno Klatt<br>**
MyIDE is a development tool for advanced Arduino-IDE users.<br>
MyIDE is intended for programmers who want to understand the basics<br>
behind the scene (Arduino-IDE). Therefore MyIDE contains only<br>
the basic components like:<br>
* AVR-GCC 10.1.0 for Windows 64 bit
* Programmer's Notepad 2
* GNU utilities for Win32.<br>
No debugging tools are added.<br>
## Installation
See details in "Install.md".<br>
You may move the location of MyIDE where you want.<br>
No settings of environment-values are nessesary.<br>
The makefile will find all tools automatically.<br>
This is done because Programmer's Notepad sends its installation-path to the makefile.<br>
Hence do not change the structure of MyIDE.<br>
Below the MyIDE main folder needs to be the following subfolders: <br>

<table width="600px" border="0" cellpadding="0" cellspacing="0">
  <tr>
  <td>MyIDE --- </td>
  <td>+ --------------</td>
  <td>+ --------------</td>
  <td>+ ----------------</td>
  <td>+ --------------</td>
  <td>+ --------------</td>
  <td>+</td>
 </tr>
 <tr>
  <td>&nbsp;</td>
  <td>|</td>
  <td>|</td>
  <td>|</td>
  <td>|</td>
  <td>|</td>
  <td>|</td>
 </tr>
 <tr>
  <td>&nbsp;</td>
  <td>archives</td>
  <td>libraries</td>
  <td>makefile</td>
  <td>PNP</td>
  <td>toolchain</td>
  <td>utils</td>
 </tr>
 <tr>
  <td>&nbsp;</td>
  <td>|</td>
  <td>|</td>
  <td>|</td>
  <td>|</td>
  <td>|</td>
  <td>|</td>
 </tr>
 <tr>
  <td>&nbsp;</td>
  <td>core.a</td>
  <td>   + -- lcd</td>
  <td>makefile.master</td>
  <td>   + -- clips</td>
  <td>   + -- avr</td>
  <td>ls.exe</td>
 </tr>
<tr>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>|</td>
  <td>&nbsp;</td>
  <td>|</td>
  <td>|</td>
 </tr>
  <tr>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>   + -- USART</td>
  <td>&nbsp;</td>
  <td>   + -- ctags</td>
  <td>   + -- bin</td>
  <td>&nbsp;</td>
 </tr>
 <tr>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>|</td>
  <td>|</td>
  <td>&nbsp;</td>
 </tr>
 <tr>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>   + -- presets</td>
  <td>   + -- include</td>
  <td>&nbsp;</td>
 </tr>
 <tr>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>|</td>
  <td>|</td>
  <td>&nbsp;</td>
 </tr>
 <tr>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>   + -- schemes</td>
  <td>   + -- lib</td>
  <td>&nbsp;</td>
 </tr>
 <tr>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>|</td>
  <td>|</td>
  <td>&nbsp;</td>
 </tr>
 <tr>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>   + -- settings</td>
  <td>   + -- libexec</td>
  <td>&nbsp;</td>
 </tr>
 <tr>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>|</td>
  <td>|</td>
  <td>&nbsp;</td>
 </tr>
 <tr>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>pn.exe</td>
  <td>   + -- share</td>
  <td>&nbsp;</td>
 </tr>
</table><br>
										  
## Included tools
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
needed tools like AVRDUDE and Make.<br>

**Programmer's Notepad 2**<br>
As Editor I choosed portable Programmer's Notepad.<br>
I made some additions in UserTools.xml<br>
These additions will be found in the Tools-Menue:<br>
Task	|	Command     |    Key
------------------|------------------ | ----
compile and link	|	[MyIDE] make all | F5<br>
flash	|	[MyIDE] make program | F6<br>
clean	|	[MyIDE] make clean | F7<br>
listing	|	[MyIDE] ls | F8<br>
get makefile |	[MyIDE] get makefile | F9<br>

Progammer's Notepad is located in folder "../MyIDE/PNP".<br>
In order to get the above mentioned enhancements, you need to do:<br>
1. Locate ..\MyIDE\PNP\settings
2. Rename the file "UserTools.xml" to "UserTools.xml.old"
3. Rename the file "UserTools.xml.new" to "UserTools.xml"<br>

## First trial:<br>
For a first trial copy the folder "..\MyIDE\examples" to your desktop.<br>
Open Programmer's Notepad "pn.exe" located in "..\MyIDE\PNP\pn.exe".<br>
Create a Project: <br>
> \> File > New > Project; Name it MyIDE_Blink_C.<br>
> As "Folder" move to your location of "..\examples\MyIDE_Blink_C" and open it.<br>
> Press ALT+F6 to open Projects and Rightclick on "MyIDE_Blink_C" and chose "Add Magic Folder...".<br>
> Look for "..\examples\MyIDE_Blink_C" and choose it. Accept the following options.<br>
## Open a Source-file:<br>
It is **absolutely nessesary** to **open a file** within the **present project**.<br> 
All actions you choose in "menue tools" depends on this open file.<br> 
The "menue option" sends the directory-name to the "makefile".<br>
In consequence of this the commands like "avr-gcc.exe" can be found from "make.exe".
Hence expand "MyIDE_Blink_C" and open "Example.cpp".<br>
## Getting the makefile:<br>
Use PN menue:<br>  
> &gt; Tools > "[MyIDE] get makefile" and click on it.<br>
> Rightclick on folder-symbol  "MyIDE_Blink_C" and Refresh.<br>
> Open makefile and edit AVRDUDE_PORT.<br>
<br>

Ready to go:<br>
> &gt; Tools > [MyIDE] make all     or F5<br>
> &gt; Tools > [MyIDE] make program or F6<br>
> &gt; Tools > [MyIDE] make clean   or F7<br>
> &gt; Tools > [MyIDE] ls           or F8<br>
> &gt; Tools > [MyIDE] get makefile or F9<br>

## Using GNU make<br>
The Arduino-IDE comes not with GNU Make and a so called "makefile".<br>
If you chose "compile/check" within the Arduino-IDE a tool called<br>
"arduino-builder.exe" will be started. The options of the build-process<br>
are defined in the file "platform.txt". Without this file the Arduino-IDE<br>
will not run.<br>
Instead of this "MyIDE" uses "GNU Make" and a "makefile". Commonly<br>
the "makefile" has no extension.<br>
Actual WINAVR works also with Make and a "makefile".<br>
Instead of editing "platform.txt" you may edit my "makefile".<br>

**Goal of MyIDE**<br>
If you want to understand what is going on behind the scene, you<br>
have to understand the building-process. That means, you start with<br>
a C++ source-code and end up with flashing your microcontroller.<br>
Hence becoming familiar with a "makefile" is a goal.<br>
*But for your assistance I developped a "makefile" ready to use.<br>*

**My makefile**<br>
Hence the main task of MyIDE was the development of a makefile.<br>
To start with I transfered a number of ideas from the WINAVR makefile<br>
written by Eric B. Weddington, Jörg Wunsch, et al.<br>

**Compiler and Linker options**<br>
I decided to use the options from Arduino "platform.txt".<br>

**Getting makefile**<br>
> Using &gt; Tools > "[MyIDE] get makefile" you get a copy of <br>
> "../makefile/makefile.master", renamed to "makefile",
> into your present project-folder.<br>

**Extensions**<br>
> The new makefile is ready to use.<br>
> You only need to edit the *PORT* if you work with a "ATmega328".<br>
> The type of source: C++, C or S-file (assembler) will be automatically<br>
> detected and the related sources will be included in the building-process.

**Libraries**<br>
Like the "Arduino-IDE" MyIDE comes with a folder called "../MyIDE/libraries".<br>
Create your library (subfolder) and add the *.h and *.o files.<br>
The library-files will be automatically included in the compile- and<br>
link-process.<br>
Hence follow this structure:<br>
 <table width="500px" border="0" cellpadding="0" cellspacing="0">
  <tr>
  <td>MyIDE --- </td>
  <td>+ --------------</td>
  <td>+</td>
 </tr>
 <tr>
  <td>&nbsp;</td>
  <td>|</td>
  <td>|</td>
 </tr>
 <tr>
  <td>&nbsp;</td>
  <td>archives</td>
  <td>libraries ---</td>
  <td>+ ----</td>
  <td> ----</td>
  <td>+</td>
 </tr>
 <tr>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>|</td>
  <td>&nbsp;</td>
  <td>|</td>
 </tr>
  <tr>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>lcd ---</td>
  <td>+</td>
  <td>USART ---</td>
  <td>+</td>
 </tr>
 <tr>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>|</td>
  <td>&nbsp;</td>
  <td>|</td>
 </tr>
<tr>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>lcd.h</td>
  <td>&nbsp;</td>
  <td>USART.h</td>
 </tr>
<tr>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>lcd.o</td>
  <td>&nbsp;</td>
  <td>USART.o</td>
 </tr>
</table><br>

> *Compiling:*<br>
> The reference in your source code needs to be - #include "lcd.h" -.<br>
> Therefore your library within subfolder "lcd", in this case "lcd.h", will be<br>
> scannded for automatically.<br>
> *Linking:*<br>


**Archives**<br>
> *Linking:*<br>

> The associated object-file "lcd.o" will also automatically scanned for<br>
> in the libray-folder.<br>







 