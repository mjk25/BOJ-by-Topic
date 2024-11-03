#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
// 2156 포도주 시식  https://www.acmicpc.net/problem/2156
// i의 식이 i-3부터 시작, i=1,2 값 미리 넣어놓기
// i=4-1=3부터 시작하므로, 영향 없도록 3-3=0, 0번째도 0으로 초기화하기

using namespace std;

int N;
int A[10001];
int B[10001];
int ans=0;


int main(){
    freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >> N;
    for (int i=1; i<N+1; i++){
        cin >> A[i];
    }
    B[0] = 0;
    B[1] = A[1];
    B[2] = A[1]+A[2];

    for (int i=3; i<N+1; i++){
        B[i] = max({B[i-3] + A[i-1]+ A[i], B[i-2]+ A[i], B[i-1]}) ;
    }

    cout << B[N] << endl;
}