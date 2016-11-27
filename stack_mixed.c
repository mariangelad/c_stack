#include <stdio.h>
#include <stdlib.h>
#include "stackmixed.h"



pstack malloc_stack_list(unsigned int size_data, stack_type st){
  pstack psl;
  if((psl=malloc(sizeof(stack)))==NULL)return psl;
  if(((psl->pstart)=(pstackelem)malloc(sizeof(stackelement)))==NULL){
    free(psl);
    fprintf(stderr,"No sufficient memory to allocate the stack.\n");
    return NULL;
  }
  unsigned int n_max;
  printf("Insert the static stacks dimension:\n");
  scanf("%u",&n_max);
  pvoid pdata;
  if((pdata=(pvoid)malloc(size_data*n_max))==NULL){
    free(psl->pstart);
    fprintf(stderr,"No sufficient memory to allocate the data array.\n");
    return NULL;
  }
  psl->n_max=n_max;
  psl->size_data=size_data;
  psl->stacktype=st;
  psl->pos=-1;
  ((pstackelem)(psl->pstart))->next=psl->pstart; /* dummy element, next pointer pointing to itself to make the list ends */
  ((pstackelem)(psl->pstart))->array=pdata;
  ((pstackelem)(psl->pstart))->pos=-1;

  return psl;
}

int push_stack_list(pstack psl, pvoid new_data){

  if((((psl->pos)==-1))||(((((pstackelem)(psl->pstart))->pos)+1)==(psl->n_max))){
    printf("Adding a new element.\n");
    pstackelem pnew;
    pvoid pdatanew;
    if((pnew=(pstackelem)malloc(sizeof(stackelement)))==NULL)return 0;
    if(((pdatanew)=(pvoid)malloc((psl->size_data)*(psl->n_max)))==NULL){
      fprintf(stderr,"No sufficient memory to add a new stack element.\n");
      free(pnew);
      return 0;
    }
    pnew->next=(psl->pstart);
    pnew->array=pdatanew;
    pnew->pos=-1;
    
    (psl->pstart)=pnew;
    psl->pos++;
  }

  memcpy((pvoid)(long unsigned int)(((pstackelem)(psl->pstart))->array)+(psl->size_data)*((((pstackelem)(psl->pstart))->pos)+1), new_data, psl->size_data);
  (((pstackelem)(psl->pstart))->pos)++;
  return EXIT_SUCCESS;
}


pvoid pop_stack_list(pstack psl){
  pstackelem tmp;
  if(((((pstackelem)(psl->pstart))->pos)==-1)){
    printf("An element delayed.\n");
    tmp=((pstackelem)(psl->pstart))->next;
    free(psl->pstart);
    psl->pstart=tmp;
    psl->pos--;
    if((psl->pos)==-1){
      fprintf(stderr,"Can't delay an item: the list is empty!\n");
      exit(EXIT_FAILURE);
    }
    else (((pstackelem)(psl->pstart))->pos)=(psl->n_max)-1;
  }
  return (pvoid)(long unsigned int)(((pstackelem)(psl->pstart))->array)+(psl->size_data)*(((pstackelem)(psl->pstart))->pos--);
}

unsigned int mixed_stack_data_num(pstack psl){
  if((psl->pos+1)<=1){
    return (psl->pos+1)*((((pstackelem)(psl->pstart))->pos)+1);
  }
  else{
    return (psl->pos)*(psl->n_max)+(((pstackelem)(psl->pstart))->pos)+1;
  }
}

