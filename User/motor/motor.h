#ifndef __MOTOR_H
#define	__MOTOR_H

#include "stm32f10x.h"

//  Òý½Å¶¨Òå
#define    MOTOR1A_GPIO_CLK     RCC_APB2Periph_GPIOB
#define    MOTOR1A_GPIO_PORT    GPIOB			   
#define    MOTOR1A_GPIO_PIN		 GPIO_Pin_12

#define    MOTOR1B_GPIO_CLK     RCC_APB2Periph_GPIOB
#define    MOTOR1B_GPIO_PORT    GPIOB			   
#define    MOTOR1B_GPIO_PIN		 GPIO_Pin_13

#define    MOTOR2A_GPIO_CLK     RCC_APB2Periph_GPIOB
#define    MOTOR2A_GPIO_PORT    GPIOB		   
#define    MOTOR2A_GPIO_PIN		 GPIO_Pin_14

#define    MOTOR2B_GPIO_CLK     RCC_APB2Periph_GPIOB
#define    MOTOR2B_GPIO_PORT    GPIOB		   
#define    MOTOR2B_GPIO_PIN		 GPIO_Pin_15

#define    MOTOR3A_GPIO_CLK     RCC_APB2Periph_GPIOC
#define    MOTOR3A_GPIO_PORT    GPIOC		   
#define    MOTOR3A_GPIO_PIN		 GPIO_Pin_8

#define    MOTOR3B_GPIO_CLK     RCC_APB2Periph_GPIOC
#define    MOTOR3B_GPIO_PORT    GPIOC		   
#define    MOTOR3B_GPIO_PIN		 GPIO_Pin_9

#define    MOTOR4A_GPIO_CLK     RCC_APB2Periph_GPIOC
#define    MOTOR4A_GPIO_PORT    GPIOC		   
#define    MOTOR4A_GPIO_PIN		 GPIO_Pin_10

#define    MOTOR4B_GPIO_CLK     RCC_APB2Periph_GPIOC
#define    MOTOR4B_GPIO_PORT    GPIOC	   
#define    MOTOR4B_GPIO_PIN		 GPIO_Pin_11

void motor_GPIO_init(void);

void M1_go(void);
void M2_go(void);
void M3_go(void);
void M4_go(void);
void M1_back(void);
void M2_back(void);
void M3_back(void);
void M4_back(void);
void Car_go(void);
void Car_back(void);

#endif /* __KEY_H */


