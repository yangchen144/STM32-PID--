#include "./motor/motor.h"  


void motor_GPIO_init(void)
{
	/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*开启GPIO外设时钟*/
		RCC_APB2PeriphClockCmd( MOTOR1A_GPIO_CLK | MOTOR1B_GPIO_CLK | MOTOR2A_GPIO_CLK | MOTOR2B_GPIO_CLK | MOTOR3A_GPIO_CLK | MOTOR3B_GPIO_CLK | MOTOR4A_GPIO_CLK | MOTOR4B_GPIO_CLK, ENABLE);
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = MOTOR1A_GPIO_PIN;	

		/*设置引脚模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*设置引脚速率为50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*调用库函数，初始化GPIO*/
		GPIO_Init(MOTOR1A_GPIO_PORT, &GPIO_InitStructure);		
	
		GPIO_InitStructure.GPIO_Pin = MOTOR1B_GPIO_PIN;	
		GPIO_Init(MOTOR1B_GPIO_PORT, &GPIO_InitStructure);	
	
		GPIO_InitStructure.GPIO_Pin = MOTOR2A_GPIO_PIN;
		GPIO_Init(MOTOR2A_GPIO_PORT, &GPIO_InitStructure);

		GPIO_InitStructure.GPIO_Pin = MOTOR2B_GPIO_PIN;
		GPIO_Init(MOTOR2B_GPIO_PORT, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = MOTOR3A_GPIO_PIN;
		GPIO_Init(MOTOR3A_GPIO_PORT, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = MOTOR3B_GPIO_PIN;
		GPIO_Init(MOTOR3B_GPIO_PORT, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = MOTOR4A_GPIO_PIN;
		GPIO_Init(MOTOR4A_GPIO_PORT, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = MOTOR4B_GPIO_PIN;
		GPIO_Init(MOTOR4B_GPIO_PORT, &GPIO_InitStructure);
		
		
		GPIO_SetBits(MOTOR1A_GPIO_PORT, MOTOR1A_GPIO_PIN);
		GPIO_ResetBits(MOTOR1B_GPIO_PORT, MOTOR1B_GPIO_PIN);
		GPIO_SetBits(MOTOR2A_GPIO_PORT, MOTOR2A_GPIO_PIN);
		GPIO_ResetBits(MOTOR2B_GPIO_PORT, MOTOR2B_GPIO_PIN);
		GPIO_SetBits(MOTOR3A_GPIO_PORT, MOTOR3A_GPIO_PIN);
		GPIO_ResetBits(MOTOR3B_GPIO_PORT, MOTOR3B_GPIO_PIN);
		GPIO_SetBits(MOTOR4A_GPIO_PORT, MOTOR4A_GPIO_PIN);
		GPIO_ResetBits(MOTOR4B_GPIO_PORT, MOTOR4B_GPIO_PIN);
}
void M1_go(void)
{
	GPIO_SetBits(MOTOR1A_GPIO_PORT, MOTOR1A_GPIO_PIN);
	GPIO_ResetBits(MOTOR1B_GPIO_PORT, MOTOR1B_GPIO_PIN);
}
void M2_go(void)
{
	GPIO_SetBits(MOTOR2A_GPIO_PORT, MOTOR2A_GPIO_PIN);
	GPIO_ResetBits(MOTOR2B_GPIO_PORT, MOTOR2B_GPIO_PIN);
}
void M3_go(void)
{
	GPIO_SetBits(MOTOR3A_GPIO_PORT, MOTOR3A_GPIO_PIN);
	GPIO_ResetBits(MOTOR3B_GPIO_PORT, MOTOR3B_GPIO_PIN);
}
void M4_go(void)
{
	GPIO_SetBits(MOTOR4A_GPIO_PORT, MOTOR4A_GPIO_PIN);
	GPIO_ResetBits(MOTOR4B_GPIO_PORT, MOTOR4B_GPIO_PIN);
}


void M1_back(void)
{
	GPIO_ResetBits(MOTOR1A_GPIO_PORT, MOTOR1A_GPIO_PIN);
	GPIO_SetBits(MOTOR1B_GPIO_PORT, MOTOR1B_GPIO_PIN);
}
void M2_back(void)
{
	GPIO_ResetBits(MOTOR2A_GPIO_PORT, MOTOR2A_GPIO_PIN);
	GPIO_SetBits(MOTOR2B_GPIO_PORT, MOTOR2B_GPIO_PIN);
}
void M3_back(void)
{
	GPIO_ResetBits(MOTOR3A_GPIO_PORT, MOTOR3A_GPIO_PIN);
	GPIO_SetBits(MOTOR3B_GPIO_PORT, MOTOR3B_GPIO_PIN);
}
void M4_back(void)
{
	GPIO_ResetBits(MOTOR4A_GPIO_PORT, MOTOR4A_GPIO_PIN);
	GPIO_SetBits(MOTOR4B_GPIO_PORT, MOTOR4B_GPIO_PIN);
}


void Car_go(void)
{
	M1_go();
	M2_go();
	M3_go();
	M4_go();
}
void Car_back(void)
{
	M1_back();
	M2_back();
	M3_back();
	M4_back();
}
