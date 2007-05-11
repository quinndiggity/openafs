/*
 * Copyright 2006-2007, Sine Nomine Associates and others.
 * All Rights Reserved.
 * 
 * This software has been released under the terms of the IBM Public
 * License.  For details, see the LICENSE file in the top-level source
 * directory or online at http://www.openafs.org/dl/license10.html
 */

#include <trace/common/trace_impl.h>
#include <osi/osi_mem.h>
#include <trace/gen_rgy.h>
#include <rx/xdr.h>
#include <rx/rx.h>
#include <trace/rpc/agent_api.h>
#include <trace/console/agent_client.h>

/*
 * osi tracing framework
 * trace console library
 * agent probe control rpc interface 
 * low-level client routines
 */

osi_extern struct rx_securityClass * osi_trace_console_rpc_C_sc_vec[1];
osi_extern struct rx_securityClass * osi_trace_console_rpc_S_sc_vec[1];
osi_extern struct rx_service * osi_trace_console_rpc_service;

osi_extern osi_Trace_rpc_console_handle osi_trace_console_uuid;

osi_result
osi_trace_console_agent_enable(osi_Trace_rpc_addr4 * addr)
{
    osi_result res;
    afs_int32 code;
    struct rx_connection * conn;

    conn = rx_GetCachedConnection(addr->addr,
				  addr->port,
				  OSI_TRACE_RPC_SERVICE_AGENT,
				  osi_trace_console_rpc_C_sc_vec,
				  0);
    if (osi_compiler_expect_false(conn == osi_NULL)) {
	res = OSI_FAIL;
	goto error;
    }

    code = Agent_ConsoleEnable(conn,
			       &osi_trace_console_uuid);
    res = (osi_result) code;

    rx_ReleaseCachedConnection(conn);

 error:
    return res;
}

osi_result
osi_trace_console_agent_disable(osi_Trace_rpc_addr4 * addr)
{
    osi_result res;
    afs_int32 code;
    struct rx_connection * conn;

    conn = rx_GetCachedConnection(addr->addr,
				  addr->port,
				  OSI_TRACE_RPC_SERVICE_AGENT,
				  osi_trace_console_rpc_C_sc_vec,
				  0);
    if (osi_compiler_expect_false(conn == osi_NULL)) {
	res = OSI_FAIL;
	goto error;
    }

    code = Agent_ConsoleDisable(conn,
				&osi_trace_console_uuid);
    res = (osi_result) code;

    rx_ReleaseCachedConnection(conn);

 error:
    return res;
}

osi_result
osi_trace_console_agent_client_PkgInit(void)
{
    return OSI_OK;
}

osi_result
osi_trace_console_agent_client_PkgShutdown(void)
{
    return OSI_OK;
}

