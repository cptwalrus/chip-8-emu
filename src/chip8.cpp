#include "chip8.h"

#include <array>


unsigned char chip8_fontset[80] =
{ 
  0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
  0x20, 0x60, 0x20, 0x20, 0x70, // 1
  0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
  0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
  0x90, 0x90, 0xF0, 0x10, 0x10, // 4
  0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
  0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
  0xF0, 0x10, 0x20, 0x40, 0x40, // 7
  0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
  0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
  0xF0, 0x90, 0xF0, 0x90, 0x90, // A
  0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
  0xF0, 0x80, 0x80, 0x80, 0xF0, // C
  0xE0, 0x90, 0x90, 0x90, 0xE0, // D
  0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
  0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

Chip8::Chip8()
{
   pc = 0x200; 
   opcode = 0;
   I = 0;

   for(int i = 0; i < 80; ++i)
   {
       memory[i] = chip8_fontset[i];
   }

}


void Chip8::emulateCycle()
{

    //fetch
    opcode = memory[pc] << 8 | memory[pc + 1];

    //decode
    //execute
    executeOp();
    //update timers

    if(delayTimer > 0)
    {
        --delayTimer;
    }

    if(soundTimer > 0)
    {
        // TODO: make sound play
        --soundTimer;
    }


}

void Chip8::executeOp()
{

    if( 0 == opcode )
    {
        return;
    }
  
    int reg = opcode & 0x0F00 >> 8;
    int reg2 = opcode & 0x00F0 >> 4;
    switch (opcode & 0xF000)
    {
        case 0x0000:
            switch (reg2) 
            {
                case 0x00E0:

                    if ((opcode & 0x000F) = 0x000E) 
                    {
                        //perform return from subroutine
                    }
                    else 
                    {
                        clearGfx();
                    }
                default:
                    pc = opcode & 0x0FFF;
            }
            break;
        case 0x1000:
            pc = opcode & 0x0FFF;
            break;
        case 0x2000:
            stack.push(pc);
            pc = opcode & 0x0FFF;
            break;
        case 0x3000:
            if(V[reg] == (opcode & 0x0FFF))
            {
                pc++;
            }
            break;
        case 0x4000:
            if(V[reg] != (opcode & 0x0FFF))
            {
                pc++;
            }
            break;
        case 0x5000:
            if(V[reg] == V[reg2])
            {
                pc++;
            }
            break;
        case 0x6000:
            V[reg] = opcode & 0x00FF;
            break;
        case 0x7000:
            V[reg] += opcode & 0x00FF;
            break;
        case 0x8000:
            
            switch(opcode & 0x000F)
            {
                case 0x0000:
                    V[reg] = V[reg2];
                    break;
                case 0x0001:
                    V[reg] = V[reg] | V[reg2];
                    break;
                case 0x0002:
                    V[reg] = V[reg] & V[reg2];
                    break;
                case 0x0003:
                    V[reg] = V[reg] ^ V[reg2];
                    break;
                case 0x0004:
                    //carry flag check
                    if(V[(reg2)] > (0xFF - V[reg]))
                    {
                        V[0xF] = 1;
                    }
                    else
                    {
                        V[0xF] = 0;
                    }
                    V[reg] += V[reg2];
                    break;
                case 0x0005:
                    //carry flag check
                    if(V[reg2] > V[reg])
                    {
                        V[0xF] = 1;
                    }
                    else
                    {
                        V[0xF] = 0;
                    }
                    V[reg] -= V[reg2];
                    break;
                case 0x0006:
                    break;
                case 0x0007:
                    V[reg] = V[reg2] - V[reg];
                    break;
                case 0x000E:
                    break;

                default:
                    break;
            }
            break;
        case 0x9000:
            break;
        case 0xA000:
            I = opcode & 0x0FFF;
            break;
        case 0xB000:
            pc = V[0] + (opcode & 0x0FFF);
            break;
        case 0xC000:
            break;
        case 0xD000:
            break;
        case 0xE000:
            break;
        case 0xF000:
            break;

        default:
            //UNK OPCODE
            // TODO: Use SFML to generate error here - or throw exception giving unk opcode
            break;
    }

    pc++;


}

void Chip8::clearGfx()
{
    std::fill_n(gfx, gfx.size(), 0);
}

void Chip8::draw(int x, int y, int height)
{
    
}
