#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>

#define SEQ_INIT_SIZE 10    //初始化顺序表容量
#define SEQ_INC_SIZE  2     //顺序表增长因子

typedef int ElemType;
typedef struct
{
    ElemType * data;  //存储空间地址
    int capacity;     //容量
    int sursize;      //元素的个数
}SeqList;

//初始化线性表函数实现
void InitSeqList(SeqList * plist);

int main(void)
{
    SeqList myseq;

    InitSeqList(&myseq);

    printf("Hello, World!\n");
    return 0;
}

void InitSeqList(SeqList * plist)
{
    assert(plist != NULL);

    plist->data = (ElemType *)malloc(sizeof(ElemType) * SEQ_INIT_SIZE);
    if (NULL == plist)
    {
        printf("Failed to allocate memory");
        exit(EXIT_FAILURE);
        //若 exit_code 为 EXIT_FAILURE ，则返回指示不成功终止的实现定义状态
    }
    plist->sursize = 0;
    plist->capacity = SEQ_INIT_SIZE;
}
