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
 * @file    icu_lld.h
 * @brief   SPC5xx ICU low level driver header.
 *
 * @addtogroup ICU
 * @{
 */

#ifndef _ICU_LLD_H_
#define _ICU_LLD_H_

#include "spc5_lld.h"
#include "lldconf.h"

#if (LLD_USE_ICU == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   ICUD1 driver enable switch.
 * @details If set to @p TRUE the support for ICUD1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS_CH0) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS_CH0              FALSE
#endif

/**
 * @brief   ICUD2 driver enable switch.
 * @details If set to @p TRUE the support for ICUD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS_CH1) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS_CH1              FALSE
#endif

/**
 * @brief   ICUD3 driver enable switch.
 * @details If set to @p TRUE the support for ICUD3 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS_CH2) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS_CH2              FALSE
#endif

/**
 * @brief   ICUD4 driver enable switch.
 * @details If set to @p TRUE the support for ICUD4 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS_CH3) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS_CH3              FALSE
#endif

/**
 * @brief   ICUD5 driver enable switch.
 * @details If set to @p TRUE the support for ICUD5 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS_CH4) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS_CH4              FALSE
#endif

/**
 * @brief   ICUD6 driver enable switch.
 * @details If set to @p TRUE the support for ICUD6 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS_CH5) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS_CH5              FALSE
#endif

/**
 * @brief   ICUD7 driver enable switch.
 * @details If set to @p TRUE the support for ICUD7 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS_CH6) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS_CH6              FALSE
#endif

/**
 * @brief   ICUD8 driver enable switch.
 * @details If set to @p TRUE the support for ICUD8 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS_CH7) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS_CH7              FALSE
#endif

/**
 * @brief   ICUD9 driver enable switch.
 * @details If set to @p TRUE the support for ICUD9 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS_CH8) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS_CH8              FALSE
#endif

/**
 * @brief   ICUD10 driver enable switch.
 * @details If set to @p TRUE the support for ICUD10 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS_CH9) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS_CH9              FALSE
#endif

/**
 * @brief   ICUD11 driver enable switch.
 * @details If set to @p TRUE the support for ICUD11 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS_CH10) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS_CH10             FALSE
#endif

/**
 * @brief   ICUD12 driver enable switch.
 * @details If set to @p TRUE the support for ICUD12 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS_CH11) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS_CH11             FALSE
#endif

/**
 * @brief   ICUD13 driver enable switch.
 * @details If set to @p TRUE the support for ICUD13 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS_CH12) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS_CH12             FALSE
#endif

/**
 * @brief   ICUD14 driver enable switch.
 * @details If set to @p TRUE the support for ICUD14 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS_CH13) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS_CH13             FALSE
#endif

/**
 * @brief   ICUD15 driver enable switch.
 * @details If set to @p TRUE the support for ICUD15 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS_CH14) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS_CH14             FALSE
#endif

/**
 * @brief   ICUD16 driver enable switch.
 * @details If set to @p TRUE the support for ICUD16 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS_CH15) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS_CH15             FALSE
#endif

/**
 * @brief   ICUD17 driver enable switch.
 * @details If set to @p TRUE the support for ICUD17 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS_CH16) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS_CH16             FALSE
#endif

/**
 * @brief   ICUD18 driver enable switch.
 * @details If set to @p TRUE the support for ICUD18 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS_CH17) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS_CH17             FALSE
#endif

/**
 * @brief   ICUD19 driver enable switch.
 * @details If set to @p TRUE the support for ICUD19 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS_CH18) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS_CH18             FALSE
#endif

/**
 * @brief   ICUD20 driver enable switch.
 * @details If set to @p TRUE the support for ICUD20 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS_CH19) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS_CH19             FALSE
#endif

/**
 * @brief   ICUD21 driver enable switch.
 * @details If set to @p TRUE the support for ICUD21 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS_CH20) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS_CH20             FALSE
#endif

/**
 * @brief   ICUD22 driver enable switch.
 * @details If set to @p TRUE the support for ICUD22 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS_CH21) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS_CH21             FALSE
#endif

/**
 * @brief   ICUD23 driver enable switch.
 * @details If set to @p TRUE the support for ICUD23 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS_CH22) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS_CH22             FALSE
#endif

/**
 * @brief   ICUD24 driver enable switch.
 * @details If set to @p TRUE the support for ICUD24 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS_CH23) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS_CH23             FALSE
#endif

/**
 * @brief   ICUD1 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F0_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F0_PRIORITY         7
#endif

/**
 * @brief   ICUD2 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F1_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F1_PRIORITY         7
#endif

/**
 * @brief   ICUD3 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F2_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F2_PRIORITY         7
#endif

/**
 * @brief   ICUD4 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F3_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F3_PRIORITY         7
#endif

/**
 * @brief   ICUD5 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F4_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F4_PRIORITY         7
#endif

/**
 * @brief   ICUD6 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F5_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F5_PRIORITY         7
#endif

/**
 * @brief   ICUD7 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F6_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F6_PRIORITY         7
#endif

/**
 * @brief   ICUD8 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F7_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F7_PRIORITY         7
#endif

/**
 * @brief   ICUD9 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F8_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F8_PRIORITY         7
#endif

/**
 * @brief   ICUD10 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F9_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F9_PRIORITY         7
#endif

/**
 * @brief   ICUD11 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F10_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F10_PRIORITY        7
#endif

/**
 * @brief   ICUD12 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F11_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F11_PRIORITY        7
#endif

/**
 * @brief   ICUD13 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F12_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F12_PRIORITY        7
#endif

/**
 * @brief   ICUD14 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F13_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F13_PRIORITY        7
#endif

/**
 * @brief   ICUD15 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F14_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F14_PRIORITY        7
#endif

/**
 * @brief   ICUD16 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F15_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F15_PRIORITY        7
#endif

/**
 * @brief   ICUD17 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F16_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F16_PRIORITY        7
#endif

/**
 * @brief   ICUD18 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F17_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F17_PRIORITY        7
#endif

/**
 * @brief   ICUD19 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F18_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F18_PRIORITY        7
#endif

/**
 * @brief   ICUD20 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F19_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F19_PRIORITY        7
#endif

/**
 * @brief   ICUD21 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F20_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F20_PRIORITY        7
#endif

/**
 * @brief   ICUD22 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F21_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F21_PRIORITY        7
#endif

/**
 * @brief   ICUD23 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F22_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F22_PRIORITY        7
#endif

/**
 * @brief   ICUD24 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F23_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F23_PRIORITY        7
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if (SPC5_HAS_EMIOS == FALSE)
#error "EMIOS not present in the selected device"
#endif

#if (SPC5_ICU_USE_EMIOS_CH0  == TRUE) || (SPC5_ICU_USE_EMIOS_CH1  == TRUE) || \
    (SPC5_ICU_USE_EMIOS_CH2  == TRUE) || (SPC5_ICU_USE_EMIOS_CH3  == TRUE) || \
    (SPC5_ICU_USE_EMIOS_CH4  == TRUE) || (SPC5_ICU_USE_EMIOS_CH5  == TRUE) || \
    (SPC5_ICU_USE_EMIOS_CH6  == TRUE) || (SPC5_ICU_USE_EMIOS_CH7  == TRUE) || \
    (SPC5_ICU_USE_EMIOS_CH8  == TRUE) || (SPC5_ICU_USE_EMIOS_CH9  == TRUE) || \
    (SPC5_ICU_USE_EMIOS_CH10 == TRUE) || (SPC5_ICU_USE_EMIOS_CH11 == TRUE) || \
    (SPC5_ICU_USE_EMIOS_CH12 == TRUE) || (SPC5_ICU_USE_EMIOS_CH13 == TRUE) || \
    (SPC5_ICU_USE_EMIOS_CH14 == TRUE) || (SPC5_ICU_USE_EMIOS_CH15 == TRUE) || \
    (SPC5_ICU_USE_EMIOS_CH16 == TRUE) || (SPC5_ICU_USE_EMIOS_CH17 == TRUE) || \
    (SPC5_ICU_USE_EMIOS_CH18 == TRUE) || (SPC5_ICU_USE_EMIOS_CH19 == TRUE) || \
    (SPC5_ICU_USE_EMIOS_CH20 == TRUE) || (SPC5_ICU_USE_EMIOS_CH21 == TRUE) || \
    (SPC5_ICU_USE_EMIOS_CH22 == TRUE) || (SPC5_ICU_USE_EMIOS_CH23 == TRUE)
#define SPC5_ICU_USE_EMIOS                  TRUE
#else
#define SPC5_ICU_USE_EMIOS                  FALSE
#endif

#if (SPC5_ICU_USE_EMIOS == FALSE)
#error "ICU driver activated but no Channels assigned"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of a structure representing an ICU driver.
 */
