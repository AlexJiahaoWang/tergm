#ifndef CHANGESTATS_H
#define CHANGESTATS_H

#include "edgeTree.h"

typedef struct ModelTermstruct {
	void (*func)(int, Vertex*, Vertex*, struct ModelTermstruct*, Network*);
	double *attrib; /* Ptr to vector of covariates (if necessary; generally unused) */
	int nstats;   /* Number of change statistics to be returned */
	double *dstats; /* ptr to change statistics returned */
	int ninputparams; /* Number of input parameters passed to function */
	double *inputparams; /* ptr to input parameters passed */
} ModelTerm;

/****************************************************/
/* changestat function prototypes, 
   plus a few supporting function prototypes */
#define CHANGESTAT_FN(a) void (a) (int ntoggles, Vertex *heads, Vertex *tail, ModelTerm *mtp, Network *nwp);
/********************  changestats:  A    ***********/
CHANGESTAT_FN(d_absdiff)         
CHANGESTAT_FN(d_absdiffcat)
CHANGESTAT_FN(d_aconcurrent)
CHANGESTAT_FN(d_aconcurrent_by_attr)
CHANGESTAT_FN(d_actorfactor)
CHANGESTAT_FN(d_adegree)
CHANGESTAT_FN(d_adegree_by_attr)
CHANGESTAT_FN(d_akappa)
CHANGESTAT_FN(d_altistar)
CHANGESTAT_FN(d_altkstar)
CHANGESTAT_FN(d_altostar)
CHANGESTAT_FN(d_asymmetric)
/********************  changestats:  B    ***********/
CHANGESTAT_FN(d_balance)
CHANGESTAT_FN(d_berninhom)
CHANGESTAT_FN(d_biduration)
CHANGESTAT_FN(d_bimix)
CHANGESTAT_FN(d_bkappa)
CHANGESTAT_FN(d_boundeddegree)
CHANGESTAT_FN(d_boundedidegree)
CHANGESTAT_FN(d_boundedodegree)
CHANGESTAT_FN(d_boundedistar)
  double my_choose(double n, int r);
CHANGESTAT_FN(d_boundedkstar)
CHANGESTAT_FN(d_boundedostar)
CHANGESTAT_FN(d_boundedtriangle)
  Vertex CountTriangles (Vertex h, Vertex t, int outcount, 
                         int incount, Network *nwp);
/********************  changestats:  C    ***********/
CHANGESTAT_FN(d_concurrent) 
CHANGESTAT_FN(d_concurrent_by_attr)
CHANGESTAT_FN(d_ctriple)
CHANGESTAT_FN(d_cycle)
  void edgewise_path_recurse(Network *g, Vertex dest, 
     Vertex curnode, Vertex *availnodes, long int availcount, 
     long int curlen, double *countv, long int maxlen, 
     int directed);
  void edgewise_cycle_census(Network *g, Vertex t, Vertex h, 
     double *countv, long int maxlen, int directed);
