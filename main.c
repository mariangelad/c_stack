#include <stdio.h>
#include "stack.h"


int main(void){
  int sd1=sizeof(int);
  pstack st1;
  st1=create_stack(sd1, DYNAMIC);

  printf("The stack st1 contains %d data\n", stack_data_number(st1));

  int a=1,b=2,c=3,d=4;
  push(st1,&a);
  push(st1,&b);
  push(st1,&c);
  push(st1,&d);
  printf("The st1 stack has maximum dimension %u and contains %u elements\n",stack_max_dimension(st1), element_number(st1));

  printf("The st1 stack contains %d data\n", stack_data_number(st1));

  printf("The element %d has been deleted\n",*(int*)pop(st1));
  printf("The element %d has been deleted\n",*(int*)pop(st1));
//  push(st1,&d);
  printf("The element %d has been deleted\n",*(int*)pop(st1));
  printf("The st1 stack contains %d data\n", stack_data_number(st1));


  int sd2=sizeof(char)*50;
  pstack st2;
  st2=create_stack(sd2, MIXED);
  printf("The st2 stack has maximum dimension %u and contains %u elements\n",stack_max_dimension(st2), element_number(st2));
  printf("The st2 stack contains %d data\n", stack_data_number(st2));


  char* name1=malloc(sizeof(char)*50);
  char* name2=malloc(sizeof(char)*50);
  char* name3=malloc(sizeof(char)*50);
  char* name4=malloc(sizeof(char)*50);
  name1="is_love";
  name2="need";
  name3="you";
  name4="All";
  push(st2,&name1);
  push(st2,&name2);
  push(st2,&name3);
  push(st2,&name4);
  
  printf("The st2 stack contains %d data\n", stack_data_number(st2));
  printf("The st2 stack has maximum dimension %u and contains %u elements\n",stack_max_dimension(st2), element_number(st2));

  printf("The datum %s has been deleted\n",*(char**)pop(st2));
  printf("The st2 stack contains %d data\n", stack_data_number(st2));

  printf("The item %s has been deleted\n",*(char**)pop(st2));
  printf("The datum %s has been deleted\n",*(char**)pop(st2));
  printf("The st2 stack contains %d data\n", stack_data_number(st2));

  printf("The datum %s has been deleted\n",*(char**)pop(st2));
  pop(st2);
 


  return 1;
}


