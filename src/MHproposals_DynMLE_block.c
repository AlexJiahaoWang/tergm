#include "MHproposals_DynMLE.h"
#include "edgelist.h"

/* Shorthand. */
#define Mtail (MHp->toggletail)
#define Mhead (MHp->togglehead)

/********************
   void MH_FormationMLEblockdiag
   Propose ONLY edges not in the reference graph that within a block
***********************/
void MH_FormationMLEblockdiag (MHproposal *MHp, Network *nwp) 
{  
  static Vertex nnodes;
  unsigned int trytoggle;
  static Edge ndyads, nedges0;

  static Vertex blks;
  static double *blkinfo, *blkpos, *blkcwt; 

  if(MHp->ntoggles == 0) { /* Initialize */
    MHp->ntoggles=1;
    nnodes = nwp[0].nnodes;
    nedges0 = MHp->inputs[0];
    blkinfo = MHp->inputs+1+nedges0*2;
    ndyads = blkinfo[0];
    blks = blkinfo[1];
    blkpos = blkinfo+2;
    blkcwt = blkinfo+2+blks+1;
    return;
  }
  
  if(nedges0==ndyads){ /* Attempting formation on a complete graph. */
    Mtail[0]=MH_FAILED;
    Mhead[0]=MH_IMPOSSIBLE;
    return;
  }

  for(trytoggle=0;trytoggle<MAX_TRIES;trytoggle++){
    /* Keep trying dyads until a one that is not an edge in the reference network is found. */
    /* Generate. */
    double r = unif_rand();
    // TODO: Use bisection to perform this search in O(log b) instead of O(b) time. 
    Vertex blk = 1;
    while(r>blkcwt[blk-1]) blk++;
    Mtail[0] = blkpos[blk-1]+1 + unif_rand() * (blkpos[blk]-blkpos[blk-1]);
    while ((Mhead[0] = blkpos[blk-1]+1 + unif_rand() * (blkpos[blk]-blkpos[blk-1])) == Mtail[0]);
    
    /* If undirected, reorder. */
    if(!nwp->directed_flag && Mhead[0]<Mtail[0]){
      Vertex tmp=Mhead[0];
      Mhead[0]=Mtail[0];
      Mtail[0]=tmp;
    }
      
    if(!dEdgeListSearch(Mtail[0],Mhead[0],MHp->inputs) &&
	    CheckTogglesValid(MHp, nwp)) break;
  }

  /* If no valid proposal found, signal a failed proposal. */
  if(trytoggle>=MAX_TRIES) {
    Mtail[0]=MH_FAILED;
    Mhead[0]=MH_UNSUCCESSFUL;
  }
}

/********************
   MH_DissolutionMLEblockdiag is not needed, because we can't have off-diagonal ties in the first place.
***********************/

/********************
   void MH_FormationMLEblockdiagTNT
   Propose ONLY edges not in the reference graph and on the block-diagonal
***********************/
void MH_FormationMLEblockdiagTNT(MHproposal *MHp, Network *nwp) 
{  
  static Vertex nnodes, blks;
  unsigned int trytoggle;
  Vertex tail,head;
  static Edge ndyads;
  static double comp=0.5, odds;
  static Network discord;
  static double *blkinfo, *blkpos, *blkcwt; 

  if(MHp->ntoggles == 0) { /* Initialize */
    MHp->ntoggles=1;
    nnodes = nwp->nnodes;
    odds = comp/(1.0-comp);

    Edge nedges0 = MHp->inputs[0];
    MHp->discord = (Network**) calloc(2,sizeof(Network*)); // A space for the sentinel NULL pointer.
    MHp->discord[0] = &discord;
    discord = NetworkInitializeD(MHp->inputs+1, MHp->inputs+1+nedges0, nedges0, nnodes, nwp->directed_flag, nwp->bipartite, 0, 0, NULL);
   
    for(Edge i=0; i<nwp->nedges; i++){
      FindithEdge(&tail, &head, i+1, nwp);
      ToggleEdge(tail,head,&discord);
    }
    
    blkinfo = MHp->inputs+1+nedges0*2;
    ndyads = blkinfo[0];
    blks = blkinfo[1];
    blkpos = blkinfo+2;
    blkcwt = blkinfo+2+blks+1;
    return;
  }
  
  Edge nedges = nwp->nedges, ndedges = discord.nedges, nempty = ndyads-nedges;

  if(nempty==0 && ndedges==0){ /* Attempting formation on a complete graph. */
    Mtail[0]=MH_FAILED;
    Mhead[0]=MH_IMPOSSIBLE;
    return;
  }

  for(trytoggle=0;trytoggle<MAX_TRIES*2;trytoggle++){
    if(ndedges != 0 && unif_rand() < comp) { /* Select a discordant dyad at random */
      GetRandEdge(&tail, &head, &discord);
      
      MHp->logratio += log(ndedges / ((double)nempty + 1)/comp * ((ndedges==1)? 1 : (1-comp)));
    }else{ /* select an empty dyad in nwp[0] at random */
      do{ /* Keep trying block-diagonal dyads as long as it's an edge in nwp */
	double r = unif_rand();
	// TODO: Use bisection to perform this search in O(log b) instead of O(b) time. 
	Vertex blk = 1;
	while(r>blkcwt[blk-1]) blk++;
	tail = blkpos[blk-1]+1 + unif_rand() * (blkpos[blk]-blkpos[blk-1]);
	while ((head = blkpos[blk-1]+1 + unif_rand() * (blkpos[blk]-blkpos[blk-1])) == tail);
        trytoggle++;
      }while(((tail > head && !nwp->directed_flag) || 
	      EdgetreeSearch(tail,head,nwp->outedges)) && trytoggle<MAX_TRIES);
      
      /* Proposal failed after trying */
      if(trytoggle >= MAX_TRIES*2){
        Mtail[0]=MH_FAILED;
        Mhead[0]=MH_UNSUCCESSFUL; 
        return;
      }
      
      if(ndedges==0){
        MHp->logratio += log(nempty*comp);
      }else{
        MHp->logratio += log(((double)nempty)/(ndedges+1) *odds);
      }
    }
    
    Mtail[0]=tail;
    Mhead[0]=head;
    
    if(CheckTogglesValid(MHp, nwp)) break;
  }

  /* If no valid proposal found, signal a failed proposal. */
  if(trytoggle>=MAX_TRIES*2) {
    Mtail[0]=MH_FAILED;
    Mhead[0]=MH_UNSUCCESSFUL;
  }
}
