
#include "stdint.h"
#include "GPIO_lib.h"

int a=0;
int main (void ){
 
		
GPIO_InitTypeDef GPIOInit;
GPIOInit.Pin=GPIO_PIN_5;
GPIOInit.Mode=GPIO_MODE_OUTPUT;
GPIOInit.Pull=GPIO_PULL_UP;
		
__RCC_GPIOA_CLK_ENABLE();
GPIO_Init( GPIOA ,& GPIOInit);
				
while (1){
	if( GPIO_readPin(GPIOA,GPIO_PIN_5)==GPIO_PIN_SET){
	 GPIO_writePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
	for(int i=0; i<900000; i++){}
		GPIO_writePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
	  }
	return 0; 
	}
}