/* sdi_athd.h - client includes */
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

/* 11/08/2000 - Made the same as the ACE/Server definitions */

#ifndef _SDI_ATHD
#define _SDI_ATHD

#include "sdi_defs.h"

#ifdef WIN32
#pragma pack(8)
#endif

typedef struct stolen_store {
    INT32BIT key;
    char pin;
    char prn[LENPRNST];
} stolen_store;

typedef struct SD_CLIENT {

    INT16BIT application_id;
    unsigned char circuit_id;
    char username[LENACMNAME];
    passkey wpcodes[4];
    INT32BIT passcode_time;
    char validated_passcode[LENPRNST];
    char shell[LENACMFILE];             /* outputs from acm_ok          */

    char ignition_key[16];              /* outputs from acm_pc_ok       */
    char new_key[16];
    char release_code;
    char protectdir[LENACMFILE];

    INT32BIT time_delta;                /* acm_time                     */

    INT32BIT timeout;                   /* next prn param               */

    struct stolen_store steal_check[3]; /* stolen card check storage    */

    char fixed_pin_size;                /* fixed size pin               */

    char system_pin[16];                /* new pin params               */
    char min_pin_len;
    char max_pin_len;
    char user_selectable;
    char alphanumeric;

    /* for next code and new pin during valid admin requests */
    UINT32BIT u32UserNum;
    UINT32BIT u32AdminType;

} SD_CLIENT, * LP_SD_CLIENT;

#ifdef WIN32
#pragma pack()
#endif

#ifdef WIN32    /* WIN32 NT */

// a WINAPI equivalent
#define AGENTDLLCALL __stdcall

#ifndef USE_ACE_AGENT_API_PROTOTYPES

/* "Old" non-thread-safe API calls */
typedef int  (AGENTDLLCALL *SDINITPROC)  ( LP_SD_CLIENT );
typedef int  (AGENTDLLCALL *SDCHECKPROC) ( char *, char *, LP_SD_CLIENT );
typedef int  (AGENTDLLCALL *SDNEXTPROC)  ( char *, LP_SD_CLIENT );
typedef int  (AGENTDLLCALL *SDPINPROC)   ( char *, char, LP_SD_CLIENT );
typedef void (AGENTDLLCALL *SDCLOSEPROC) ( void );

#else  /* !USE_ACE_AGENT_API_PROTOTYPES */

/* "Old" non-thread-safe API calls */
int  AGENTDLLCALL sd_init  ( LP_SD_CLIENT );
int  AGENTDLLCALL sd_check ( char *, char *, LP_SD_CLIENT );
int  AGENTDLLCALL sd_next  ( char *, LP_SD_CLIENT );
int  AGENTDLLCALL sd_pin   ( char *, char, LP_SD_CLIENT );
void AGENTDLLCALL sd_close ( void );

#endif /* !USE_ACE_AGENT_API_PROTOTYPES */

#else   /* Unix will use these prototypes */

/* "Old" non-thread-safe API calls */
int  sd_init  ( LP_SD_CLIENT sd );
int  sd_check ( char * passcode, char * username, LP_SD_CLIENT sd );
int  sd_next  ( char * nextcode, LP_SD_CLIENT sd );
int  sd_pin   ( char * pin, char canceled, LP_SD_CLIENT sd );
void sd_close ( void );

#endif /* #ifdef WIN32 */

#endif

