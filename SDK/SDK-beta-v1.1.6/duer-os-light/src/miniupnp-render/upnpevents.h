/*
 *
 * miniupnprender @ Baidu
 *
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
#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_MINIUPNPRENDER_UPNPEVENT_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_MINIUPNPRENDER_UPNPEVENT_H

#include "sockets.h"

enum SubscriberServiceEnum {
    EConnectionManager = 1,
    ERenderingControl,
    EAVTransport
};

void upnp_event_var_change_notify(enum SubscriberServiceEnum service);

const char* upnpevents_add_subscriber(const char* eventurl,
                                     const char* callback, int callbacklen,
                                     int timeout);

int upnpevents_remove_subscriber(const char* sid, int sidlen);
void upnpevents_remove_subscribers(void);

int renew_subscription(const char* sid, int sidlen, int timeout);

void upnpevents_select_fds(fd_set* readset, fd_set* writeset, int* max_fd);
void upnpevents_process_fds(fd_set* readset, fd_set* writeset);

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_MINIUPNPRENDER_UPNPEVENT_H

