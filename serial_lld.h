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
 * @file    serial_lld.h
 * @brief   SPC5xx SERIAL low level driver header.
 *
 * @addtogroup SERIAL
 * @{
 */

#ifndef _SERIAL_LLD_H_
#define _SERIAL_LLD_H_

#include "spc5_lld.h"
#include "lldconf.h"

#if (LLD_USE_SERIAL == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    Serial port modes
 * @{
 */
#define SD_MODE_PARITY_MASK     0x03U       /**< @brief Parity field mask.  */
#define SD_MODE_PARITY_NONE     0x00U       /**< @brief No parity.          */
#define SD_MODE_PARITY_EVEN     0x01U       /**< @brief Even parity.        */
#define SD_MODE_PARITY_ODD      0x02U       /**< @brief Odd parity.         */

#define SD_MODE_NORMAL          0x00U       /**< @brief Normal operations.  */
#define SD_MODE_LOOPBACK        0x80U       /**< @brief Internal loopback.  */
/** @} */

/**
 * @name    Serial buffer state
 * @{
 */
#define SERIAL_BUFFER_OK        (1UL << 1)  /**< @brief serial buffer is OK.    */
#define SERIAL_BUFFER_EMPTY     (1UL << 2)  /**< @brief serial buffer is emply. */
#define SERIAL_BUFFER_FULL      (1UL << 3)  /**< @brief serial buffer is full.  */
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @brief   eSCI-A driver enable switch.
 * @details If set to @p TRUE the support for eSCI-A is included.
 * @note    The default is @p TRUE.
 */
#if !defined(SPC5_USE_ESCIA) || defined(__DOXYGEN__)
#define SPC5_USE_ESCIA                      FALSE
#endif

/**
 * @brief   eSCI-B driver enable switch.
 * @details If set to @p TRUE the support for eSCI-B is included.
 * @note    The default is @p TRUE.
 */
#if !defined(SPC5_USE_ESCIB) || defined(__DOXYGEN__)
#define SPC5_USE_ESCIB                      FALSE
#endif

/**
 * @brief   eSCI-C driver enable switch.
 * @details If set to @p TRUE the support for eSCI-C is included.
 * @note    The default is @p TRUE.
 */
#if !defined(SPC5_USE_ESCIC) || defined(__DOXYGEN__)
#define SPC5_USE_ESCIC                      FALSE
#endif

/**
 * @brief   eSCI-A interrupt priority level setting.
 */
#if !defined(SPC5_ESCIA_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_ESCIA_PRIORITY                 8
#endif

/**
 * @brief   eSCI-B interrupt priority level setting.
 */
#if !defined(SPC5_ESCIB_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_ESCIB_PRIORITY                 8
#endif

/**
 * @brief   eSCI-C interrupt priority level setting.
 */
#if !defined(SPC5_ESCIC_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_ESCIC_PRIORITY                 8
#endif

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if (SPC5_USE_ESCIA == TRUE) && (SPC5_HAS_ESCIA == FALSE)
#error "eSCI-A not present in the selected device"
#endif

#if (SPC5_USE_ESCIB == TRUE) && (SPC5_HAS_ESCIB == FALSE)
#error "eSCI-B not present in the selected device"
#endif

#if (SPC5_USE_ESCIC == TRUE) && (SPC5_HAS_ESCIC == FALSE)
#error "eSCI-C not present in the selected device"
#endif

#if (SPC5_USE_ESCIA == FALSE) && (SPC5_USE_ESCIB == FALSE) && (SPC5_USE_ESCIC == FALSE)
#error "SERIAL driver activated but no eSCI peripheral assigned"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Generic Serial Driver configuration structure.
 * @details An instance of this structure must be passed to @p sdStart()
 *          in order to configure and start a serial driver operations.
 * @note    This structure content is architecture dependent, each driver
 *          implementation defines its own version and the custom static
 *          initializers.
 */
typedef struct {
  /**
   * @brief Bit rate.
   */
  uint32_t                  sc_speed;
  /**
   * @brief Mode flags.
   */
  uint8_t                   sc_mode;
} SerialConfig;

/**
 * @brief   Structure representing the Serial buffer.
 */
typedef struct {
  /**
  * @brief  Serial buffer.
  */
  uint8_t                   buffer[SERIAL_BUFFERS_SIZE];
  /**
  * @brief  Pointer to the current write position in the buffer.
  */
  uint8_t                   *wrptr;
  /**
  * @brief  Pointer to the current read position in the buffer.
  */
  uint8_t                   *rdptr;
  /**
  * @brief  Number of available bytes in the buffer.
  */
  uint16_t                  counter;
} SerialBuffer;
  
/**
 * @brief   Structure representing the Serial driver.
 */
typedef struct {
  /**
  * @brief Input circular buffer.
  */
  SerialBuffer              ib;
  /**
  * @brief Output circular buffer.
  */
  SerialBuffer              ob;
  /**
  * @brief Pointer to the volatile eSCI registers block.
  */
  volatile struct ESCI_tag  *escip;
}SerialDriver;

/**
* @brief   Serial buffer state.
*/
typedef uint32_t sbstate_t;

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* IRQ Handlers.                                                             */
/*===========================================================================*/

IRQ_HANDLER(SPC5_ESCIA_HANDLER);
IRQ_HANDLER(SPC5_ESCIB_HANDLER);
IRQ_HANDLER(SPC5_ESCIC_HANDLER);

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if (SPC5_USE_ESCIA == TRUE) && !defined(__DOXYGEN__)
extern SerialDriver SD1;
#endif

#if (SPC5_USE_ESCIB == TRUE) && !defined(__DOXYGEN__)
extern SerialDriver SD2;
#endif

#if (SPC5_USE_ESCIC == TRUE) && !defined(__DOXYGEN__)
extern SerialDriver SD3;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void sd_lld_init(void);
  void sd_lld_start(SerialDriver *sdp, const SerialConfig *config);
  void sd_lld_stop(SerialDriver *sdp);
  size_t sd_lld_write(SerialDriver *sdp, uint8_t *buffer, size_t len);
  size_t sd_lld_read(SerialDriver *sdp, uint8_t *buffer, size_t len);
#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_SERIAL */

#endif /* _SERIAL_LLD_H_ */

/** @} */