typedef struct ICUDriver ICUDriver;

/**
 * @brief   ICU notification callback type.
 *
 * @param[in] icup      pointer to a @p ICUDriver object
 */
typedef void (*icucallback_t)(ICUDriver *icup);

/**
 * @brief ICU driver mode.
 */
typedef enum {
  ICU_INPUT_ACTIVE_HIGH = 0,        /**< Trigger on rising edge.            */
  ICU_INPUT_ACTIVE_LOW = 1          /**< Trigger on falling edge.           */
} icumode_t;

/**
 * @brief   ICU frequency type.
 */
typedef uint32_t icufreq_t;

/**
 * @brief   ICU counter type.
 */
typedef uint32_t icucnt_t;

/**
 * @brief   ICU pulse edge type.
 */
typedef uint32_t icupe_t;

/**
 * @brief   Driver configuration structure.
 * @note    It could be empty on some architectures.
 */
typedef struct {
  /**
   * @brief   Driver mode.
   */
  icumode_t                 mode;
  /**
   * @brief   Timer clock in Hz.
   */
  icufreq_t                 frequency;
  /**
   * @brief   Callback for pulse width measurement.
   */
  icucallback_t             width_cb;
  /**
   * @brief   Callback for cycle period measurement.
   */
  icucallback_t             period_cb;
  /**
   * @brief   Callback for timer overflow.
   */
  icucallback_t             overflow_cb;
  /* End of the mandatory fields.*/
} ICUConfig;

