#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

void DFS();

int n,m;
int senior;
int i, w;
vector <vector<int>> worker;
vector <int> compli;

int main(){
    freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >>n>>m;
    worker.resize(n+1, vector<int> (0,0));
    compli.resize(n+1, 0);

    for (int j=1; j<n+1; j++){
        cin >> senior;
        if (senior ==-1){
            worker[0].push_back(j);
        }else{
            worker[senior].push_back(j);
        }  
    }

    for (int j=0; j<m; j++){
        cin >> i >> w;
        compli[i] += w;
    }
    DFS();

    for (int j=1; j<n+1; j++){
        cout << compli[j] << " ";
    }
    return 0;
}

void DFS(){
    for (int j=1; j<n; j++){
        for (int junior : worker[j]){
            compli[junior] += compli[j];
        }
    }
}