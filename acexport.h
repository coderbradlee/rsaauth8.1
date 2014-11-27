/* acexport.h -- required include file for ACE/Agent API calls */
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

#ifndef ACEXPORT_H
#define ACEXPORT_H

#include <time.h>


#ifdef WIN32
#pragma pack(push,8)
#endif

#ifdef  __cplusplus
extern "C" {
#endif

/*
 * we'll do this before including the header files.
 */
#ifndef WIN32 
#define WINAPI	/* must hide windows calling convention */
#define USE_ACE_AGENT_API_PROTOTYPES
#endif

#include "sdacmvls.h"       /* return codes from ACE/Server */
#include "acclnt.h"         /* return codes from AceXxx functions */
#include "sdi_defs.h"       /* definition of SD_CLIENT structure */
#include "sd_types.h"       /* new portability macros */

/*
 * This enum type is used 
 *  to tell the api what type of agent is installed
 */
typedef enum
{
   RSA_DA_AGENT_LOCAL=0,       
   RSA_DA_AGENT_DOMAIN=1,
   RSA_DA_AGENT_ANY=2,
   RSA_DA_AGENT_NONE=3
} RSA_DA_AGENT_TYPE;

/*
 * The AceDAGetAuthData() call uses this enum type
 *  to determin what attributes to return to the caller
 */
typedef enum
{
   RSA_DA_ATTR_AUTH_TIME,   /* The time the auth successfully matched       */
   RSA_DA_ATTR_POA ,         /* The Hash Derived POA Key associated with the     */
                            /* successful authentication                    */
   RSA_DA_ATTR_EAC_EXP,     /* If the authentication was an EAC auth, this  */
                            /* returns the date and time the EAC code used  */
                            /* will expire.                                 */
   RSA_DA_ATTR_TICKET,
   RSA_DA_ATTR_LOGIN_PW,
   RSA_DA_ATTR_HIGH_WATER_MARK,
   RSA_DA_ATTR_SERVER_LIST,
   RSA_DA_ATTR_DOWLOAD_STATUS,
   RSA_DA_ATTR_TOKEN_SERIAL,
   RSA_DA_ATTR_PASSWORD_CHANGED,
   RSA_DA_ATTR_POLICY_CHANGED,
   RSA_DA_ATTR_DADAYS,
   RSA_DA_ATTR_LPIENABLED,
   RSA_DA_ATTR_DAENABLED,
   RSA_DA_ATTR_SALT,
   RSA_DA_ATTR_LAST_AVAILABLE,
   RSA_DA_ATTR_OA_VERSION,
   RSA_DA_ATTR_PIN_LENGTH
           
} RSA_DA_ATTR;



#ifdef WIN32
#include "status_display.h"
#endif


/* Holds pin limits and related values */
typedef struct tagSD_PIN
{
	SD_CHAR Min;
    SD_CHAR Max;
    SD_CHAR Selectable;
    SD_CHAR Alphanumeric;
	SD_CHAR System[LENPRNST+2];
} SD_PIN;

/* ACE/Agent API handle */
typedef int SDI_HANDLE, * LP_SDI_HANDLE;

/* invalid ACE/Agent API handle */
#define SDI_HANDLE_NONE 0

/* 
 * Additional RSA_DA_ATTR used in AceGetDAAuthData (really to get
 * something out of the sUSER structure).
 */
#define RSA_DA_ATTR_DA_HANDLE       -1
#define RSA_DA_ATTR_IS_DISCONNECTED -2
#define RSA_DA_ATTR_DA_ADDRESS      -3
#define RSA_DA_ATTR_DA_PORT         -4
#define RSA_DA_ATTR_DA_STATE        -5  /* Same as AceGetDAuthenticationStatus */
#define RSA_DA_ATTR_DA_STATUS       -6  /* Status of the last call to AceDACheck */

/*
 * SET Attributes
 */
typedef enum 
{
    RSA_AUTH_SET_ATTR_LPI,              /* Login Password Integration */
    RSA_AUTH_SET_ATTR_DL_DAYFILES,      /* Download dayfiles */
    RSA_AUTH_SET_ATTR_RADIUS_PROFILE,   /* Third-party Auth Extension */
    RSA_AUTH_SET_ATTR_OFFLINE_AUTH,     /* Authenticate offline */
    RSA_AUTH_SET_ATTR___RESERVED__,     /* Reserved value */
    RSA_AUTH_SET_ATTR___RESERVED2__,    /* Reserved value */
    RSA_AUTH_SET_ATTR_DOMAIN_CLIENT_VERSION,       /* Indicate the domain agent client is 6.1 or after*/
    RSA_AUTH_SET_ATTR_AGENT_TYPE,        /* is it LAC or DAH installation */ 
    RSA_AUTH_SET_ATTR_RADIUS_EXTENSIONS, /* Radius User Extensions requested */
    RSA_AUTH_SET_ATTR_EAP32
    /* Insert any new SET attribute types here */
} RSA_AUTH_SET_ATTR;

/*
 * GET Attributes
 */
typedef enum 
{
    RSA_AUTH_GET_ATTR_RADIUS_PROFILE,   /* Get Radius profile */
    RSA_AUTH_GET_ATTR_RADIUS_EXTENSIONS,/* Get Radius user extensions */  
    RSA_AUTH_GET_ATTR_PIN_LENGTH,       /* Get user's PIN length */
    RSA_AUTH_GET_ATTR_EAP32_KEYS,   /* Get EAP Keys */
    RSA_AUTH_GET_ATTR_EAP32_PEPPER,     /* Get EAP data */
    RSA_AUTH_GET_ATTR_AUTHENTICATOR_ID, /* Get the user's token ID */
    RSA_AUTH_GET_ATTR_AUTH_HASH,        /* Get the authentication hash */
    RSA_AUTH_GET_ATTR_DOMAIN_CLIENT_VERSION,       /* Indicate the domain agent client is 6.1 or after*/
    RSA_AUTH_GET_ATTR_AGENT_TYPE,       /* is it LAC or DAH installation */
    RSA_AUTH_GET_ATTR_EAP32_MAC,        /* EAP32 MacA */
    RSA_AUTH_GET_ATTR_ENC_SYSTEM_PIN    /* Encrypted System Pin, for new pin mode */

    /* Insert any new GET attribute types here */
} RSA_AUTH_GET_ATTR;

/*
 * Authentication Credential Types
 */
typedef enum 
{
    RSA_AUTH_CRED_TYPE_PASSCODE,        /* Pass-code: Pin, Token-code, or both */
    RSA_AUTH_CRED_TYPE_EAP32,           /* EAP32 Auth Credential */
    RSA_AUTH_CRED_TYPE_EAP32_RESUME     /* EAP32 Session Resumption Auth Credential */
    /* Insert any new credential types here */
} RSA_AUTH_CRED_TYPE;


/* this is what our callbacks always look like */
typedef void (WINAPI *ACECALLBACK)(SDI_HANDLE);

/* Unix will use these prototypes always */
#ifdef USE_ACE_AGENT_API_PROTOTYPES

/* initialization and shutdown calls */
SD_BOOL WINAPI AceInitialize   ( void );
SD_BOOL WINAPI AceInitializeEx ( SD_CHAR *ConfigFile, SD_CHAR *SharedMemoryName, SD_U32 HashIndexSize );
SD_BOOL WINAPI AceShutdown     ( ACECALLBACK CleanupCallback );
void    WINAPI AceCleanup      ( ACECALLBACK CleanupCallback );

void    WINAPI AceDisableNodeSecretCache ( void );
void    WINAPI AceRefreshIP              ( void );

/* New Asynchronous and thread-safe calls */
int  WINAPI AceInit             ( LP_SDI_HANDLE, void *, ACECALLBACK );
int  WINAPI AceInitEx           ( LP_SDI_HANDLE, void *, ACECALLBACK, RSA_DA_AGENT_TYPE );
int  WINAPI AceLock             ( SDI_HANDLE, ACECALLBACK );
int  WINAPI AceCheck            ( SDI_HANDLE, ACECALLBACK );
int  WINAPI AceClientCheck      ( SDI_HANDLE, ACECALLBACK );
int  WINAPI AceSendNextPasscode ( SDI_HANDLE, ACECALLBACK );
int  WINAPI AceSendPin          ( SDI_HANDLE, ACECALLBACK );
int  WINAPI AceCancelPin        ( SDI_HANDLE,  ACECALLBACK );
int  WINAPI AceClose            ( SDI_HANDLE, ACECALLBACK );

int  WINAPI AceGetAuthenticationStatus ( SDI_HANDLE, SD_I32 * );
int  WINAPI AceGetMinPinLen     ( SDI_HANDLE, SD_CHAR * );
int  WINAPI AceGetMaxPinLen     ( SDI_HANDLE, SD_CHAR * );
int  WINAPI AceGetUserSelectable( SDI_HANDLE, SD_CHAR * );
int  WINAPI AceGetAlphanumeric  ( SDI_HANDLE, SD_CHAR * );
int  WINAPI AceGetSystemPin     ( SDI_HANDLE, SD_CHAR * );
int  WINAPI AceGetPinParams     ( SDI_HANDLE, SD_PIN* );
int  WINAPI AceGetUserData      ( SDI_HANDLE, void ** );
int  WINAPI AceGetLoginPW       ( SDI_HANDLE, SD_CHAR *, SD_U32 * );
int  WINAPI AceSetLoginPW       ( SDI_HANDLE, SD_CHAR * , SD_U32 );
int	 WINAPI	AceGetDAuthenticationStatus(SDI_HANDLE, INT32BIT *);
int  WINAPI AceGetDAAuthData    ( SDI_HANDLE, RSA_DA_ATTR, void *, SD_U32*);
int	 WINAPI AceGetAuthAttr		(SDI_HANDLE, RSA_AUTH_GET_ATTR, void *, SD_U32 *);
int  WINAPI AceGetTime          ( SDI_HANDLE, SD_I32 * );
int  WINAPI AceGetShell         ( SDI_HANDLE, SD_CHAR * );
int  WINAPI AceGetPepperPolicy  (SDI_HANDLE, char *, char *);
int  WINAPI AceGetIterCountPolicy(SDI_HANDLE, INT32BIT *, INT32BIT *);
int  WINAPI AceGetRealmID       ( SDI_HANDLE, char* );

int  WINAPI AceSetPasscode      ( SDI_HANDLE, SD_CHAR * );
int  WINAPI AceSetCredential    ( SDI_HANDLE, RSA_AUTH_CRED_TYPE, void *, SD_U32);
int  WINAPI AceSetUsername      ( SDI_HANDLE, SD_CHAR * );
int  WINAPI AceSetClientAddr    ( SDI_HANDLE, SD_U32 );
int  WINAPI AceSetNextPasscode  ( SDI_HANDLE, SD_CHAR * );
int  WINAPI AceSetNextCredential( SDI_HANDLE, void *, SD_U32 );
int  WINAPI AceSetPin           ( SDI_HANDLE, SD_CHAR * );
int  WINAPI AceSetPinCredential ( SDI_HANDLE, void *, SD_U32 );
int  WINAPI AceSetUserClientAddress ( SDI_HANDLE, SD_UCHAR * );
int  WINAPI AceSetUserData      ( SDI_HANDLE, void * );
int  WINAPI AceSetTimeout       ( SDI_HANDLE, time_t, ACECALLBACK );
int	 WINAPI AceSetAuthAttr		( SDI_HANDLE, RSA_AUTH_SET_ATTR, void *, SD_U32);

/* New Synchronous and thread-safe calls */
int  WINAPI SD_Init             ( LP_SDI_HANDLE );
int  WINAPI SD_InitEx           ( LP_SDI_HANDLE, SD_BOOL, RSA_DA_AGENT_TYPE );
int  WINAPI SD_Lock             ( SDI_HANDLE, SD_CHAR * );
int  WINAPI SD_Check            ( SDI_HANDLE, SD_CHAR *, SD_CHAR * );
int  WINAPI SD_CheckCredential  ( SDI_HANDLE, SD_CHAR *, RSA_AUTH_CRED_TYPE, void *, SD_U32 );
int  WINAPI SD_ClientCheck      ( SDI_HANDLE, SD_CHAR *, SD_CHAR *, SD_U32 );
int  WINAPI SD_ClientCheckCredential 
                                ( SDI_HANDLE, SD_CHAR *, RSA_AUTH_CRED_TYPE, void *, SD_U32, SD_U32 );
int  WINAPI SD_Next             ( SDI_HANDLE, SD_CHAR * );
int  WINAPI SD_NextCredential   ( SDI_HANDLE, void *, SD_U32 );
int  WINAPI SD_Pin              ( SDI_HANDLE, SD_CHAR * );
int  WINAPI SD_PinCredential    ( SDI_HANDLE, void *, SD_U32 );
int  WINAPI SD_Close            ( SDI_HANDLE );

/* New Synchronous and thread-safe calls */
SD_ERROR WINAPI AceStartAuth(LP_SDI_HANDLE,
    SD_CHAR *userID,         
    SD_I32 userIDLen,     
    SD_BOOL *moreData,    
    SD_BOOL *noEcho,      
    SD_I32 *respTimeout,  
    SD_I32 *nextRespLen,  
    SD_CHAR *promptStr,      
    SD_I32 *promptStrLen);

SD_ERROR WINAPI AceContinueAuth(SDI_HANDLE, 
    SD_CHAR *userID,         
    SD_I32 userIDLen,     
    SD_BOOL *moreData,    
    SD_BOOL *noEcho,      
    SD_I32 *respTimeout,  
    SD_I32 *nextRespLen,  
    SD_CHAR *promptStr,      
    SD_I32 *promptStrLen);

SD_ERROR WINAPI AceCloseAuth(SDI_HANDLE);

#else  /* !USE_ACE_AGENT_API_PROTOTYPES */

/* initialization and shutdown calls */
typedef SD_BOOL (WINAPI *ACEINITIALIZEPROC)   ( void );
typedef SD_BOOL (WINAPI *ACEINITIALIZEEXPROC) ( SD_CHAR *, SD_CHAR *, SD_U32 );
typedef SD_BOOL (WINAPI *ACESHUTDOWNPROC)     ( ACECALLBACK );
typedef void    (WINAPI *ACECLEANUPPROC)      ( ACECALLBACK );

typedef void    (WINAPI *ACEDISABLENODESECRETCACHE) ( void );
typedef void    (WINAPI *ACEREFRESHIP)              ( void );

/* New Asynchronous and thread-safe calls */
typedef int  (WINAPI *ACEINITPROC)              ( LP_SDI_HANDLE, void *, ACECALLBACK );
typedef int  (WINAPI *ACEINITEXPROC)            ( LP_SDI_HANDLE, void *, ACECALLBACK, RSA_DA_AGENT_TYPE );
typedef int  (WINAPI *ACELOCKPROC)              ( SDI_HANDLE, ACECALLBACK );
typedef int  (WINAPI *ACECHECKPROC)             ( SDI_HANDLE, ACECALLBACK );
typedef int  (WINAPI *ACECLIENTCHECKPROC)       ( SDI_HANDLE, ACECALLBACK );
typedef int  (WINAPI *ACESENDNEXTPASSCODEPROC)  ( SDI_HANDLE, ACECALLBACK );
typedef int  (WINAPI *ACESENDPINPROC)           ( SDI_HANDLE, ACECALLBACK );
typedef int  (WINAPI *ACECANCELPINPROC)         ( SDI_HANDLE,  ACECALLBACK );
typedef int  (WINAPI *ACECLOSEPROC)             ( SDI_HANDLE, ACECALLBACK );
typedef int  (WINAPI *ACEGETAUTHENTICATIONSTATUSPROC) ( SDI_HANDLE, SD_I32 * );
typedef int  (WINAPI *ACEGETMINPINLENPROC)      ( SDI_HANDLE, SD_CHAR * );
typedef int  (WINAPI *ACEGETMAXPINLENPROC)      ( SDI_HANDLE, SD_CHAR * );
typedef int  (WINAPI *ACEGETUSERSELECTABLEPROC) ( SDI_HANDLE, SD_CHAR * );
typedef int  (WINAPI *ACEGETALPHANUMERICPROC)   ( SDI_HANDLE, SD_CHAR * );
typedef int  (WINAPI *ACEGETSYSTEMPINPROC)      ( SDI_HANDLE, SD_CHAR * );
typedef int  (WINAPI *ACEGETPINPARAMSPROC)      ( SDI_HANDLE, SD_PIN * );
typedef int  (WINAPI *ACEGETUSERDATAPROC)       ( SDI_HANDLE, void ** );
typedef int  (WINAPI *ACEGETLOGINPWPROC)        ( SDI_HANDLE, SD_CHAR *, SD_U32 * );
typedef int  (WINAPI *ACESETLOGINPWPROC)        ( SDI_HANDLE, SD_CHAR *, SD_U32 );
typedef int	 (WINAPI *ACEGETDAUTHENTICATIONSTATUSPROC)	(SDI_HANDLE, INT32BIT *);
typedef int  (WINAPI *ACEGETDAAUTHDATAPROC)		( SDI_HANDLE, int, void *, SD_U32*);
typedef int  (WINAPI *ACEGETTIMEPROC)           ( SDI_HANDLE, SD_I32 * );
typedef int  (WINAPI *ACEGETSHELLPROC)          ( SDI_HANDLE, SD_CHAR * );
typedef	int	 (WINAPI *ACEGETAUTHATTRPROC)        ( SDI_HANDLE, RSA_AUTH_GET_ATTR, void *, SD_U32 *);
typedef int  (WINAPI *ACESETPASSCODEPROC)       ( SDI_HANDLE, SD_CHAR * );
typedef int  (WINAPI *ACESETCREDENTIALPROC)         ( SDI_HANDLE, RSA_AUTH_CRED_TYPE, void *, SD_U32);
typedef int  (WINAPI *ACESETUSERNAMEPROC)       ( SDI_HANDLE, SD_CHAR * );
typedef int  (WINAPI *ACESETCLIENTADDRPROC)     ( SDI_HANDLE, SD_U32 );
typedef int  (WINAPI *ACESETNEXTPASSCODEPROC)   ( SDI_HANDLE, SD_CHAR * );
typedef int  (WINAPI *ACESETNEXTCREDENTIALPROC) ( SDI_HANDLE, void *, SD_U32 );
typedef int  (WINAPI *ACESETPINPROC)            ( SDI_HANDLE, SD_CHAR * );
typedef int  (WINAPI *ACESETPINCREDENTIALPROC)  ( SDI_HANDLE, void *, SD_U32 );
typedef int  (WINAPI *ACESETUSERCLIENTADDRESSPROC) ( SDI_HANDLE, SD_UCHAR * );
typedef int  (WINAPI *ACESETUSERDATAPROC)       ( SDI_HANDLE, void * );
typedef int  (WINAPI *ACESETTIMEOUTPROC)        ( SDI_HANDLE, time_t, ACECALLBACK );
typedef int  (WINAPI *ACEAGENTSTATUSDISPLAYPROC) ( S_status_display * );
typedef	int  (WINAPI *ACESETAUTHATTRPROC)        ( SDI_HANDLE, RSA_AUTH_SET_ATTR, void *, SD_U32);
typedef int  (WINAPI *ACEGETPEPPERPOLICYPROC)    ( SDI_HANDLE, char *, char * );
typedef int  (WINAPI *ACEGETITERCOUNTPOLICYPROC) ( SDI_HANDLE, INT32BIT *, INT32BIT * );
typedef int  (WINAPI *ACEGETREALMIDPROC)         ( SDI_HANDLE, char* );

/* New Synchronous and thread-safe calls */
typedef int  (WINAPI *NEWSDINITPROC)        ( LP_SDI_HANDLE );
typedef int  (WINAPI *NEWSDINITEXPROC)      ( LP_SDI_HANDLE, SD_BOOL, RSA_DA_AGENT_TYPE );
typedef int  (WINAPI *NEWSDLOCKPROC)        ( SDI_HANDLE, SD_CHAR * );
typedef int  (WINAPI *NEWSDCHECKPROC)       ( SDI_HANDLE, SD_CHAR *, SD_CHAR * );
typedef int  (WINAPI *NEWSDCHECKCREDENTIALPROC) 
                                            ( SDI_HANDLE, SD_CHAR *, RSA_AUTH_CRED_TYPE, void *, SD_U32);
typedef int  (WINAPI *NEWSDCLIENTCHECKCREDENTIALPROC) 
                                            ( SDI_HANDLE, SD_CHAR *, RSA_AUTH_CRED_TYPE, void *, SD_U32, SD_U32 );
typedef int  (WINAPI *NEWSDCLIENTCHECKPROC) ( SDI_HANDLE, SD_CHAR *, SD_CHAR *, SD_U32 );
typedef int  (WINAPI *NEWSDNEXTPROC)        ( SDI_HANDLE, SD_CHAR * );
typedef int  (WINAPI *NEWSDNEXTCREDENTIALPROC)
                                            ( SDI_HANDLE, void *, SD_U32 );
typedef int  (WINAPI *NEWSDPINPROC)         ( SDI_HANDLE, SD_CHAR * );
typedef int  (WINAPI *NEWSDPINCREDENTIALPROC)
                                            ( SDI_HANDLE, void *, SD_U32 );
typedef int  (WINAPI *NEWSDCLOSEPROC)       ( SDI_HANDLE );

/* New Synchronous and thread-safe calls */
typedef SD_ERROR (WINAPI *ACESTARTAUTHPROC)(LP_SDI_HANDLE,
    SD_CHAR *userID,         
    SD_I32 userIDLen,     
    SD_BOOL *moreData,    
    SD_BOOL *noEcho,      
    SD_I32 *respTimeout,  
    SD_I32 *nextRespLen,  
    SD_CHAR *promptStr,      
    SD_I32 *promptStrLen);

typedef SD_ERROR (WINAPI *ACECONTINUEAUTHPROC)(SDI_HANDLE, 
    SD_CHAR *userID,         
    SD_I32 userIDLen,     
    SD_BOOL *moreData,    
    SD_BOOL *noEcho,      
    SD_I32 *respTimeout,  
    SD_I32 *nextRespLen,  
    SD_CHAR *promptStr,      
    SD_I32 *promptStrLen);

typedef SD_ERROR (WINAPI *ACECLOSEAUTHPROC)(SDI_HANDLE);

#endif /* USE_ACE_AGENT_API_PROTOTYPES */

#ifdef  __cplusplus
}
#endif

#ifdef WIN32
#pragma pack(pop)
#endif

#endif /* !ACEXPORT_H */
