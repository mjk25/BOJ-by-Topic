#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

int arr[1005];

int main(){
    int n;
    int ans = 0;

    cin >> n;

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    sort(arr,arr+n);

    for(int i=0;i<n;i++)
        ans += arr[i]*(n-i);

    cout << ans;

    return 0;
}