/* Acclnt.h -- common include file for ACECLNT sources */
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


#ifndef _ACCLNT_H
#define _ACCLNT_H

/* AceXxxx calls error codes */
#define ACE_SUCCESS                     1

#define ACE_ERR_START                   100
#define ACE_ERR_INVALID_HANDLE          ACE_ERR_START+1
#define ACE_ERR_NOT_INITIALIZED         ACE_ERR_START+2

/* these two used to be separate values, they are now obsolete but this */
/* will let legacy code compile without modifications */
#define ACE_CHECK_INVALID_HANDLE        ACE_ERR_INVALID_HANDLE
#define ACE_CLOSE_INVALID_HANDLE        ACE_ERR_INVALID_HANDLE

#define ACE_PROCESSING                  150

#define ACE_START                       200
#define ACE_CFGFILE_NOT_FOUND           ACE_START+1
#define ACE_CFGFILE_READ_FAIL           ACE_START+2
#define ACE_EVENT_CREATE_FAIL           ACE_START+3
#define ACE_SEMAPHORE_CREATE_FAIL       ACE_START+4
#define ACE_THREAD_CREATE_FAIL	        ACE_START+5
#define ACE_SOCKET_LIB_NOT_FOUND        ACE_START+6
#define ACE_PTHREAD_FAIL                ACE_START+7
#define ACE_PTHREAD_CREATE_FAIL         ACE_START+8
#define ACE_PTHREADATTR_FAIL            ACE_START+9
#define ACE_PTHREADATTR_CREATE_FAIL     ACE_START+10
#define ACE_PTHREADCONDVAR_CREATE_FAIL  ACE_START+11
#define ACE_PTHREADMUTEX_CREATE_FAIL    ACE_START+12

#define ACE_NET_START                   300
#define ACE_NET_SEND_PACKET_FAIL        ACE_NET_START+1
#define ACE_NET_WAITING_TIMEOUT         ACE_NET_START+2

#define ACE_INIT_START                  400
#define ACE_INIT_NO_RESOURCE            ACE_INIT_START+2
#define ACE_INIT_SOCKET_FAIL            ACE_INIT_START+3
#define ACE_INIT_SYNCRONIZE_FAIL        ACE_INIT_START+4

#define ACE_CHECK_START                 500
#define ACE_CHECK_PIN_REQ_NOT_KNOWN     ACE_CHECK_START+2

#define ACE_TOO_MANY_CALLERS            700
#define ACE_NOT_ENOUGH_STORAGE          750
#define ACE_INVALID_ARG                 800

#define ACE_UNDEFINED                   900
#define ACE_UNDEFINED_USERNAME          ACE_UNDEFINED+1
#define ACE_UNDEFINED_PASSCODE          ACE_UNDEFINED+2
#define ACE_UNDEFINED_NEXT_PASSCODE     ACE_UNDEFINED+3
#define ACE_UNDEFINED_PIN               ACE_UNDEFINED+4
#define ACE_UNDEFINED_CLIENTADDR        ACE_UNDEFINED+5

#define ACE_DA_START					1000
#define ACE_DA_INVALID_PASSWORD			ACE_DA_START +1


#endif


