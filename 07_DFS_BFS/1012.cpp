#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int t;
int m,n,k;
int num;
int x,y;
bool farm[51][51] = {false};
int pm[] = {-1,0,1,0};
int pn[] = {0,-1,0,1};

//vector <bool> visited;
bool visited[51][51] = {false};

void DFS(int r, int c){
    visited[r][c] = true;

    for (int p=0; p<4; p++){
        if (pn[p]+r < 0 || pm[p]+c < 0) continue;
        else if (pn[p]+r >= n || pm[p]+c >= m) continue;
        //cout << pn[p]+r << pm[p]+c <<endl;
        if ( (!visited[pn[p]+r][pm[p]+c]) && (farm[pn[p]+r][pm[p]+c]) ){
            //cout << "farm "<< farm[pn[p]+r][pm[p]+c] <<endl;
            //cout << "DFS " << pn[p]+r << pm[p]+c <<endl;
            DFS(pn[p]+r, pm[p]+c);
            
        }
    }
        
}

void start(){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if ((!visited[i][j]) && (farm[i][j] == true)){
                //cout << "ij "<< i <<j<<endl;
                DFS(i, j);
                num +=1;
            }
        }
    }
}


int main(){
    freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >> t;

    for (int i=0; i<t; i++){
        num=0;
        for (int i=0; i<51; i++){
            for (int j=0; j<51; j++){
                farm[i][j] = false;
                visited[i][j] = false;
            }
        }
        farm[51][51] = {false};
        visited[51][51] = {false};
        
        cin >>m>>n>>k;
        for (int i=0; i<k; i++){
            cin >> x >> y;
            farm[y][x] = true;
        }
        start();
        cout << num << endl;
    }
}