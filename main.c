#include <stdio.h>

#include "my_seqlist.h"

int main(void)
{
    SeqList myseq = {};
    InitSeqList(&myseq);

    //第一次测试，用尾插法初始给顺序表赋值，备注p13
    for (int i = 0; i < 20; ++i)
    {
        PushBack(&myseq, i);
        PrintSeqList(&myseq);
    }
    status tag = InsertItem(&myseq, 12, 23);
    PrintSeqList(&myseq);

    DestorySeqList(&myseq);
    return 0;
}

