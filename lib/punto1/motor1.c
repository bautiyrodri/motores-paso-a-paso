#include "motor1.H"
    void pasoNormal_init(int IN0, int IN1, int IN2, int IN3){
       RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
       int pines[4]={IN0,IN1,IN2, IN3};
        for (int i = 0; i < 4; i++)  {
            if(i<4) GPIOA->CRL|=(0X1<<((pines[i])*4));
             else GPIOA->CRH|=(0X1<<((pines[i]+16)*4));
        }           
}

    void pasoNormal(int IN0, int IN1, int IN2, int IN3, int pasos){
         int pines[4]={IN0,IN1,IN2, IN3};
        int estpasos[4][4]={
            {1,1,0,0},
            {0,1,1,0},
            {0,0,1,1},
            {1,0,0,1}

        };
        for (int i = 0; i < 8; i++){
            for (int f = 0; f < 4; f++){
               if(estpasos[f%4][i]) GPIOA->BSRR|=(1<<pines[f]);
            else GPIOA->BSRR|=(1<<(pines[f]+16));

            }
            
        }
        

    }

    void pasoCompleto_init(int IN0, int IN1, int IN2, int IN3){
       RCC->APB2ENR|=RCC_APB2ENR_IOPBEN;
       int pinesB[4]={IN0,IN1,IN2, IN3};
        for (int i = 0; i < 4; i++)  {
            if(i<4) GPIOB->CRL|=(0X1<<((pinesB[i])*4));
             else GPIOB->CRH|=(0X1<<((pinesB[i]+16)*4));
        }           
}
    void pasoCompleto(int IN0, int IN1, int IN2, int IN3, int pasos){

        int pines[4]={IN0,IN1,IN2, IN3};
        int estpasos[4][4]={
            {1,0,0,0},
            {0,1,0,0},
            {0,0,1,0},
            {0,0,0,1}

        };
        for (int i = 0; i < 8; i++){
            for (int f = 0; f < 4; f++){
               if(estpasos[f%4][i]) GPIOB->BSRR|=(1<<pines[f]);
            else GPIOB->BSRR|=(1<<(pines[f]+16));

            }
            
        }
        

    } 

    void pasoMedio_init(int IN0, int IN1, int IN2, int IN3){
       RCC->APB2ENR|=RCC_APB2ENR_IOPCEN;
       int pinesC[4]={IN0,IN1,IN2, IN3};
        for (int i = 0; i < 4; i++)  {
            if(i<4) GPIOC->CRL|=(0X1<<((pinesC[i])*4));
             else GPIOC->CRH|=(0X1<<((pinesC[i]+16)*4));
        }           
}
    void pasoMedio(int IN0, int IN1, int IN2, int IN3, int pasos){

        int pinesC[4]={IN0,IN1,IN2, IN3};
        int estpasos[8][4]={
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
               if(estpasos[f%4][i]) GPIOC->BSRR|=(1<<pinesC[f]);
            else GPIOC->BSRR|=(1<<(pinesC[f]+16));

            }
            
        }
        

    }
