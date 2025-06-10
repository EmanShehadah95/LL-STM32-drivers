#include "GPIO_lib.h"

#define GPIO_PIN_NIMBER    16U
#define GPIO_MODER_MODE0   0x3U<<0
#define GPIO_MODE          0x03U
#define GPIO_PUPDR_PUPDR0  0x3U<<0


void GPIO_Init(GPIO_TypeDef *GPIOx , GPIO_InitTypeDef *GPIO_Init ){

	uint32_t position ;
	uint32_t temp   =0x00U;
	uint32_t ioposition =0x00U;
	uint32_t iocurrent=0x00U;
for (position=0U;position<GPIO_PIN_NIMBER ;position++){

 ioposition =  0x01U << position ;
 iocurrent = ioposition & GPIO_Init->Pin;
}
 if (iocurrent==ioposition){
	 
 temp=GPIOx->MODER; //read the value of the registr before modifying and save it in temp variable 
 temp &= ~( GPIO_MODER_MODE0 << (position*2U));// clear the specific pins ;	 
 temp |= (GPIO_Init->Mode & GPIO_MODE)<<( position * 2U); 
 GPIOx->MODER=temp;
	 
	 
 temp=GPIOx->PUPDR;
 temp &=~(GPIO_PUPDR_PUPDR0) << (position * 2U);
 temp |= (GPIO_Init->Pull)   << (position * 2U);
 GPIOx->PUPDR=temp;
 }
	
	

}
GPIO_PinState  GPIO_readPin(GPIO_TypeDef *GPIOx , uint16_t pin){
GPIO_PinState pinState;
	if ((GPIOx->IDR & pin)!= GPIO_PIN_RESET) {
		pinState=GPIO_PIN_SET;
	}
	else { pinState=GPIO_PIN_RESET;
	}
	return pinState;
}
void GPIO_writePin(GPIO_TypeDef * GPIOx, uint16_t pin,GPIO_PinState pinState){
if(pinState == GPIO_PIN_SET){
GPIOx->BSRR |= pin;
}
else {
GPIOx->BSRR |= (uint32_t) pin << 16;
}

}
void GPIO_togglePin(GPIO_TypeDef *GPIOx, uint16_t pin ){
GPIOx->ODR ^= pin ;
}

void __RCC_GPIOA_CLK_ENABLE (void){RCC->AHB1ENR |=GPIOA_EN;}

void __RCC_GPIOB_CLK_ENABLE (void){RCC->AHB1ENR|=GPIOB_EN;}

void __RCC_GPIOC_CLK_ENABLE (void){RCC->AHB1ENR|=GPIOC_EN;}

void __RCC_GPIOD_CLK_ENABLE (void){RCC->AHB1ENR|=GPIOD_EN;}

void __RCC_GPIOE_CLK_ENABLE (void){RCC->AHB1ENR|=GPIOE_EN;}

void __RCC_GPIOF_CLK_ENABLE (void){RCC->AHB1ENR|=GPIOF_EN;}

void __RCC_GPIOG_CLK_ENABLE (void){RCC->AHB1ENR|=GPIOG_EN;}

void __RCC_GPIOH_CLK_ENABLE (void){RCC->AHB1ENR|=GPIOH_EN;}
