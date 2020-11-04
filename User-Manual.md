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

<table width="500px" border="0" cellpadding="0" cellspacing="0">
  <tr>
  <td>MyIDE --- </td>
  <td>+ --------------</td>
  <td>+ --------------</td>
  <td>+ --------------</td>
  <td>+ --------------</td>
  <td>+</td>
 </tr>
 <tr>
  <td>&nbsp;</td>
  <td>   |       </td>
  <td>   |       </td>
  <td>   |       </td>
  <td>   |       </td>
  <td>   |       </td>
 </tr>
 <tr>
  <td>&nbsp;</td>
  <td>archives</td>
  <td>libraries</td>
  <td>PNP</td>
  <td>toolchain</td>
  <td>utils</td>
 </tr>
 <tr>
  <td>&nbsp;</td>
  <td>   |     </td>
  <td>   |     </td>
  <td>   |     </td>
  <td>   |     </td>
  <td>   |     </td>
 </tr>
 <tr>
  <td>&nbsp;</td>
  <td>core.a</td>
  <td>   + -- lcd</td>
  <td>   + -- clips</td>
  <td>   + -- avr</td>
  <td>ls.exe</td>
 </tr>
<tr>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>   |     </td>
  <td>   |     </td>
  <td>   |     </td>
  <td>&nbsp;</td>
 </tr>
  <tr>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>   + -- USART</td>
  <td>   + -- ctags</td>
  <td>   + -- bin</td>
  <td>&nbsp;</td>
 </tr>
 <tr>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>   |     </td>
  <td>   |     </td>
  <td>&nbsp;</td>
 </tr>
 <tr>
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
  <td>   |     </td>
  <td>   |     </td>
  <td>&nbsp;</td>
 </tr>
 <tr>
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
  <td>   |     </td>
  <td>   |     </td>
  <td>&nbsp;</td>
 </tr>
 <tr>
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
  <td>   |     </td>
  <td>&nbsp;</td>
 </tr>
 <tr>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>&nbsp;</td>
  <td>   + -- share</td>
  <td>&nbsp;</td>
 </tr>
</table>
										  
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
needed tools like AVRDUDE and Make.exe.<br>

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

Progammer's Notepad is located in folder "../MyIDE/PNP".<br>
In order to get the above mentioned enhancements, you need to do:<br>
1. Locate ..\MyIDE\PNP\settings
2. Rename the file "UserTools.xml" to "UserTools.xml.old"
3. Rename the file "UserTools.xml.new" to "UserTools.xml"<br>

## First trial:<br>
For a first trial copy the folder ..\MyIDE\examples e.g. to your desktop.<br>
Open Programmer's Notepad pn.exe located in ...\MyIDE\PNP\pn.exe.<br>
Create a Project: <br>
> \> File > New > Project; Name it MyIDE_Blink_C.<br>
> As "Folder" move to your location of "..\examples\MyIDE_Blink_C" and open it.<br>
> Press ALT+F6 to open Projects and Rightclick on "MyIDE_Blink_C" and chose "Add Magic Folder...".<br>
> Look for ..\examples\MyIDE_Blink_C and choose it. Accept the following options.<br>
## Open a Project-file:<br>
It is absolutely nessesary to open a file within the present project.<br> 
The directory of the file is needed for further actions.<br>
Expand "MyIDE_Blink_C" and open "Example.cpp".<br>
## Getting the makefile:<br>
Use menue<br>  
> &gt; Tools > [MyIDE] get makefile and click on it.<br>
> Rightclick on folder-symbol  "MyIDE_Blink_C" and Refresh.<br>
> Open makefile and edit AVRDUDE_PORT.<br>
<br>
Ready to go:<br>
> &gt; Tools > [MyIDE] make all     or F5.<br>
> &gt; Tools > [MyIDE] make program or F6.<br>
> &gt; Tools > [MyIDE] make clean   or F7.<br>
> &gt; Tools > [MyIDE] ls           or F8.<br>




 