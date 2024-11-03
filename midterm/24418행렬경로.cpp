#include <iostream>
using namespace std;

int arr[31][31];
int mx[31][31];
int n;

int dp(int i, int j){
    if (i ==0 && j==0){
        mx[i][j] = 0;
    }
    else if (i ==0){
        mx[i][j] = mx[i-1][j] + arr[i][j];
    }
    else if (j ==0){
        mx[i][j] = mx[i][j-1] + arr[i][j];
    }else{
        mx[i][j] = mx[i-1][j] + mx[i][j-1];
    }
}

int main() {
    freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    dp(n-1, n-1);

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){

        }
    }

}