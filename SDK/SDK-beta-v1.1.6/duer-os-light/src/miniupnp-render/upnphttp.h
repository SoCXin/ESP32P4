/*
 * miniupnprender @ Baidu
 *
 * Portions of the code from the MiniUPnP project:
 *
 * Copyright (c) 2006-2007, Thomas Bernard
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * The name of the author may not be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_MINIUPNPRENDER_UPNPHTTP_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_MINIUPNPRENDER_UPNPHTTP_H


#include "sockets.h"
#include "list.h"

/*
 states :
  0 - waiting for data to read
  1 - waiting for HTTP Post Content.
  ...
  >= 100 - to be deleted
*/

enum HttpCommands {
    EUNKNOWN = 0,
    EGET,
    EPOST,
    ESUBSCRIBE,
    EUNSUBSCRIBE
};

struct upnphttp {
    int socket;
    struct in_addr clientaddr;	/* client address */
    int iface;
    int state;
    char HttpVer[16];
    /* request */
    char* req_buf;
    int req_buflen;
    int req_contentlen;
    int req_contentoff;     /* header length */
    enum HttpCommands req_command;
    const char* req_soapAction;
    int req_soapActionLen;
    const char* req_Callback;	/* For SUBSCRIBE */
    int req_CallbackLen;
    const char* req_NT;
    int req_NTLen;
    int req_Timeout;
    const char* req_SID;		/* For UNSUBSCRIBE */
    int req_SIDLen;
    int req_RangeStart;
    int req_RangeEnd;
    long int req_chunklen;
    uint32_t reqflags;
    /* response */
    char* res_buf;
    int res_buflen;
    int res_buf_alloclen;
    uint32_t respflags;
    /*int res_contentlen;*/
    /*int res_contentoff;*/		/* header length */
    LIST_ENTRY(upnphttp) entries;
};

#define FLAG_TIMEOUT            0x00000001
#define FLAG_SID                0x00000002
#define FLAG_RANGE              0x00000004
#define FLAG_HOST               0x00000008
#define FLAG_LANGUAGE           0x00000010

#define FLAG_INVALID_REQ        0x00000040
#define FLAG_HTML               0x00000080

#define FLAG_CHUNKED            0x00000100
#define FLAG_TIMESEEK           0x00000200
#define FLAG_REALTIMEINFO       0x00000400
#define FLAG_PLAYSPEED          0x00000800
#define FLAG_XFERSTREAMING      0x00001000
#define FLAG_XFERINTERACTIVE    0x00002000
#define FLAG_XFERBACKGROUND     0x00004000
#define FLAG_CAPTION            0x00008000

#ifndef MSG_MORE
#define MSG_MORE 0
#endif

/* new_upnphttp() */
struct upnphttp*
new_upnphttp(int);

/* close_socket_upnphttp() */
void
close_socket_upnphttp(struct upnphttp*);

/* delete_upnphttp() */
void
delete_upnphttp(struct upnphttp*);

/* process_upnphttp() */
void
process_upnphttp(struct upnphttp*);

/* build_header_upnphttp()
 * build the header for the HTTP Response
 * also allocate the buffer for body data */
void
build_header_upnphttp(struct upnphttp* h, int respcode,
                      const char* respmsg,
                      int bodylen);

/* build_resp_upnphttp()
 * fill the res_buf buffer with the complete
 * HTTP 200 OK response from the body passed as argument */
void
build_resp_upnphttp(struct upnphttp*, const char*, int);

/* build_resp_upnphttp2()
 * same but with given response code/message */
void
build_resp_upnphttp2(struct upnphttp* h, int respcode,
                     const char* respmsg,
                     const char* body, int bodylen);

/* Error messages */
void
send500(struct upnphttp*);
void
send501(struct upnphttp*);

/* send_resp_upnphttp() */
void
send_resp_upnphttp(struct upnphttp*);

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_MINIUPNPRENDER_UPNPHTTP_H

