#ifndef __EXTI_H
#define	__EXTI_H


#include "stm32f10x.h"


//Òý½Å¶¨Òå
#define KEY1_INT_GPIO_PORT         GPIOE
#define KEY1_INT_GPIO_CLK          (RCC_APB2Periph_GPIOE|RCC_APB2Periph_AFIO)
#define KEY1_INT_GPIO_PIN          GPIO_Pin_0
#define KEY1_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOE
#define KEY1_INT_EXTI_PINSOURCE    GPIO_PinSource0
#define KEY1_INT_EXTI_LINE         EXTI_Line0
#define KEY1_INT_EXTI_IRQ          EXTI0_IRQn

#define KEY1_IRQHandler            EXTI0_IRQHandler


#define KEY2_INT_GPIO_PORT         GPIOC
#define KEY2_INT_GPIO_CLK          (RCC_APB2Periph_GPIOC|RCC_APB2Periph_AFIO)
#define KEY2_INT_GPIO_PIN          GPIO_Pin_12
#define KEY2_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOC
#define KEY2_INT_EXTI_PINSOURCE    GPIO_PinSource12
#define KEY2_INT_EXTI_LINE         EXTI_Line12
#define KEY2_INT_EXTI_IRQ          EXTI15_10_IRQn

#define KEY2_IRQHandler            EXTI15_10_IRQHandler


#define KEY3_INT_GPIO_PORT         GPIOC
#define KEY3_INT_GPIO_CLK          (RCC_APB2Periph_GPIOC|RCC_APB2Periph_AFIO)
#define KEY3_INT_GPIO_PIN          GPIO_Pin_4
#define KEY3_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOC
#define KEY3_INT_EXTI_PINSOURCE    GPIO_PinSource4
#define KEY3_INT_EXTI_LINE         EXTI_Line4
#define KEY3_INT_EXTI_IRQ          EXTI4_IRQn

#define KEY3_IRQHandler            EXTI4_IRQHandler

#define KEY4_INT_GPIO_PORT         GPIOC
#define KEY4_INT_GPIO_CLK          (RCC_APB2Periph_GPIOC|RCC_APB2Periph_AFIO)
#define KEY4_INT_GPIO_PIN          GPIO_Pin_5
#define KEY4_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOC
#define KEY4_INT_EXTI_PINSOURCE    GPIO_PinSource5
#define KEY4_INT_EXTI_LINE         EXTI_Line5
#define KEY4_INT_EXTI_IRQ          EXTI9_5_IRQn

#define KEY4_IRQHandler            EXTI9_5_IRQHandler
void EXTI_Key_Config(void);


#endif /* __EXTI_H */
