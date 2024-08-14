#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int num=-1;
vector <vector<int>> A;
vector <bool> visited;

void DFS(int now);

int main(){
    freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >> n;
    cin >> m;
    A.resize(n+1);
    visited.resize(n+1, false);

    int a,b;
    for (int i=0; i<m; i++){
        cin >> a >> b;
        A[a].push_back(b);
        A[b].push_back(a);
    }

    DFS(1);
    cout << num;
}

void DFS(int now){
    visited[now] = true;
    num +=1;

    for (int node : A[now]){
        if (!visited[node]){
            DFS(node);
        }
    }
}