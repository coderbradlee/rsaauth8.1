/* sdacmvls.h - securid protocol */
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

#ifndef _SDACMVLS

/* message status codes for ACM_RESP_MSG.status */

#define ACM_OK                      0
#define ACM_ACCESS_DENIED           1
#define ACM_NEXT_CODE_REQUIRED      2
#define ACM_NEXT_CODE_BAD           4
#define ACM_NEW_PIN_REQUIRED        5
#define ACM_NEW_PIN_ACCEPTED        6
#define ACM_NEW_PIN_REJECTED        7
#define ACM_SHELL_OK                8
#define ACM_SHELL_BAD               9
#define ACM_TIME_OK                 10
#define ACM_SUSPECT_ACK             13

#define ACM_LOG_ACK                 16

/* client only values */
#define ACM_NO_SERVER               23
#define ACM_INVALID_SERVER          24

/* A/S V5.0 - new status values */
#define ACM_OK_2				    25
#define	ACM_DOWNGRADE			    26
#define ACM_ACK_NAMELOCK		    27

/* A/S V6.1 - new status values */
#define ACM_OK_5                    28
#define ACM_EAP_INVALID_PEPPER      29

/* sd_auth result; no chars entered, ignore entry */
#define ACM_ENTRY_ERR -1

#define _SDACMVLS
#endif

