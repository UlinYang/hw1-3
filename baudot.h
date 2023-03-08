#ifndef _BAUDOT_
#define _BAUDOT_

struct Word{
    short word = -1;
    short switch_code = -1;
};


class Baudot{
    private:
                           /*A  B   C   D  E   F   G   H  I  J   K   L   M   N  O   P   Q   R   S   T  U   V   W   X  Y   Z*/  
        short Letter[26] = {1, 12, 13, 15, 2, 14, 10, 11, 6, 9, 25, 27, 26, 30, 7, 31, 29, 28, 20, 21, 5, 23, 22, 18, 4, 19};
        short Figure[10] = {15, 1, 2, 4, 5, 7, 9, 10, 12, 14};
        char inv_Letter[32] = {'\0', 'A', 'E', '\0', 'Y', 'U', 'I', 'O', '\0', 'J', 'G', 'H', 'B', 'C', 'F', 'D', '\0', '\0', 'X', 'Z', 'S', 'T', 'W', 'V', '\0', 'K', 'M', 'L', 'R', 'Q', 'N', 'P'};
        char inv_Figure[16] = {'\0', '1', '2', '\0', '3', '4', '\0', '5', '\0', '6', '7', '\0', '8', '9', '\0', '0'};
        bool cur_type = false; 

    public:
        Baudot(){}

        void ASCII_2_Baudot(char *src, Word *dst, short num){
            if( (src[0]-'A') < 0) this->cur_type = true;

            for(int i=0; i<num; i++){

                if( (src[i]-'A') < 0){ 

                    dst[i].word = Figure[ src[i]-'0' ];
                    if(cur_type==false){ 
                        dst[i].switch_code = 8;
                        cur_type = true;
                    }
                    else dst[i].switch_code = -1;

                }
                else{  

                    dst[i].word = Letter[ src[i]-'A' ];
                    if(cur_type==true){
                        dst[i].switch_code = 10;
                        cur_type = false;
                    }
                    else dst[i].switch_code = -1;

                }
            }
        };
        char Baudot_2_ASCII(int code){
            if(this->cur_type==false){ 
                if(code==0x08){
                    this->cur_type = true;
                    return 0;
                }
                return inv_Letter[code];
            }
            else{  
                if(code==0x10){
                    this->cur_type = false;
                    return 0;
                }
                return inv_Figure[code];
            }
        };

};

#endif