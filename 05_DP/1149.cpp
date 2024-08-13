#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
int n;
int r,g,b;
int color[1001][3];
int mm[1001][3];

int main(){
    freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >> n;

    for (int i=1; i<=n; i++){
        cin >> r >> g >> b;
        color[i][0] = r;
        color[i][1] = g;
        color[i][2] = b;
    }

    for (int i=1; i<=n; i++){
        color[i][0]+=min(color[i-1][1],color[i-1][2]);
        color[i][1]+=min(color[i-1][0],color[i-1][2]);
        color[i][2]+=min(color[i-1][0],color[i-1][1]);
    }
    int answer = min(color[n][0],min(color[n][1],color[n][2]));
    cout << answer ;
}