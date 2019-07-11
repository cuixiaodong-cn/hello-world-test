/****************************************************************************
*
* Copyright © 2015-2019 STMicroelectronics - All Rights Reserved
*
* License terms: STMicroelectronics Proprietary in accordance with licensing
* terms SLA0089 at www.st.com.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* EVALUATION ONLY – NOT FOR USE IN PRODUCTION
*****************************************************************************/
/**
 * @file    spc5_emios.h
 * @brief   eMIOS200 helper driver header.
 *
 * @addtogroup SPC5xx_eMIOS200
 * @{
 */

#ifndef _SPC5_EMIOS_H_
#define _SPC5_EMIOS_H_

#include "pwm_lld.h"
#include "icu_lld.h"

#if (LLD_USE_ICU == TRUE) || (LLD_USE_PWM == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

#define EMIOSMCR_MDIS                       (1UL << 30U)
#define EMIOSMCR_FRZ                        (1UL << 29U)
#define EMIOSMCR_GTBE                       (1UL << 28U)
#define EMIOSMCR_GPREN                      (1UL << 26U)
#define EMIOSMCR_GPRE(n)                    ((uint32_t)(n) << 8U)

#define EMIOSC_FREN                         (1UL << 31U)
#define EMIOSC_UCPRE(n)                     ((uint32_t)(n) << 26U)
#define EMIOSC_UCPREN                       (1UL << 25U)
#define EMIOSC_DMA                          (1UL << 24U)
#define EMIOSC_IF(n)                        ((uint32_t)(n) << 19U)
#define EMIOSC_FCK                          (1UL << 18U)
#define EMIOSC_FEN                          (1UL << 17U)
#define EMIOSC_FORCMA                       (1UL << 13U)
#define EMIOSC_FORCMB                       (1UL << 12U)
#define EMIOSC_BSL(n)                       ((uint32_t)(n) << 9U)
#define EMIOSC_EDSEL                        (1UL << 8U)
#define EMIOSC_EDPOL                        (1UL << 7U)
#define EMIOSC_MODE(n)                      ((uint32_t)(n) << 0U)

#define EMIOS_BSL_COUNTER_BUS_A             0UL
#define EMIOS_BSL_COUNTER_BUS_2             1UL
#define EMIOS_BSL_INTERNAL_COUNTER          3UL

#define EMIOS_CCR_MODE_GPIO_IN              0U
#define EMIOS_CCR_MODE_GPIO_OUT             1U
#define EMIOS_CCR_MODE_SAIC                 2U
#define EMIOS_CCR_MODE_SAOC                 3U
#define EMIOS_CCR_MODE_IPWM                 4U
#define EMIOS_CCR_MODE_IPM                  5U
#define EMIOS_CCR_MODE_DAOC_B_MATCH         6U
#define EMIOS_CCR_MODE_DAOC_BOTH_MATCH      7U
#define EMIOS_CCR_MODE_MC_CMS               16U
#define EMIOS_CCR_MODE_MC_CME               17U
#define EMIOS_CCR_MODE_MC_UP_DOWN           18U
#define EMIOS_CCR_MODE_OPWMT                38U
#define EMIOS_CCR_MODE_MCB_UP               80U
#define EMIOS_CCR_MODE_MCB_UP_DOWN          84U
#define EMIOS_CCR_MODE_OPWFMB               88U
#define EMIOS_CCR_MODE_OPWMCB_TE            92U
#define EMIOS_CCR_MODE_OPWMCB_LE            93U
#define EMIOS_CCR_MODE_OPWMB                96U

#define EMIOSS_OVR                          (1UL << 31U)
#define EMIOSS_OVRC                         (1UL << 31U)
#define EMIOSS_OVFL                         (1UL << 15U)
#define EMIOSS_OVFLC                        (1UL << 15U)
#define EMIOSS_FLAG                         (1UL << 0U)
#define EMIOSS_FLAGC                        (1UL << 0U)

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/**
 * @brief   eMIOS global prescaler value.
 */
#if !defined(SPC5_EMIOS_GPRE_VALUE) || defined(__DOXYGEN__)
#define SPC5_EMIOS_GPRE_VALUE               20UL
#endif

/* Check on the SPC5_EMIOS_GPRE_VALUE.*/
#if (SPC5_EMIOS_GPRE_VALUE < 1U) || (SPC5_EMIOS_GPRE_VALUE > 256U)
#error "invalid SPC5_EMIOS_GPRE_VALUE value specified"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

void reset_emios_active_channels(void);
uint32_t get_emios_active_channels(void);
void increase_emios_active_channels(void);
void decrease_emios_active_channels(void);
#if (LLD_USE_ICU == TRUE)
void icu_active_emios_clock(ICUDriver *icup);
#endif
#if (LLD_USE_PWM == TRUE)
void pwm_active_emios_clock(PWMDriver *pwmp);
#endif
void deactive_emios_clock(void);

#endif /* LLD_USE_ICU || LLD_USE_PWM */

#endif /* _SPC5_EMIOS_H_ */

/** @} */
