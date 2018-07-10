//
// Created by elena on 27.09.17.
//

#include <iostream>
#include "assert.h"
#include "math.h"
using std::cin;
using std::cout;

const int MAX_VALUE=1000;
const int MIN_VALUE=2;
double getSquare(int n){
    int CurrentX=0, CurrentY=0;
    int PreviousX=0, PreviousY=0;
    cin>>PreviousX;
    cin>>PreviousY;
    int v0x=PreviousX;
    int v0y=PreviousY;
    assert(PreviousX<MAX_VALUE && PreviousY<MAX_VALUE);
    double Square=0.0;
    for(int i=0; i<n-1; i++){
        cin>>CurrentX;
        cin>>CurrentY;
        assert(CurrentX<MAX_VALUE && CurrentY<MAX_VALUE);
        Square+=0.5*(PreviousY+CurrentY)*(PreviousX-CurrentX);
        PreviousX=CurrentX;
        PreviousY=CurrentY;
    }
    Square+=0.5*(PreviousY+v0y)*(PreviousX-v0x);
    return fabs(Square);
}

int main(){
    int n=0;
    cin>>n;
    assert(n > MIN_VALUE && n<MAX_VALUE);
    cout<<getSquare(n);
}