#define Maxsize 100
typedef int Elemtype;
#include <stdio.h>

typedef struct
{
  Elemtype data[Maxsize];
  int top;
} stack;

void initstack(stack *s)
{
  s->top = -1;
}

int isEmpty(stack *s)
{
  if (s->top == -1)
  {
    printf("栈为空");
    return 1;
  }
  else
  {
    return 0;
  }
}

int push(stack *s, Elemtype e)
{
  if (s->top == Maxsize - 1)
  {
    printf("栈满了");
    return 0;
  }

  s->top++;
  s->data[s->top] = e;
  return 1;
}

Elemtype pop(stack *s, Elemtype *e)
{
  if (s->top == -1)
  {
    printf("栈为空");
    return 0;
  }
  *e = s->data[s->top];
  s->top--;
  return 1;
}

Elemtype getTop(stack *s, Elemtype *e)
{
  if (s->top == -1)
  {
    printf("栈为空");
    return 0;
  }
  *e = s->data[s->top];
  return 1;
}

int main()
{

  stack s;
  initstack(&s);
  push(&s, 10);
  push(&s, 20);
  push(&s, 30);
  Elemtype e;
  pop(&s, &e);
  printf("删除的数据为%d", e);
  getTop(&s, &e);
  printf("栈顶数据为%d", e);

  return 0;
}