/**
 * @brief   Pulse edge structure.
 * @note    It contains for each channel the temporary counter A2 
 *          values used to calculate the period and width of the 
 *          related input pulse.
 */
typedef struct {
  /**
   * @brief   Counter A2 value on the first pulse edge.
   * @note    First rising edge for ICU_INPUT_ACTIVE_HIGH,
   *          first falling edge for ICU_INPUT_ACTIVE_LOW.
   */
  icupe_t                   a2_1;
  /**
   * @brief   Counter A2 value on the second pulse edge.
   * @note    First falling edge for ICU_INPUT_ACTIVE_HIGH,
   *          first rising edge for ICU_INPUT_ACTIVE_LOW.
   */
  icupe_t                   a2_2;
  /**
   * @brief   Counter A2 value on the first pulse edge.
   * @note    Second rising edge for ICU_INPUT_ACTIVE_HIGH,
   *          second falling edge for ICU_INPUT_ACTIVE_LOW.
   */
  icupe_t                   a2_3;
} ICUPulseEdges;

/**
 * @brief   Structure representing an ICU driver.
 */
struct ICUDriver {
  /**
   * @brief eMIOSx channel number.
   */
  uint32_t                  ch_number;
  /**
   * @brief Current configuration data.
   */
  const ICUConfig           *config;
  /**
   * @brief CH Counter clock.
   */
  uint32_t clock;
  /* End of the mandatory fields.*/
  /**
   * @brief Pointer to the eMIOSx registers block.
   */
  volatile struct EMIOS_tag *emiosp;
  /**
   * @brief Last pulse edges.
   */
  ICUPulseEdges             pe;
  /**
   * @brief Last width capture value.
   */
  uint32_t                  width;
  /**
   * @brief Last period capture value.
   */
  uint32_t                  period;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Returns the width of the latest pulse.
 * @details The pulse width is defined as number of ticks between the start
 *          edge and the stop edge.
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 * @return              The number of ticks.
 *
 * @notapi
 */
#define icu_lld_get_width(icup) ((icup)->width)

/**
 * @brief   Returns the period of the latest cycle.
 * @details The period is defined as number of ticks between a start edge
 *          and the next start edge.
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 * @return              The number of ticks.
 *
 * @notapi
 */
#define icu_lld_get_period(icup) ((icup)->period)

/**
 * @name    Low Level driver helper macros
 * @{
 */
/**
 * @brief   Common ISR code, ICU width event.
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 *
 * @notapi
 */
#define _icu_isr_invoke_width_cb(icup) {                                    \
  (icup)->config->width_cb(icup);                                           \
}

