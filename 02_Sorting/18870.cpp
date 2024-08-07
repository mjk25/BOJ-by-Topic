#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int main(){
    //freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >> N;
    vector <int> p;
    p.resize(N);
    
    for (int i=0; i<N; i++){
        cin >> p[i];
    }
    vector <int> p2;
    p2 = p;

    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
     

    for (int i=0; i<N; i++){
        cout << lower_bound(p.begin(), p.end(), p2[i]) - p.begin() << " ";
    }
    return 0;
}