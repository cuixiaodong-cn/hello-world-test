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
 * @file    pwm_lld.h
 * @brief   SPC5xx PWM low level driver header.
 *
 * @addtogroup PWM
 * @{
 */

#ifndef _PWM_LLD_H_
#define _PWM_LLD_H_

#include "spc5_lld.h"
#include "lldconf.h"

#if (LLD_USE_PWM == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    PWM output mode macros
 * @{
 */

/**
 * @name    PWM output mode macros
 * @{
 */
/**
 * @brief   Standard output modes mask.
 */
#define PWM_OUTPUT_MASK                         0x0FU

/**
 * @brief   Output not driven, callback only.
 */
#define PWM_OUTPUT_DISABLED                     0x00U

/**
 * @brief   Positive PWM logic, active is logic level one.
 */
#define PWM_OUTPUT_ACTIVE_HIGH                  0x01U

/**
 * @brief   Inverse PWM logic, active is logic level zero.
 */
#define PWM_OUTPUT_ACTIVE_LOW                   0x02U
/** @} */

/**
 * @brief   Number of PWM channels per PWM driver.
 */
#define PWM_CHANNELS                            1U

/**
 * @brief   Edge-Aligned PWM functional mode.
 * @note    This is an SPC5-specific setting.
 */
#define PWM_ALIGN_EDGE                          0x00U

/**
 * @brief   Center-Aligned PWM functional mode.
 * @note    This is an SPC5-specific setting.
 */
#define PWM_ALIGN_CENTER                        0x01U

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   PWMD1 driver enable switch.
 * @details If set to @p TRUE the support for PWMD1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS_CH0) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS_CH0              FALSE
#endif

/**
 * @brief   PWMD2 driver enable switch.
 * @details If set to @p TRUE the support for PWMD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS_CH1) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS_CH1              FALSE
#endif

/**
 * @brief   PWMD3 driver enable switch.
 * @details If set to @p TRUE the support for PWMD3 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS_CH2) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS_CH2              FALSE
#endif

/**
 * @brief   PWMD4 driver enable switch.
 * @details If set to @p TRUE the support for PWMD4 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS_CH3) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS_CH3              FALSE
#endif

/**
 * @brief   PWMD5 driver enable switch.
 * @details If set to @p TRUE the support for PWMD5 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS_CH4) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS_CH4              FALSE
#endif

/**
 * @brief   PWMD6 driver enable switch.
 * @details If set to @p TRUE the support for PWMD6 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS_CH5) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS_CH5              FALSE
#endif

/**
 * @brief   PWMD7 driver enable switch.
 * @details If set to @p TRUE the support for PWMD7 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS_CH6) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS_CH6              FALSE
#endif

/**
 * @brief   PWMD8 driver enable switch.
 * @details If set to @p TRUE the support for PWMD8 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS_CH7) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS_CH7              FALSE
#endif

/**
 * @brief   PWMD9 driver enable switch.
 * @details If set to @p TRUE the support for PWMD9 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS_CH8) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS_CH8              FALSE
#endif

/**
 * @brief   PWMD10 driver enable switch.
 * @details If set to @p TRUE the support for PWMD10 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS_CH9) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS_CH9              FALSE
#endif

/**
 * @brief   PWMD11 driver enable switch.
 * @details If set to @p TRUE the support for PWMD11 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS_CH10) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS_CH10             FALSE
#endif

/**
 * @brief   PWMD12 driver enable switch.
 * @details If set to @p TRUE the support for PWMD12 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS_CH11) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS_CH11             FALSE
#endif

/**
 * @brief   PWMD13 driver enable switch.
 * @details If set to @p TRUE the support for PWMD13 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS_CH12) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS_CH12             FALSE
#endif

/**
 * @brief   PWMD14 driver enable switch.
 * @details If set to @p TRUE the support for PWMD14 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS_CH13) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS_CH13             FALSE
#endif

/**
 * @brief   PWMD15 driver enable switch.
 * @details If set to @p TRUE the support for PWMD15 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS_CH14) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS_CH14             FALSE
#endif

/**
 * @brief   PWMD16 driver enable switch.
 * @details If set to @p TRUE the support for PWMD16 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS_CH15) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS_CH15             FALSE
#endif

/**
 * @brief   PWMD17 driver enable switch.
 * @details If set to @p TRUE the support for PWMD17 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS_CH16) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS_CH16             FALSE
#endif

/**
 * @brief   PWMD18 driver enable switch.
 * @details If set to @p TRUE the support for PWMD18 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS_CH17) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS_CH17             FALSE
#endif

/**
 * @brief   PWMD19 driver enable switch.
 * @details If set to @p TRUE the support for PWMD19 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS_CH18) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS_CH18             FALSE
#endif

/**
 * @brief   PWMD20 driver enable switch.
 * @details If set to @p TRUE the support for PWMD20 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS_CH19) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS_CH19             FALSE
#endif

/**
 * @brief   PWMD21 driver enable switch.
 * @details If set to @p TRUE the support for PWMD21 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS_CH20) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS_CH20             FALSE
#endif

/**
 * @brief   PWMD22 driver enable switch.
 * @details If set to @p TRUE the support for PWMD22 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS_CH21) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS_CH21             FALSE
#endif

/**
 * @brief   PWMD23 driver enable switch.
 * @details If set to @p TRUE the support for PWMD23 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS_CH22) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS_CH22             FALSE
#endif

/**
 * @brief   PWMD24 driver enable switch.
 * @details If set to @p TRUE the support for PWMD24 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS_CH23) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS_CH23             FALSE
#endif

/**
 * @brief   PWMD1 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F0_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F0_PRIORITY         7
#endif

/**
 * @brief   PWMD2 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F1_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F1_PRIORITY         7
#endif

/**
 * @brief   PWMD3 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F2_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F2_PRIORITY         7
#endif

/**
 * @brief   PWMD4 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F3_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F3_PRIORITY         7
#endif

/**
 * @brief   PWMD5 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F4_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F4_PRIORITY         7
#endif

/**
 * @brief   PWMD6 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F5_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F5_PRIORITY         7
#endif

/**
 * @brief   PWMD7 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F6_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F6_PRIORITY         7
#endif

/**
 * @brief   PWMD8 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F7_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F7_PRIORITY         7
#endif

/**
 * @brief   PWMD9 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F8_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F8_PRIORITY         7
#endif

/**
 * @brief   PWMD10 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F9_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F9_PRIORITY         7
#endif

/**
 * @brief   PWMD11 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F10_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F10_PRIORITY        7
#endif

/**
 * @brief   PWMD12 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F11_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F11_PRIORITY        7
#endif

/**
 * @brief   PWMD13 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F12_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F12_PRIORITY        7
#endif

/**
 * @brief   PWMD14 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F13_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F13_PRIORITY        7
#endif

/**
 * @brief   PWMD15 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F14_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F14_PRIORITY        7
#endif

/**
 * @brief   PWMD16 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F15_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F15_PRIORITY        7
#endif

/**
 * @brief   PWMD17 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F16_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F16_PRIORITY        7
#endif

/**
 * @brief   PWMD18 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F17_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F17_PRIORITY        7
#endif

/**
 * @brief   PWMD19 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F18_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F18_PRIORITY        7
#endif

/**
 * @brief   PWMD20 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F19_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F19_PRIORITY        7
#endif

/**
 * @brief   PWMD21 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F20_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F20_PRIORITY        7
#endif

/**
 * @brief   PWMD22 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F21_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F21_PRIORITY        7
#endif

/**
 * @brief   PWMD23 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS_FLAG_F22_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS_FLAG_F22_PRIORITY        7
#endif

/**
 * @brief   PWMD24 interrupt priority level setting.
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

#if (SPC5_PWM_USE_EMIOS_CH0  == TRUE || SPC5_PWM_USE_EMIOS_CH1  == TRUE || \
     SPC5_PWM_USE_EMIOS_CH2  == TRUE || SPC5_PWM_USE_EMIOS_CH3  == TRUE || \
     SPC5_PWM_USE_EMIOS_CH4  == TRUE || SPC5_PWM_USE_EMIOS_CH5  == TRUE || \
     SPC5_PWM_USE_EMIOS_CH6  == TRUE || SPC5_PWM_USE_EMIOS_CH7  == TRUE || \
     SPC5_PWM_USE_EMIOS_CH8  == TRUE || SPC5_PWM_USE_EMIOS_CH9  == TRUE || \
     SPC5_PWM_USE_EMIOS_CH10 == TRUE || SPC5_PWM_USE_EMIOS_CH11 == TRUE || \
     SPC5_PWM_USE_EMIOS_CH12 == TRUE || SPC5_PWM_USE_EMIOS_CH13 == TRUE || \
     SPC5_PWM_USE_EMIOS_CH14 == TRUE || SPC5_PWM_USE_EMIOS_CH15 == TRUE || \
     SPC5_PWM_USE_EMIOS_CH16 == TRUE || SPC5_PWM_USE_EMIOS_CH17 == TRUE || \
     SPC5_PWM_USE_EMIOS_CH18 == TRUE || SPC5_PWM_USE_EMIOS_CH19 == TRUE || \
     SPC5_PWM_USE_EMIOS_CH20 == TRUE || SPC5_PWM_USE_EMIOS_CH21 == TRUE || \
     SPC5_PWM_USE_EMIOS_CH22 == TRUE || SPC5_PWM_USE_EMIOS_CH23 == TRUE) 
#define SPC5_PWM_USE_EMIOS                  TRUE
#else
#define SPC5_PWM_USE_EMIOS                  FALSE
#endif

#if (SPC5_PWM_USE_EMIOS == FALSE)
#error "PWM driver activated but no Channels assigned"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of a structure representing a PWM driver.
 */
typedef struct PWMDriver PWMDriver;

/**
 * @brief   PWM notification callback type.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 */
typedef void (*pwmcallback_t)(PWMDriver *pwmp);

/**
 * @brief   PWM mode type.
 */
typedef uint32_t pwmmode_t;

/**
 * @brief   PWM channel type.
 */
typedef uint8_t pwmchannel_t;

/**
 * @brief   PWM counter type.
 */
typedef uint32_t pwmcnt_t;

/**
 * @brief   PWM driver channel configuration structure.
 * @note    Some architectures may not be able to support the channel mode
 *          or the callback, in this case the fields are ignored.
 */
typedef struct {
  /**
   * @brief Channel active logic level.
   */
  pwmmode_t                 mode;
  /**
   * @brief Channel callback pointer.
   * @note  This callback is invoked on the channel compare event. If set to
   *        @p NULL then the callback is disabled.
   */
  pwmcallback_t             callback;
  /* End of the mandatory fields.*/
} PWMChannelConfig;

/**
 * @brief   Driver configuration structure.
 * @note    Implementations may extend this structure to contain more,
 *          architecture dependent, fields.
 */
typedef struct {
  /**
   * @brief Timer clock in Hz.
   */
  uint32_t                  frequency;
  /**
   * @brief PWM period in ticks.
   */
  pwmcnt_t                  period;
  /**
   * @brief Periodic callback pointer.
   * @note  This callback is invoked on PWM counter reset. If set to
   *        @p NULL then the callback is disabled.
   */
  pwmcallback_t             callback;
  /**
   * @brief Channels configurations.
   */
  PWMChannelConfig          channels[PWM_CHANNELS];
  /* End of the mandatory fields.*/
  /**
   * @brief PWM functional mode.
   */
  pwmmode_t                 mode;
} PWMConfig;

/**
 * @brief   Structure representing an PWM driver.
 * @note    Implementations may extend this structure to contain more,
 *          architecture dependent, fields.
 */
struct PWMDriver {
  /**
   * @brief eMIOSx channel number.
   */
  uint8_t                   ch_number;
  /**
   * @brief Current configuration data.
   */
  const PWMConfig           *config;
  /**
   * @brief Current PWM period in ticks.
   */
  pwmcnt_t                  period;
#if defined(PWM_DRIVER_EXT_FIELDS)
  PWM_DRIVER_EXT_FIELDS
#endif
  /* End of the mandatory fields.*/
  /**
   * @brief Pointer to the eMIOSx registers block.
   */
  volatile struct EMIOS_tag *emiosp;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @name    PWM duty cycle conversion
 * @{
 */
/**
 * @brief   Converts from fraction to pulse width.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] denominator denominator of the fraction
 * @param[in] numerator numerator of the fraction
 * @return              The pulse width to be passed to @p pwm_lld_enable_channel().
 *
 * @api
 */
#define PWM_FRACTION_TO_WIDTH(pwmp, denominator, numerator)                 \
  ((pwmcnt_t)((((pwmcnt_t)(pwmp)->period) *                                 \
               (pwmcnt_t)(numerator)) / (pwmcnt_t)(denominator)))

/**
 * @brief   Converts from degrees to pulse width.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] degrees   degrees as an integer between 0 and 36000
 * @return              The pulse width to be passed to @p pwm_lld_enable_channel().
 *
 * @api
 */
#define PWM_DEGREES_TO_WIDTH(pwmp, degrees)                                 \
  PWM_FRACTION_TO_WIDTH(pwmp, 36000, degrees)

/**
 * @brief   Converts from percentage to pulse width.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] percentage percentage as an integer between 0 and 10000
 * @return              The pulse width to be passed to @p pwm_lld_enable_channel().
 *
 * @api
 */
#define PWM_PERCENTAGE_TO_WIDTH(pwmp, percentage)                           \
  PWM_FRACTION_TO_WIDTH(pwmp, 10000, percentage)
/** @} */

/*===========================================================================*/
/* IRQ Handlers                                                              */
/*===========================================================================*/

#if SPC5_PWM_USE_EMIOS_CH0
IRQ_HANDLER(SPC5_EMIOS_FLAG_F0_HANDLER);
#endif /* SPC5_PWM_USE_EMIOS_CH0 */

#if SPC5_PWM_USE_EMIOS_CH1
IRQ_HANDLER(SPC5_EMIOS_FLAG_F1_HANDLER);
#endif /* SPC5_PWM_USE_EMIOS_CH1 */

#if SPC5_PWM_USE_EMIOS_CH2
IRQ_HANDLER(SPC5_EMIOS_FLAG_F2_HANDLER);
#endif /* SPC5_PWM_USE_EMIOS_CH2 */

#if SPC5_PWM_USE_EMIOS_CH3
IRQ_HANDLER(SPC5_EMIOS_FLAG_F3_HANDLER);
#endif /* SPC5_PWM_USE_EMIOS_CH3 */

#if SPC5_PWM_USE_EMIOS_CH4
IRQ_HANDLER(SPC5_EMIOS_FLAG_F4_HANDLER);
#endif /* SPC5_PWM_USE_EMIOS_CH4 */

#if SPC5_PWM_USE_EMIOS_CH5
IRQ_HANDLER(SPC5_EMIOS_FLAG_F5_HANDLER);
#endif /* SPC5_PWM_USE_EMIOS_CH5 */

#if SPC5_PWM_USE_EMIOS_CH6
IRQ_HANDLER(SPC5_EMIOS_FLAG_F6_HANDLER);
#endif /* SPC5_PWM_USE_EMIOS_CH6 */

#if SPC5_PWM_USE_EMIOS_CH7
IRQ_HANDLER(SPC5_EMIOS_FLAG_F7_HANDLER);
#endif /* SPC5_PWM_USE_EMIOS_CH7 */

#if SPC5_PWM_USE_EMIOS_CH8
IRQ_HANDLER(SPC5_EMIOS_FLAG_F8_HANDLER);
#endif /* SPC5_PWM_USE_EMIOS_CH8 */

#if SPC5_PWM_USE_EMIOS_CH9
IRQ_HANDLER(SPC5_EMIOS_FLAG_F9_HANDLER);
#endif /* SPC5_PWM_USE_EMIOS_CH9 */

#if SPC5_PWM_USE_EMIOS_CH10
IRQ_HANDLER(SPC5_EMIOS_FLAG_F10_HANDLER);
#endif /* SPC5_PWM_USE_EMIOS_CH10 */

#if SPC5_PWM_USE_EMIOS_CH11
IRQ_HANDLER(SPC5_EMIOS_FLAG_F11_HANDLER);
#endif /* SPC5_PWM_USE_EMIOS_CH11 */

#if SPC5_PWM_USE_EMIOS_CH12
IRQ_HANDLER(SPC5_EMIOS_FLAG_F12_HANDLER);
#endif /* SPC5_PWM_USE_EMIOS_CH12 */

#if SPC5_PWM_USE_EMIOS_CH13
IRQ_HANDLER(SPC5_EMIOS_FLAG_F13_HANDLER);
#endif /* SPC5_PWM_USE_EMIOS_CH13 */

#if SPC5_PWM_USE_EMIOS_CH14
IRQ_HANDLER(SPC5_EMIOS_FLAG_F14_HANDLER);
#endif /* SPC5_PWM_USE_EMIOS_CH14 */

#if SPC5_PWM_USE_EMIOS_CH15
IRQ_HANDLER(SPC5_EMIOS_FLAG_F15_HANDLER);
#endif /* SPC5_PWM_USE_EMIOS_CH15 */

#if SPC5_PWM_USE_EMIOS_CH16
IRQ_HANDLER(SPC5_EMIOS_FLAG_F16_HANDLER);
#endif /* SPC5_PWM_USE_EMIOS_CH16 */

#if SPC5_PWM_USE_EMIOS_CH17
IRQ_HANDLER(SPC5_EMIOS_FLAG_F17_HANDLER);
#endif /* SPC5_PWM_USE_EMIOS_CH17 */

#if SPC5_PWM_USE_EMIOS_CH18
IRQ_HANDLER(SPC5_EMIOS_FLAG_F18_HANDLER);
#endif /* SPC5_PWM_USE_EMIOS_CH18 */

#if SPC5_PWM_USE_EMIOS_CH19
IRQ_HANDLER(SPC5_EMIOS_FLAG_F19_HANDLER);
#endif /* SPC5_PWM_USE_EMIOS_CH19 */

#if SPC5_PWM_USE_EMIOS_CH20
IRQ_HANDLER(SPC5_EMIOS_FLAG_F20_HANDLER);
#endif /* SPC5_PWM_USE_EMIOS_CH20 */

#if SPC5_PWM_USE_EMIOS_CH21
IRQ_HANDLER(SPC5_EMIOS_FLAG_F21_HANDLER);
#endif /* SPC5_PWM_USE_EMIOS_CH21 */

#if SPC5_PWM_USE_EMIOS_CH22
IRQ_HANDLER(SPC5_EMIOS_FLAG_F22_HANDLER);
#endif /* SPC5_PWM_USE_EMIOS_CH22 */

#if SPC5_PWM_USE_EMIOS_CH23
IRQ_HANDLER(SPC5_EMIOS_FLAG_F23_HANDLER);
#endif /* SPC5_PWM_USE_EMIOS_CH23 */

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if (SPC5_PWM_USE_EMIOS_CH0 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD1;
#endif

#if (SPC5_PWM_USE_EMIOS_CH1 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD2;
#endif

#if (SPC5_PWM_USE_EMIOS_CH2 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD3;
#endif

#if (SPC5_PWM_USE_EMIOS_CH3 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD4;
#endif

#if (SPC5_PWM_USE_EMIOS_CH4 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD5;
#endif

#if (SPC5_PWM_USE_EMIOS_CH5 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD6;
#endif

#if (SPC5_PWM_USE_EMIOS_CH6 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD7;
#endif

#if (SPC5_PWM_USE_EMIOS_CH7 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD8;
#endif

#if (SPC5_PWM_USE_EMIOS_CH8 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD9;
#endif

#if (SPC5_PWM_USE_EMIOS_CH9 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD10;
#endif

#if (SPC5_PWM_USE_EMIOS_CH10 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD11;
#endif

#if (SPC5_PWM_USE_EMIOS_CH11 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD12;
#endif

#if (SPC5_PWM_USE_EMIOS_CH12 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD13;
#endif

#if (SPC5_PWM_USE_EMIOS_CH13 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD14;
#endif

#if (SPC5_PWM_USE_EMIOS_CH14 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD15;
#endif

#if (SPC5_PWM_USE_EMIOS_CH15 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD16;
#endif

#if (SPC5_PWM_USE_EMIOS_CH16 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD17;
#endif

#if (SPC5_PWM_USE_EMIOS_CH17 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD18;
#endif

#if (SPC5_PWM_USE_EMIOS_CH18 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD19;
#endif

#if (SPC5_PWM_USE_EMIOS_CH19 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD20;
#endif

#if (SPC5_PWM_USE_EMIOS_CH20 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD21;
#endif

#if (SPC5_PWM_USE_EMIOS_CH21 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD22;
#endif

#if (SPC5_PWM_USE_EMIOS_CH22 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD23;
#endif

#if (SPC5_PWM_USE_EMIOS_CH23 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD24;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void pwm_lld_init(void);
  void pwm_lld_start(PWMDriver *pwmp, const PWMConfig *config);
  void pwm_lld_stop(PWMDriver *pwmp);
  void pwm_lld_change_period(PWMDriver *pwmp, pwmcnt_t period);
  void pwm_lld_enable_channel(PWMDriver *pwmp,
                              pwmchannel_t channel,
                              pwmcnt_t width);
  void pwm_lld_disable_channel(PWMDriver *pwmp, pwmchannel_t channel);
#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_PWM */

#endif /* _PWM_LLD_H_ */

/** @} */
