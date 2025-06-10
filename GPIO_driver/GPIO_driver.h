
#ifndef __GPIO_DRIVER_H
#define __GPIO_DRIVER_H

#include "stdint.h" 

#define PERIPH_BASE           0x40000000
#define AHP1PERIPH_BASE      (PERIPH_BASE + 0x20000U)
#define RCC_BASE             (AHP1PERIPH_BASE + 0x3800U)
#define GPIOA_BASE            (AHP1PERIPH_BASE +0x00U)
#define GPIOB_BASE           (AHP1PERIPH_BASE +0x400U )
#define GPIOC_BASE           (AHP1PERIPH_BASE + 0x800U)
#define GPIOD_BASE           (AHP1PERIPH_BASE + 0xC00U)
#define GPIOE_BASE           (AHP1PERIPH_BASE + 0x1000U )
#define GPIOF_BASE           (AHP1PERIPH_BASE + 1400U )
#define GPIOG_BASE           (AHP1PERIPH_BASE + 0x1800U)
#define GPIOH_BASE           (AHP1PERIPH_BASE + 0xC00U)

#define __IO   volatile
	
typedef struct{
__IO  uint32_t  MODER;
__IO	uint32_t  OTYPER;
__IO  uint32_t  OSPEEDER;
__IO  uint32_t  PUPDR;
__IO  uint32_t  IDR;
__IO  uint32_t  ODR;
__IO  uint32_t  BSRR;
__IO  uint32_t  LCKR;
__IO  uint32_t  AFR[2];
	
}GPIO_TypeDef;
	
typedef struct {
__IO uint32_t CR;
__IO uint32_t PLLCFGR;
__IO uint32_t CFGR;
__IO uint32_t CIR;	
__IO uint32_t AHB1RSTR;
__IO uint32_t AHB2RSTR;
__IO uint32_t AHB3RSTR;
uint32_t Reserved0;
__IO uint32_t APB1RSTR;
__IO uint32_t APB2RSTR;
 uint32_t Reserved1;
 uint32_t Reserved2;
__IO uint32_t AHB1ENR;
__IO uint32_t AHB2ENR;
__IO uint32_t AHB3ENR;
	uint32_t Reserved3;
__IO uint32_t APB1ENR;
__IO uint32_t APB2ENR;
 uint32_t	 Reserved4;
 uint32_t  Reserved5;
__IO uint32_t AHB1LPENR;
__IO uint32_t AHB2LPENR;
__IO uint32_t AHB3LPENR;
uint32_t  Reserved6;
__IO uint32_t APB1LPENR;
__IO uint32_t APB2LPENR;
 uint32_t Reserved7;
 uint32_t  Reserved8;
	__IO uint32_t BDCR;
	__IO uint32_t CSR;
	__IO uint32_t Reserved9;
uint32_t Reserved10;
	__IO uint32_t SSCGR;
	__IO uint32_t PLLI2SCFGR;
	__IO uint32_t PLLSAICFGR;
	__IO uint32_t DCKCFGR;
	__IO uint32_t CKGATENR;
	__IO uint32_t DCKCFGR2;
}RCC_TypeDef;


#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE ((GPIO_TypeDef *)GPIOE_BASE)
#define GPIOF ((GPIO_TypeDef *)GPIOF_BASE)
#define GPIOG ((GPIO_TypeDef *)GPIOG_BASE)
#define GPIOH ((GPIO_TypeDef *)GPIOH_BASE)
#define RCC   ((RCC_TypeDef  *)RCC_BASE)


//enable rcc for port X 
#define GPIOA_EN (1<<0)
#define GPIOB_EN (1<<1)
#define GPIOC_EN (1<<2)
#define GPIOD_EN (1<<3)
#define GPIOE_EN (1<<4)
#define GPIOF_EN (1<<5)
#define GPIOG_EN (1<<6)
#define GPIOH_EN (1<<7)


#define LED_PIN  (1<<5)  //ODR register pin 5 

//MODER register  -->  01: General purpose output mode
#define MODER_PIN_5   (1<<10)
  
	//1 first enable clock for portA 
	//2 chose the mode // for this case we will chose output mode
  //3 give value for ODR register 	
	#endif
	