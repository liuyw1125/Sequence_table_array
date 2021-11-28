#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

#define SEQ_INIT_SIZE 10    //初始化顺序表容量
#define SEQ_INC_SIZE  2     //顺序表增长因子

typedef int ElemType;
typedef struct
{
    ElemType * data;  //存储空间地址
    int capacity;     //容量
    int sursize;      //元素的个数
}SeqList;

//1.初始化线性表函数实现
void InitSeqList(SeqList * plist);
//2.打印函数实现
void PrintSeqList(const SeqList * plist);
//3.查询函数，返回下标(两种实现方法)
//pos代表的是数组下标
int FindValue1(const SeqList * plist, ElemType val);
int FindValue2(const SeqList * plist, ElemType val);
//4.返回表中数据元素的个数
int GetSize(const SeqList * plist);
//5.返回表的容量
int GetCapacity(const SeqList * plist);
//6.判表是否为空，是true，否flase
bool IsEmpty(const SeqList * plist);
//7.判表是否已满
bool IsFull(const SeqList * plist);

int main(void)
{
    SeqList myseq;

    InitSeqList(&myseq);

    printf("Hello, World!\n");
    return 0;
}

void InitSeqList(SeqList * plist)
{
    assert(plist != NULL);  //若用户指定的条件非true，则异常终止程序

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

void PrintSeqList(const SeqList * plist)
{
    assert(plist != NULL);
    printf("capacity: %d", plist->capacity);
    printf("cursize: %d", plist->sursize);

    for (int i = 0; i < plist->sursize; ++i)
    {
        printf("%3d", plist->data[i]);
    }
    printf("\n");
}

int FindValue1(const SeqList * plist, ElemType val)
{
    assert(plist != NULL);
    int pos = -1;
    for (int i = 0; i < plist->sursize; ++i)
    {
        if (val == plist->data[i])
        {
            pos = i;
            break;
        }
    }
    return pos;
}

int FindValue2(const SeqList * plist, ElemType val)
{
    assert(plist != NULL);
    int pos = plist->sursize-1;
    while ((pos >= 0) && (val!= plist->data[pos]))
    {
        --pos;
    }
    return pos;
}

int GetSize(const SeqList * plist)
{
    return plist->sursize;
}

int GetCapacity(const SeqList * plist)
{
    return plist->capacity;
}

bool IsEmpty(const SeqList * plist)
{
    //return 0 == plist->sursize;
    return 0 == GetSize(plist);
}

bool IsFull(const SeqList * plist)
{
    //return plist->sursize == plist->capacity;
    return GetSize(plist) == GetCapacity(plist);
}