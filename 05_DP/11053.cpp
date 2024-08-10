#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A;
vector<int> B;
int num;

int longer(int id){
    //if (id==N) return 1;
    //else if (B[id]!=1) return B[id];
    for (int j=1; j<id; j++){
        if (A[id] > A[j])
            B[id] = max(B[id], B[j]+1);
    }
    return 0;
}

int main(){
    freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >> N;
    A.resize(N+1);
    B.resize(N+1, 1);
    for (int i=1; i<N+1; i++){
        cin >> A[i];
    }

    for (int j=1; j<N+1; j++){
        longer(j);
    }

    int ans = *max_element(B.begin(), B.end());
    cout << ans << endl;
}