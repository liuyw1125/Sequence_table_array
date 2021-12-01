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
#define NULLPTR     -3  //空指针

typedef int status;     //状态

#define SEQ_INIT_SIZE 10    //初始化顺序表容量
#define SEQ_INC_SIZE  2     //顺序表增长因子

typedef int ElemType;
typedef struct
{
    ElemType * data;  //存储空间地址
    int capacity;     //容量
    int cursize;      //元素的个数
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
//19.冒泡排序
void BubbleSort(SeqList * plist);
//20.删除所有和val相等的数据元素,三种实现方法
void Remove_All1(SeqList * plist, ElemType val);
void Remove_All2(SeqList * plist, ElemType val);
void Remove_All3(SeqList * plist, ElemType val);

//数据结构书，或者面试题中的一些题目
//21.严蔚敏数据结构第一版，算法2.7，两个顺序线性表的合并，第一种方式用c语言指针，另一种方式用C++的引用,另一种是结构体浅拷贝
void MergeList_Sqa(const SeqList *pLa, const SeqList * pLb, SeqList *pLc);
status MergeList_Sqb(const SeqList *pLa, const SeqList * pLb, SeqList &pLc);
status MergeList_Sq(SeqList pLa, SeqList pLb, SeqList &pLc);
//22.合并两个有序数组(非递减),参数，数组首地址，数组空间大小，元素个数,两种方法
void merge_1(int * nums1, int nums1Size, int m, int * nums2, int nums2Size, int n);
void merge(int * nums1, int nums1Size, int m, int * nums2, int nums2Size, int n);
//23.旋转数组，将数组中的元素向右移动k个位置，其中k是非负整数。
//第一种
void MoveArray(int *nums, int n);  //right 1
void Rotate(int *nums, int n, int k);
//第二种，空间换时间
void Rotate_Right(int * nums, int n, int k);
//第三种,逆置
void Swap_Init(int * ap, int *bp);
void Rev(int * nums, int left, int right);
void Rotate_Ar(int * nums, int n , int k);
//24.严蔚敏数据结构第一版，算法2.1,往顺序表中插入没有的元素
void Union(SeqList * pLa, const SeqList * pLb);

//25.返回指定位置的数据元素
status GetElem(const SeqList * plist, int pos, ElemType * pval); //定位11:00 p23 24数据结构书中的代码详解
status Get_Elem(const SeqList * plist, int pos, ElemType &pval); //定位24:34

#endif