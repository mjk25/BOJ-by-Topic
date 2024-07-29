#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;
// 자리 수에 0이 오면 처리가 안됨.--

int N, K;
int elem;
int big=0;
int digit=0;
int n, d;
int answer=0;
int flag=0;

int main(){
    freopen("input.txt", "r", stdin);

    cin >> N >> K;
    int set[K];
    for (int i=0; i<K; i++){
        cin >> set[i];
    }

    int num = N;
    while (num > 0){ //자리수 구하기 
        num /= 10;
        digit +=1;
    }

    num = N;
    // 가장 큰 자리수부터 big == n인 경우:
    for (int i=0; i<digit; i++){
        big = 0;
        d = pow(10, (digit-i-1));
        n = num/d;  // 숫자
        num %= d;
        // cout << n << " " << num <<endl;
        for (int j=0; j<K; j++){   // n이하의 최대 값
            // cout << "big "<<big<<endl;
            // cout << "j "<<set[j] <<endl;
            if (big < set[j] && set[j] <= n){
                big = set[j];
                
            }
        }
        
        answer += d*big;
        //cout << "a "<<answer<<endl;
        if (big != n){
            flag =i+1;
            break;
        }
    }
    
    
    // 나머지 자리 수 결정 
    for (int i=flag; i<digit; i++){ // 자리수 별
        d = pow(10,(digit-i-1));

        for (int j=0; j<K; j++){    // 무조건 최대 값
            if (big < set[j]){
                big = set[j];
            }
        }
        answer += d*big;
    }
    cout << answer ;
}