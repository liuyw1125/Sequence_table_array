#include <stdio.h>

#include "my_seqlist.h"

int main(void)
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

//第二次测试，测试冒泡
//时间2021年11月29日20:44:52
/*
    BubbleSort(&myseq);
    PrintSeqList(&myseq);
*/
    DestorySeqList(&myseq);
    return 0;
}

/*
 * 备注p19
 */