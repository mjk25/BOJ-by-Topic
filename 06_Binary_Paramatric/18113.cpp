#include <iostream>
#include <stdio.h>
using namespace std;

int n,k,m;
int l=1;
int r=0;
int kb[1000000];
int piece=0;
int p;
int answer=-1;

int main() {
    // freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >> n >> k >> m;

    // 김밥 전처리
    for (int i=0; i<n; i++){
        cin >> kb[i];
        if (kb[i] >= 2*k){
            kb[i] = kb[i] - 2*k;
        }
        else if (kb[i] > k){
            kb[i] = kb[i] - k;
        }else{
            kb[i] =0;
        }
        
        r = max(r, kb[i]);
    }

    // P최대
    while (l<=r){
        piece =0;
        p = (l+r)/2;

        for (int i=0; i<n; i++){
            piece += kb[i]/p;
        }

        if (piece >= m){
            answer = max(answer, p); 
            l = p+1;
        }else{
            r = p-1;
        }

    }
    cout << answer;
}