// 가장 긴 바이토닉 부분 수열 (증 + 감)
// https://www.acmicpc.net/problem/11054
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A;
vector<int> B;
vector<int> C;
int num;


int smaller(int id){
    // C[id] = B[id];
    for (int i=N; i>id; i--){
        if (A[id] > A[i]){
            C[id] = max(C[id], C[i]+1);
            //cout << id << C[id] <<endl;
        }
    }
    return 0;
}

int bigger(int id){
    for (int j=1; j<id; j++){
        if (A[id] > A[j]){
            B[id] = max(B[id], B[j]+1);
            //cout << id << B[id] <<endl;
        }
    }
    return 0;
}



int main(){
    freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >> N;
    A.resize(N+1);
    B.resize(N+1, 1);
    C.resize(N+1, 1);
    for (int i=1; i<N+1; i++){
        cin >> A[i];
    }

    for (int j=1; j<N+1; j++){
        bigger(j);
    }
    for (int j=N; j>=1; j--){
        smaller(j);
    }
    
    for (int j=1; j<N+1; j++){
        //cout << B[j] <<C[j] << endl;

        B[j] += C[j] -1;
    }
    


    int ans1 = *max_element(B.begin(), B.end()); // #include <algorithm>
    cout << ans1 << endl;
}