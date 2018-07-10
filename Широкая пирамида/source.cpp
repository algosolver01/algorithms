//
// Created by elena on 20.10.17.
//

#include <iostream>
#include <assert.h>

using namespace std;


void initArray(long **arr, long N){
    for(long i=0; i<N;i++){
        for(long j=0; j<N; j++){
            if(i==j)
                arr[i][j]=1;
            else
                arr[i][j]=0;
        }
    }
}

void show(long **arr, long N){
    cout<<endl;
    for(long i=0; i<N;i++){
        for(long j=0; j<N; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void calculateValues(long **arr, long N){
    long sum=0;
    for(long i=2; i<N;i++){
        for(long j=1; j<i; j++){
            for(long r=0; r<j; r++){
                sum+=arr[i-j-1][r];
            }
            arr[i][j]=sum;
            sum=0;
        }
        //show(arr,N);
    }
}



long getAmountOfLevels(int N){
    long **arr=new long*[N];
    for(long i=0; i<N; i++){
        arr[i]=new long [N];
    }

    initArray(arr, N);
    //show(arr,N);
    calculateValues(arr,N);

    long amount=0;
    for(long i=0; i<N; i++){
        amount+=arr[N-1][i];
    }


    for(long i=0; i<N; i++){
        delete arr[i];
    }

    delete [] arr;

    return amount;
}

int main(){
    int N=0;
    cin>>N;
    assert(N<=300 && N>=0);
    long amount=getAmountOfLevels(N);
    cout<<amount<<endl;
}