#include "stm32f103xb.h"
#include "motor1.h"

int IN0=0,IN1=1,IN2=2,IN3=3;

int main(){
    pasoNormal_init(IN0,IN1,IN2,IN3);
    
while(1){
    int pasos=38;
    pasoNormal(IN0,IN1,IN2,IN3,pasos);
    }


    pasoNormal_init(IN0,IN1,IN2,IN3);
}

