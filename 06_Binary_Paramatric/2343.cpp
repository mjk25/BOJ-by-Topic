#include <iostream>
#include <stdio.h>
using namespace std;

int n, m;
int l=0;
int r;
int s=0;
int lect[100001];
int mid, length;
int ans;

int main() {
    //freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> lect[i];
        s += lect[i];
        l = max(l, lect[i]);
    }
    l = 1;
    r = s;

    ans = s;
    while (l <= r){
        length =0;
        int time =1;
        mid = (l+r)/2;

        for (int i=0; i<n; i++){
            if (lect[i] > mid){ 
                time = s+1;
                break;
            }
            length += lect[i];
            if (length > mid){
                length = lect[i];
                time +=1;
            }
        }


        if (time > m){
            l = mid+1;
        }else {
            r = mid-1;
            ans = min(ans, mid);
        }
        
    }

    cout << ans ;
}
