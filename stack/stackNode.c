#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int Elemtype;
typedef struct stackNode
{
  Elemtype data;
  struct stackNode *next;
} Stack;

Stack *stackinit()
{
  Stack *s = (Stack *)malloc(sizeof(Stack));
  s->next = NULL;
  s->data = 0;
  return s;
}

int isEmpty(Stack *s)
{
  if (s->next == NULL)
  {
    printf("stack is empty\n");
    return 1;
  }
  else
  {
    return 0;
  }
}
