#ifndef __GPIO_LIB_H
#define __GPIO_LIB_H

#include "GPIO_driver.h"

#define GPIO_PIN_0  (uint16_t)(0x0001)  // 0b0000 0000 0000 0001
#define GPIO_PIN_1  (uint16_t)(0x0002)  // 0b0000 0000 0000 0010
#define GPIO_PIN_2  (uint16_t)(0x0004)  // 0b0000 0000 0000 0100
#define GPIO_PIN_3  (uint16_t)(0x0008)  // 0b0000 0000 0000 1000

#define GPIO_PIN_4  (uint16_t)(0x0010)  // 0b0000 0000 0001 0000
#define GPIO_PIN_5  (uint16_t)(0x0020)  // 0b0000 0000 0010 0000
#define GPIO_PIN_6  (uint16_t)(0x0040)  // 0b0000 0000 0100 0000
#define GPIO_PIN_7  (uint16_t)(0x0080)  // 0b0000 0000 1000 0000

#define GPIO_PIN_8  (uint16_t)(0x0100)  // 0b0000 0000 0001 0000
#define GPIO_PIN_9  (uint16_t)(0x0200)  // 0b0000 0000 0010 0000
#define GPIO_PIN_10 (uint16_t)(0x0400)  // 0b0000 0000 0100 0000
#define GPIO_PIN_11 (uint16_t)(0x0800)  // 0b0000 0000 1000 0000

#define GPIO_PIN_12  (uint16_t)(0x1000)  // 0b0000 0000 0000 0001
#define GPIO_PIN_13  (uint16_t)(0x2000)  // 0b0000 0000 0000 0010
#define GPIO_PIN_14  (uint16_t)(0x4000)  // 0b0000 0000 0000 0100
#define GPIO_PIN_15  (uint16_t)(0x8000)  // 0b0000 0000 0000 1000

#define GPIO_PIN_ALL (uint16_t)(0xFFFF)  // 0b1111 1111 1111 1111 

#define GPIO_MODE_INPUT   0x00U
#define GPIO_MODE_OUTPUT   0x01U
#define GPIO_MODE_ALTERNAT_FUNCTION  0x02U

#define GPIO_NO_PULL 0x00U
#define GPIO_PULL_UP  0x01U
#define GPIO_PULL_DOWN 0x2U



typedef struct {
	uint32_t Pin;
  uint32_t Mode;
	uint32_t Pull;
	uint32_t Alternate;
	uint32_t Speed;

}GPIO_InitTypeDef;

typedef enum {
GPIO_PIN_RESET=0,
GPIO_PIN_SET
}GPIO_PinState;

void GPIO_Init(GPIO_TypeDef * GPIOx , GPIO_InitTypeDef *GPIO_Init );
GPIO_PinState  GPIO_readPin(GPIO_TypeDef *GPIOx , uint16_t pin);
void GPIO_writePin(GPIO_TypeDef * GPIOx, uint16_t pin,GPIO_PinState pinState);
void GPIO_togglePin(GPIO_TypeDef *GPIOx, uint16_t pin );

void __RCC_GPIOA_CLK_ENABLE (void);

void __RCC_GPIOB_CLK_ENABLE (void);

void __RCC_GPIOC_CLK_ENABLE (void);

void __RCC_GPIOD_CLK_ENABLE (void);

void __RCC_GPIOE_CLK_ENABLE (void);

void __RCC_GPIOF_CLK_ENABLE (void);

void __RCC_GPIOG_CLK_ENABLE (void);

void __RCC_GPIOH_CLK_ENABLE (void);




#endif