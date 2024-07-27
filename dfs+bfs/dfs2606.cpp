// 백준 2606 DFS

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

static vector <vector<int>> A;
static vector <bool> visited;
static bool arrive;
void DFS(int now, int depth);
int com;

int main(){
    freopen("input.txt", "r", stdin);

    int n;
    int m;
    cin >> n >> m;
    
    // 벡터 크기 정해주는거 잊지않기 !!
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
    }

   
}

void DFS(int now, int depth){
    
    visited[now] = true;
    com ++;
    for (int node: A[now]){ //재귀
        if (!visited[node])
            DFS(node, depth+1);
        }
    
}
