#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int N, K;
int elem;
int big=0;
int digit=0;
int n, d;
int answer=0;
vector<int> set;

void mximum(int n){
    if (N < n){
        return;
    }
    answer = max(answer, n);

    n *= 10;

    for (int i=0; i<K; i++){
        mximum(n + set[i]);
    }
}

int main(){
    //freopen("input.txt", "r", stdin);

    cin >> N >> K;
    set = vector<int>(K);
    for (int i=0; i<K; i++){
        cin >> set[i];
    }

    int num = N;
    while (num > 0){ //자리수 구하기 
        num /= 10;
        digit +=1;
    }

    mximum(0);
    cout << answer;
}