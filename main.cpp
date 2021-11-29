#include "my_seqlist.h"

int main()
{
    SeqList myseq = {};
    InitSeqList(&myseq);

//第一次测试，用尾插法初始给顺序表赋值，备注p13
//时间2021年11月29日12:00:00
/*
    for (int i = 0; i < 20; ++i)
    {
        PushBack(&myseq, i);
        PrintSeqList(&myseq);
    }
    //测试插入
    status tag = InsertItem(&myseq, 12, 23);
    PrintSeqList(&myseq);
*/

//第二次测试，测试冒泡    //自己写的
//时间2021年11月29日20:44:52
/*
    BubbleSort(&myseq);
    PrintSeqList(&myseq);
*/

//第三次测试，测试删除重复元素    //备注p19
//时间2021年11月29日21:01:13
/*
    int arr[] = {23, 12, 12, 34, 56, 12, 12, 78};
    int length = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < length; ++i)
    {
        PushBack(&myseq,arr[i]);
    }
    PrintSeqList(&myseq);
    //Remove_All1(&myseq, 12);
    //Remove_All2(&myseq, 12);
    Remove_All3(&myseq, 12);
    PrintSeqList(&myseq);
*/

    DestorySeqList(&myseq);
    return 0;
}

/*
 * 备注p20
 * dev分支
 */