#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


/////////////////////////*** Static stack functions ***//////////////////////////////////


pstack malloc_stack(unsigned int size_data, stack_type st){
  unsigned int n_max;
  pstack ps;
  if((ps=((pstack)malloc(sizeof(stack))))==NULL){
    fprintf(stderr,"No sufficient memory to allocate the stack.\n");
    exit(EXIT_FAILURE);
  }  
  pvoid pdati;
  printf("Insert the stack dimension: \n");
  scanf("%u",&n_max);
  if((pdati=((pvoid)malloc(size_data*n_max)))==NULL){
    fprintf(stderr,"No sufficient memory to allocate the data array.\n");
    free(ps);
    exit(EXIT_FAILURE);
  }
  ps->pos=-1;
  ps->n_max=n_max;
  ps->size_data=size_data;
  ps->stacktype=st;
  ps->pstart=pdati;

  return ps;
}

int push_stack(pstack ps, pvoid new_data){
  if((ps->pos)==((ps->n_max)-1)){
    fprintf(stderr,"Can't push new data, the stack is full\n");
    exit(EXIT_FAILURE);
  }

  memcpy((pvoid)(((long unsigned int)(ps->pstart))+(ps->size_data)*((ps->pos)+1)), new_data, ps->size_data);
  (ps->pos)++;
  return EXIT_SUCCESS;
}

pvoid pop_stack(pstack ps){
  if((ps->pos)==-1){
    fprintf(stderr,"Can't pop the data, the stack is empty\n");
    exit(EXIT_FAILURE);	
  }
  return (pvoid)((long unsigned int)(ps->pstart))+(ps->size_data)*(ps->pos--);

}


int stack_is_empty(pstack ps){
  return((ps->pos)==-1);
}

int stack_is_full(pstack ps){
  return ((ps->pos)==((ps->n_max)-1));
}

unsigned int static_stack_dimension(pstack ps){
  return ps->n_max;
}

unsigned int static_stack_data_number(pstack ps){
  return ps->pos+1;
}

unsigned int stack_elements_number(pstack ps){
  fprintf(stderr,"The stack is STATIC, it has only one element.");
  return 1;
}

