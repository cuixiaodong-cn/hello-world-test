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
* EVALUATION ONLY - NOT FOR USE IN PRODUCTION
*****************************************************************************/
/**
 * @file    adc_lld.h
 * @brief   SPC5xx ADC low level driver header.
 *
 * @addtogroup ADC
 * @{
 */

#ifndef _ADC_LLD_H_
#define _ADC_LLD_H_

#include "spc5_lld.h"
#include "lldconf.h"

#if (LLD_USE_ADC == TRUE) || defined(__DOXYGEN__)

#include "spc5_edma.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    Analog channel identifiers
 * @{
 */
#define ADC_CHN_AN0                 0UL
#define ADC_CHN_AN1                 1UL
#define ADC_CHN_AN2                 2UL
#define ADC_CHN_AN3                 3UL
#define ADC_CHN_AN4                 4UL
#define ADC_CHN_AN5                 5UL
#define ADC_CHN_AN6                 6UL
#define ADC_CHN_AN7                 7UL
#define ADC_CHN_AN8                 8UL
#define ADC_CHN_AN9                 9UL
#define ADC_CHN_AN10                10UL
#define ADC_CHN_AN11                11UL
#define ADC_CHN_AN12                12UL
#define ADC_CHN_AN13                13UL
#define ADC_CHN_AN14                14UL
#define ADC_CHN_AN15                15UL
#define ADC_CHN_AN16                16UL
#define ADC_CHN_AN17                17UL
#define ADC_CHN_AN18                18UL
#define ADC_CHN_AN19                19UL
#define ADC_CHN_AN20                20UL
#define ADC_CHN_AN21                21UL
#define ADC_CHN_AN22                22UL
#define ADC_CHN_AN23                23UL
#define ADC_CHN_AN24                24UL
#define ADC_CHN_AN25                25UL
#define ADC_CHN_AN26                26UL
#define ADC_CHN_AN27                27UL
#define ADC_CHN_AN28                28UL
#define ADC_CHN_AN29                29UL
#define ADC_CHN_AN30                30UL
#define ADC_CHN_AN31                31UL
#define ADC_CHN_AN32                32UL
#define ADC_CHN_AN33                33UL
#define ADC_CHN_AN34                34UL
#define ADC_CHN_AN35                35UL
#define ADC_CHN_AN36                36UL 
#define ADC_CHN_AN37                37UL 
#define ADC_CHN_AN38                38UL 
#define ADC_CHN_AN39                39UL 
#define ADC_CHN_VRH                 40UL 
#define ADC_CHN_VRL                 41UL 
#define ADC_CHN_VREF50              42UL
#define ADC_CHN_VREF75              43UL
#define ADC_CHN_VREF25              44UL
#define ADC_CHN_BANDGAP             45UL
#define ADC_CHN_DAN0                96UL
#define ADC_CHN_DAN1                97UL
#define ADC_CHN_DAN2                98UL
#define ADC_CHN_DAN3                99UL
#define ADC_CHN_TEMP_SENSOR         128UL
#define ADC_CHN_SPARE               129UL
/** @} */

/**
 * @name    Internal registers indexes
 * @{
 */
#define ADC_REG_CR                  0x1UL
#define ADC_REG_TSCR                0x2UL
#define ADC_REG_TBCR                0x3UL
#define ADC_REG_GCCR                0x4UL
#define ADC_REG_OCCR                0x5UL
#define ADC_REG_AC1GCCR             0x31UL
#define ADC_REG_AC1OCCR             0x32UL
#define ADC_REG_AC2GCCR             0x35UL
#define ADC_REG_AC2OCCR             0x36UL
#define ADC_REG_AC1CR               0x30UL
#define ADC_REG_AC2CR               0x34UL
#define ADC_REG_AC3CR               0x38UL
#define ADC_REG_AC4CR               0x3CUL
#define ADC_REG_AC5CR               0x40UL
#define ADC_REG_AC6CR               0x44UL
#define ADC_REG_AC7CR               0x48UL
#define ADC_REG_AC8CR               0x4CUL
#define ADC_REG_PUDCR(n)            (0x70UL + (n))
#define ADC_REG_PUDCR0              0x70UL
#define ADC_REG_PUDCR1              0x71UL
#define ADC_REG_PUDCR2              0x72UL
#define ADC_REG_PUDCR3              0x73UL
#define ADC_REG_PUDCR4              0x74UL
#define ADC_REG_PUDCR5              0x75UL
#define ADC_REG_PUDCR6              0x76UL
#define ADC_REG_PUDCR7              0x77UL
/** @} */

/**
 * @name    EQADC IDCR registers definitions
 * @{
 */
#define EQADC_IDCR_NCIE             (1UL << 15)
#define EQADC_IDCR_TORIE            (1UL << 14)
#define EQADC_IDCR_PIE              (1UL << 13)
#define EQADC_IDCR_EOQIE            (1UL << 12)
#define EQADC_IDCR_CFUIE            (1UL << 11)
#define EQADC_IDCR_CFFE             (1UL << 9)
#define EQADC_IDCR_CFFS             (1UL << 8)
#define EQADC_IDCR_RFOIE            (1UL << 3)
#define EQADC_IDCR_RFDE             (1UL << 1)
#define EQADC_IDCR_RFDS             (1UL << 0)
/** @} */

/**
 * @name    EQADC CFCR registers definitions
 * @{
 */
#define EQADC_CFCR_CFEEE0           (1UL << 12)
#define EQADC_CFCR_STRME0           (1UL << 11)
#define EQADC_CFCR_SSE              (1UL << 10)
#define EQADC_CFCR_CFINV            (1UL << 9)
#define EQADC_CFCR_MODE_MASK        (15U << 4)
#define EQADC_CFCR_MODE(n)          ((n) << 4)
#define EQADC_CFCR_MODE_DISABLED    EQADC_CFCR_MODE(0UL)
#define EQADC_CFCR_MODE_SWSS        EQADC_CFCR_MODE(1UL)
#define EQADC_CFCR_MODE_HWSS_LL     EQADC_CFCR_MODE(2UL)
#define EQADC_CFCR_MODE_HWSS_HL     EQADC_CFCR_MODE(3UL)
#define EQADC_CFCR_MODE_HWSS_FE     EQADC_CFCR_MODE(4UL)
#define EQADC_CFCR_MODE_HWSS_RE     EQADC_CFCR_MODE(5UL)
#define EQADC_CFCR_MODE_HWSS_BE     EQADC_CFCR_MODE(6UL)
#define EQADC_CFCR_MODE_SWCS        EQADC_CFCR_MODE(9UL)
#define EQADC_CFCR_MODE_HWCS_LL     EQADC_CFCR_MODE(10UL)
#define EQADC_CFCR_MODE_HWCS_HL     EQADC_CFCR_MODE(11UL)
#define EQADC_CFCR_MODE_HWCS_FE     EQADC_CFCR_MODE(12UL)
#define EQADC_CFCR_MODE_HWCS_RE     EQADC_CFCR_MODE(13UL)
#define EQADC_CFCR_MODE_HWCS_BE     EQADC_CFCR_MODE(14UL)
#define EQADC_CFCR_AMODE0_MASK      (15U << 0)
#define EQADC_CFCR_AMODE0(n)        ((n) << 0)
/** @} */

/**
 * @name    EQADC FISR registers definitions
 * @{
 */
#define EQADC_FISR_POPNXTPTR_MASK   (15U << 0)
#define EQADC_FISR_RFCTR_MASK       (15U << 4)
#define EQADC_FISR_TNXTPTR_MASK     (15UL << 8)
#define EQADC_FISR_CFCTR_MASK       (15UL << 12)
#define EQADC_FISR_RFDF             (1UL<< 17)
#define EQADC_FISR_RFOF             (1UL<< 19)
#define EQADC_FISR_CFFF             (1UL<< 25)
#define EQADC_FISR_SSS              (1UL<< 26)
#define EQADC_FISR_CFUF             (1UL<< 27)
#define EQADC_FISR_EOQF             (1UL<< 28)
#define EQADC_FISR_PF               (1UL<< 29)
#define EQADC_FISR_TORF             (1UL<< 30)
#define EQADC_FISR_NCF              (1UL<< 31)
#define EQADC_FISR_CLEAR_MASK       (EQADC_FISR_NCF  | EQADC_FISR_TORF |    \
                                     EQADC_FISR_PF   | EQADC_FISR_EOQF |    \
                                     EQADC_FISR_CFUF | EQADC_FISR_RFOF |    \
                                     EQADC_FISR_RFDF)
