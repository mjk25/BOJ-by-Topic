// 백준 13023 DFS

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

static vector <vector<int>> A;
static vector <bool> visited;
static bool arrive;

int main(){
    freopen("input.txt", "r", stdin);

    int n;
    int m;
    cin >> n >> m;

    arrive = false;
    A.resize(n);
    visited = vector<bool>(n, false);

    for (int i=0; i<n; i++){
        int s,e;
        cin >> s >> e;
        //양방향 저장
        A[s].push_back(e);
        A[e].push_back(s);
    }


}
