#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

int N,M;
int x,c;
int cards[500002];

int main() {
    freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> x;
        cards[i] =x;
    }
    sort(cards, cards+N);

    cin >> M;
    for (int i=0; i<M; i++){
        cin >> c;
        int answer = upper_bound(cards, cards + N, c) - lower_bound(cards, cards + N, c);
        cout << answer << " ";
    }
}