/** @} */

/**
 * @name    EQADC conversion/configuration commands
 * @{
 */
#define EQADC_CONV_CONFIG_STD   (0U << 0)   /**< @brief Alt.config.1.       */
#define EQADC_CONV_CONFIG_SEL1  (8U << 0)   /**< @brief Alt.config.1.       */
#define EQADC_CONV_CONFIG_SEL2  (9U << 0)   /**< @brief Alt.config.2.       */
#define EQADC_CONV_CONFIG_SEL3  (10U << 0)  /**< @brief Alt.config.3.       */
#define EQADC_CONV_CONFIG_SEL4  (11U << 0)  /**< @brief Alt.config.4.       */
#define EQADC_CONV_CONFIG_SEL5  (12U << 0)  /**< @brief Alt.config.5.       */
#define EQADC_CONV_CONFIG_SEL6  (13U << 0)  /**< @brief Alt.config.6.       */
#define EQADC_CONV_CONFIG_SEL7  (14U << 0)  /**< @brief Alt.config.7.       */
#define EQADC_CONV_CONFIG_SEL8  (15U << 0)  /**< @brief Alt.config.8.       */
#define EQADC_CONV_CHANNEL_MASK (255UL << 8) /**< @brief Channel number mask.*/
#define EQADC_CONV_CHANNEL(n)   ((n) << 8)  /**< @brief Channel number.     */
#define EQADC_CONV_FMT_RJU      (0UL << 16)  /**< @brief Unsigned samples.   */
#define EQADC_CONV_FMT_RJS      (1UL << 16)  /**< @brief Signed samples.     */
#define EQADC_CONV_TSR          (1UL << 17)  /**< @brief Time stamp request. */
#define EQADC_CONV_LST_MASK     (3UL << 18)  /**< @brief Sample time.        */
#define EQADC_CONV_LST_2        (0UL << 18)  /**< @brief 2 clock cycles.     */
#define EQADC_CONV_LST_8        (1UL << 18)  /**< @brief 8 clock cycles.     */
#define EQADC_CONV_LST_64       (2UL << 18)  /**< @brief 64 clock cycles.    */
#define EQADC_CONV_LST_128      (3UL << 18)  /**< @brief 128 clock cycles.   */
#define EQADC_CONV_MSG_MASK     (15UL << 20) /**< @brief Message mask.       */
#define EQADC_CONV_MSG_RFIFO(n) ((n) << 20) /**< @brief Result in RFIFO0..5.*/
#define EQADC_CONV_MSG_NULL     (6UL << 20)  /**< @brief Null message.       */
#define EQADC_CONV_CAL          (1UL << 24)  /**< @brief Calibrated result.  */
#define EQADC_CONV_BN_MASK      (1UL << 25)  /**< @brief Buffer number mask. */
#define EQADC_CONV_BN_ADC0      (0UL << 25)  /**< @brief ADC0 selection.     */
#define EQADC_CONV_BN_ADC1      (1UL << 25)  /**< @brief ADC1 selection.     */
#define EQADC_CONV_REP          (1UL << 29)  /**< @brief Repeat loop flag.   */
#define EQADC_CONV_PAUSE        (1UL << 30)  /**< @brief Pause flag.         */
#define EQADC_CONV_EOQ          (1UL << 31)  /**< @brief End of queue flag.  */
/** @} */

