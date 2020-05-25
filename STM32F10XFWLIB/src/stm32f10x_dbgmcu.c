/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : stm32f10x_dbgmcu.c
* Author             : MCD Application Team
* Version            : V2.0
* Date               : 05/23/2008
* Description        : This file provides all the DBGMCU firmware functions.
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
* FOR MORE INFORMATION PLEASE CAREFULLY READ THE LICENSE AGREEMENT FILE LOCATED 
* IN THE ROOT DIRECTORY OF THIS FIRMWARE PACKAGE.
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_dbgmcu.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define IDCODE_DEVID_Mask    ((u32)0x00000FFF)

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : DBGMCU_GetREVID
* Description    : Returns the device revision identifier.
* Input          : None
* Output         : None
* Return         : Device revision identifier
*******************************************************************************/
u32 DBGMCU_GetREVID(void)
{
   return(DBGMCU->IDCODE >> 16);
}

/*******************************************************************************
* Function Name  : DBGMCU_GetDEVID
* Description    : Returns the device identifier.
* Input          : None
* Output         : None
* Return         : Device identifier
*******************************************************************************/
u32 DBGMCU_GetDEVID(void)
{
   return(DBGMCU->IDCODE & IDCODE_DEVID_Mask);
}

/*******************************************************************************
*��������:DBGMCU_Config
*����:����ָ������Χ�͵͹���ģʽ����Ϊ
*����Ƭ���ڵ���ģʽ��
*����:- DBGMCU_Periph:ָ���ܱߺ͵͹���ģʽ��
*��������������κ���ϵ�����ֵ:
* - DBGMCU_SLEEP:�õ�����������˯��ģʽ
* - DBGMCU_STOP:�õ�����������ֹͣģʽ
* - DBGMCU_STANDBY:�õ����������ڴ���ģʽ
* - DBGMCU_IWDG_STOP:����IWDGֹͣ��������ֹͣ
* - DBGMCU_WWDG_STOP:����WWDGֹͣ��������ֹͣ
* - DBGMCU_TIM1_STOP:TIM1������ֹͣ��������ֹͣ
* - DBGMCU_TIM2_STOP:TIM2������ֹͣ��������ֹͣ
* - DBGMCU_TIM3_STOP:TIM3������ֹͣ��������ֹͣ
* - DBGMCU_TIM4_STOP:TIM4������ֹͣ��������ֹͣ
* - DBGMCU_CAN_STOP:���Կ���ֹͣ��������ֹͣ
* - DBGMCU_I2C1_SMBUS_TIMEOUT:I2C1 SMBUS��ʱ״ֹ̬ͣ
*��������ֹͣ
* - DBGMCU_I2C2_SMBUS_TIMEOUT:I2C2 SMBUS��ʱ״ֹ̬ͣ
*��������ֹͣ
* - DBGMCU_TIM5_STOP:TIM5������ֹͣ��������ֹͣ
* - DBGMCU_TIM6_STOP:TIM6������ֹͣ��������ֹͣ
* - DBGMCU_TIM7_STOP:TIM7������ֹͣ��������ֹͣ
* - DBGMCU_TIM8_STOP:TIM8������ֹͣ��������ֹͣ
* - NewState:�µĹ���ָ������Χ�ڵ���ģʽ��
*�����������:���û���á�
*���:û��
*����:��
*******************************************************************************/
void DBGMCU_Config(u32 DBGMCU_Periph, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_DBGMCU_PERIPH(DBGMCU_Periph));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    DBGMCU->CR |= DBGMCU_Periph;
  }
  else
  {
    DBGMCU->CR &= ~DBGMCU_Periph;
  }
}

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/
