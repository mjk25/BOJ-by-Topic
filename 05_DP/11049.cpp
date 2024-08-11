#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int n;
int r,c;

int mtrx[501][2];
int mm[501][501];

int dp(int i, int n){
    for(int i=1; i<n; i++){
        for(int j=1; j<=n-i; j++){
            mm[j][i+j] = 2147483647;

            for(int k=j; k<=i+j; k++){
                mm[j][i+j] = min(mm[j][i+j], mm[j][k]+ mm[k+1][i+j]+ mtrx[j][0]*mtrx[k][1]*mtrx[i+j][1]);
            }
        }
    }
    return 0;
}

int main(){
    //freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >> n;

    for (int i=1; i<n+1; i++){
        cin >> r >> c;
        mtrx[i][0] = r;
        mtrx[i][1] = c;
    }

    dp(1,n);

    cout << mm[1][n] ;

}