/**
 * @name    EQADC read/write commands
 * @{
 */
#define EQADC_RW_REG_ADDR_MASK  (255U << 0)
#define EQADC_RW_REG_ADDR(n)    ((n) << 0)
#define EQADC_RW_VALUE_MASK     (0xFFFFUL << 8)
#define EQADC_RW_VALUE(n)       ((n) << 8)
#define EQADC_RW_WRITE          (0UL << 24)
#define EQADC_RW_READ           (1UL << 24)
#define EQADC_RW_BN_ADC0        (0UL << 25)
#define EQADC_RW_BN_ADC1        (1UL << 25)
#define EQADC_RW_REP            (1UL << 29)
#define EQADC_RW_PAUSE          (1UL << 30)
#define EQADC_RW_EOQ            (1UL << 31)
/** @} */

/**
 * @name    ADC CR register definitions
 * @{
 */
#define ADC_CR_CLK_PS_MASK      (31U << 0)

#define ADC_CR_CLK_SEL          (1U << 5)
#define ADC_CR_CLK_DTY          (1U << 6)
#define ADC_CR_ODD_PS           (1UL << 7)
#define ADC_CR_TBSEL_MASK       (3U << 8)
#define ADC_CR_TBSEL(n)         ((n) << 8)
#define ADC_CR_EMUX             (1U << 11)
#define ADC_CR_EN               (1UL << 15)
/** @} */

