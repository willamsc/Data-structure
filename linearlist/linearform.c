#include<stdio.h>
void IniList();

#define Maxsize 10

typedef struct 
{
    int data[Maxsize];
    int length;
}Sqlist;

//将线性表初始化
void IniList(Sqlist *L){
    int i;
    for(i=0; i<Maxsize; i++){
        L->data[i]=0;
        L->length =0;
    }
}

int main(){
    Sqlist L;
    IniList(&L);
    //尝试打印整个线性表
    for(int i = 0; i<Maxsize; i++){
        printf("%d\n",L.data[i]);
    }
    return 0;
}