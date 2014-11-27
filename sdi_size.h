/* sdi_size.h */
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

/* this file contains ACE Portability definitions. */

#ifndef _SDI_SIZE
#define _SDI_SIZE

#define LENID 6
#define LENPIN 12
#define LENSER 12
#define LENLOGID 32
#define LENPRNST 16
#define LENPATH 64
#define LENTITLE 40
#define LENACMFILE 64
#define LENHOSTNAME 64
#define LENACMNAME 32
#define LENUSERNAME 64
#define LENUSERNAME_61 128
#define LENSECRET 16
#define LENMAXPIN 16
#define LENMAXPIN_61 32
#define LENSEQNUM 8
#define LENMSGSTRING 256
#define LENFULLPATH 1024
#define LENAUCHBUFF 1024
#define LENSYSCMD 2048
#define SOCKET_BUFFER_LEN 4096
#define MAX_RESPONSE_DATA	100
#define LENREALMID 24

#define MAX_LENPRN 8		/*Max size of PRN */

#define BATCH_NUMPRNS      9    /*  for batch mode  */
#define SPECIAL_NUMPRNS    7    /*  for special mode  */

#define LENPASCD 20             /* parsed passcode 8 + 1 + 8 + slop     */
#define LENSHELL LENACMNAME     /* better name for api users            */
#define LENCERTIFICATE 35

/* Length that user data gets hashed into */
#define CERT_USER_DATA_HASH_LEN 36


#endif /* _SDI_SIZE */

