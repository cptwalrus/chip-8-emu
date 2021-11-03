#include <array>
#include <stack>

class Chip8
{

    public:

        Chip8();

        void emulateCycle();
        
        //graphics - Chip8 is just black and white/on off pixels
        //  NOTE: Might be easier to implement a 2d array for this... will see when actually doing gfx
        //  TEMP move to public as I test stuff and deside how I want this engineered
        std::array<unsigned char, 64*32*4> gfx;

    private:

        unsigned short opcode;

        //Mem map
        // 0x000 - 0x1FF - Chip 8 inerpreter
        // 0x050 - 0x0A0 - Built in 4x5 pixel font
        // 0x200 - 0xFFF - Program ROM and work ROM
        std::array<unsigned char, 4096> memory;

        //15 regsisters - 16th is carry register
        std::array<unsigned char, 16> V;

        std::array<unsigned char, 80> fontset;

        //16 byte stack
        std::stack<unsigned char> stack;

        //HEX keypad
        std::array<unsigned char, 16> keypad;
        
        //I is the index register
        unsigned short I;

        //PC == program counter == instruction pointer
        unsigned short pc;

        //Chip-8 timers count at 60hz
        unsigned char delayTimer;
        unsigned char soundTimer;


        void executeOp();

        
        

};
