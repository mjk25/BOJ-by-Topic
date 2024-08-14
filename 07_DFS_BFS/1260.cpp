#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m,v;
vector <vector<int>> A;
vector <bool> visited;

void BFS(int now);
void DFS(int now);

int main(){
    //freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >>n>>m>>v;
    A.resize(n+1);
    visited.resize(n+1, false);

    for (int i=0; i<m; i++){
        int n1,n2;
        cin >> n1 >> n2;
        // 양방향
        A[n1].push_back(n2);
        A[n2].push_back(n1);
    }

    for (int i=0; i<=n; i++){
        sort(A[i].begin(), A[i].end());
    }

    DFS(v);
    visited.assign(n + 1, false); // 방문 배열 초기화
    cout << "\n";
    BFS(v);
}

void BFS(int now){
    queue <int> q;
    q.push(now);
    visited[now] = true;

    while (!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int next: A[node]){
            if (!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }
}


void DFS(int now){
    visited[now] = true;
    cout << now << " ";

    for (int node: A[now]){
        if (!visited[node]){
            DFS(node);
        }
    }
}

