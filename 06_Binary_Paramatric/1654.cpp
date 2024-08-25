#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

int k, n;
int lan[10002];
int leng =1;
long long leftl =1;
long long rightl, mid, num;
long long ans=0;

int main() {
    freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >> k >> n;
    for (int i=0; i<k; i++){
        cin >> lan[i];
        leng = max(leng, lan[i]);        
    }
    rightl = leng;

    while (leftl <= rightl){
        num = 0;
        mid = (leftl + rightl)/2;

        for (int i=0; i<k; i++){
            num += lan[i]/mid;
        }

        if (num < n){
            rightl = mid-1;
        }else{
            leftl = mid+1;
            ans = max(mid, ans);
        }
    }
    cout << ans ;
}
