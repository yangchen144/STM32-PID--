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
	
int x1=0,x2=0,x3=0,x4=0;	//*****************************����������¼
int n=0;									//***************************��Ƕ�ʱ���ж�

void Delay(__IO uint32_t nCount);//*************************��ʱ����
void pwm_set(int n1,int n2,int n3,int n4);//****************�ٶ�����
//*******************************************************************
//********************************************************pid��������

//1.��������
 
	float Kp=5, Ki=18, Kd=0;//****************������������֡�΢��ϵ��
	
	float ExpectedValue[4]={15.0,30.0,50.0,70.0};//*�����趨ֵ��Ŀ��ֵ��
	float err[4]={0.0,0.0,0.0,0.0};//********************ÿ�����ӵ����
	float err_last[4]={0.0,0.0,0.0,0.0};//***********ÿ�������ϴε����
  float pwm[4]={0.0,0.0,0.0,0.0};//***************************ÿ�����ӵ�PWMֵ

	float pwm_max=7100;//************************PID����ĵõ������PWM
  float pwm_min=0;//*****************************PID����õ�����СPWM
	
//2.pid���ļ������
void PID_Calculate(float actualValue,float expectedValue,int a)
	{
	  err[a] = expectedValue - actualValue;
				
		pwm[a] += Kp*(err[a] - err_last[a]) + Ki*err[a] ; 
		
		err_last[a] = err[a];
				
	  //�޷�
		if(pwm[a]>pwm_max)  
		pwm[a] = pwm_max;
		else if(pwm[a]<pwm_min) 
		pwm[a] = pwm_min;	
 }

//****************************************************************over

int main(void)
{
	//��ʼ��
	LED_GPIO_Config();
	BASIC_TIM_Init();
	GENERAL_TIM_Init();
	EXTI_Key_Config(); 
	USART_Config();
	
	motor_GPIO_init();
	
	Usart_SendString( DEBUG_USARTx,"�����Զ�����С������\n");
	printf("YCHENţ��\n\n\n\n");

	
	//****************************************************��ʼ����������
	//ExpectedValue[0]=40;
	//ExpectedValue[1]=40;
	//ExpectedValue[2]=40;
	//ExpectedValue[3]=40;
	//*******************************************************************
	
	//��ʼ����										
	Car_go();
	
	//����ѭ�����˺��ɶ�ʱ��ȫȨ����
	while(1)
	{
		pwm_set(pwm[0],pwm[1],pwm[2],pwm[3]);
		//pwm_set(5000,5000,5000,5000);
	}
}


void Delay(__IO uint32_t nCount) //�򵥵���ʱ����
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
 
 
