# Assembler-Manual<br>
You may write code in Assembler. 

### Assembler families

- Assembler standalone (GNU AVR-GCC) 
- Assembler standalone (AVR Assembler) 
- Inline Assembler
- Mixing Assembler & C++ or C code

##### Assembler standalone (GNU AVR-GCC)

The way  of compiling and assembling with GNU AVR-GC:

<img src="Building a Code - Workflow.jpg" alt="img" style="zoom:80%;" />

In this case we write the code in **GNU AVR-GCC assembler**. <br>
We invoke the compiling and assembling process with the **avr-gcc C-compiler**.<br>
After precompiling, the assembler "avr-as.exe" is invoked automatically.<br>
The source file needs to have the extension "**myFile.S**".<br>
Therefore "**makefile**" expects the file extension capital '**S'**.<br>

##### Assembler standalone (AVR Assembler)
If you check out the assembler for 8 bit micro processors used in "Atmel Studio 7.0" you will <br>notice a assembler with the filename "avrasm2.exe".<br>
I decided to integrate this assembler in MyIDE. <br>
The source file needs to have the extension **"myFile.asm"**.<br>
Therefore "**makefile**" expects the file extension **"asm"**.

> See: http://ww1.microchip.com/downloads/en/DeviceDoc/40001917A.pdf<br>
> https://onlinedocs.microchip.com/pr/GUID-E06F3258-483F-4A7B-B1F8-69933E029363-en-US-2/index.html

##### Differences GNU AVR-GCC to AVR Assembler<br>
Unfortunately, the syntax differs slightly between these two assemblers. And it turns out that the syntax differences are big <br>enough to make the conversion of existing source code a non-trivial task that tends to take way longer than expected.<br>
> See: https://tenbaht.github.io/posts/migrating-from-avra-to-avr-as/<br>

##### Inline Assembler
With the GNU avr-gcc compiler for AVR micro processors you may embed assembly language code into C++ or C programs.<br>
 This feature may be used for manually optimizing time critical parts of the software or to use specific processor instruction, <br>which are not available in the C++ or C language.<br>
> See: https://www.nongnu.org/avr-libc/user-manual/inline_asm.html
>         http://ww1.microchip.com/downloads/en/appnotes/doc42055.pdf.

Therefore "makefile" expects the file extension "cpp" or 'c'.<br>
I didn't check this way of coding with MyIDE.<br>

##### Mixing Assembler & C++ or C code

You may write code in C++ or C code and using functions which are written in Assembler.<br>

> Reference:  http://ww1.microchip.com/downloads/en/appnotes/doc42055.pdf.
>

I didn't check this way of coding with MyIDE.<br><br>

| **AVR-GCC (AS) Assembly Language Syntax** | [sourceware.org](https://sourceware.org/binutils/docs-2.19/as/index.html) |
| :---------------------------------------- | ------------------------------------------------------------ |
| #include <avr/io.h>                       | C-precompiler directive for headerfile                       |
|                                           | (we use the C or C++ libraries)                              |
| .include "file"                           | include supporting files at the specified loacation          |
| ; my comment                              | comment starts with a colon ";"                              |
| /* ... */    and //                       | C-style comments are allowed                                 |
|                                           |                                                              |
| .nolist .list                             | assembly listings are not generated or generated             |
| .global main                              | makes the symbol visible to the linker (absolutely necessary) |
|                                           |                                                              |
| .text <br>.data <br>.bss ...              | The .text section contains the actual machine instructions.<br>This section contains static data which was defined in your code.<br>Uninitialized global or static variable |
| label: instruction                        | label as target for program execution                        |
| .org 0x00                                 | advance the location counter to 0x00                         |
| lo8(val)                                  | `lo8()` Takes the least significant 8 bits of a 16-bit integer |
| hi8(val)                                  | `hi8()`Takes the most significant 8 bits of a 16-bit integer |
|                                           |                                                              |
| .equ adams, (5 * 8) + 2                   | set the value of symbol to expression                        |
| .set adams, 42                            | alternative to .equ                                          |
| adams = 42                                | alternative to .equ                                          |
|                                           |                                                              |
| mov r16, 74                               | decimal number 74                                            |
| mov r16 ,0x4A                             | hexadecimal number 0x4A                                      |
| mov r16, 0b1001010                        | binary number 0b1001010                                      |
| mov r16, number                           | using preliminary defined number                             |




| **AVR Assembler Language Syntax** | (AVRASM2)                                                    |
| :-------------------------------- | ------------------------------------------------------------ |
| #include "myfile.inc"             | Preprocessor including file (equivalent to .include)         |
| .include "filename.asm"           | including means reading from another file                    |
|                                   |                                                              |
| ; my comment                      | comment starts with a colon ";"                              |
| /* ... */    and //               | C-style comments are allowed (AVRASM2)                       |
|                                   |                                                              |
| .nolist .list                     | assembly listings are not generated or generated             |
|                                   |                                                              |
| .dseg<br>.cseg                    | The DSEG directive defines the start of a Data segment<br>The CSEG directive defines the start of a Code Segment |
| label: instruction                | label as target for program execution                        |
| .org 0x00                         | advance the location counter to 0x00                         |
|                                   |                                                              |
| low(val)                          | `low()` Takes the least significant 8 bits of a 16-bit integer |
| high(val)                         | `high()`Takes the most significant 8 bits of a 16-bit integer |
|                                   |                                                              |
| .equ adams = (5 * 8) + 2          | set the value of symbol to expression                        |
| .set adams = 42                   | alternative to .equ                                          |
| .def temp=R16                     | The DEF directive allows the registers to be referred to through symbols |
|                                   |                                                              |
| mov r16, 74                       | decimal number 74                                            |
| mov r16 ,0x4A                     | hexadecimal number 0x4A                                      |
| mov r16, 0b1001010                | binary number 0b1001010                                      |
| mov r16, number                   | using preliminary defined number                             |


