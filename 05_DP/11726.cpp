#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int n;
int num;
vector<int> tiles;

int tile(int n){
    if (n==1) return 1;
    if (n==2) return 2;
    if (tiles[n] != -1) return tiles[n];
    else{
        tiles[n] = (tile(n-1) + tile(n-2))%10007;
        return tiles[n];
    }
}

int main(){
    freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >> n;
    tiles.resize(n+1, -1);
    int answer = tile(n);
    cout << answer << '\n';
}

