/* sd_types.h */
/******************************************************************************
*                  COPYRIGHT © 1995-2011 EMC CORPORATION                     **
*                         ---ALL RIGHTS RESERVED---                           *
*                                                                             *
* THIS SOFTWARE IS PROPRIETARY AND CONFIDENTIAL TO EMC CORPORATION  , IS      *
* FURNISHED UNDER A LICENSE AND MAY BE USED AND COPIED ONLY IN ACCORDANCE THE *
* TERMS OF SUCH LICENSE AND WITH THE INCLUSION OF THE ABOVE COPYRIGHT NOTICE. *
* THIS SOFTWARE OR ANY OTHER COPIES THEREOF MAY NOT BE PROVIDED OR OTHERWISE  *
* MADE AVAILABLE TO ANY OTHER PERSON.  NO TITLE TO AND OWNERSHIP OF THE       *
* SOFTWARE IS HEREBY TRANSFERRED.                                             *
*                                                                             *
* THE INFORMATION IN THIS SOFTWARE IS SUBJECT TO CHANGE WITHOUT NOTICE AND    *
* SHOULD NOT BE CONSTRUED AS A COMMITMENT BY EMC CORPORATION                  *
******************************************************************************/

#ifndef _SD_TYPES_H
#define _SD_TYPES_H

/*
 * Characters
 */

typedef char          SD_CHAR;  /* ch or sz */
typedef signed char   SD_SCHAR; /* sch */
typedef unsigned char SD_UCHAR; /* uch */

/*
 * Integers 
 */

typedef signed char   SD_I8; /* i8 */
typedef unsigned char SD_U8; /* u8 */

typedef signed int     SD_I32;      /* i32 */
typedef unsigned int   SD_U32;      /* u32 */
typedef signed short   SD_I16;      /* i16 */
typedef unsigned short SD_U16;      /* u16 */

 /* Booleans.*/

typedef SD_I32 SD_BOOL;                 /* b */
#define SD_TRUE ((SD_BOOL) 1)
#define SD_FALSE ((SD_BOOL) 0)

/*
 * misc. dirived types
 */

typedef char WPCODE[16];

typedef SD_U32 SD_ERROR;                /* err */

typedef SD_U32 SD_ACM_TIME;            /* seconds since 1/1/86 GMT */

/* 
 * Time Of Day
 */

typedef SD_U32 SD_TOD;                   /* tod is seconds since midnite */
#define SD_HOURMULTIPLE 3600L
#define SD_MINMULTIPLE 60L

/*
 * Supporting multiple language platform
 */
typedef SD_I16 SD_LANGUAGE;

#define SD_LANGUAGE_UNKNOWN -1
#define SD_ENGLISH          0
#define SD_JAPANESE         1

/*** Note: P_SD_DATE typedef is redundant and must be fixed later.  **/ 

#define SD_DATE_LEN 13

typedef char SD_DATE[SD_DATE_LEN];      /* dt */
typedef char (*P_SD_DATE)[SD_DATE_LEN]; /* pdt */


/* this is a generic handle, each api can use it differently */
typedef unsigned long SD_HANDLE;

#endif

