#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"



///////* General stack functions *////////////

#ifndef funz
#define funz
pstack (*creastack_array[])(unsigned int sizedata, stack_type st)={malloc_stack, malloc_list, malloc_stack_list};
int (*push_array[])(pstack ps, pvoid newdata)={push_stack, add_in_top, push_stack_list};
pvoid (*pop_array[])(pstack ps)={pop_stack, delay_in_top, pop_stack_list};
unsigned int (*element_num[])(pstack ps)={stack_elements_number, list_elements_number, list_elements_number};
unsigned int (*stack_dim[])(pstack ps)={static_stack_dimension, list_dimension, static_stack_dimension};
unsigned int(*data_num[])(pstack ps)={static_stack_data_number, list_elements_number, mixed_stack_data_num};
#endif


////*** Function creating the stack. The stack type must be specified by the parameter st STATIC, DINAMIC or MIXED  ***////
pstack create_stack(unsigned int sizedata, stack_type st){
  return creastack_array[st](sizedata, st);
}


////*** Insert a data on top of the stack  ***////
int push(pstack ps, pvoid newdata){
  return push_array[ps->stacktype](ps, newdata);
}

////*** Pick up and delay a data from the top of the stack ***////
pvoid pop(pstack ps){

  return pop_array[ps->stacktype](ps);
}


////*** Function giving the number of data stored in the stack ***////
unsigned int stack_data_number(pstack ps){
  return data_num[ps->stacktype](ps);
}


////*** Function giving the maximum dimension of the static stack, if used ***////
unsigned int stack_max_dimension(pstack ps){
  return stack_dim[ps->stacktype](ps);
}

////*** Function giving the number of element in the list ***////
unsigned int element_number(pstack ps){
  return element_num[ps->stacktype](ps);
}