/**
 * @brief   Common ISR code, ICU period event.
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 *
 * @notapi
 */
#define _icu_isr_invoke_period_cb(icup) {                                   \
  (icup)->config->period_cb(icup);                                          \
}

/**
 * @brief   Common ISR code, ICU timer overflow event.
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 *
 * @notapi
 */
#define _icu_isr_invoke_overflow_cb(icup) {                                 \
  (icup)->config->overflow_cb(icup);                                        \
}
/** @} */

/*===========================================================================*/
/* IRQ Handlers                                                              */
/*===========================================================================*/

#if SPC5_ICU_USE_EMIOS_CH0
IRQ_HANDLER(SPC5_EMIOS_FLAG_F0_HANDLER);
#endif /* SPC5_ICU_USE_EMIOS_CH0 */

#if SPC5_ICU_USE_EMIOS_CH1
IRQ_HANDLER(SPC5_EMIOS_FLAG_F1_HANDLER);
#endif /* SPC5_ICU_USE_EMIOS_CH1 */

#if SPC5_ICU_USE_EMIOS_CH2
IRQ_HANDLER(SPC5_EMIOS_FLAG_F2_HANDLER);
#endif /* SPC5_ICU_USE_EMIOS_CH2 */

#if SPC5_ICU_USE_EMIOS_CH3
IRQ_HANDLER(SPC5_EMIOS_FLAG_F3_HANDLER);
#endif /* SPC5_ICU_USE_EMIOS_CH3 */

#if SPC5_ICU_USE_EMIOS_CH4
IRQ_HANDLER(SPC5_EMIOS_FLAG_F4_HANDLER);
#endif /* SPC5_ICU_USE_EMIOS_CH4 */

#if SPC5_ICU_USE_EMIOS_CH5
IRQ_HANDLER(SPC5_EMIOS_FLAG_F5_HANDLER);
#endif /* SPC5_ICU_USE_EMIOS_CH5 */

#if SPC5_ICU_USE_EMIOS_CH6
IRQ_HANDLER(SPC5_EMIOS_FLAG_F6_HANDLER);
#endif /* SPC5_ICU_USE_EMIOS_CH6 */

#if SPC5_ICU_USE_EMIOS_CH7
IRQ_HANDLER(SPC5_EMIOS_FLAG_F7_HANDLER);
#endif /* SPC5_ICU_USE_EMIOS_CH7 */

#if SPC5_ICU_USE_EMIOS_CH8
IRQ_HANDLER(SPC5_EMIOS_FLAG_F8_HANDLER);
#endif /* SPC5_ICU_USE_EMIOS_CH8 */

#if SPC5_ICU_USE_EMIOS_CH9
IRQ_HANDLER(SPC5_EMIOS_FLAG_F9_HANDLER);
#endif /* SPC5_ICU_USE_EMIOS_CH9 */

#if SPC5_ICU_USE_EMIOS_CH10
IRQ_HANDLER(SPC5_EMIOS_FLAG_F10_HANDLER);
#endif /* SPC5_ICU_USE_EMIOS_CH10 */

#if SPC5_ICU_USE_EMIOS_CH11
IRQ_HANDLER(SPC5_EMIOS_FLAG_F11_HANDLER);
#endif /* SPC5_ICU_USE_EMIOS_CH11 */

#if SPC5_ICU_USE_EMIOS_CH12
IRQ_HANDLER(SPC5_EMIOS_FLAG_F12_HANDLER);
#endif /* SPC5_ICU_USE_EMIOS_CH12 */

#if SPC5_ICU_USE_EMIOS_CH13
IRQ_HANDLER(SPC5_EMIOS_FLAG_F13_HANDLER);
#endif /* SPC5_ICU_USE_EMIOS_CH13 */

#if SPC5_ICU_USE_EMIOS_CH14
IRQ_HANDLER(SPC5_EMIOS_FLAG_F14_HANDLER);
#endif /* SPC5_ICU_USE_EMIOS_CH14 */

#if SPC5_ICU_USE_EMIOS_CH15
IRQ_HANDLER(SPC5_EMIOS_FLAG_F15_HANDLER);
#endif /* SPC5_ICU_USE_EMIOS_CH15 */

