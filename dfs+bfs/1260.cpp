// 백준 1303 BFS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int n,m,v;
vector <vector<int>> A;
vector <bool> visited;
void BFS(int now);
void DFS(int now);

int main(){
    freopen("input.txt", "r", stdin);
    cin >> n >> m >> v;
    A.resize(n);
    visited = vector<bool>(n, false);

    // 입력받아서 벡터에 넣기
    for (int i=0; i<m; i++){
        int num1, num2;
        cin >> num1 >> num2;
        A[num1].push_back(num2);
    }
    
    DFS(v);
}


//BFS
void BFS(int now){

}


//DFS
void DFS(int now){
    
    while(!A.empty()){
        for (int node: A[now]){
            
        }
        if (!visited[now]){
            visited[now] = true;
            cout << now <<" ";
        }
        DFS(now);
    }
}