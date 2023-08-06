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
        case 0x0f: printf("RRC"); break;

        case 0x10: printf("NOP"); break;
        case 0x11: printf("LXI    D, #$%02x%02x", chunk[2], chunk[1]); opbytes = 3; break;
        case 0x12: printf("STAX   D"); break;
        case 0x13: printf("INX    D"); break;
        case 0x14: printf("INR    D"); break;
        case 0x15: printf("DCR    D"); break;
        case 0x16: printf("MVI    D, #$%02x", chunk[1]); opbytes = 2; break;
        case 0x17: printf("RAL"); break;
        case 0x18: printf("NOP"); break;
        case 0x19: printf("DAD    D"); break;
        case 0x1a: printf("LDAX   D"); break;
        case 0x1b: printf("DCX    D"); break;
        case 0x1c: printf("INR    E"); break;
        case 0x1d: printf("DCR    E"); break;
        case 0x1e: printf("MVI    E, #$%02x", chunk[1]); opbytes = 2; break;
        case 0x1f: printf("RAR"); break;

        case 0x20: printf("RIM"); break;
        case 0x21: printf("LXI    H, #$%02x%02x", chunk[2], chunk[1]); opbytes = 3; break;
        case 0x22: printf("SHLD   $%02x%02x", chunk[2], chunk[1]); opbytes = 3; break;
        case 0x23: printf("INX    H"); break;
        case 0x24: printf("INR    H"); break;
        case 0x25: printf("DCR    H"); break;
        case 0x26: printf("MVI    H, #$%02x", chunk[1]); break;
        case 0x27: printf("DAA"); break;
        case 0x28: printf("NOP"); break;
        case 0x29: printf("DAD    H"); break;
        case 0x2a: printf("LHLD   $%02x%02x", chunk[2], chunk[1]); opbytes = 3; break;
        case 0x2b: printf("DCX    H"); break;
        case 0x2c: printf("INR    L"); break;
        case 0x2d: printf("DCR    L"); break;
        case 0x2e: printf("MVI    L, #$%02x", chunk[1]); opbytes = 2; break;
        case 0x2f: printf("CMA"); break;

    }

    printf("\n");
    return opbytes;
}