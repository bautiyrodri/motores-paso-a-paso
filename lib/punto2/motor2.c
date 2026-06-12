#include "motor2.H"
void MotorPaP_init(int IN0, int IN1, int IN2, int IN3){
    RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
    int pines[4]={IN0,IN1,IN2,IN3};
    for(int i=0; i<4;i++){
        if(pines[i]<8){
            GPIOA->CRL&=~(0XF<<(pines[i]*4));
            GPIOA->CRL|=(0x1<<(pines[i]*4));
        }
        else{
            GPIOA->CRH&=~(0xF<<((pines[i]%8)*4));
            GPIOA->CRH|=(0x1<<((pines[i]%8)*4));
        }
    }

}
MotorPaP(int IN0, int IN1, int IN2, int IN3, char tipoPaso, int pasos){//para desarrollar la funcion
     int pines[4]={IN0,IN1,IN2, IN3};
    switch(tipoPaso){
    case 'n':
    int paso[4][4]={
        {1,1,0,0},
        {0,1,1,0},
        {0,0,1,1},
        {1,0,0,1}
    };
        for(int i=0; i<pasos;i++)
        {
            for(int j=0; j<4; j++){
                if(paso[i%4][j]) GPIOA->BSRR|=(1<<pines[i]);
                else GPIOA->BSRR|=(1<<(pines[i]+16));
            }
        }
    break;

    case 'c':
    int paso[4][4]={
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1}
    };
        for(int i=0; i<pasos;i++){
            for(int j=0; j<4; j++){
                if(paso[i%4][j]) GPIOA->BSRR|=(1<<pines[i]);
                else GPIOA->BSRR|=(1<<(pines[i]+16));
            }
        }



    break;

    case 'm':
        int estpasos1[8][4]={
            {1,0,0,0},
            {1,1,0,0},
            {0,1,0,0},
            {0,1,1,0},
            {0,0,1,0},
            {0,0,1,1},
            {0,0,0,1},
            {1,0,0,1}
        
        };
        for(int i=0; i<pasos;i++){//repetira la cant. de pasos que pongas
            for(int j=0; j<8; j++){//filas
                if(estpasos1[i%8][j]) GPIOA->BSRR|=(1<<pines[i]);
                else GPIOA->BSRR|=(1<<(pines[i]+16));
            }
        break;
    }
    default:
    
        break;
}
    