/**
 * @name    ADC AxCR registers definitions
 * @{
 */
#define ADC_ACR_PRE_GAIN_MASK   (3UL << 0)
#define ADC_ACR_PRE_GAIN_X1     (0UL << 0)
#define ADC_ACR_PRE_GAIN_X2     (1UL << 0)
#define ADC_ACR_PRE_GAIN_X4     (2UL << 0)
#define ADC_ACR_RESSEL_MASK     (3UL << 6)
#define ADC_ACR_RESSEL_12BITS   (0UL << 6)
#define ADC_ACR_RESSEL_10BITS   (1UL << 6)
#define ADC_ACR_RESSEL_8BITS    (2UL << 6)
/** @} */

/**
 * @name    ADC PUDCRx registers definitions
 * @{
 */
#define ADC_PUDCR_NONE          0x0000UL
#define ADC_PUDCR_UP_200K       0x1100UL
#define ADC_PUDCR_UP_100K       0x1200UL
#define ADC_PUDCR_UP_5K         0x1300UL
#define ADC_PUDCR_DOWN_200K     0x2100UL
#define ADC_PUDCR_DOWN_100K     0x2200UL
#define ADC_PUDCR_DOWN_5K       0x2300UL
#define ADC_PUDCR_UP_DOWN_200K  0x3100UL
#define ADC_PUDCR_UP_DOWN_100K  0x3200UL
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   ADCD1 driver enable switch.
 * @details If set to @p TRUE the support for ADC0 queue 0 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ADC_USE_ADC0_Q0) || defined(__DOXYGEN__)
#define SPC5_ADC_USE_ADC0_Q0                FALSE
#endif

/**
 * @brief   ADCD2 driver enable switch.
 * @details If set to @p TRUE the support for ADC0 queue 1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ADC_USE_ADC0_Q1) || defined(__DOXYGEN__)
#define SPC5_ADC_USE_ADC0_Q1                FALSE
#endif

/**
 * @brief   ADCD3 driver enable switch.
 * @details If set to @p TRUE the support for ADC0 queue 2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ADC_USE_ADC0_Q2) || defined(__DOXYGEN__)
#define SPC5_ADC_USE_ADC0_Q2                FALSE
#endif

/**
 * @brief   ADCD4 driver enable switch.
 * @details If set to @p TRUE the support for ADC1 queue 3 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ADC_USE_ADC1_Q3) || defined(__DOXYGEN__)
#define SPC5_ADC_USE_ADC1_Q3                FALSE
#endif

/**
 * @brief   ADCD5 driver enable switch.
 * @details If set to @p TRUE the support for ADC1 queue 4 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ADC_USE_ADC1_Q4) || defined(__DOXYGEN__)
#define SPC5_ADC_USE_ADC1_Q4                FALSE
#endif

/**
 * @brief   ADCD6 driver enable switch.
 * @details If set to @p TRUE the support for ADC1 queue 5 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ADC_USE_ADC1_Q5) || defined(__DOXYGEN__)
#define SPC5_ADC_USE_ADC1_Q5                FALSE
#endif

/**
 * @brief   EQADC CFIFO0 and RFIFO0 DMA IRQ priority.
 */
#if !defined(SPC5_ADC_FIFO0_DMA_IRQ_PRIO) || defined(__DOXYGEN__)
#define SPC5_ADC_FIFO0_DMA_IRQ_PRIO         12
#endif

/**
 * @brief   EQADC CFIFO1 and RFIFO1 DMA IRQ priority.
 */
