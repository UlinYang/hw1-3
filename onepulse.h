#ifndef _ONEPULSE_
#define _ONEPULSE_


class Onepulse{
    private:
        bool cur_state;
        int counter;

    public:
        Onepulse(){this->cur_state = false; this->counter = 0;}

        void input(int read_button){
            if(cur_state==false && read_button==1){
                ++this->counter;
                this->cur_state = true;
            }
            if(cur_state==true && read_button==0){
                this->cur_state = false;
            }
            
        }
        void reset(){this->counter = 0; this->cur_state = false;}
        bool state(){return (counter>=3) ? 1 : 0;}

};

#endif