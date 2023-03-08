#ifndef _7_SEGMENT_
#define _7_SEGMENT_



class SSD{
    private: 
        char Figure_Table[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
        char Letter_Table[26] = {
            0b01110111,
            0b01111100,
            0b00111001,
            0b01011110,
            0b01111001,
            0b01110001,
            0b00111101,
            0b01110110,
            0b00000110,
            0b00011110,
            0b01110000,
            0b00111000,
            0b01001001,
            0b01010100,
            0b01011100,
            0b01110011,
            0b01100111,
            0b01010000,
            0b01101101,
            0b01111000,
            0b00111110,
            0b00011100,
            0b00101010,
            0b00110110,
            0b01100110,
            0b01011011
        };
    public:
        SSD(){}
        char display(char ch){
            if(ch==(char)-1 || ch==(char)0)
                return 0x00;
            if(ch-'A' < 0)
                return Figure_Table[ch-'0'];    
            return Letter_Table[ch-'A'];
        }

};


#endif

    