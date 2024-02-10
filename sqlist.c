#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#define Maxsize 50
typedef char ElemType;
typedef struct 
{
    ElemType data[Maxsize];
    int length;
}Sqlist;
void CreateList(Sqlist *L,ElemType a[], int n){     //初始化线性表
    L = (Sqlist *)malloc(sizeof(Sqlist));   //动态分配线性表需要的空间
    for (int i = 0; i < n; i++)
    {
        L->data[i] = a[i];
    }
    L->length = n;
    
}

void InitList(Sqlist*L)     //初始化线性表
{
    L = (Sqlist * )malloc(sizeof(Sqlist));      //给线性表分配空间
    L->length = 0;
}

void DestroyList(Sqlist *L)
{
    free(L);
}

bool ListEmpty(Sqlist *L)       //判断线性表是否为空
{
    return(L->length == 0);
}

int ListLength(Sqlist *L)       //求线性表的长度
{
    return(L->length);
}

void DisList(Sqlist *L)
{   int i = 0;
    for ( i = 0; i < L->length; i++)
    {
        printf("%c", L->data[i]);
    }
    printf("\n");
}

bool GetElem(Sqlist * L,int i,ElemType *e)
{
    if (i<1 || i>L->length)
    {
        return false;
    }
    *e = L->data[i - 1];
}

int LocateElem(Sqlist * L,ElemType e)
{
    int i = 0;
    while (i<L->length && L->data[i])
    {
        i++;
    }
    if(i>L->length)
    {
        return 0;
    }
    else{
        return i+1;
    }
}

bool ListInsert(Sqlist * L, int i, ElemType e)
{
    int j;
    if(i<1 || i>L->length+1 || L->length ==Maxsize)
    {
        return false;
    }
    i--;
    for(L->length;j>i;j--)
    {
        L->data[j]=L->data[j-1];
    }
}