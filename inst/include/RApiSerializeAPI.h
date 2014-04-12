/* -*- mode: C; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*- */

/* header used by other packages */

#ifndef _R_Api_Serialize_API_h_
#define _R_Api_Serialize_API_h_

/* number of R header files (possibly listing too many) */
#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>
#include <Rconfig.h>
#include <R_ext/Rdynload.h>

#ifdef HAVE_VISIBILITY_ATTRIBUTE
    # define attribute_hidden __attribute__ ((visibility ("hidden")))
#else
    # define attribute_hidden
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* provided the interface for the function exported 	*/
/* in ../src/init.c via R_RegisterCCallable()		*/

SEXP attribute_hidden serializeToRaw(SEXP x) {
    static SEXP(*fun)(SEXP) = 
        (SEXP(*)(SEXP)) R_GetCCallable("RApiSerialize", "serializeToRaw");
    return fun(x);
}

SEXP attribute_hidden unserializeFromRaw(SEXP x) {
    static SEXP(*fun)(SEXP) = 
        (SEXP(*)(SEXP)) R_GetCCallable("RApiSerialize", "unserializeFromRaw");
    return fun(x);
}

SEXP attribute_hidden serializeToChar(SEXP x) {
    static SEXP(*fun)(SEXP) = 
        (SEXP(*)(SEXP)) R_GetCCallable("RApiSerialize", "serializeToChar");
    return fun(x);
}

SEXP attribute_hidden unserializeFromChar(SEXP x) {
    static SEXP(*fun)(SEXP) = 
        (SEXP(*)(SEXP)) R_GetCCallable("RApiSerialize", "unserializeFromChar");
    return fun(x);
}

#ifdef __cplusplus
}
#endif

#endif /* _R_Api_Serialize_API_h */


