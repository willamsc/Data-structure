#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef char el;
typedef struct Lnode
{
    el data;
    struct Lnode *next;
} LinkNode;

void CreatListF(LinkNode *L, el a[], int n)
{
    LinkNode *s;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
    for (int i = 0; i < n; i++)
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        s->next = L->next;
        L->next = s;
    }
}

void CreateListR(LinkNode *L, el a[], int n)
{
    LinkNode *s, *r;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
    r = L;
    for (int i = 0; i < n; i++)
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        s->next = NULL; // 新节点的下一个节点先设置为NULL
        r->next = s;    // 将新节点链接到链表的末尾
        r = s;          // 更新尾节点指针
    }
}

// 可以添加一个函数来打印链表，以验证链表是否正确创建
void PrintList(LinkNode *L)
{
    LinkNode *p = L->next; // 跳过头节点
    while (p != NULL)
    {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 主函数，用于测试上述函数
int main()
{
    el a[] = {'a', 'b', 'c', 'd', 'e'};
    int n = sizeof(a) / sizeof(a[0]);
    LinkNode *L;

    CreatListF(L, a, n);
    printf("Front insertion list: ");
    PrintList(L);

    // 释放前插法创建的链表内存
    LinkNode *p, *q;
    p = L->next;
    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    free(L);

    // 使用后插法重新创建链表
    CreateListR(L, a, n);
    printf("Rear insertion list: ");
    PrintList(L);

    // 释放后插法创建的链表内存
    p = L->next;
    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    free(L);

    return 0;
}