/********************  changestats:  D    ***********/
CHANGESTAT_FN(d_degree)
CHANGESTAT_FN(d_degree_by_attr)
CHANGESTAT_FN(d_degree_w_homophily)
CHANGESTAT_FN(d_degreep)
CHANGESTAT_FN(d_degreep_by_attr)
CHANGESTAT_FN(d_degreep_w_homophily)
CHANGESTAT_FN(d_density)
CHANGESTAT_FN(d_dissolve)
CHANGESTAT_FN(d_dsp)
CHANGESTAT_FN(d_duration)
CHANGESTAT_FN(d_dyadcov)
/********************  changestats:  E    ***********/
CHANGESTAT_FN(d_econcurrent)
CHANGESTAT_FN(d_econcurrent_by_attr)
CHANGESTAT_FN(d_edegree)
CHANGESTAT_FN(d_edegree_by_attr)
CHANGESTAT_FN(d_edgecov)
CHANGESTAT_FN(d_edges)
CHANGESTAT_FN(d_ekappa)
CHANGESTAT_FN(d_esp)
CHANGESTAT_FN(d_eventfactor)
/********************  changestats:  F    ***********/
CHANGESTAT_FN(d_factor)
CHANGESTAT_FN(d_formation)
/********************  changestats:  G    ***********/
CHANGESTAT_FN(d_geodegree)
CHANGESTAT_FN(d_geospartner)
CHANGESTAT_FN(d_gwactor)
CHANGESTAT_FN(d_gwadegree)
CHANGESTAT_FN(d_gwadegree_by_attr)
CHANGESTAT_FN(d_gwd)
CHANGESTAT_FN(d_gwdegree)
CHANGESTAT_FN(d_gwdegree_by_attr)
CHANGESTAT_FN(d_gwdegree706)
CHANGESTAT_FN(d_gwdegreealpha)
CHANGESTAT_FN(d_gwdegreelambda)
CHANGESTAT_FN(d_gwdsp)
CHANGESTAT_FN(d_gwedegree)
CHANGESTAT_FN(d_gwedegree_by_attr)
CHANGESTAT_FN(d_gwesp)
CHANGESTAT_FN(d_gwevent)
CHANGESTAT_FN(d_gwidegree)
CHANGESTAT_FN(d_gwidegree_by_attr)
CHANGESTAT_FN(d_gwodegree)
CHANGESTAT_FN(d_gwodegree_by_attr)
CHANGESTAT_FN(d_gwtdsp)
CHANGESTAT_FN(d_gwtesp)
/********************  changestats:   H    ***********/
CHANGESTAT_FN(d_hamming)
CHANGESTAT_FN(d_hammingdyadcov)
CHANGESTAT_FN(d_hammingfixmix)
CHANGESTAT_FN(d_hammingmix)
CHANGESTAT_FN(d_heideriandynamic)
CHANGESTAT_FN(d_hiertriad)
  double numposthree (Vertex t, Network *nwp);
CHANGESTAT_FN(d_hiertriaddegree)
/********************  changestats:   I    ***********/
CHANGESTAT_FN(d_icvar)
CHANGESTAT_FN(d_idc)
CHANGESTAT_FN(d_idegree)
CHANGESTAT_FN(d_idegree_by_attr)
CHANGESTAT_FN(d_idegree_w_homophily)
CHANGESTAT_FN(d_intransitive)
CHANGESTAT_FN(d_intransitivedynamic)
CHANGESTAT_FN(d_intransitivity)
CHANGESTAT_FN(d_isolates)
CHANGESTAT_FN(d_istar)
/********************  changestats:   K    ***********/
CHANGESTAT_FN(d_kappa)
CHANGESTAT_FN(d_kstar)
/********************  changestats:   L    ***********/
CHANGESTAT_FN(d_localtriangle)
/********************  changestats:   M    ***********/
CHANGESTAT_FN(d_m2star)
CHANGESTAT_FN(d_meandeg)
CHANGESTAT_FN(d_mix)
CHANGESTAT_FN(d_monopolymixmat)
CHANGESTAT_FN(d_mutual)
/********************  changestats:   N    ***********/
CHANGESTAT_FN(d_nearsimmelian)
CHANGESTAT_FN(d_nodefactor)
CHANGESTAT_FN(d_nodeifactor)
CHANGESTAT_FN(d_nodemain)                 
CHANGESTAT_FN(d_nodematch)
CHANGESTAT_FN(d_nodemix)
CHANGESTAT_FN(d_nodeofactor)
/********************  changestats:   O    ***********/
CHANGESTAT_FN(d_odegree)
CHANGESTAT_FN(d_odegree_by_attr)
CHANGESTAT_FN(d_odegree_w_homophily)
CHANGESTAT_FN(d_ostar)
/********************  changestats:   R    ***********/
CHANGESTAT_FN(d_receiver)
CHANGESTAT_FN(d_receivercov)
/********************  changestats:   S    ***********/
CHANGESTAT_FN(d_sender)
CHANGESTAT_FN(d_sendercov)
CHANGESTAT_FN(d_simmelian)
CHANGESTAT_FN(d_simmeliandynamic)
CHANGESTAT_FN(d_simmelianties)
CHANGESTAT_FN(d_smalldiff)
CHANGESTAT_FN(d_spatial)
CHANGESTAT_FN(d_sociality)
/********************  changestats:   T    ***********/
CHANGESTAT_FN(d_tdsp)
CHANGESTAT_FN(d_tesp)
CHANGESTAT_FN(d_transitive)
CHANGESTAT_FN(d_transitivedynamic)
CHANGESTAT_FN(d_transitivity)
CHANGESTAT_FN(d_triadcensus)
CHANGESTAT_FN(d_triangle)
CHANGESTAT_FN(d_tripercent)
CHANGESTAT_FN(d_ttriple)



              
#endif