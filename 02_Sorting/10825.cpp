#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;
string names[10];

// 구조체
struct score {
    string name;
    int k, e, m;
};

bool compare(score a, score b){
    // compare함수에서는 가장 후 순위의 좁은 조건부터 
    if (a.k == b.k && a.e == b.e && a.m == b.m){
        return a.name < b.name;   
    }else if (a.k == b.k && a.e == b.e){
        return a.m > b.m;
    }else if (a.k == b.k){
        return a.e < b.e;
    }else {
        return a.k > b.k;
    }
}
    // if (a.k == b.k){
    //     if (a.e == b.e){
    //         if (a.k == b.k){
    //             return a.name < b.name;
    //             }
    //             else return a.m > b.m;
    //         }
    //         else return a.e < b.e;        
    //     }
    //     else return a.k > b.k;
    // }

int main(){
    //freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >> N;
    vector <score> v(N);    // 구조체 vector 생성

    for (int i=0; i<N; i++){
        cin >> v[i].name >>v[i].k>>v[i].e>>v[i].m;
    }
    
    sort(v.begin(), v.end(), compare);

    for (int j=0; j<N; j++){
        cout << v[j].name << "\n";
    }
    return 0;
}
