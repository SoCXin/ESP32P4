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

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_MINIUPNPRENDER_HTTPPATH_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_MINIUPNPRENDER_HTTPPATH_H

/* Paths and other URLs in the minirender http server */

#define ROOTDESC_PATH                "/rootDesc.xml"

#define CONNECTIONMGR_PATH           "/renderconnmgrSCPD.xml"
#define CONNECTIONMGR_CONTROLURL     "/ctl/ConnectionMgr1"
#define CONNECTIONMGR_EVENTURL       "/evt/ConnectionMgr1"

#define AVTRANSPORT_PATH             "/rendertransportSCPD.xml"
#define AVTRANSPORT_CONTROLURL       "/ctl/rendertransport1"
#define AVTRANSPORT_EVENTURL         "/evt/rendertransport1"

#define RENDERINGCONTROL_PATH        "/rendercontrolSCPD.xml"
#define RENDERINGCONTROL_CONTROLURL  "/ctl/rendercontrol1"
#define RENDERINGCONTROL_EVENTURL    "/evt/rendercontrol1"

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_MINIUPNPRENDER_HTTPPATH_H

