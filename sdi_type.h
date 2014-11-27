/* sdi_type.h */
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
 
/* this file contains typedef declarations for ACE/Server data structures */
 
#ifndef _SDI_TYPE
#define _SDI_TYPE

/********* 32 bit integers for portability consideration ******************/
 
typedef int INT32BIT;
typedef unsigned int UINT32BIT;
 
/********** 16 bit integers for portability consideration ****************/

typedef short INT16BIT;
typedef unsigned short UINT16BIT;

typedef unsigned char BOOLEAN;

typedef char passkey[16];

typedef unsigned char doskey[8];

#endif