#if !defined(SPC5_ADC_FIFO1_DMA_IRQ_PRIO) || defined(__DOXYGEN__)
#define SPC5_ADC_FIFO1_DMA_IRQ_PRIO         12
#endif

/**
 * @brief   EQADC CFIFO2 and RFIFO2 DMA IRQ priority.
 */
#if !defined(SPC5_ADC_FIFO2_DMA_IRQ_PRIO) || defined(__DOXYGEN__)
#define SPC5_ADC_FIFO2_DMA_IRQ_PRIO         12
#endif

/**
 * @brief   EQADC CFIFO3 and RFIFO3 DMA IRQ priority.
 */
#if !defined(SPC5_ADC_FIFO3_DMA_IRQ_PRIO) || defined(__DOXYGEN__)
#define SPC5_ADC_FIFO3_DMA_IRQ_PRIO         12
#endif

/**
 * @brief   EQADC CFIFO4 and RFIFO4 DMA IRQ priority.
 */
#if !defined(SPC5_ADC_FIFO4_DMA_IRQ_PRIO) || defined(__DOXYGEN__)
#define SPC5_ADC_FIFO4_DMA_IRQ_PRIO         12
#endif

/**
 * @brief   EQADC CFIFO5 and RFIFO5 DMA IRQ priority.
 */
#if !defined(SPC5_ADC_FIFO5_DMA_IRQ_PRIO) || defined(__DOXYGEN__)
#define SPC5_ADC_FIFO5_DMA_IRQ_PRIO         12
#endif

/**
 * @brief   EQADC clock prescaler value.
 */
#if !defined(SPC5_ADC_CR_CLK_PS) || defined(__DOXYGEN__)
#define SPC5_ADC_CR_CLK_PS                  ADC_CR_CLK_PS(5UL)
#endif

/**
 * @brief   Initialization value for PUDCRx registers.
 */
#if !defined(SPC5_ADC_PUDCR) || defined(__DOXYGEN__)
#define SPC5_ADC_PUDCR                      {ADC_PUDCR_NONE,                \
                                             ADC_PUDCR_NONE,                \
                                             ADC_PUDCR_NONE,                \
                                             ADC_PUDCR_NONE,                \
                                             ADC_PUDCR_NONE,                \
                                             ADC_PUDCR_NONE,                \
                                             ADC_PUDCR_NONE,                \
                                             ADC_PUDCR_NONE}
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if (SPC5_HAS_EQADC == FALSE)
#error "EQADC not present in the selected device"
#endif

#define SPC5_ADC_USE_ADC0                   (SPC5_ADC_USE_ADC0_Q0 |        \
                                             SPC5_ADC_USE_ADC0_Q1 |        \
                                             SPC5_ADC_USE_ADC0_Q2)
#define SPC5_ADC_USE_ADC1                   (SPC5_ADC_USE_ADC1_Q3 |        \
                                             SPC5_ADC_USE_ADC1_Q4 |        \
                                             SPC5_ADC_USE_ADC1_Q5)

#if (SPC5_ADC_USE_ADC0 == FALSE) && (SPC5_ADC_USE_ADC1 == FALSE)
#error "ADC driver activated but no ADC peripheral assigned"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*!
 * @brief   FIFO unit numeric IDs.
 */
typedef enum {
  ADC_FIFO_0 = 0,
  ADC_FIFO_1 = 1,
  ADC_FIFO_2 = 2,
  ADC_FIFO_3 = 3,
  ADC_FIFO_4 = 4,
  ADC_FIFO_5 = 5
} adcfifo_t;

/**
 * @brief   ADC command data type.
 */
typedef uint32_t adccommand_t;

/**
 * @brief   ADC sample data type.
 */
typedef uint16_t adcsample_t;

/**
 * @brief   Channels number in a conversion group.
 */
typedef uint16_t adc_channels_num_t;

/**
 * @brief   Possible ADC failure causes.
 * @note    Error codes are architecture dependent and should not relied
 *          upon.
 */
typedef enum {
  ADC_ERR_DMAFAILURE = 0                    /**< DMA operations failure.    */
} adcerror_t;

/**
 * @brief   Type of a structure representing an ADC driver.
 */
