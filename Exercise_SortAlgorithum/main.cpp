//
//  main.cpp
//  test
//
//  Created by ChengJY on 14-2-25.
//  Copyright (c) 2014年 ChengJY. All rights reserved.
//

#include <iostream>
using namespace std;

#include "MyData.h"

//插入
void InsertSort(int* pData,int Count)
{
    int iTemp;
    int iPos;
    for(int i = 1;i < Count;i++)
    {
        iTemp = pData[i]; //保存要插入的数
        iPos = i-1;     //被插入的数组数字个数
        while((iPos >= 0) && (iTemp < pData[iPos]))
        { //从最后一个（最大数字）开始对比,大于它的数字往后移位
            pData[iPos+1] = pData[iPos];
            iPos--;
        }
        pData[iPos+1] = iTemp; //插入数字的位置
    } 
}

//选择
void SelectSort(int* pData,int Count)
{
    int iTemp;
    int iPos;
    for(int i = 0;i < Count - 1;i++)
    {
        iPos = i;
        iTemp = pData[iPos];
        for(int j = i + 1;j < Count;j++)
        {
            if(pData[j] < iTemp)
            {
                iTemp = pData[j];
                iPos = j;
            }
        }
        pData[iPos] = pData[i];
        pData[i] = iTemp;
    }
}

//交换
void ExchangeSort(int* pData,int Count)
{
    int iTemp;
    int i;
    for(i = 0;i < Count - 1;i++)//共（count-1)轮,每轮得到一个最小值
    {
        for(int j = i + 1;j < Count;j++)//每次从剩下的数字中寻找最小值,于当前最小值相比,如果小则交换
        {
            if(pData[j] < pData[i])
            {
                iTemp = pData[i];
                pData[i] = pData[j];
                pData[j] = iTemp;
            }
        }
    } 
}

//冒泡
void BubbleSort(int* pData,int Count)
{
    int iTemp;
    for(int i = 1;i < Count;i++)//一共进行（count-1）轮,每次得到一个最小值
    {
        for(int j = Count-1;j >= i;j--) //每次从最后往前交换,得到最小值
        {
            if(pData[j] < pData[j-1])
            {
                iTemp = pData[j-1];
                pData[j-1] = pData[j];
                pData[j] = iTemp;
            }
        }
    } 
}

//快速
void run(int* pData,int left,int right)
{
    int i,j;
    int middle,iTemp;
    i = left;
    j = right;
    middle = pData[(left+right)/2]; //求中间值
    do{
        while((pData[i] < middle) && (i < right))//从左扫描大于中值的数
            i++;
        while((pData[j] > middle) && (j > left))//从右扫描大于中值的数
            j--;
        if(i <= j)//找到了一对值
        {
            //交换
            iTemp = pData[i];
            pData[i] = pData[j];
            pData[j] = iTemp;
            i++;
            j--;
        }
    }while(i <= j);//如果两边扫描的下标交错,就停止（完成一次）
    
    //当左边部分有值(left<j),递归左半边 
    if(left < j)
        run(pData,left,j);
    //当右边部分有值(right>i),递归右半边 
    if(right > i)
        run(pData,i,right);
} 

void QuickSort(int* pData,int Count)
{ 
    run(pData,0,Count-1);
}

//双向冒泡
void Bubble2Sort(int* pData,int Count)
{
    int iTemp;
    int left = 1;
    int right =Count -1;
    int t;
    do
    {
        //正向的部分
        for(int i=right;i>=left;i--)
        {
            if(pData[i] < pData[i-1])
            {
                iTemp = pData[i];
                pData[i] = pData[i-1];
                pData[i-1] = iTemp;
                t = i;
            }
        }
        left = t+1;
        
        //反向的部分
        for(int j=left;j<right+1;j++)
        {
            if(pData[j] < pData[j-1])
            {
                iTemp = pData[j];
                pData[j] = pData[j-1];
                pData[j-1] = iTemp;
                t = j;
            }
        }
        right = t - 1;
    }while(left <= right);
}

//SHELL 稳定的插入排序
void ShellSort(int* pData,int Count)
{
    int step[4];
    step[0] = 9;
    step[1] = 5;
    step[2] = 3;
    step[3] = 1;
    
    int iTemp;
    int k,s,w;//step
    
    for(int i=0;i<4;i++)
    {
        k = step[i];
        s = -k;
        for(int j=k;j<Count;j++)
        {
            iTemp = pData[j];
            w = j-k;//求上step个元素的下标
            if(s ==0)
            {
                s = -k;
                s++;
                pData[s] = iTemp;
            }
            while((iTemp<pData[w]) && (w>=0) && (w<=Count))
            {
                pData[w+k] = pData[w];
                w = w-k;
            }
            pData[w+k] = iTemp;
        }
    } 
}


