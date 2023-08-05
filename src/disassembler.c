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

int disassembler(unsigned char *buffer, int programCounter)
{
    unsigned char *chunk = &buffer[programCounter]; // put pointer at beginning of buffer
    int opbytes = 1; // default obytes, since most opcodes are one byte
    printf("%04x", programCounter);

    switch (*chunk)
    {
        case 0x00: printf("NOP"); break;
        case 0x01: printf("LXI    B, #$%02x%02x", chunk[2], chunk[1]); opbytes = 3; break;
        case 0x02: printf("STAX   B"); break; 
        case 0x03: printf("INX    B"); break;
        case 0x04: printf("INR    B"); break;
        case 0x05: printf("DCR    B"); break;
        case 0x06: printf("MVI    B, #$%02x", chunk[1]); opbytes = 2; break;
        case 0x07: printf("RLC"); break;
        case 0x08: printf("NOP"); break;
        case 0x09: printf("DAD    B"); break;
        case 0x0a: printf("LDAX   B"); break;
        case 0x0b: printf("DCX    B"); break;
        case 0x0c: printf("INR    C"); break;
        case 0x0d: printf("DCR    C"); break;
        case 0x0e: printf("MVI    C, #$%02x", chunk[1]); opbytes = 2; break;



    }

    printf("\n");
    return opbytes;
}