#if SPC5_ICU_USE_EMIOS_CH16
IRQ_HANDLER(SPC5_EMIOS_FLAG_F16_HANDLER);
#endif /* SPC5_ICU_USE_EMIOS_CH16 */

#if SPC5_ICU_USE_EMIOS_CH17
IRQ_HANDLER(SPC5_EMIOS_FLAG_F17_HANDLER);
#endif /* SPC5_ICU_USE_EMIOS_CH17 */

#if SPC5_ICU_USE_EMIOS_CH18
IRQ_HANDLER(SPC5_EMIOS_FLAG_F18_HANDLER);
#endif /* SPC5_ICU_USE_EMIOS_CH18 */

#if SPC5_ICU_USE_EMIOS_CH19
IRQ_HANDLER(SPC5_EMIOS_FLAG_F19_HANDLER);
#endif /* SPC5_ICU_USE_EMIOS_CH19 */

#if SPC5_ICU_USE_EMIOS_CH20
IRQ_HANDLER(SPC5_EMIOS_FLAG_F20_HANDLER);
#endif /* SPC5_ICU_USE_EMIOS_CH20 */

#if SPC5_ICU_USE_EMIOS_CH21
IRQ_HANDLER(SPC5_EMIOS_FLAG_F21_HANDLER);
#endif /* SPC5_ICU_USE_EMIOS_CH21 */

#if SPC5_ICU_USE_EMIOS_CH22
IRQ_HANDLER(SPC5_EMIOS_FLAG_F22_HANDLER);
#endif /* SPC5_ICU_USE_EMIOS_CH22 */

#if SPC5_ICU_USE_EMIOS_CH23
IRQ_HANDLER(SPC5_EMIOS_FLAG_F23_HANDLER);
#endif /* SPC5_ICU_USE_EMIOS_CH23 */

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if (SPC5_ICU_USE_EMIOS_CH0 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD1;
#endif

#if (SPC5_ICU_USE_EMIOS_CH1 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD2;
#endif

#if (SPC5_ICU_USE_EMIOS_CH2 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD3;
#endif

#if (SPC5_ICU_USE_EMIOS_CH3 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD4;
#endif

#if (SPC5_ICU_USE_EMIOS_CH4 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD5;
#endif

#if (SPC5_ICU_USE_EMIOS_CH5 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD6;
#endif

#if (SPC5_ICU_USE_EMIOS_CH6 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD7;
#endif

#if (SPC5_ICU_USE_EMIOS_CH7 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD8;
#endif

#if (SPC5_ICU_USE_EMIOS_CH8 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD9;
#endif

#if (SPC5_ICU_USE_EMIOS_CH9 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD10;
#endif

#if (SPC5_ICU_USE_EMIOS_CH10 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD11;
#endif

#if (SPC5_ICU_USE_EMIOS_CH11 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD12;
#endif

#if (SPC5_ICU_USE_EMIOS_CH12 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD13;
#endif

#if (SPC5_ICU_USE_EMIOS_CH13 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD14;
#endif

#if (SPC5_ICU_USE_EMIOS_CH14 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD15;
#endif

#if (SPC5_ICU_USE_EMIOS_CH15 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD16;
#endif

#if (SPC5_ICU_USE_EMIOS_CH16 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD17;
#endif

#if (SPC5_ICU_USE_EMIOS_CH17 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD18;
#endif

#if (SPC5_ICU_USE_EMIOS_CH18 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD19;
#endif

#if (SPC5_ICU_USE_EMIOS_CH19 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD20;
#endif

#if (SPC5_ICU_USE_EMIOS_CH20 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD21;
#endif

#if (SPC5_ICU_USE_EMIOS_CH21 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD22;
#endif

#if (SPC5_ICU_USE_EMIOS_CH22 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD23;
#endif

#if (SPC5_ICU_USE_EMIOS_CH23 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD24;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void icu_lld_init(void);
  void icu_lld_start(ICUDriver *icup, const ICUConfig *config);
  void icu_lld_stop(ICUDriver *icup);
  void icu_lld_enable(ICUDriver *icup);
  void icu_lld_disable(ICUDriver *icup);
#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_ICU */

#endif /* _ICU_LLD_H_ */

/** @} */
