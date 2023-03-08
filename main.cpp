#include "mbed.h"
#include "onepulse.h"
#include "7segment.h"
#include "baudot.h"


Timer timer;
Onepulse onepulse; 
SSD ssd;
Baudot baudot;
int mark_counter;
int code;
DigitalIn BUTTON(BUTTON1);
DigitalOut LED_CLOCK(LED1);
DigitalOut LED_CODE(LED3);
BusOut Pin(D8, D4, D9, D10, D11, D5, D6, D7);


int main()
{
    if (BUTTON.is_connected()) printf("BUTTON is connected and initialized! \n\r");
    if (LED_CLOCK.is_connected()) printf("LED_CLOCK is initialized and connected!\n\r");
    if (LED_CODE.is_connected()) printf("LED_CODE is initialized and connected!\n\r");

    BUTTON.mode(PullNone);

    code = 0;
    mark_counter = 0;
    LED_CLOCK.write(0);
    timer.start();
    printf("Code has value:\n");
    
    while(1){   

        onepulse.reset();
        LED_CODE.write(0);
        LED_CLOCK.write(1);

        while(1){
            if(timer.read()>2){
                timer.reset();
                break;
            }
            onepulse.input(BUTTON.read());
            ThisThread::sleep_for(120ms);  
            LED_CODE.write(onepulse.state());
        }

        if(mark_counter==5){
            printf(" %c", baudot.Baudot_2_ASCII(code));
            Pin = ssd.display( baudot.Baudot_2_ASCII(code) );
            code = 0;
            mark_counter = 0;
            printf("\n");
        }
        
        printf("%d", onepulse.state());
        code <<= 1;
        code += onepulse.state();
        ++mark_counter;


        LED_CLOCK.write(0);
        ThisThread::sleep_for(1s);
    }
}