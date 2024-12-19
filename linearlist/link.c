#include <stdio.h>
#include <stdlib.h>

// 定义单链表结构体
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *initilist()
{ // 创建一个头结点并将它初始化
    Node *list = (Node *)malloc(sizeof(Node));
    list->data = 0; // 用头结点的数据域来记录链表中的元素的个数
    list->next = NULL;
    return list;
}

void headInsert(Node *list, int data)
{ // 头插法
    // 1、创建一个新节点
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = list->next;
    list->next = node;
    list->data++;
}

void tailInsert(Node *list, int data)
{                      // 尾插法
    Node *head = list; // 保存头结点
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    Node *temp = list->next; // 使用临时指针遍历链表
    while (temp && temp->next)
    {
        temp = temp->next;
    }
    if (temp)
    {
        temp->next = node;
    }
    else
    {
        list->next = node; // 如果链表为空，直接插入到头结点后面
    }
    head->data++;
}

void delete(Node *list, int data)
{ // 删除含有对应元素值的结点
    Node *pre = list;
    Node *current = list->next;
    int found = 0; // 标记是否找到要删除的元素
    while (current)
    {
        if (current->data == data)
        {
            pre->next = current->next;
            free(current);
            found = 1;
            break; // 找到并删除后退出循环
        }
        pre = current;
        current = current->next;
    }
    if (found)
    {
        list->data--;
    }
}

void printlist(Node *list)
{
    list = list->next;
    while (list)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

int main()
{
    Node *list = initilist();
    headInsert(list, 1);
    headInsert(list, 2);
    headInsert(list, 3);
    headInsert(list, 4);
    headInsert(list, 5);
    tailInsert(list, 6);
    tailInsert(list, 7);
    tailInsert(list, 8);
    tailInsert(list, 9);
    tailInsert(list, 10);
    printlist(list);
    return 0;
}