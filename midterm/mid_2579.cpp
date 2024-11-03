#include <iostream>
#include <stdio.h>

using namespace std;

int n;
int num;
int st[301];
int pt[301];


int main(){
    //freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >> n;
    for (int i=1; i<n+1; i++){
        cin >> st[i];
    }
    pt[1] = st[1];
    pt[2] = st[1] + st[2];
    pt[3] = max(st[1]+st[3], st[2]+st[3]);

    for (int i=4; i<n+1; i++){

        pt[i] = max(pt[i-3] + st[i-1] , pt[i-2]) + st[i];
    }
    cout << pt[n];
}