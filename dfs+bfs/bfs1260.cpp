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
vector <bool> visited ;

void BFS(int now);
void DFS(int now);

int main(){
    freopen("input.txt", "r", stdin);
    cin >> n >> m >> v;
    A.resize(n+1);
    visited.resize(n+1, false);

    // 입력받아서 벡터에 넣기
    for (int i=0; i<m; i++){
        int num1, num2;
        cin >> num1 >> num2;
        A[num1].push_back(num2);
        A[num2].push_back(num1);
    }

    // 정렬 
    for (int i = 0; i <= n; ++i) {
		sort(A[i].begin(), A[i].end());
	}
    
    
    DFS(v);
    visited.assign(n + 1, false); // 방문 배열 초기화
    cout << "\n";
    BFS(v);
    return 0;
}


//BFS
void BFS(int now){
    queue <int> q;
    q.push(now);
    visited[now] =true;

    while (!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int next: A[node]){
            if (!visited[next]){
                visited[next]=true;
                q.push(next);
            }
        }
    }
}

/*void BFS(int now) {
    queue<int> q;
    // now는 현재 방문 노드
    q.push(now);
    visited[now] = true;

    while (!q.empty()) {
        // node는 큐에서 뽑은 현재 방문 노드
        int node = q.front();
        q.pop();
        cout << node << " ";

        // next는 node의 인접 노드
        for (int next : A[node]) {
            if (!visited[next]) {
                q.push(next);   // next가 새롭게 큐에 추가됨
                visited[next] = true;
            }
        }
    }
}*/


//DFS
void DFS(int now){
    
    visited[now] = true;
    cout << now <<" ";

    for (int node : A[now]) {
        if (!visited[node]) {
            DFS(node);
        }
    }
}
