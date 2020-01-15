#include <iostream>
#include "SortTestHelper.h"
using namespace std;



template <typename T>
int  __partition(T arr [],int left,int right){
    /*
     * partition process
     * 在 [left,right]
     *返回一个位置 p   arr[l..p-1] < arr[p] , arr[p+1] > arr[p]
     * */
    T v  = arr[left] ;

    int  j = left;
    // arr[left+1 ...j] <v ; arr[j+1,i) >v
    for (int i = left+1;i<=right;i++){
        //  arr[i]>v  do nothig 只要 i++ 即可
        if (arr[i]< v){
            swap(arr[j+1] ,arr[i]);
            j++ ;
        }
    }
    swap(arr[j],arr[left]) ;
    return j ;
}


template <typename T>
void  __quickSort(T arr[],int left,int right){
    /* 快速排序
     * */

    if (left>=right){
        return ;
    }

    // 返回一个分界点
    int pos  = __partition(arr,left,right);
    __quickSort(arr,left,pos-1);
    __quickSort(arr,pos+1,right) ;

}


template <typename T>
void  quickSort(T arr,int len){
    /* 快速排序
     * */

    __quickSort(arr,0 ,len-1) ;

}



int main() {
    cout << "Hello, World!" << std::endl;

    int n  =10000 ;
    cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;

    int * arr1 = SortTestHelper::generateRandomArray(n,0,n) ;
    int * arr2 = SortTestHelper::copyIntArray(arr1,n) ;

    quickSort(arr1,n) ;

    SortTestHelper::testSort("quick Sort:" ,quickSort,arr1,n);
//    SortTestHelper::testSort("quick Sort:" ,quickSort,arr1,n);


//    SortTestHelper::printArray(arr1,n);
    delete [] arr1;
    delete []  arr2;
    return 0;
}
