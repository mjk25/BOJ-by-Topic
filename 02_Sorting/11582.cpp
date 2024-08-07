#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>

using namespace std;


int N;
int k, p, chick;
vector<int> ck;
vector<int> ck2;

void merge(int left, int right){
    if ((right-left) > (N/k)) return;

    int mid = (left + right)/2;

    int i1 = left;
    int i2 = mid+1;
    int i3 = left;

    while (i1 <= mid && i2 <= right){
        if (ck[i1] <= ck[i2]){
            ck2[i3++] = ck[i1++];
        }else{
            ck2[i3++] = ck[i2++];
        }
    }
    int tmp = i1 > mid ? i2 : i1;
    while (i3 <= right){
        ck2[i3++] = ck[tmp++];
    }
    for (int i=left; i<=right; i++){
        ck[i] = ck2[i];
    }

}

void mergesort(int left, int right){
    if (left < right){
        int mid = (left + right)/2;
        mergesort(left, mid);
        mergesort(mid+1, right);
        merge(left, right);
    }
}

int main(){
    //freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >> N;
    ck.resize(N);
    ck2.resize(N);

    for (int i=0; i<N; i++){
        cin >> ck[i];
    }
    cin >> k;

    mergesort(0, N-1);

    // for (int j=0; j<N/2; j++){
    //     p=N/pow(2,(j+1));

    //     if (p==k){
    //         break;
    //     }
    // }
    for (int i=0; i<N; i++){
        cout << ck2[i] << ' ';
    }
}