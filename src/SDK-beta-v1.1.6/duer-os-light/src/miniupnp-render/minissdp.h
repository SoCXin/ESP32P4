/*
 * miniupnprender @ Baidu
 *
 * Portions of the code from the MiniUPnP project:
 * http://miniupnp.free.fr/ or http://miniupnp.tuxfamily.org/
 *
 * Copyright (c) 2006-2008, Thomas Bernard
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

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_MINIUPNPRENDER_MINISSDP_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_MINIUPNPRENDER_MINISSDP_H

#ifdef __cpluscplus
extern "C" {
#endif

/**
 *  @brief create ssdp notify socket
 *  @ret ssdp notify socket fd
 */  
int open_ssdp_notify_socket();

/**
 *  @brief broadcast ssdp notifications
 *  @param[in] ssdp notify fd
 *  @param[in] host ip address
 *  @param[in] host http port waiting for connections
 *  @param[in] notification life timeval
 */
void send_ssdp_notifies(int fd, const char* hostip, unsigned short httpport, unsigned int lifetime);

/**
 *  @brief open sspd receive socket
 *  @param[in] void
 *  @return[out] soket id if return -1 , create socket fail
 */
int open_and_conf_ssdp_receive_socket(void);

/**
 *  @brief process ssdp request
 *  @param[in] soket_id
 *  @param[int] input ip string
 *  @return[out] negative is fail or else is secuss
 */
int process_ssdp_request(int s, const char* host_ip, int local_server_port);

#ifdef __cplusplus
}
#endif

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_MINIUPNPRENDER_MINISSDP_H

