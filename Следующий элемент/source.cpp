// Created by elena on 27.09.17.
//

#include <iostream>
#include "assert.h"
using std::cout;
using std::cin;
const int MIN_VALUE=0;
const int MAX_VALUE=10000;


void getArrayData(int *array, int n){
    for (int i = 0; i < n; ++i) {
        cin>>array[i];
    }
}

int getIndex(int* A, int count, int x){// x- искомый элемент
    int first=0;
    int last=count;
    while(first<last){
        int mid=(first+last)/2;
        if(A[mid]<x)
            first=mid+1;
        else
            last=mid;
    }
    return (first == count || A[first]<x) ? -1 :first;
}
//Для каждого элемента массива B[i] найдите минимальный индекс k минимального элемента массива A,
//равного или превосходящего B[i]: A[k] >= B[i]. Если такого элемента нет, выведите n.
int * findIndexOfMinElement(int* A, int n, int* B, int m){
    int* minIndexes=new int[m];
    int j=0;
    for (int i = 0; i < m; i++) {
        int index=getIndex(A,n,B[i]);
        if(index==-1){
            minIndexes[j++]=n;
        }else{
            minIndexes[j++]=index;
        }
    }
    return minIndexes;
}

void printArrayMinIndexes(int *minIndexes, int m){
    for(int i=0; i<m; i++)
        cout<<minIndexes[i]<<" ";
}

int main(){
    int n=0;
    int m=0;
    cin>>n;
    cin>>m;
    assert(n>=MIN_VALUE && n<=MAX_VALUE);
    assert(n>=MIN_VALUE && n<=MAX_VALUE);
    int* A=new int[n];
    int* B= new int[m];
    getArrayData(A,n);
    getArrayData(B,m);
    int * minIndexes=findIndexOfMinElement(A,n,B,m);
    printArrayMinIndexes(minIndexes, m);

    delete [] A;
    delete [] B;
    delete [] minIndexes;
    return 0;
}