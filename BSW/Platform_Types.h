/*
 * Platform_Types.h - AUTOSAR Platform Types for Infineon TC377
 *
 *  Created on: 2023-xx-xx
 *      Author: BSW Team
 *
 *  Description: This file contains the platform-specific type definitions
 *               for Infineon TC377 TriCore architecture
 */

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

/* Platform Type Definitions for TriCore TC377 */

/* CPU register type width */
#define CPU_TYPE_32             (8u)    /* 32-bit CPU */
#define CPU_TYPE_16             (16u)   /* 16-bit CPU */
#define CPU_TYPE_8              (8u)    /* 8-bit CPU */

/* Byte order definition */
#define MSB_FIRST               (0u)    /* Big endian bit ordering */
#define LSB_FIRST               (1u)    /* Little endian bit ordering */

/* Bit order definition */
#define HIGH_BYTE_FIRST         (0u)    /* Big endian byte ordering */
#define LOW_BYTE_FIRST          (1u)    /* Little endian byte ordering */

/* Platform characteristics for TC377 */
#define CPU_TYPE                CPU_TYPE_32
#define CPU_BIT_ORDER           LSB_FIRST
#define CPU_BYTE_ORDER          LSB_FIRST

/* Signed integer types */
typedef signed char         sint8;

typedef signed short        sint16;

typedef signed int          sint32;

#if defined (__GNUC__) && !defined (__CC_ARM)
/* For GCC TriCore compiler */
typedef signed long long    sint64;
#else
/* For other compilers */
typedef signed long long    sint64;
#endif

/* Unsigned integer types */
typedef unsigned char       uint8;

typedef unsigned short      uint16;

typedef unsigned int        uint32;

#if defined (__GNUC__) && !defined (__CC_ARM)
/* For GCC TriCore compiler */
typedef unsigned long long  uint64;
#else
/* For other compilers */
typedef unsigned long long  uint64;
#endif

/* Least types (minimum size, may be larger) */
typedef signed char         sint8_least;

typedef signed short        sint16_least;

typedef signed int          sint32_least;

typedef unsigned char       uint8_least;

typedef unsigned short      uint16_least;

typedef unsigned int        uint32_least;

/* Boolean type */
#ifndef _BOOL_DEFINED
#define _BOOL_DEFINED
#endif

typedef unsigned char       boolean;

/* Volatile types (for memory-mapped registers) */
typedef volatile uint8      vuint8;

typedef volatile uint16     vuint16;

typedef volatile uint32     vuint32;

typedef volatile uint64     vuint64;

typedef volatile sint8      vsint8;

typedef volatile sint16     vsint16;

typedef volatile sint32     vsint32;

typedef volatile sint64     vsint64;

#endif /* PLATFORM_TYPES_H */