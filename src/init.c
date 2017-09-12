/*  File src/init.c in package tergm, part of the Statnet suite
 *  of packages for network analysis, http://statnet.org .
 *
 *  This software is distributed under the GPL-3 license.  It is free,
 *  open source, and has the attribution requirements (GPL Section 7) at
 *  http://statnet.org/attribution
 *
 *  Copyright 2008-2017 Statnet Commons
 */
/* This code was procedurally generated by running

   > tools::package_native_routine_registration_skeleton(".", "./src/init.c")

   in R started in the package's root directory, then changing

   "R_useDynamicSymbols(dll, FALSE)" to "R_useDynamicSymbols(dll, TRUE)".
*/
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* .C calls */
extern void godfather_wrapper(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
extern void MCMCDyn_wrapper(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
extern void MCMCDynSArun_wrapper(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);

static const R_CMethodDef CEntries[] = {
    {"godfather_wrapper",    (DL_FUNC) &godfather_wrapper,    24},
    {"MCMCDyn_wrapper",      (DL_FUNC) &MCMCDyn_wrapper,      56},
    {"MCMCDynSArun_wrapper", (DL_FUNC) &MCMCDynSArun_wrapper, 52},
    {NULL, NULL, 0}
};

void R_init_tergm(DllInfo *dll)
{
    R_registerRoutines(dll, CEntries, NULL, NULL, NULL);
    R_useDynamicSymbols(dll, TRUE);
}
