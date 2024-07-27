#include <iostream>
#include <stdio.h>
#include <utility>

using namespace std;

int N;
int x, y, heavy;
int d[50];

int main(){
    //freopen("input.txt", "r", stdin);

    cin >> N;
    pair<int, int> arr[N];

    for (int i=0; i<N; i++){
        cin >> arr[i].first >> arr[i].second ;
    }

    for (int i=0; i<N; i++){
        heavy =1;
        for (int j=0; j<N; j++){
            if (arr[i].first < arr[j].first){
                if (arr[i].second < arr[j].second){
                    heavy +=1; 
                }
            }
        }
        d[i] = heavy;
    }

    for (int i=0; i<N; i++){
        cout << d[i] << ' ';
    }
}
