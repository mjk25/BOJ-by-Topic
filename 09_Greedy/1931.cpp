#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

int n, a, b;
int num =1;
pair <int,int> arr[100001];

int main(){
    freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >> n;

    for (int i=0; i<n; i++){
        cin >> a >>b;
        arr[i] = {b,a};
    }
    sort(arr, arr+n);

    int f = arr[0].first;

    for (int i=1; i<n; i++){
        if (f <= arr[i].second){
            num +=1;
            f = arr[i].first;
        }
    }
    cout << num;
}