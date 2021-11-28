#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TRUE    1
#define FALSE   0
#define OK      1
#define ERROR   0

#define INFEASIBLE  -1  //不能实行
#define OVERFLOW    -2  //内存溢出

typedef int status;     //状态

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
//8.指定位置插入数据元素
status EraseElem(SeqList * plist, int pos, ElemType val);
//9.头插数据元素
void PushFront(SeqList * plist, ElemType val);
//10.尾插数据元素
void PushBack(SeqList * plist, ElemType val);
//11.扩容函数,两种实现方法，一个是malloc，另一个是realloc
bool Inc_Capacity(SeqList * plist);
bool Inc_Capacity_realloc(SeqList * plist);


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
    assert(plist != NULL);
    return plist->sursize;
}

int GetCapacity(const SeqList * plist)
{
    assert(plist != NULL);
    return plist->capacity;
}

bool IsEmpty(const SeqList * plist)
{
    assert(plist != NULL);
    //return 0 == plist->sursize;
    return 0 == GetSize(plist);
}

bool IsFull(const SeqList * plist)
{
    assert(plist != NULL);
    //return plist->sursize == plist->capacity;
    return GetSize(plist) == GetCapacity(plist);
}

status EraseElem(SeqList * plist, int pos, ElemType val)
{
    assert(plist != NULL);
    if (pos < 0 && pos > plist->sursize)
    {
        return -INFEASIBLE;
    }
    //这里意思是先判断顺序表是否先满了，不满就不执行扩容函数
    //顺序表满了后，就执行扩容函数，然后扩容函数返回值取反，用来判断是否扩容成功
    if (IsFull(plist) && !Inc_Capacity(plist))
    {
        return -ERROR;
    }
    for (int i = plist->sursize; i > pos; --i)
    {
        plist->data[i] = plist->data[i-1];
    }
    plist->data[pos] = val;

    return OK;
}

void PushFront(SeqList * plist, ElemType val)
{
    assert(plist != NULL);
    EraseElem(plist, 0, val);
}

void PushBack(SeqList * plist, ElemType val)
{
    assert(plist != NULL);
    EraseElem(plist, plist->sursize, val);
}

bool Inc_Capacity(SeqList * plist)
{
    assert(plist != NULL);
    int total = plist->capacity * SEQ_INC_SIZE;
    ElemType * newdata = (ElemType *)malloc(sizeof(ElemType) * total);
    if (NULL == newdata)
    {
        return false;
    }
    /*  在插入元素的函数调用的情况下，因为是顺序表满了条件成立才使用。
     *  for循环里面的plist->capacity和plist->cursize是一样的，
     */
//    for (int i = 0; i < plist->capacity; ++i)
//    {
//        newdata[i] = plist->data[i];
//    }

    //for循环对顺序表迁移，可以直接使用memmove替代,头文件为string.h
    /*
     *  void* memmove( void* dest, const void* src, size_t count );
     *  从 src 所指向的对象复制 count 个字节到 dest 所指向的对象。
    */
    memmove(newdata, plist->data, sizeof(ElemType) * plist->capacity);
    //第一种定义一个临时变量存放plist->data
//    ElemType * tempdata = plist->data;
//    plist->data = newdata;
//    free(tempdata);

    //第二种直接先free，然后再改，不用定义一个临时变量
    free(plist->data);
    plist->data = newdata;
    plist->capacity = total;
    return true;
}

bool Inc_Capacity_realloc(SeqList * plist)
{
    assert(plist != NULL);
    int total = plist->capacity * SEQ_INC_SIZE;
    //realloc的用法请参考杨老师的说明或者自己百度解决
    ElemType * newdata = (ElemType *)realloc(plist->data, sizeof(ElemType) * total);
    if (newdata == NULL)
    {
        return false;
    }
    plist->data = newdata;
    plist->capacity = total;
    return true;
}