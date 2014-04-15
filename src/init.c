/* -*- mode: C; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*- */
/*
 *  RApiSerialize -- Packge to provide Serialization as in the R API 
 *
 *  Copyright (C) 2014  Dirk Eddelbuettel 
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

#include <Rconfig.h>
#include <Rinternals.h>
#include <R_ext/Rdynload.h>


/*  function declarations -- could be in external header file if used  */
/*  by functions in anotherfile in this package                        */
SEXP serializeToRaw(SEXP object);
SEXP unserializeFromRaw(SEXP object);


/* definition of functions provided for .Call() 			*/
static const R_CallMethodDef callMethods[] = {
    { "serializeToRaw",    	(DL_FUNC) &serializeToRaw,          1 },
    { "unserializeToRaw",  	(DL_FUNC) &unserializeFromRaw,      1 },
    { NULL,                	NULL,                               0 }
};


/* functions being called when package is loaded -- used to register 	*/
/* the functions we are exporting here					*/
void R_init_RApiSerialize(DllInfo *info) {

    /* used by external packages linking to internal xts code from C */
    R_RegisterCCallable("RApiSerialize", "serializeToRaw", 
                        (DL_FUNC) &serializeToRaw);
    R_RegisterCCallable("RApiSerialize", "unserializeFromRaw",  
                        (DL_FUNC) &unserializeFromRaw);

    R_registerRoutines(info,
                       NULL,		/* slot for .C */
                       callMethods, 	/* slot for .Call */
                       NULL,            /* slot for .Fortran */
                       NULL);   	/* slot for .External */

    R_useDynamicSymbols(info, TRUE);    /* controls visibility */ 

}




