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

    int v;
    cin >> v;
    int n,l;
    for (int i=0; i<v; i++){
        while (n!=-1){
            cin >> n >> l;
        } 
    }
}

void BFS(int node){
    // 큐 구현
    queue <int> myqueue;
    myqueue.push(node);
    visited[node] = true;

    while(!myqueue.empty()){
        
    }
}