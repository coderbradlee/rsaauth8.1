/* status_display.h -- definitions for status_display API */
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

#ifndef __STATUS_DISPLAY_H
#define __STATUS_DISPLAY_H

#define DISP_MAX_SERVERS    15      /* four extra entries in order to resolve first 4 servers	*/

#define DISP_MAXALIASES     10

#define DISP_LENHOSTNAME    256

/*
 * This structure holds the information for each server in the
 * replication array. Any server specific flags and options are
 * set in the struct. 
 */

typedef struct
{
    SD_U32      addr;                       /* server IP address - set to real addr as soon as 
                                               it is known, may be an alias before then */
    SD_U32      active_addr;                /* active addr when available */ 
    SD_U32      aliases[DISP_MAXALIASES];   /* server IP address aliases */
    SD_UCHAR    alias_options;              /* from sdopts,see IGNORE_ALIAS_OPTION etc  */
    SD_UCHAR    display_status;             /* server status reformatted for easy display */
    SD_CHAR     hostname[DISP_LENHOSTNAME]; /* host name when available */

} DISP_SRVR_INFO;

/* display_status values */

#define DISP_STATUS_ADDR_VERIFIED   0x0080  /* addr field is same addr that the servers use to 
                                               identify the server, verified by sdconf.rec
                                               or info from a server */
#define DISP_STATUS_PRIMARY         0x0040  /* Primary Server  */

#define DISP_STATUS_SELECTABLE      0x0020  /* selectable for authentications */

#define DISP_STATUS_EMERGENCY       0x0010  /* emergency_only server */

#define DISP_STATUS_SUSPENDED       0x0008  /* server is suspended */ 

#define DISP_MSTR_SLAVE             0x0004  /* master or slave */           


/* option values */

#define DISP_ALIASES_ONLY_OPTION    0x0002

#define DISP_IGNORE_ALIASES_OPTION  0x0001

/*
 * Below is the  structure used to describe the status.
 */

typedef struct
{
    SD_U32 u32Size;                         /* must be set = sizeof S_status_display */
    SD_I32 config_version;                  /* sdconf version considering extension */
    SD_I32 acmmaxservers;                   /* Maximum number of servers from SDCONF.REC */
    SD_I32 acmmaxreplicas;                  /* Maximum number of replica servers 
                                               may be as high as MAXCONFIG_SERVERS */
    SD_I32 acmmaxretries;                   /* Maximum number of retries */
    SD_I32 acmbasetimeout;                  /* Base timeout value */
    SD_I32 use_des;                         /* Use DES algorithm or ours */
    SD_I32 trusted;                         /* Secure name resolution? */

    SD_I32 acmport;                         /* port number (socket) */
    SD_CHAR acmservice[32];                 /* /etc/services value string */
    SD_CHAR acmprotocol[4];                 /* protocol for /etc/services */

    SD_UCHAR server_hi_protocol;            /* highest message protocol server understands */
    SD_UCHAR default_alias_options;         /* see DISP_IGNORE_ALIAS_OPTION etc */

    SD_UCHAR server_release_from_server[4]; /* server release when sent from a server */

    DISP_SRVR_INFO acm_servers[DISP_MAX_SERVERS];   /* server information array */
} S_status_display;

#if defined(__cplusplus)
extern "C" {
#endif

SD_I32 WINAPI AceAgentStatusDisplay( S_status_display * );

#if defined(__cplusplus)
}
#endif

#endif /* __STATUS_DISPLAY_H */
