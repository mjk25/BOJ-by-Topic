#include <iostream>
#include <stdio.h>
using namespace std;
// 1차 실패코드

int N, Z, M;
int field = 1;
int k=0; // k씩 이동, 가장 작은 k찾기 
int flag =true;

int main(){
    //freopen("input.txt", "r", stdin);
    cin >> N >> Z >> M; //필드, 도착지, 장애물수
    int block[M];
    for (int i=0; i<M; i++){
        cin >> block[i];
    }

    int bigk = Z-1;

    if(M==0){
        cout << 1 << endl;
    }
    else{
        for (int i=1; i<=999; i++){ //작은 k부터 시도
            //cout <<"i " << i<<endl;
            field =1;
            //cout << "flag0 " <<flag <<endl;
            flag=true;
            while (flag==true){ //k만큼씩 field
                field +=i;
                //cout << "field " <<field <<endl;

                for (int j=0; j<M; j++){ //장애물 만나면 종료 후 다음 k
                    if (field%N == block[j]){
                        //cout << "break " << field << " " << block[j] <<endl;
                        flag =false;
                        //cout << "flagggg " <<flag <<endl;
                        break;
                    }
                }
                if (field%N == Z){ //종료 조건1 : 성공 N진법
                    k=i;
                    flag =false;
                }else if (field%N==0 | field>1000){ //종료 조건2 : 목표 도달 실패
                    flag =false;
                    //cout << field <<" out"<<endl;
                }
            }
            if (k == i) //성공
                break;
        }
        cout <<k << endl;
    }
}