typedef struct ADCDriver ADCDriver;

/**
 * @brief   ADC notification callback type.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object triggering the
 *                      callback
 * @param[in] buffer    pointer to the most recent samples data
 * @param[in] n         number of buffer rows available starting from @p buffer
 */
typedef void (*adccallback_t)(ADCDriver *adcp, adcsample_t *buffer, size_t n);

/**
 * @brief   ADC error callback type.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object triggering the
 *                      callback
 * @param[in] err       ADC error code
 */
typedef void (*adcerrorcallback_t)(ADCDriver *adcp, adcerror_t err);

/**
 * @brief   Conversion group configuration structure.
 * @details This implementation-dependent structure describes a conversion
 *          operation.
 * @note    Implementations may extend this structure to contain more,
 *          architecture dependent, fields.
 */
typedef struct {
  /**
   * @brief   Enables the circular buffer mode for the group.
   */
  uint8_t                   circular;
  /**
   * @brief   Number of the analog channels belonging to the conversion group.
   */
  adc_channels_num_t        num_channels;
  /**
   * @brief   Callback function associated to the group or @p NULL.
   */
  adccallback_t             end_cb;
  /**
   * @brief   Error callback or @p NULL.
   */
  adcerrorcallback_t        error_cb;
  /* End of the mandatory fields.*/
  /**
   * @brief   Initialization value for CFCR register.
   */
  uint16_t                  cfcr;
  /**
   * @brief   SIU ETISR.TSEL value for this queue;
   */
  uint8_t                   tsel;
  /**
   * @brief   SIU ISEL3.ETSEL value for this queue;
   */
  uint8_t                   etsel;
  /**
   * @brief   Number of command iterations stored in @p commands.
   * @note    The total number of array elements must be @p num_channels *
   *          @p num_iterations.
   * @note    This fields is the upper limit of the parameter @p n that can
   *          be passed to the functions @p adcConvert() and
   *          @p adcStartConversion().
   */
  uint32_t                  num_iterations;
  /**
   * @brief   Pointer to an array of low level EQADC commands to be pushed
   *          into the CFIFO during a conversion.
   */
  const adccommand_t        *commands;
} ADCConversionGroup;

/**
 * @brief   Driver configuration structure.
 * @note    Empty in this implementation can be ignored.
 */
typedef struct {
  uint32_t                  dummy;
} ADCConfig;

/**
 * @brief   Structure representing an ADC driver.
 */
struct ADCDriver {
  /**
   * @brief   Current configuration data.
   */
  const ADCConfig           *config;
  /**
   * @brief   Current samples buffer pointer or @p NULL.
   */
  adcsample_t               *samples;
  /**
   * @brief   Current samples buffer depth or @p 0.
   */
  size_t                    depth;
  /**
   * @brief   Current conversion group pointer or @p NULL.
   */
  const ADCConversionGroup  *grpp;
#if defined(ADC_DRIVER_EXT_FIELDS)
  ADC_DRIVER_EXT_FIELDS
#endif
  /* End of the mandatory fields.*/
  /**
   * @brief   CFIFO/RFIFO used by this instance.
   */
  adcfifo_t                 fifo;
  /**
   * @brief   EDMA channel used for the CFIFO.
   */
  edma_channel_t            cfifo_channel;
  /**
   * @brief   EDMA channel used for the RFIFO.
   */
  edma_channel_t            rfifo_channel;
};

