#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


typedef char *pchar;


////*** Generic list element structure ***////
typedef struct elemento{
  struct elemento *next;
  char mem;             /* to make access to data simply point to &(pl->mem) then cast the item according to the data type */
}elem;

typedef elem *pelem;
typedef pelem *ppelem;


////*** List structure ***////
typedef struct{
  int pos;        /* number of elements */
  int size_data;  /* data size in CHARBIT units */
  pelem pinizio;  /* pinizio points to the first element of the list */
}list;

typedef list *plist;
typedef pvoid (*func)();
