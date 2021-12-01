#include "my_seqlist.h"

//p24 25 数据结构中代码的详解(2),main函数部分
//时间 2021年12月1日11:56:08
#if 0
int main()
{
    int ar[] = {2, 4, 6, 8, 10};
    int na = sizeof(ar)/sizeof(ar[0]);
    int br[] = {1, 3, 6, 8, 9, 11};
    int nb = sizeof(br)/sizeof(br[0]);

    SeqList La, Lb;
    InitSeqList(&La);
    InitSeqList(&Lb);
    for (int i = 0; i < na; ++i) { PushBack(&La, ar[i]);}
    for (int i = 0; i < nb; ++i) { PushBack(&Lb, br[i]);}
    PrintSeqList(&La);
    PrintSeqList(&Lb);
    Union(&La, &Lb);

    PrintSeqList(&La);

    DestorySeqList(&La);
    DestorySeqList(&Lb);

    return 0;
}
#endif


//p22 23旋转数组的三种方法
//时间2021年11月30日16:02:38
#if 0
int main()
{
    int ar[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(ar)/sizeof(ar[0]);
    //第一种方法，一个一个移动
    //Rotate(ar, n, 3);
    //第二种方法,辅助空间
    //Rotate_Right(ar, n, 3);
    //第三种方法，逆置
    Rotate_Ar(ar, n , 3);


    return 0;
}
#endif



//p20 21合并两个有序数据
//时间2021年11月30日13:38:04
#if 0
int main()
{
    //用debug调试
    //第一种方法
    /*
    int ar[6] = {1, 2, 5};  //1 2 2 3 5 8
    int br[3] = {2, 3, 8};
    //merge_1(ar, 6, 3, br, 3, 3);
     */
    //第二种方法
    int ar[6] = {6, 8, 9};  //2 3 6 8 8 9
    int br[3] = {2, 3, 8};
    merge(ar, 6, 3, br, 3, 3);

    return 0;
}
#endif

//p19 20数据结构中代码的详解(1),main函数部分
//时间 2021年11月30日11:30:23
#if 0
int main()
{
    int ar[] = {1, 3, 5, 7, 9, 11, 20};
    int an = sizeof(ar)/sizeof(ar[0]);
    int br[] = {2, 4, 8, 10, 15, 19, 45, 89, 100};
    int bn = sizeof(br)/sizeof(br[0]);
    SeqList La, Lb, Lc;
    InitSeqList(&La);
    InitSeqList(&Lb);
    // 不用InitList()创建空表Lc

    for (int i = 0; i < an; ++i)
    {
        PushBack(&La, ar[i]);
    }
    for (int i = 0; i < bn; ++i)
    {
        PushBack(&Lb, br[i]);
    }
    PrintSeqList(&La);
    PrintSeqList(&Lb);

    //这里是引用和直接用指针的差别
    //1.指针
    //MergeList_Sqa(&La, &Lb, &Lc);
    //2.引用(取别名)
    //MergeList_Sqb(&La, &Lb, Lc);
    //3.结构体浅拷贝临时变量La，Lb的*data里的值和实参的指向的是同一个堆区数组(线性表)
    MergeList_Sq(La, Lb, Lc);

    PrintSeqList(&Lc);

    DestorySeqList(&La);
    DestorySeqList(&Lc);
    DestorySeqList(&Lc);

    return 0;
}
#endif

//p18 19面试题删除所有重复的值的代码详解main函数（p1到p18）
//时间 2021年11月30日10:20:05
#if 0
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

#endif

/*
 * 备注更新到那个里，目前是p23
 * dev分支
 */