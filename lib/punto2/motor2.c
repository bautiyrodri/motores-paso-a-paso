#include "motor2.H"
MotorPaP_init(int IN0, int IN1, int IN2, int IN3){  //para inicializar los pines
    RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
    int pines[4]={IN0,IN1,IN2, IN3};
        for (int i = 0; i < 4; i++)  {
            if(i<4) GPIOA->CRL|=(0X1<<((pines[i])*4));
             else GPIOA->CRH|=(0X1<<((pines[i]+16)*4));
        }
}
MotorPaP(int IN0, int IN1, int IN2, int IN3, char tipoPaso, int pasos){//para desarrollar la funcion
    switch(tipoPaso){
        case 'n':
        int pines[4]={IN0,IN1,IN2, IN3};
        int pasos[4][4]={
            {1,1,0,0},
            {0,1,1,0},
            {0,0,1,1},
            {1,0,0,1}

        };
        for (int i = 0; i < 8; i++){
            for (int f = 0; f < 4; f++){
               if(pasos[f%4][i]) GPIOA->BSRR|=(1<<pines[f]);
            else GPIOA->BSRR|=(1<<(pines[f]+16));

            }
            
        }  
    break;

    case 'c':
        int pines[4]={IN0,IN1,IN2, IN3};
        int pasos[4][4]={
            {1,0,0,0},
            {0,1,0,0},
            {0,0,1,0},
            {0,0,0,1}

        };
        for (int i = 0; i < 8; i++){
            for (int f = 0; f < 4; f++){
               if(pasos[f%4][i]) GPIOB->BSRR|=(1<<pines[f]);
            else GPIOB->BSRR|=(1<<(pines[f]+16));

            }
            
        }
    break;

    case 'm':
        int pines[4]={IN0,IN1,IN2, IN3};
        int pasos[8][4]={
            {1,0,0,0},
            {1,1,0,0},
            {0,1,0,0},
            {0,1,1,0},
            {0,0,1,0},
            {0,0,1,1},
            {0,0,0,1},
            {1,0,0,1}

        };
        for (int i = 0; i < 8; i++){
            for (int f = 0; f < 4; f++){
               if(pasos[f%4][i]) GPIOC->BSRR|=(1<<pines[f]);
            else GPIOC->BSRR|=(1<<(pines[f]+16));

            }
            
        }
        break;
    }
}
    
