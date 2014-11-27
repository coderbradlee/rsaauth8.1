/******************************************************************************
*                      COPYRIGHT ? 2011 EMC CORPORATION                       *
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
* SHOULD NOT BE CONSTRUED AS A COMMITMENT BY EMC CORPORATION.                 *
******************************************************************************/
// sd_auth.c : Defines the entry point for the console application.
//

#ifdef WIN32
#include <windows.h>
#define sleep(x)    Sleep(x*1000)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef WIN32
#include <termio.h>
#include <fcntl.h>
#endif

// in NT this allows using the aceclnt.lib file for linking
#define USE_ACE_AGENT_API_PROTOTYPES
#include "acexport.h"

#ifndef WIN32
int sd_echo_off(void);
int sd_echo_on(void);
#endif

// safe prompt function
static int promptUser( const char *prompt, char * buf, const int bufsize )
{
    int i;

    // flush pre-typing if terminal I/O
    //fflush(stdin);

    // tel the user what to do
    printf(prompt);

    // get the response
    if (0 == fgets(buf, bufsize, stdin))
        return 0;

    // remove line ender, two for NT
    i = strlen(buf);
    if (buf[i] < ' ')
        buf[i--] = 0;
    if (buf[i] < ' ')
        buf[i--] = 0;

    return 1;
}

///////////////////////////////////////////////////////////////////////////////
// this function is a demonstration of the use of the new synchronous API
// defined by the calls AceStartAuth(), AceContinueAuth(), and AceCloseAuth().
// Please notice the use of the AceGetAuthenticationStatus() call before the
// AceCloseAuth() call to determine the final authentication result.
//
SD_BOOL authenticate(char *username,char* passcode)
{
    SDI_HANDLE  aceHdl;
    SD_CHAR     resp[128];
    SD_CHAR     prompt[512];
    SD_I32      promptLen;
    SD_I32      nextRespLen;
    SD_I32      respTimeout;
    SD_BOOL     moreFlag;
    SD_BOOL     noechoFlag;
    SD_I32      AuthStatus;

#ifdef WIN32
    HANDLE hStdIn;
    DWORD OrigConsoleMode, ConsoleMode;
#endif
    SD_BOOL retVal;

#ifdef WIN32
    // get the handle to stdin and the console mode
    hStdIn = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(hStdIn, &OrigConsoleMode);

    // enable input echo
    ConsoleMode = OrigConsoleMode|ENABLE_ECHO_INPUT|ENABLE_LINE_INPUT;
#endif

    if (!AceInitialize())
    {
        printf("\nAceInitialize failed\n");
        return SD_FALSE;
    }

    //if (0 == promptUser("Enter USERNAME: ", resp, sizeof(resp)) )
   // {
    //    return SD_FALSE;
    //}

    strcpy(resp,username);
    // reset size of prompt string
    promptLen = sizeof(prompt);
    //retVal = AceStartAuth(&aceHdl, resp, strlen(resp),
      //  &moreFlag, &noechoFlag, &respTimeout, &nextRespLen,
       // prompt, &promptLen);

 //   printf("username=%s\n",resp);
    SDI_HANDLE SdiHandle;
    if(SD_Init(&SdiHandle)!=ACM_OK)
    {
        printf("sd_init fail\n");
        exit(-1);
    }
    retVal=SD_Check(SdiHandle,passcode,resp);
	return retVal;
   // printf("passcode=%s\n",passcode);
   // if (retVal == ACM_OK)
    ///{
     //   printf("%s", prompt);
        // return failure
      //  return SD_FALSE;
        
    //}
   // else
    //    return 1;
  /*  moreFlag=0;
    // loop until no more data is requested
    while (moreFlag)
    {
#ifdef WIN32
        // if echo is on make sure it is turned on
        if (noechoFlag)
            SetConsoleMode(hStdIn, ConsoleMode & ~ENABLE_ECHO_INPUT);
        else
            SetConsoleMode(hStdIn, ConsoleMode);
#else
        if (noechoFlag)
           sd_echo_off();
        else
           sd_echo_on();
#endif

        // a system PIN is about to be displayed
        if (respTimeout == 10)
        {
            printf("%s", prompt);
            // wait for 10 seconds
            sleep(10);
            // clear the screen
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            // make sure display is cleared
            fflush(stdout);
            // clear keystrokes from impatient users
            fflush(stdin);
        }
        else
        {
            if (0 == promptUser(prompt, resp, sizeof(resp)) )
            {
                // must also cause access denied
                break;
            }
#ifdef WIN32
            // if echo is off make linefeeds
            if (noechoFlag)
                puts("");
#else
            if (noechoFlag)
               sd_echo_on();
               printf("\n");
#endif
        }

        // reset size of prompt string
        promptLen = sizeof(prompt);
        retVal = AceContinueAuth(aceHdl, resp, strlen(resp),
            &moreFlag, &noechoFlag, &respTimeout, &nextRespLen,
            prompt, &promptLen);
    }

#ifndef WIN32
    sd_echo_on();
#endif

    // write final prompt to output
    printf("%s", prompt);

    // we need to call AceGetAuthenticationStatus() to retrieve
    // the final result. the return code from AceContinueAuth()
    // indicates the success/failure of the call and not of the
    // authentication request.
    AuthStatus = ACM_ACCESS_DENIED;
    if (moreFlag)       // the loop was broken by I/O error?
    {
        puts("\n\nAccess denied.");
    }
    else
    {
        retVal = AceGetAuthenticationStatus(aceHdl, &AuthStatus);
    }

    // close authentication context
    AceCloseAuth(aceHdl);

#ifdef WIN32
    // reset console and close handle
    SetConsoleMode(hStdIn, OrigConsoleMode);
    CloseHandle(hStdIn);
#endif
    // return true if status is ACM_OK
    return AuthStatus == ACM_OK;
    */
}


