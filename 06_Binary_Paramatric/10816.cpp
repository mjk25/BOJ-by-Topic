#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

int N,M,x;

int main() {
    freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >> N;
    map<int, int> cards;
    
    for (int i = 0; i < N; i++) {
        cin >> x;
        cards[x]++;
    }

    cin >> M;
    for (int i=0; i<M; i++){
        cin >> x;
        cout << cards[x] << " ";
    }
}