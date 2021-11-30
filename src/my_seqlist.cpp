#include "my_seqlist.h"

void InitSeqList(SeqList * plist)
{
    assert(plist != NULL);  //若用户指定的条件非true，则异常终止程序

    plist->sursize = 0;
    plist->capacity = SEQ_INIT_SIZE;
    plist->data = (ElemType *)malloc(sizeof(ElemType) * plist->capacity);
    if (NULL == plist->data)
    {
        printf("Failed to allocate memory\n");
        exit(EXIT_FAILURE);
        //若 exit_code 为 EXIT_FAILURE ，则返回指示不成功终止的实现定义状态
    }
}

void PrintSeqList(const SeqList * plist)
{
    assert(plist != NULL);
    printf("capacity: %d\n", plist->capacity);
    printf("cursize: %d\n", plist->sursize);

    for (int i = 0; i < plist->sursize; ++i)
    {
        printf("%3d ", plist->data[i]);
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
    //不可以对函数返回值赋值，所以格式写成GetSize(plist) == 0问题不大
    //当写成GetSize(plist) = 0编译器会报错
}

bool IsFull(const SeqList * plist)
{
    assert(plist != NULL);
    //return plist->sursize == plist->capacity;
    return GetSize(plist) == GetCapacity(plist);
}

status InsertItem(SeqList * plist, int pos, ElemType val)
{
    assert(plist != NULL);
    if (pos < 0 || pos > plist->sursize)
    {
        return INFEASIBLE;  //-1
    }
    //这里意思是先判断顺序表是否先满了，不满就不执行扩容函数
    //顺序表满了后，就执行扩容函数，然后扩容函数返回值取反，用来判断是否扩容成功
    if (IsFull(plist) && !Inc_Capacity(plist))
    {
        return OVERFLOW;    //-2
    }
    for (int i = plist->sursize; i > pos; --i)
    {
        plist->data[i] = plist->data[i-1];
    }
    plist->data[pos] = val;
    plist->sursize +=1;

    return OK;  //1
}

void PushFront(SeqList * plist, ElemType val)
{
    assert(plist != NULL);
    InsertItem(plist, 0, val);
}

void PushBack(SeqList * plist, ElemType val)
{
    assert(plist != NULL);
    InsertItem(plist, plist->sursize, val);
}

bool Inc_Capacity(SeqList * plist)
{
    assert(plist != NULL);
    int total = plist->capacity * SEQ_INC_SIZE;
    ElemType  * newdata = NULL;
    newdata = (ElemType *)malloc(sizeof(ElemType) * total);
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
    //理想情况下，realloc函数是直接在顺序表后面追加
    //顺序表后续堆空间不足的时候，realloc就像我们之前写的代码那样，重新申请一块已经扩容的堆内存。
    //然后把数据复制到新的堆内存上，并把扩容之前的那个顺序表的内存控制权限给回我们的操作系统
    //或者系统的堆内存不足，这里要是直接realloc分配失败，返回给plist->data,就变成NULL了。
    //导致内存泄露，丢失重要数据
    ElemType * newdata = NULL;
    newdata = (ElemType *)realloc(plist->data, sizeof(ElemType) * total);
    if (newdata == NULL)
    {
        return false;
    }
    plist->data = newdata;
    plist->capacity = total;
    return true;
}

status EraseElem(SeqList * plist, int pos)
{
    assert(plist != NULL);
    if (pos < 0 || pos > plist->sursize - 1) {
        return INFEASIBLE;
    }
    for (int i = pos; i < plist->sursize - 1; ++i) {
        plist->data[i] = plist->data[i + 1];
    }
    plist->sursize -= 1;
    return OK;
}

void PopFront(SeqList * plist)
{
    assert(plist != NULL);
    EraseElem(plist, 0);
}

void PopBack(SeqList * plist)
{
    assert(plist != NULL);
    EraseElem(plist, plist->sursize - 1);
}

bool LocateElem(const SeqList * plist, ElemType val)
{
    assert(plist != NULL);
    return FindValue1(plist, val) != -1;
}

void DestorySeqList(SeqList * plist)
{
    assert(plist != NULL);
    plist->sursize = 0;
    plist->capacity = 0;
    free(plist->data);
    plist->data = NULL;
}

void ClearSeqList(SeqList * plist)
{
    assert(plist != NULL);
    plist->sursize = 0;
}

status Remove(SeqList * plist, ElemType val)
{
    assert(plist != NULL);
    return EraseElem(plist,FindValue1(plist, val));
}

void BubbleSort(SeqList * plist)
{
    assert(plist != NULL);
    int temp;//临时变量
    for (int i = 0; i < plist->sursize - 1; ++i)
    {
        for (int j = 0; j < plist->sursize - 1 - i; ++j)
        {
            if (plist->data[j] > plist->data[j+1])  // >表示升序 <表示降序
            {
                temp = plist->data[j];
                plist->data[j] = plist->data[j+1];
                plist->data[j+1] = temp;
            }
        }
    }

}

void Remove_All1(SeqList * plist, ElemType val)
{
    assert(plist != NULL);
    int pos;
    while ((pos = FindValue1(plist, val)) != -1)
    {
        EraseElem(plist, pos);
    }
}

void Remove_All2(SeqList * plist, ElemType val)
{
    assert(plist != NULL);
    int j = -1;
    for (int i = 0; i < plist->sursize; ++i)
    {
        if (plist->data[i] != val)
        {
            j = j +1;
            plist->data[j] = plist->data[i];
        }
    }
    plist->sursize = j + 1;
}

void Remove_All3(SeqList * plist, ElemType val)
{
    assert(plist != NULL);
    int j = 0;
    for (int i = 0; i < plist->sursize; ++i)
    {
        if (plist->data[i] != val)
        {
            plist->data[j] = plist->data[i];
            j = j +1;
        }
    }
    plist->sursize = j;
}

void MergeList_Sqa(const SeqList *pLa, const SeqList * pLb, SeqList *pLc)
{
    //已知顺序线性表La和Lb的元素按值非递减排列。
    // 归并La和Lb得到新的顺序线性表Lc,Lc的元素也按值非递减排列
    ElemType * pa = pLa->data;
    ElemType * pb = pLb->data;
    pLc->capacity = pLc->sursize = pLa->sursize + pLb->sursize;
    ElemType * pc = pLc->data = (ElemType *)malloc(pLc->capacity * sizeof(ElemType));
    //这里要加上这个比较好
    if(NULL== pc) // 存储分配失败
        exit(OVERFLOW);
    ElemType * pa_Last = pLa->data + pLa->sursize - 1;
    ElemType * pb_Last = pLb->data + pLb->sursize - 1;
    while (pa <= pa_Last && pb <= pb_Last)
    {
        if (*pa <= *pb)
        {
            *pc++ = *pa++;  // *pc = *pa; pc++; pa++;
        }
        else
        {
            *pc++ = *pb++;
        }
    }
    while (pa <= pa_Last)
    {
        *pc++ = *pa++;
    }
    while (pb <= pb_Last)
    {
        *pc++ = *pb++;
    }
}

status MergeList_Sqb(const SeqList *pLa, const SeqList * pLb, SeqList &pLc)
{
    //已知顺序线性表La和Lb的元素按值非递减排列。
    // 归并La和Lb得到新的顺序线性表Lc,Lc的元素也按值非递减排列
    ElemType * pa = pLa->data;
    ElemType * pb = pLb->data;
    pLc.capacity = pLc.sursize = pLa->sursize + pLb->sursize;
    ElemType * pc = pLc.data = (ElemType *)malloc(pLc.capacity * sizeof(ElemType));
    if(NULL== pLc.data)
    {
        //exit(EXIT_FAILURE);
        return OVERFLOW;

    }
    ElemType * pa_Last = pLa->data + pLa->sursize - 1;
    ElemType * pb_Last = pLb->data + pLb->sursize - 1;
    while (pa <= pa_Last && pb <= pb_Last)
    {
        if (*pa <= *pb)
        {
            *pc++ = *pa++;  // *pc = *pa; pc++; pa++;
        }
        else
        {
            *pc++ = *pb++;
        }
    }
    while (pa <= pa_Last)
    {
        *pc++ = *pa++;
    }
    while (pb <= pb_Last)
    {
        *pc++ = *pb++;
    }
    return OK;
}

status MergeList_Sq(SeqList pLa, SeqList pLb, SeqList &pLc)
{
    //已知顺序线性表La和Lb的元素按值非递减排列。
    // 归并La和Lb得到新的顺序线性表Lc,Lc的元素也按值非递减排列
    ElemType * pa = pLa.data;
    ElemType * pb = pLb.data;
    pLc.capacity = pLc.sursize = pLa.sursize + pLb.sursize;
    ElemType * pc = pLc.data = (ElemType *)malloc(pLc.capacity * sizeof(ElemType));
    if(NULL== pLc.data)
    {
        //exit(EXIT_FAILURE);
        return OVERFLOW;

    }
    ElemType * pa_Last = pLa.data + pLa.sursize - 1;
    ElemType * pb_Last = pLb.data + pLb.sursize - 1;
    while (pa <= pa_Last && pb <= pb_Last)
    {
        if (*pa <= *pb)
        {
            *pc++ = *pa++;  // *pc = *pa; pc++; pa++;
        }
        else
        {
            *pc++ = *pb++;
        }
    }
    while (pa <= pa_Last)
    {
        *pc++ = *pa++;
    }
    while (pb <= pb_Last)
    {
        *pc++ = *pb++;
    }
    return OK;
}

void merge_1(int * nums1, int nums1Size, int m, int * nums2, int nums2Size, int n)
{
    assert(nums1 != NULL && nums2 != NULL);
    int * newdata = (int *)malloc(sizeof(int) * (m + n));
    if (NULL == newdata)
    {
        exit(1);
    }
    int i = 0, j = 0;  //i nums1, j nums2
    int k = 0;
    while (i < m && j < n)
    {
        newdata[k++] = nums1[i] <= nums2[j]?nums1[i++]:nums2[j++];
    }
    while (i < m) newdata[k++] = nums1[i++];
    while (j < n) newdata[k++] = nums2[j++];

    for (i = 0; i < m + n; ++i)
    {
        nums1[i] = newdata[i];
    }
    free(newdata);
    newdata =NULL;
}

void merge(int * nums1, int nums1Size, int m, int * nums2, int nums2Size, int n)
{
    assert(nums1 != NULL && nums2 != NULL);
    int i = m - 1;  //s1
    int j = n - 1;  //s2
    int k = m + n -1;   //s1
    while (i >= 0 && j >= 0)
    {
        nums1[k--] = nums2[j] >= nums1[i] ? nums2[j--]:nums1[i--];
    }
    while (j >= 0) {nums1[k--] = nums2[j--];}
}

void MoveArray(int * nums, int n)  //right 1
{
    assert(nums != NULL);
    int temp = nums[n-1];
    for (int i = n-1; i > 0; --i)
    {
        nums[i] = nums[i-1];
    }
    nums[0] = temp;
}

void Rotate(int *nums, int n, int k)
{
    assert(nums != NULL);
    if (k < 0) {printf("k error \n"); return ;}
    k = k % n;
    for (int i = 0; i < k; ++i)
    {
        MoveArray(nums, n);
    }
}

void Rotate_Right(int * nums, int n, int k)
{
    assert(nums != NULL);
    if (k < 0) return;
    k = k % n;
    int * newdata = (int *)calloc(sizeof(int), n);  //
    if(NULL == newdata) {exit(1);}
    int j = k;
    for (int i = 0; i <= n - k - 1; ++i)
    {
        newdata[j] = nums[i];
        j = j + 1;
    }
    j = 0;
    for (int i = n - k; i <= n - 1; ++i)
    {
        newdata[j] = nums[i];
        j = j + 1;
    }
    for (int i = 0; i < n; ++i)
    {
        nums[i] = newdata[i];
    }
    free(newdata);
    newdata = NULL;
}

void Swap_Init(int * ap, int *bp)
{
    int temp = *ap;
    *ap = *bp;
    *bp = temp;
}

void Rev(int * nums, int left, int right)
{
    assert(nums != NULL);
    while (left < right)
    {
        Swap_Init(&nums[left], &nums[right]);
        left++;
        right--;
    }
}

void Rotate_Ar(int * nums, int n , int k)
{
    assert(nums != NULL);
    if (k < 0) return;
    k = k % n;
    Rev(nums, 0, n-1);
    Rev(nums, 0, k - 1);
    Rev(nums, k, n - 1);
}