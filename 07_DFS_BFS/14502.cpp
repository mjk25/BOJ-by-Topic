#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n,m;
int w=0;
int map[8][8];
int map_o[8][8];
int map_ing[8][8];
int visited[8][8];
int safe = 0;
int num=0;
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};


void BFS(){
    //cout << "bfs" <<endl;
    queue <pair<int,int>> q;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (map[i][j] == 2){
                q.push({i,j});
                //cout << "v "<< i <<j <<endl;
            }
        }
    }
    while (!q.empty()){
        int ii = q.front().first;
        int jj = q.front().second;
        q.pop();

        for (int i=0; i<4; i++){
            int ni = ii + dy[i];
            int nj = jj + dx[i];

            if(ni < 0 || nj < 0 || ni >= n || nj >= m) continue;

            if (map[ni][nj]==0){
                map[ni][nj] = 2;
                //cout << "new "<< ni <<nj <<endl;
                q.push({ni,nj});
            }
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (map[i][j] == 0){
                num ++;
            }
        }
    }
    
    safe = max(num, safe);
    num=0;
    //cout << "sf " << safe<< endl;
    return;
}

void Wall(int w){
    if (w==3) {
        copy(&map_ing[0][0], &map_ing[0][0]+64, &map[0][0]);
        BFS();
        return;
    }
    //나머지 2개 벽 고르기
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (map_ing[i][j] == 0){
                map_ing[i][j]=1;
                Wall(w+1);
                map_ing[i][j]=0;
            }
        }
    }
}

int main(){
    //freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >> n>>m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> map_o[i][j];
        }
    }
    copy(&map_o[0][0], &map_o[0][0]+64, &map_ing[0][0]);


    // 이중 for문으로 wall 하나 먼저 결정
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (map_ing[i][j]==0){
                map_ing[i][j]=1;
                Wall(1);
                map_ing[i][j]=0;
            }
        }
    }
    
    cout << safe << endl;
    return 0;
}