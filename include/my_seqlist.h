#ifndef  MY_SEQLIST_H
#define  MY_SEQLIST_H

#include <stdio.h>      //printf
#include <assert.h>     //断言函数
#include <malloc.h>      //malloc realloc free
#include <stdlib.h>     //EXIT_FAILURE
#include <stdbool.h>    //bool
#include <string.h>     //memmove

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

//接口声明
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
status InsertItem(SeqList * plist, int pos, ElemType val);
//9.头插数据元素
void PushFront(SeqList * plist, ElemType val);
//10.尾插数据元素
void PushBack(SeqList * plist, ElemType val);
//11.扩容函数,两种实现方法，一个是malloc，另一个是realloc
bool Inc_Capacity(SeqList * plist);
bool Inc_Capacity_realloc(SeqList * plist);
//12.删除指定位置数据元素
status EraseElem(SeqList * plist, int pos);
//13.头删数据元素
void PopFront(SeqList * plist);
//14.尾删除元素
void PopBack(SeqList * plist);
//15.判断数据元素是否在表中
bool LocateElem(const SeqList * plist, ElemType val);
//16.销毁
void DestorySeqList(SeqList * plist);
//17.重置为空表
void ClearSeqList(SeqList * plist);
//18.删除数据元素
status Remove(SeqList * plist, ElemType val);


#endif