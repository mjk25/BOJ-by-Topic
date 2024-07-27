#include <iostream>
#include <stdio.h>

using namespace std;

int N;
int num=100;
void han();
int hans=0;
int k1, k2, k3, m;

int main(){
    //freopen("input.txt", "r", stdin);
    cin >> N;

    if (N<100){
        hans = N;
    }
    else{
        han();
    }
    cout << hans <<endl;
}

void han(){
    // num 100부터 시작
    hans = 99;
    num =100;
    
    while(num <= N){
        m = num;
    
        k1 = m%10;
        m= m/10;
        k2 = m%10;
        m= m/10;
        k3 = m%10;
        m= m/10;
    
        if ((k3-k2)==(k2-k1)){
            hans+=1;
            //cout << num <<endl;
        }
        num +=1;
    }
    if (N>=1000){
        hans -=1;
    }
    return;
}