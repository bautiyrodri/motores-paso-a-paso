#include "stm32f103xb.h"
#include "motor2.h"
int IN0=0,IN1=1,IN2=2,IN3=3;

int main(){
    MotorPaP_init(IN0,IN1,IN2,IN3);
    
while(1){
    int pasos=47;
    char tipoPaso='m';
    MotorPaP(IN0,IN1,IN2,IN3,tipoPaso,pasos);
    }
}