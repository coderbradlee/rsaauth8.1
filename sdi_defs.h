/* sdi_defs.h */
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

#ifndef _SDI_DEFS
#define _SDI_DEFS

/* valid delimiters for PIN/PRN combination */
#define DELIMITER " \t\\/;:,"

/* Action codes for user selectable pins. */

#define SELECT_PIN              0
#define DEFER_PIN               1

/* options codes for user selectable pins */

#define CANNOT_CHOOSE_PIN	0
#define USER_SELECTABLE		1
#define MUST_CHOOSE_PIN		2

/* sdtermio flags */
#define SDI_ECHO 0
#define SDI_NO_ECHO 1

#ifndef TRUE
#define TRUE  1
#define FALSE 0
#endif

#ifndef FAIL
#define FAIL -1
#endif

#ifndef NULL
#define NULL 0
#endif

/* typedef statements for frequently used types */

#include "sdi_type.h"

/* Definitions of lengths for api parameters. */

#include "sdi_size.h"

#endif

