/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
#include "./TimBase/bsp_TiMbase.h"
#include "./Led/bsp_led.h"
#include "./Exti/bsp_exti.h" 
#include "./usart/bsp_usart.h"


extern int x1,x2,x3,x4;
extern int n;

//extern float err_prev;//定义前一个的偏差值

extern float Kp, Ki, Kd;//定义比例、积分、微分系数

extern float pwm_max;
extern float pwm_min;

	
extern float ExpectedValue[4];//定义设定值（目标值）

extern float pwm[4];

extern float err[4];

extern float err_last[4];

extern void PID_Calculate(float actualValue,float expectedValue,int a);

/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}

void  BASIC_TIM_IRQHandler (void)
{
	if ( TIM_GetITStatus( BASIC_TIM, TIM_IT_Update) != RESET ) 
	{	

		n++;
		printf("n：%d\n",n);
		printf("x1：%d\n",x1);
		printf("x2：%d\n",x2);
		printf("x3：%d\n",x3);
		printf("x4：%d\n",x4);
		
		PID_Calculate(x1,ExpectedValue[0],0);
		x1=0;
		PID_Calculate(x2,ExpectedValue[1],1);
		x2=0;
		PID_Calculate(x3,ExpectedValue[2],2);
		x3=0;
		PID_Calculate(x4,ExpectedValue[3],3);
		x4=0;
		
		printf("pwm1=：%f\n",pwm[0]);
		printf("pwm2=：%f\n",pwm[1]);
		printf("pwm3=：%f\n",pwm[2]);
		printf("pwm4=：%f\n",pwm[3]);
		
		TIM_ClearITPendingBit(BASIC_TIM , TIM_FLAG_Update);  
	}		 	
}

void KEY1_IRQHandler(void)
{ 
	if(EXTI_GetITStatus(KEY1_INT_EXTI_LINE) != RESET)//确保是否产生了EXTI Line中断 
	{
		x1++;	  
		EXTI_ClearITPendingBit(KEY1_INT_EXTI_LINE);  //清除中断标志位   
	}  
}

void KEY2_IRQHandler(void)
{
	if(EXTI_GetITStatus(KEY2_INT_EXTI_LINE) != RESET) //确保是否产生了EXTI Line中断
	{
		x2++; 
		EXTI_ClearITPendingBit(KEY2_INT_EXTI_LINE);  //清除中断标志位   
	}  
}
void KEY3_IRQHandler(void)
{ 
	if(EXTI_GetITStatus(KEY3_INT_EXTI_LINE) != RESET) //确保是否产生了EXTI Line中断
	{
		x3++;   
		EXTI_ClearITPendingBit(KEY3_INT_EXTI_LINE);   //清除中断标志位  
	}  
}
void KEY4_IRQHandler(void)
{
	if(EXTI_GetITStatus(KEY4_INT_EXTI_LINE) != RESET) //确保是否产生了EXTI Line中断
	{
		x4++;   
		EXTI_ClearITPendingBit(KEY4_INT_EXTI_LINE);   //清除中断标志位  
	}   	  
}

void DEBUG_USART_IRQHandler(void)
{
  uint8_t ucTemp;
	if(USART_GetITStatus(DEBUG_USARTx,USART_IT_RXNE)!=RESET)
	{		
		ucTemp = USART_ReceiveData(DEBUG_USARTx);
    USART_SendData(DEBUG_USARTx,ucTemp);    
	}	 
}
/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
