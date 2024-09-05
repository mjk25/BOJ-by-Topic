#include <iostream>
#include <stdio.h>
using namespace std;

long long s;
long long m, n;

int main() {
    freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >> s ;

    while (s>0){
        n +=1;
        s = s-n;
    }

    if (s<0){
        n -=1;
    }
    cout << n;
}