/*===========================================================================*/
/* Inline functions                                                            */
/*===========================================================================*/
static inline
uint32_t ADC_CR_CLK_PS (uint32_t n){
	uint32_t retval;
	retval = (n>>1) -1UL;
	if ((n & 1UL) != 0UL) {
		retval |= ADC_CR_ODD_PS;
	}
	return retval;
}
/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/
/**
 * @brief   Common ISR code, half buffer event.
 * @details This code handles the portable part of the ISR code:
 *          - Callback invocation.
 *          .
 * @note    This macro is meant to be used in the low level drivers
 *          implementation only.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
#define _adc_isr_half_code(adcp) {                                          \
  if ((adcp)->grpp->end_cb != NULL) {                                       \
    (adcp)->grpp->end_cb(adcp, (adcp)->samples, (adcp)->depth / 2U);         \
  }                                                                         \
}

/**
 * @brief   Common ISR code, full buffer event.
 * @details This code handles the portable part of the ISR code:
 *          - Callback invocation.
 *          - Waiting thread wakeup, if any.
 *          - Driver state transitions.
 *          .
 * @note    This macro is meant to be used in the low level drivers
 *          implementation only.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
#define _adc_isr_full_code(adcp) {                                          \
  if ((adcp)->grpp->circular == TRUE) {                                     \
    /* Callback handling.*/                                                 \
    if ((adcp)->grpp->end_cb != NULL) {                                     \
      if ((adcp)->depth > 1U) {                                              \
        /* Invokes the callback passing the 2nd half of the buffer.*/       \
        size_t half = (adcp)->depth / 2U;                                    \
        size_t half_index = half * (adcp)->grpp->num_channels;              \
        (adcp)->grpp->end_cb(adcp, (adcp)->samples + half_index, half);     \
      }                                                                     \
      else {                                                                \
        /* Invokes the callback passing the whole buffer.*/                 \
        (adcp)->grpp->end_cb(adcp, (adcp)->samples, (adcp)->depth);         \
      }                                                                     \
    }                                                                       \
  }                                                                         \
  else {                                                                    \
    /* End conversion.*/                                                    \
    adc_lld_stop_conversion(adcp);                                          \
    if ((adcp)->grpp->end_cb != NULL) {                                     \
        if ((adcp)->depth > 1U) {                                            \
        /* Invokes the callback passing the 2nd half of the buffer.*/       \
        size_t half = (adcp)->depth / 2U;                                    \
        size_t half_index = half * (adcp)->grpp->num_channels;              \
        (adcp)->grpp->end_cb(adcp, (adcp)->samples + half_index, half);     \
      }                                                                     \
      else {                                                                \
        /* Invokes the callback passing the whole buffer.*/                 \
        (adcp)->grpp->end_cb(adcp, (adcp)->samples, (adcp)->depth);         \
      }                                                                     \
    }                                                                       \
  }                                                                         \
}

/**
 * @brief   Common ISR code, error event.
 * @details This code handles the portable part of the ISR code:
 *          - Callback invocation.
 *          - Waiting thread timeout signaling, if any.
 *          - Driver state transitions.
 *          .
 * @note    This macro is meant to be used in the low level drivers
 *          implementation only.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 * @param[in] err       platform dependent error code
 *
 * @notapi
 */
#define _adc_isr_error_code(adcp, err) {                                    \
  adc_lld_stop_conversion(adcp);                                            \
  if ((adcp)->grpp->error_cb != NULL) {                                     \
    (adcp)->grpp->error_cb(adcp, err);                                      \
  }                                                                         \
  (adcp)->grpp = NULL;                                                      \
}
/** @} */
/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if (SPC5_ADC_USE_ADC0_Q0 == TRUE) && !defined(__DOXYGEN__)
extern ADCDriver ADCD1;
#endif

#if (SPC5_ADC_USE_ADC0_Q1 == TRUE)&& !defined(__DOXYGEN__)
extern ADCDriver ADCD2;
#endif

#if (SPC5_ADC_USE_ADC0_Q2 == TRUE) && !defined(__DOXYGEN__)
extern ADCDriver ADCD3;
#endif

#if (SPC5_ADC_USE_ADC1_Q3 == TRUE) && !defined(__DOXYGEN__)
extern ADCDriver ADCD4;
#endif

#if (SPC5_ADC_USE_ADC1_Q4 == TRUE) && !defined(__DOXYGEN__)
extern ADCDriver ADCD5;
#endif

#if (SPC5_ADC_USE_ADC1_Q5 == TRUE) && !defined(__DOXYGEN__)
extern ADCDriver ADCD6;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void adc_lld_init(void);
  void adc_lld_start(ADCDriver *adcp,const ADCConfig *config);
  void adc_lld_stop(ADCDriver *adcp);
  void adc_lld_start_conversion (ADCDriver *adcp, const ADCConversionGroup *grpp, adcsample_t *samples, size_t depth);
  void adc_lld_stop_conversion(ADCDriver *adcp);
#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_ADC */

#endif /* _ADC_LLD_H_ */

/** @} */
