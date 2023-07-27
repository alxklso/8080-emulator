#include <stdlib.h>
#include <stdio.h>

/* 
Disassembler for the 8080 instruction set.
Translates hex values back into assembly src, useful when debugging the CPU emulator.

Algorithm:
    1. Read machine code into buffer 
    2. Init pointer at beginning of buffer.
    3. Determine opcode corresponding to byte pointer is pointing to.
    4. Print name of opcode using bytes after opcode as data (ex: JMP A, B).
    5. Increment pointer by number of bytes used by instruction (1, 2, or 3 bytes).
    6. Repeat steps 3-5 until end of buffer.


Link to 8080 opcode table: https://pastraiser.com/cpu/i8080/i8080_opcodes.html
*/

int disassembler() {


}