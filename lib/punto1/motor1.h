#ifndef motor1_H
#define motor1_H
#include <stdint.h> //para mas tipos de variables
#include "stm32f103xb.h"
#include "ctype.h"
#include "stdbool.h"

void pasoNormal_init(int IN0, int IN1, int IN2, int IN3);
void pasoNormal(int IN0, int IN1, int IN2, int IN3, int pasos);
void pasoCompleto_init(int IN0, int IN1, int IN2, int IN3);
void pasoCompleto(int IN0, int IN1, int IN2, int IN3, int pasos);
void pasoMedio_init(int IN0, int IN1, int IN2, int IN3);
void pasoMedio(int IN0, int IN1, int IN2, int IN3, int pasos);

#endif