#ifndef WIN32
int sd_echo_off()
{
  struct termio sd_echo_sav;
  if (ioctl (0, TCGETA, &sd_echo_sav) == -1)
  {
    printf("can't get orginal settings");
    return(1);
  }

  sd_echo_sav.c_lflag &= ~ECHO;
  if (ioctl(0, TCSETA, &sd_echo_sav) == -1)
  {
    printf("can't initiate new settings");
    return(2);
  }
}

int sd_echo_on()
{
  struct termio sd_echo_sav;
  if (ioctl (0, TCGETA, &sd_echo_sav) == -1)
  {
    printf("can't get orginal settings");
    return(1);
  }
  sd_echo_sav.c_lflag |= ECHO;
  if (ioctl(0, TCSETA, &sd_echo_sav) == -1)
  {
    printf("can't initiate new settings");
    return(3);
  }
}
#endif

// a simple main() to drive this program
int main(int argc, char* argv[])
{
		if(argc!=3)
		{
				printf("input:%s username passcode\n",argv[0]);
				exit(-1);
		}
		SD_BOOL retVal=authenticate(argv[1],argv[2]);
    //if ()
    //{
    //    // successful auth. let them do what they want
    //    printf("1");
    //    return 1;
    //}

    //// authentication failed
    //printf("0");
    //return 0;
		if(retVal==ACM_OK)
		{
			printf("1");
			return 1;
		}
		else if(retVal==ACE_ERR_INVALID_HANDLE)
		{
			printf("-1");
			return -1;
		}
		else if(retVal==ACM_ACCESS_DENIED)
		{	
			printf("-2");
			return -2;
		}
		else if(retVal==ACM_NEXT_CODE_REQUIRED)
		{
			printf("-3");
			return -3;
		}
		else if(retVal==ACM_NEW_PIN_REQUIRED)
		{
			printf("-4");
			return -4;
		}
		else if(retVal==ACE_TOO_MANY_CALLERS)
		{
			printf("-5");
			return -5;
		}
		else if(retVal==ACE_INVALID_ARG)
		{
			printf("-6");
			return -6;
		}
		else
		{
			printf("0");
			return 0;
		}
}
