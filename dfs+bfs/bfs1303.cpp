// 백준 1303 BFS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

//배열 선언
char field[101][101];
bool visited[101][101];
int n,m;
int w,b;
int cnt = 1;
char team;
int w_sc,b_sc;
void BFS(int x, int y, char team);
int pa[] = {-1,0,1,0};
int pb[] = {0,-1,0,1};

int main(){
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    //입력
    for (int i=0; i<m; i++){
        string s;
        cin >> s;
        for (int j=0; j<n; j++){
            field[i][j] = s[j];
        }
    }

    //초기화
    for (int i=0; i<101; i++){
        for (int j=0; j<101; j++){
            visited[i][j] = false;
        }
    }

    //아군 bfs
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (field[i][j]=='W'){
                if (visited[i][j]==false){
                    BFS(i,j,'W');
                    w_sc += cnt*cnt;
                    cnt =1;
                }
                
            }
        }
    }

    //초기화
    for (int i=0; i<101; i++){
        for (int j=0; j<101; j++){
            visited[i][j] = false;
        }
    }


    //적군 bfs
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (field[i][j]=='B' && visited[i][j]==false){
                BFS(i,j,'B');
                b_sc += cnt*cnt;
                cnt =1;
            }
        }
    }

    cout << w_sc <<" "<< b_sc << "\n";


}

void BFS(int y, int x, char team){
    queue <pair<int,int>> q;
    q.push({y,x});
    visited[y][x] = true;

    while (!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for (int i=0; i<4; i++){
            int na = a + pa[i];
            int nb = b + pb[i];
        
            if (na < 0 || na >= n || nb < 0 || nb >= m)
                continue;
            if (visited[na][nb]==false && field[na][nb] == team){
                q.push({na,nb});
                visited[na][nb] = true;
                cnt ++;
            }
            
        }
    }
}


