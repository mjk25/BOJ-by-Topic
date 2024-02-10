// 백준 13023 DFS

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

static vector <vector<int>> A;
static vector <bool> visited;
static bool arrive;
void DFS(int now, int depth);

int main(){
    freopen("input.txt", "r", stdin);

    int n;
    int m;
    cin >> n >> m;

    arrive = false;
    A.resize(n);        
    visited = vector<bool>(n, false);

    for (int i=0; i<m; i++){    //벡터에 노드관계담기
        int s,e;
        cin >> s >> e;
        //양방향 저장 ***
        A[s].push_back(e);
        A[e].push_back(s);
    }

    for (int k=0; k<n; k++){
        DFS(k,1);
        if (arrive) break;
    }

    // 종료
    if (arrive){
        cout << 1 << "\n";
    }
    else {
        cout << 0 << "\n";
    }
}

void DFS(int now, int depth){
    if (depth==5||arrive){  //종료 조건
        arrive = true;
        return;
    }
    visited[now] = true;

    for (int node: A[now]){ //재귀
        if (!visited[node])
            DFS(node, depth+1);
        }
    
    // 재귀 중 종료조건에 도달하지못한 경우: 새 시작을 위해
    visited[now] = false;
}
