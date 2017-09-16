#include "led.h"
#include "delay.h"
#include "sys.h"
#include "key.h"
#include "usart.h"
#include "exti.h"
#include "timer.h"
#include "UltrasonicWave.h"


 int main(void)
 {
 // SystemInit();
	delay_init(72);	          //��ʱ��ʼ��
	NVIC_Configuration();
	uart_init(9600);         //���ڳ�ʼ��
	KEY_Init();               //�����˿ڳ�ʼ��
	Timerx_Init(5000,7199);   //10Khz�ļ���Ƶ�ʣ�������5000Ϊ500ms 
	UltrasonicWave_Configuration();               //�Գ�����ģ���ʼ��

	while(1)
	{
		UltrasonicWave_StartMeasure();                //��ʼ��࣬����һ��>10us�����壬Ȼ��������صĸߵ�ƽʱ��
		delay_ms(1000);		
	}
}

