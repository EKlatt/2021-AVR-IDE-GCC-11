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

<table width="530px" border="0" cellpadding="0" cellspacing="0"> 
  <tr>
  <td>MyIDE -- </td>
  <td>+ --------</td>
  <td>+ -------------</td>
  <td>+ ----------------</td>
  <td>+ -------------</td>
  <td>+ -----------</td>
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
  <td>   + -- LCD</td>
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
> Open Programmer's Notepad "pn.exe" located in "..\MyIDE\PNP\pn.exe".<br>
> Open a existing Programmer's Notepad Project.<br>
> \> File > Open Project(s)...> and navigate to folder "..\examples\MyIDE_Blink_C"<br>
> and open "MyIDE_Blink_C.pnpproj"<br>
> Press ALT+F6 to open Projects expand folder "MyIDE_Blink_C"<br>

## Open a Source-file:<br>
It is **absolutely nessesary** to **open a file** within the **present project**.<br> 
All actions you choose in "menue tools" depends on this open file.<br> 
The "menue option" sends the directory-name to the "makefile".<br>
In consequence of this the commands like "avr-gcc.exe" can be found from "make.exe".
> Hence open "Example.cpp".<br>

## Compile..:<br>
In this example the makefile is already present.<br>
> Open makefile and edit AVRDUDE_PORT.<br>

## Menue Tools:<br>
> &gt; Tools > [MyIDE] make all     or F5<br>
> &gt; Tools > [MyIDE] make program or F6<br>
> &gt; Tools > [MyIDE] make clean   or F7<br>
> &gt; Tools > [MyIDE] ls           or F8<br>
> &gt; Tools > [MyIDE] get makefile or F9<br>

## New Project ##
Suppose there exists a folder with a source file but no PN Project.<br>
**Create a Project: <br>**
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

## Using GNU make<br>
If you choose "compile/check" within the Arduino-IDE a tool called<br>
"arduino-builder.exe" will be started. The options of the build-process<br>
are defined in the file "platform.txt".<br>
Actual WINAVR works with Make and a "makefile".<br>
Therefore I decided to use "GNU Make" with a "makefile" for MyIDE.<br>

**Goal of MyIDE**<br>
If you want to understand what is going on behind the scene, you<br>
have to understand the building-process. That means, you start with<br>
a C++ source-code and end up with flashing your microcontroller.<br>
Hence becoming familiar with a "makefile" is a goal.<br>
The makefile defines the building-process and has it's own language.<br>

> **But for your assistance I developped a "makefile" ready to use.**<br>
You may use this makefile, modify it or develop your own.<br>

**My makefile**<br>
Hence the main task of MyIDE was the development of a makefile.<br>
To start with I transfered a number of ideas from the WINAVR makefile<br>
written by Eric B. Weddington, Jörg Wunsch, et al.<br>
My "makefile" is located in "../makefile/makefile.master".<br>

**Extensions**<br>
I decided to develop a makefile which works like the build-process<br>
of the Arduino-IDE. You only need to edit the PORT and new are ready to go.<br>

> The type of source: C++, C or S-file (assembler) will be automatically<br>
> detected and the related sources will be included in the building-process.<br>

> Header files from the user-libraris and the associated<br> 
> object-files will be scanned for automatically.<br> 

**Compiler and Linker options**<br>
I decided to use the options from Arduino "platform.txt".<br>

**Copy "makefile.master"**<br>
> Each project needs to have a makefile.<br>
> Using &gt; Tools > "[MyIDE] get makefile" you get a copy of <br>
> "../makefile/makefile.master", renamed to "makefile",
> into your present project-folder.<br>

**Editing PORT**<br>
> You only need to edit the *PORT*, if you work with a "ATmega328".<br>

**Libraries**<br>
Like the "Arduino-IDE" MyIDE comes with a folder called "../MyIDE/libraries".<br>
These subfolders are intended for user-libraries which you create or<br>
got from other sources.<br>
I decided to create libraries for use with C++ sources.<br>
If you want libraries for C, take a look into folder "../MyIDE/libraries_c".<br>
Save the cpp-library from "../MyIDE/libraries" to "../MyIDE/libraries.cpp".<br>
Copy the C-library from "../MyIDE/libraries_c" to "../MyIDE/libraries".<br>
If you want to use a new library, follow these steps:<br>
Create a subfolder for the user-library and add the *.h and *.o files.<br>
How are the libraries used from makefile?<br>
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
  <td>LCD ---</td>
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
  <td>LCD.h</td>
  <td>&nbsp;</td>
  <td>USART.h</td>
 </tr>
<tr>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>LCD.o</td>
  <td>&nbsp;</td>
  <td>USART.o</td>
 </tr>
</table><br>

**Header file**<br>
The reference in your source code needs to be e.g. **#include "USART.h"**.<br>
Notice the above structure, therein the header file "LCD.h" will be<br>
scannded for automatically.<br>

**Linking**<br>
At the beginning of the build-process a **archive-file** named "core.a",<br>
which contains all object-files of the added libraries will be created.<br>
The archive-file is located in "../MyIDE/archives".<br>
The linker scannes "core.a" in order to find the functions reffered to<br>
in the header file.<br>
> If you "clean" the files of the build process "core.a" will be deleted.<br>

**Archives**<br>
You may add an archive-file. Doing this you need advanced experience with Make.<br>

*Steps of programmimg skills*<br>
 in work...





 