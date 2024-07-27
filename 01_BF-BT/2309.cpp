#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int dwarf[9];
int sum =0;
int h=0;
void reals();

int main()
{
    //freopen("input.txt", "r", stdin);
    for (int i=0; i<9; i++){
        cin >> N;
        dwarf[i] = N;
        sum += N;
    }
    
    reals();
    sort(dwarf, dwarf+9);
    
    for(int i=0; i<9; i++){
        if (dwarf[i]>0){
            cout << dwarf[i] << '\n';
        }
    }
    return 0;
}

void reals(){
    for (int i=0; i<9; i++){
        for (int j=1; j<9; j++){
            h = dwarf[i] + dwarf[j];    // h는 9명 키 합
            if (sum-h == 100){ // 9명-2명 키 == 100
                dwarf[i]=-1;
                dwarf[j]=-1;
                return;
            }
        }
    }
}