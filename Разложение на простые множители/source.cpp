//
// Created by elena on 27.09.17.
//
#include <assert.h>
#include <iostream>
using std::cin;
using std::cout;
const int MIN_VALUE=2;
const int MAX_VALUE=1000000;

void getSimpleMultipliers(int n){
    for (int i = 2; i <= n;) {
        if (n % i == 0) {
            cout << i;
            n /= i;
            if (n > 1)
                cout << " ";
        } else {
            i++;
        }
    }

}

int main() {
    int n;
    cin >> n;
    assert(n >= MIN_VALUE && n <= MAX_VALUE);
    getSimpleMultipliers(n);
    return 0;
}
