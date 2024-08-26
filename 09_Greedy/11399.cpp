#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

int n;
int ans = 0;
int arr[1005];

int main(){
    //freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    
    cin >> n;

    for(int i=0;i<n;i++){
        cin >>arr[i];
    }
    sort(arr,arr+n);

    for(int i=0;i<n;i++){
        ans += arr[i]*(n-i);
    }

    cout << ans;
    return 0;
}