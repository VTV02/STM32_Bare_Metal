//Where is the led connected?
//Port:A, B
//Pin:5,13
#include <stdint.h>
#define PERIPH_BASE		    0x40000000UL
#define AHB1PERIPH_OFFSET   0x00020000UL
#define AHB1PERIPH_BASE     (PERIPH_BASE+AHB1PERIPH_OFFSET)
#define GPIOA_OFFSET		(0x0000UL)
#define GPIOA_BASE			(AHB1PERIPH_BASE+GPIOA_OFFSET)
#define RCC_OFFSET			(0x00023800UL)
#define RCC_BASE      		(PERIPH_BASE+RCC_OFFSET)
#define AHB1EN_R_OFFSET		(0x30UL)
#define RCC_AHB1EN_R		(*(volatile unsigned int*)(RCC_BASE+AHB1EN_R_OFFSET))

#define GPIOAEN				(1U<<0)//shift left 1 to position 0
#define MODE_R_OFFSET		(0x00U)
#define GPIOA_MODE_R		(*(volatile unsigned int*)(GPIOA_BASE+MODE_R_OFFSET))
#define OD_R_OFFSET			(0x14UL)
#define GPIOA_OD_R			(*(volatile unsigned int*)(GPIOA_BASE+OD_R_OFFSET))
#define PIN5				(1U<<5)
#define LED_PIN				PIN5
int main(void)
{
	//ENABLE CLOCK ACCESS TO GPIOA
	RCC_AHB1EN_R |= GPIOAEN;// RCC_AHB1EN_R= 0b 0000 0000 0000 0000 0000 0000 0000 0001
	//SET PINA5 AS OUTPUT PIN bit (1u<<10), &=~(1u<<11)
	GPIOA_MODE_R|=(1U<<10);
	GPIOA_MODE_R&=~(1U<<11);
	while(1)
	{
		//set pina5 high
		GPIOA_OD_R |=LED_PIN;
	}
}




