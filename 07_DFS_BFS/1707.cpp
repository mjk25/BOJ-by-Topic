#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int k;
int v,e;
int p,l;
vector<int> graph[20001];
int visited[20001];
bool answer =true;

void BFS(int now);
void Check();


int main(){
    //freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >>k;

    for (int i=0; i<k; i++){
        cin >> v >>e;
        memset(&visited, 0, sizeof(visited));
        memset(&graph, 0, sizeof(graph));

        for (int j=1; j<1+e; j++){
            cin >> p >>l;
            graph[p].push_back(l);
            graph[l].push_back(p);
        }
        for (int h=1; h<v+1; h++){
            BFS(h);
        }
        Check();
    }
    
    return 0;
}

void BFS(int now){
    if (visited[now]==0){
        queue <int> q;
        q.push(now);
        visited[now]=1;

        while (!q.empty()){
            int node = q.front();
            q.pop();
            
            for (int next: graph[node]){
                if (visited[next]==0){
                    q.push(next);
                    if (visited[node] ==1){
                        visited[next] = 2;
                    }else {
                        visited[next] = 1;
                    }
                }
            }
        }
    }
    return;
}

void Check(){
    for (int i=1; i<v+1; i++){
        for (int next: graph[i]){
            if (visited[i] == visited[next]){
                answer = false;
                cout <<"NO" <<endl;
                return;
            }
        }
    }
    cout <<"YES" <<endl;
    return;
}