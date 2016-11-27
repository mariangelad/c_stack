#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef void *pvoid;
typedef pvoid *ppvoid;
typedef enum {STATIC, DYNAMIC, MIXED} stack_type; /* the enumerators identify three stack implementations: as an array (STATIC), as a list (DYNAMIC) and as a list of array (MIXED)  */


////*** Generic stack structure ***////

/* It is used to implement the stack in the STATIC, DYNAMIC or MIXED cases */

typedef struct{
  pvoid pstart;            /* pstart points to a generic stack: it points to an array in the STATIC case, while it points to the first element of the list in the DYNAMIC and MIXED cases */
  unsigned int n_max;      /* maximum dimension of the stack array */
  unsigned int size_data;  /* data size in CHARBIT units */
  int pos;                 /* last filled element position */
  stack_type stacktype;    /* stack type: it can be STATIC, DYNAMIC or MIXED */
}stack;

typedef stack* pstack;   /* pointer to the stack data structure */


////*** Stack functions ***////

pstack malloc_stack(unsigned int size_data, stack_type st);
int push_stack(pstack ps, pvoid new_data);
pvoid pop_stack(pstack ps);
int stack_is_empty(pstack ps);
int stack_is_full(pstack ps);
unsigned int static_stack_data_number(pstack ps);
unsigned int static_stack_dimension(pstack ps);
unsigned int stack_elements_number(pstack ps);

#ifndef mlist
#define mlist

pstack malloc_list(unsigned int size_data, stack_type st);
int add_in_top(pstack ps, pvoid new_data);
pvoid delay_in_top(pstack ps);
unsigned int list_elements_number(pstack pd);
unsigned int list_dimension(pstack ps);

pstack malloc_stack_list(unsigned int size_data, stack_type st);
int push_stack_list(pstack psl, pvoid new_data);
pvoid pop_stack_list(pstack psl);
unsigned int mixed_stack_data_num(pstack psl);

#endif

pstack create_stack(unsigned int nmax, stack_type st);
int push(pstack ps, pvoid newdata);
pvoid pop(pstack ps);
unsigned int element_number(pstack ps);
unsigned int stack_max_dimension(pstack ps);
unsigned int stack_data_number(pstack ps);


