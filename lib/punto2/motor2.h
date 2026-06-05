#ifndef motor1_H
#define motor1_H
#include <stdint.h> //para mas tipos de variables
#include "stm32f103xb.h"
#include "ctype.h"
#include "stdbool.h"

/*('n' normal, 'c' completo, 'm' medio) */

void MotorPaP_init(int IN0, int IN1, int IN2, int IN3);
void MotorPaP(int IN0, int IN1, int IN2, int IN3, char tipoPaso, int pasos);


#endif