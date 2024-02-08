// 백준 2023 DFS

#include <stdio.h>
#include <iostream>

using namespace std;

int n;
int answer;
int num;
int j=1;
void dfs(int num, int j);
bool isPrime(int num);


int main(){
    freopen("input.txt", "r", stdin);
    cin >> n;

    dfs(2,1);
    dfs(3,1);
    dfs(5,1);
    dfs(7,1);
}

void dfs(int num, int j){
    if (j==n){  //종료조건 
        if (isPrime(num)==true)
            cout << num << "\n";
    }

    for(int i=1; i<10; i+=2){   //홀수만 검사
        if (isPrime(num*10+i)==true){
            dfs(num*10+i, j+1);
        }
    }
}

bool isPrime(int num){   //소수 판별 함수: 에라토스테네스의 체
    for(int k=2; k<num/2; k++){
        if (num%k==0){
            //소수 아님
            return false;
        }
    }
    // num이 k로 나눠지지않는 경우 = 소수
    return true;
}