/*
 * Copyright 2006-2007, Sine Nomine Associates and others.
 * All Rights Reserved.
 * 
 * This software has been released under the terms of the IBM Public
 * License.  For details, see the LICENSE file in the top-level source
 * directory or online at http://www.openafs.org/dl/license10.html
 */


#include <trace/common/trace_impl.h>
#include <trace/gen_rgy.h>
#include <trace/event/event.h>
#include <trace/generator/generator.h>

/* for non-variadic macro environments we redefine osi_TraceFunc_Event to 
 * osi_TraceFunc_VarEvent and do static inline variadic functions for
 * each tracepoint.
 *
 * just in case someone hard codes things differently, let's define
 * both interfaces for all cases */
#ifdef osi_TraceFunc_Event
#undef osi_TraceFunc_Event
#endif

osi_result
osi_TraceFunc_Event(osi_trace_probe_id_t id, osi_Trace_EventType type, int nf, ...)
{
    osi_result res;
    osi_va_list args;

    osi_va_start(args, nf);
    res = osi_TraceFunc_VarEvent(id, type, nf, args);
    osi_va_end(args);

    return res;
}

osi_result
osi_TraceFunc_VarEvent(osi_trace_probe_id_t probe_id,
		       osi_Trace_EventType type,
		       int nf,
		       osi_va_list args)
{
    osi_Trace_EventHandle handle;
    int i;

    osi_TraceFunc_Prologue();
    osi_TraceBuffer_Allocate(&handle);

    osi_Trace_EventHandle_Field_Set(&handle, probe, (osi_uint32) probe_id);
    osi_Trace_EventHandle_Field_Set(&handle, tags[0], (osi_uint8) type);
    osi_Trace_EventHandle_Field_Set(&handle, tags[1], (osi_uint8) osi_Trace_Event_Null_Id);
    osi_Trace_EventHandle_Field_Set(&handle, nargs, (osi_uint8) nf);

    for (i=0; i < nf; i++) {
	osi_TracePoint_record_arg_set(osi_Trace_EventHandle_RecordPtr(&handle), 
				      i,
				      osi_va_arg(args, osi_register_int));
    }

    osi_TraceBuffer_Stamp(&handle);
    osi_TraceBuffer_Commit(&handle);
    osi_TraceFunc_Epilogue();
    return OSI_OK;
}
