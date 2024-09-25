/*
 *  RApiSerialize -- Package to provide Serialization as in the R API
 *
 *  Copyright (C) 2014-2024  Dirk Eddelbuettel
 *
 *  This file is part of RApiSerialize.
 *
 *  RApiSerialize is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  RApiSerialize is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with RApiSerialize.  If not, see <http://www.gnu.org/licenses/>.
 */


/*
   This header file provides the interface used by other packages,
   and should be included once per package. At present, the file
   contains default arguments to serializeToRaw which make use from
   C++ easier. We may remove these in a future release.
*/


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

SEXP attribute_hidden serializeToRaw(SEXP x, SEXP ver = R_NilValue,
                                     SEXP use_xdr = R_NilValue) {
    static SEXP(*fun)(SEXP, SEXP, SEXP) =
        (SEXP(*)(SEXP,SEXP,SEXP)) R_GetCCallable("RApiSerialize", "serializeToRaw");
    return fun(x, ver, use_xdr);
}

SEXP attribute_hidden unserializeFromRaw(SEXP x) {
    static SEXP(*fun)(SEXP) =
        (SEXP(*)(SEXP)) R_GetCCallable("RApiSerialize", "unserializeFromRaw");
    return fun(x);
}

#ifdef __cplusplus
}

/* add a namespace for C++ use */
namespace R {
    inline SEXP serializeToRaw(SEXP x, SEXP ver = R_NilValue, SEXP use_xdr = R_NilValue) {
        return ::serializeToRaw(x, ver, use_xdr);
    }
    inline SEXP unserializeFromRaw(SEXP x) {
        return ::unserializeFromRaw(x);
    }
}

#endif /* __cplusplus */

#endif /* _R_Api_Serialize_API_h */
