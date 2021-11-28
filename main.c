#include <stdio.h>

#define SEQ_INIT_SIZE 10    //初始化顺序表容量
#define SEQ_INC_SIZE  2     //顺序表增长因子

typedef int ElemType;
typedef struct
{
    ElemType * data;  //存储空间地址
    int capacity;     //容量
    int sursize;      //元素的个数
}SeqList;

int main(void)
{
    SeqList myseq;

    printf("Hello, World!\n");
    return 0;
}
