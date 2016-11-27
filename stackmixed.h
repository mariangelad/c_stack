#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


////*** List of static stack: a list whose elements contains static stacks storing the data ***////

////*** Generic element of the list of static stacks ***////
typedef struct stackel{
  struct stackel* next;   /* next points to the following element of the list */
  int pos;                /* number of filled element of the array */
  pvoid array;            /* array points to the static stack */
}stackelement;

typedef stackelement* pstackelem;
typedef pstackelem* ppstackelem;


