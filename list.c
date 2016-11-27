#include <stdio.h>
#include <stdlib.h>
#include "list.h"


////////////*** List functions ***////////////

pstack malloc_list(unsigned int size_data, stack_type st){
  pstack pd;
  if((pd=malloc(sizeof(stack)))==NULL)return pd;
  if(((pd->pstart)=(pelem)malloc(sizeof(elem)+size_data-1))==NULL){
     free(pd);
     fprintf(stderr,"No sufficient memory to allocate the element of the list.\n");
     return NULL;
    }
  ((pelem)(pd->pstart))->next=pd->pstart;
  pd->pos=-1;
  pd->size_data=size_data;
  pd->stacktype=st;

  return pd;
}

////*** Add a new element in the position n, starting from 0 ***////

int add_in_list(pstack pd, pvoid new_data, int n){
  int i;  
  pelem pe;
  ppelem ppe;
  if((n<0)||(n>(pd->pos+1))){
    fprintf(stderr,"Can't insert the data in this position.\n");
    return EXIT_FAILURE;
  }
  ppe=(ppelem)&(pd->pstart);
  for(i=0;i<n;i++){
    ppe=&((*ppe)->next);
   }
  if((pe=(pelem)malloc(sizeof(pelem)+(pd->size_data)-1))==NULL)return 0;
  pe->next=(*ppe);
  memcpy((pvoid)&(pe->mem), new_data, pd->size_data); 
  (*ppe)=pe;
  pd->pos++;
  return 1;
 }

int add_in_top(pstack ps, pvoid new_data){
  int n=0;
  add_in_list(ps, new_data, n);
  return 1;
}

////*** Delay the item in the position n and return the data ***////

pvoid delay_in_list(pstack pd, int n){

  pvoid old_data;
  old_data=(pvoid)malloc(pd->size_data);
  pelem tmp;
  ppelem ppe;
  int i;
  if((n<0)||(n>(pd->pos+1))){
    fprintf(stderr,"Can't delay the data: there are no items in this position!\n");
    exit(EXIT_FAILURE);
  }
  if((pd->pos)==-1){
    fprintf(stderr,"Can't delay the datum: the list is empty!\n");
    exit(EXIT_FAILURE);
  }
  ppe=(ppelem)&(pd->pstart);
    for(i=0;i<n;i++){
      ppe=&((*ppe)->next);
    }
  tmp=((*ppe)->next);
  memcpy(old_data,(pvoid)&((*ppe)->mem), pd->size_data);
//  old_data=(pvoid)&((*ppe)->mem);
  free(*ppe);
  (*ppe)=tmp;

  pd->pos--;
  return old_data;
}

pvoid delay_in_top(pstack ps){
  int n=0;
  return delay_in_list(ps, n);
}

unsigned int list_elements_number(pstack ps){
  return ps->pos+1;
}

unsigned int list_dimension(pstack ps){
  fprintf(stderr,"The stack is DYNAMIC, it has no maximum fixed dimension.\n");
  return 0;
}
