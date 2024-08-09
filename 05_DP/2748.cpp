#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

long long n;
vector<long long> num;

long long fibo(long long n){
    if (n==0) return 0;
    if (n==1) return 1;
    if (num[n] != -1) return num[n];

    num[n] = fibo(n-1) + fibo(n-2);
    return num[n];
}

int main(){
    freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >> n;
    num.resize(n+1, -1);
    long long answer = fibo(n);
    cout << answer << "\n";
}