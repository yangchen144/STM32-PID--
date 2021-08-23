#include "stm32f10x.h"   
#include "./Led/bsp_led.h"
#include "./TimBase/bsp_TiMbase.h"
#include "./GeneralTim/bsp_GeneralTim.h"  
#include "./Exti/bsp_exti.h" 
#include "./usart/bsp_usart.h"
#include "./motor/motor.h"


#define SOFT_DELAY Delay(0x0FFFFF);


	
uint16_t CCR1_Val = 0;
uint16_t CCR2_Val = 0;
uint16_t CCR3_Val = 0;
uint16_t CCR4_Val = 0;
	
int x1=0,x2=0,x3=0,x4=0;	//*****************************脉冲数量记录
int n=0;									//***************************标记定时器中断

void Delay(__IO uint32_t nCount);//*************************延时函数
void pwm_set(int n1,int n2,int n3,int n4);//****************速度重设
//*******************************************************************
//********************************************************pid参数设置

//1.申明变量
 
	float Kp=5, Ki=18, Kd=0;//****************定义比例、积分、微分系数
	
	float ExpectedValue[4]={15.0,30.0,50.0,70.0};//*定义设定值（目标值）
	float err[4]={0.0,0.0,0.0,0.0};//********************每个轮子的误差
	float err_last[4]={0.0,0.0,0.0,0.0};//***********每个轮子上次的误差
  float pwm[4]={0.0,0.0,0.0,0.0};//***************************每个轮子的PWM值

	float pwm_max=7100;//************************PID计算的得到的最大PWM
  float pwm_min=0;//*****************************PID计算得到的最小PWM
	
//2.pid核心计算程序
void PID_Calculate(float actualValue,float expectedValue,int a)
	{
	  err[a] = expectedValue - actualValue;
				
		pwm[a] += Kp*(err[a] - err_last[a]) + Ki*err[a] ; 
		
		err_last[a] = err[a];
				
	  //限幅
		if(pwm[a]>pwm_max)  
		pwm[a] = pwm_max;
		else if(pwm[a]<pwm_min) 
		pwm[a] = pwm_min;	
 }

//****************************************************************over

int main(void)
{
	//初始化
	LED_GPIO_Config();
	BASIC_TIM_Init();
	GENERAL_TIM_Init();
	EXTI_Key_Config(); 
	USART_Config();
	
	motor_GPIO_init();
	
	Usart_SendString( DEBUG_USARTx,"四轮自动调速小车程序\n");
	printf("YCHEN牛逼\n\n\n\n");

	
	//****************************************************初始化按键操作
	//ExpectedValue[0]=40;
	//ExpectedValue[1]=40;
	//ExpectedValue[2]=40;
	//ExpectedValue[3]=40;
	//*******************************************************************
	
	//开始出发										
	Car_go();
	
	//进入循环，此后由定时器全权操作
	while(1)
	{
		pwm_set(pwm[0],pwm[1],pwm[2],pwm[3]);
		//pwm_set(5000,5000,5000,5000);
	}
}


void Delay(__IO uint32_t nCount) //简单的延时函数
 {	 
 for (; nCount != 0; nCount--); 
 }
 
void pwm_set(int n1,int n2,int n3,int n4)
{
		GENERAL_TIM->CCR1=n1;
		GENERAL_TIM->CCR2=n2;
		GENERAL_TIM->CCR3=n3;
		GENERAL_TIM->CCR4=n4;
}
 
 
