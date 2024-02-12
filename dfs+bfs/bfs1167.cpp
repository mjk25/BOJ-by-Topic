// 백준 1167 BFS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair <int,int> edge;
static vector <vector<edge>> A;
static vector <bool> visited;
static vector <int> max_dist;
void BFS(int node);
int maxl;

int main(){
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    A.resize(n+1);

    for (int i=0; i<n; i++){
        int s;
        cin >> s;
        while (true){
            int e,v;
            cin >> e;
            if (e==-1) break;
            cin >> v;
            A[s].push_back(edge(e,v));
        } 
    }

    max_dist = vector<int>(n+1, 0);
    visited = vector<bool>(n+1, false);
    BFS(1);
    int max =1;
    for (int i=0; i<=n; i++){
        if (max_dist[max] <= max_dist[i]){
            max = i;
        }
    }
    fill(max_dist.begin(), max_dist.end(), 0);
    fill(visited.begin(), visited.end(), false);
    BFS(max);
    sort(max_dist.begin(), max_dist.end());
    cout << max_dist[n] << "\n";
}

void BFS(int node){
    // 큐 구현
    queue <int> myqueue;
    myqueue.push(node);
    visited[node] = true;

    while(!myqueue.empty()){    //큐에 값이 있으면 계속함
        int now_node = myqueue.front();
        myqueue.pop();
        for (edge i : A[now_node]){
            if (!visited[i.first]){ 
                visited[i.first] = true;
                myqueue.push(i.first);
                //거리 배열 업데이트
                max_dist[i.first] = max_dist[now_node] +i.second;
            }
        }
    }
}