//模板
template <class T>
void runTemp(T* pData,int left,int right)
{
    int i,j;
    T middle,iTemp;
    i = left;
    j = right;
    //下面的比较都调用我们重载的操作符函数
    middle = pData[(left+right)/2]; //求中间值
    do{
        while((pData[i]<middle) && (i<right))//从左扫描大于中值的数
            i++;
        while((pData[j]>middle) && (j>left))//从右扫描大于中值的数
            j--;
        if(i<=j)//找到了一对值
        {
            //交换
            iTemp = pData[i];
            pData[i] = pData[j];
            pData[j] = iTemp;
            i++;
            j--;
        }
    }while(i<=j);//如果两边扫描的下标交错,就停止（完成一次）
    
    //当左边部分有值(left<j),递归左半边
    if(left<j)
        runTemp(pData,left,j);
    //当右边部分有值(right＞i),递归右半边
    if(right>i)
        runTemp(pData,i,right);
}

template <class T>
void QuickSort_Temp(T* pData,int Count)
{
    runTemp(pData,0,Count-1);
}

//归并排序
//将有二个有序数列a[first...mid]和a[mid...last]合并。
void mergearray(int a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int m = mid,   n = last;
	int k = 0;
	
	while (i <= m && j <= n)    //添加进temp数组
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	
	while (i <= m)  //a[i]的后续清理工作
		temp[k++] = a[i++];
	
	while (j <= n)  //b[j]的后续清理工作
		temp[k++] = a[j++];
	
	for (i = 0; i < k; i++) //将tmep[]放回到a[]中
		a[first + i] = temp[i];
}
//归并排序
void mergesort(int a[], int first, int last, int temp[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergesort(a, first, mid, temp);    //左边有序
		mergesort(a, mid + 1, last, temp); //右边有序
		mergearray(a, first, mid, last, temp); //再将二个有序数列合并
	}
}
//归并排序
bool MergeSort(int a[], int n)
{
	int *p = new int[n];
	if (p == NULL)
		return false;
	mergesort(a, 0, n - 1, p);
	delete[] p;
	return true;
}


//堆排序
void HeapAdjust(int *a,int i,int size)  //调整堆
{
    int lchild=2*i;       //i的左孩子节点序号
    int rchild=2*i+1;     //i的右孩子节点序号
    int max=i;            //临时变量
    if(i<=size/2)          //如果i是叶节点就不用进行调整
    {
        if(lchild<=size&&a[lchild]>a[max])
        {
            max=lchild;
        }
        if(rchild<=size&&a[rchild]>a[max])
        {
            max=rchild;
        }
        if(max!=i)
        {
            swap(a[i],a[max]);
            HeapAdjust(a,max,size);    //避免调整之后以max为父节点的子树不是堆
        }
    }
}

//堆排序
void BuildHeap(int *a,int size)    //建立堆
{
    int i;
    for(i=size/2;i>=1;i--)    //非叶节点最大序号值为size/2
    {
        HeapAdjust(a,i,size);
    }
}

//堆排序
void HeapSort(int *a,int size)    //堆排序
{
    int i;
    BuildHeap(a,size);
    for(i=size;i>=1;i--)
    {
        //cout<<a[1]<<" ";
        swap(a[1],a[i]);           //交换堆顶和最后一个元素，即每次将剩余元素中的最大者放到最后面
        //BuildHeap(a,i-1);        //将余下元素重新建立为大顶堆
        HeapAdjust(a,1,i-1);      //重新调整堆顶节点成为大顶堆
    }
}


int main(int argc, const char * argv[])
{
    int data[] = {4,3,1,7,6,2,8};
    
    //before
    for (int i = 0;i < 7;i++)
        cout<<data[i]<<" ";
    cout<<"\n";
    
//    BubbleSort(data,7);
//    ExchangeSort(data,7);
//    SelectSort(data,7);
//    InsertSort(data,7);
//    QuickSort(data,7);
//    Bubble2Sort(data,7);
//    ShellSort(data,7);
//    MergeSort(data, 7);
    HeapSort(data, 7);
    
    //after
    for (int i = 0;i < 7;i++)
        cout<<data[i]<<" ";
    cout<<"\n";
    
    //模板
    /*
    CMyData data[] = {
        CMyData(4,"xulion"),
        CMyData(5,"sanzoo"),
        CMyData(9,"wangjun"),
        CMyData(2,"VCKBASE"),
        CMyData(3,"jacky2000"),
        CMyData(1,"cwally"),
        CMyData(17,"VCUSER"),
    };
    
    QuickSort_Temp(data,7);
    
    for (int i=0;i<7;i++)
        cout<<data[i].m_iIndex<<" "<<data[i].GetData()<<" "<<"\n";
    cout<<"\n";
    */
    
    
    MergeSort(data, 7);
    //after
    for (int i = 0;i < 7;i++)
        cout<<data[i]<<" ";
    cout<<"\n";
    return 0;
}

