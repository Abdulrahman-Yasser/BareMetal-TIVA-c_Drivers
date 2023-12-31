/**********************************************************************************************************************

  *  FILE DESCRIPTION
  *  -------------------------------------------------------------------------------------------------------------------
  *         File:  SysTick.h
  *       Module:  SysTick Driver
  *
  *  Description:  the file contains the header file of the SysTick module
  *  
  *********************************************************************************************************************/
#ifndef SYSTICK_H
#define SYSTICK_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "SysTick_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern const SysTick_Config My_SysTick ;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void SysTick_Init(void);

void SysTick_Start(void);

void SysTick_Stop(void);

void SysTick_Reload_ms(SysTick_ReLoadType ReLoad);

extern void SysTick_Handler(void);

void SysTick_SetCallBack(void (*PointerToFunction) (void));


#endif
