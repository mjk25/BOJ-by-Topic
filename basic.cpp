//기본 문법
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    //입력
    int n;
    int m;
    int s,e;
    cin >> n >> m;


    //1차원 벡터 + size=5 + 2로 초기화
    static vector <int> A(5, 2);
    static vector <int> C(5);   //5개 원소 기본 0으로 초기화
    static vector <int> v1;
    vector<int> v2(A);  //v2는 A를 복사해서 생성됨
    //2차원 벡터 (행의개수, 열의개수, 초기화값)
    static vector <vector<int>> B;
    //벡터 문법  : 
    // v.front(), v.back()
    // v.begin() 첫원소, v.end() 마지막의 다음자리
    A.push_back(1); // push_back은 벡터 끝에 요소 추가함
    A.pop_back();   // pop_back은 맨 뒤(v.back()) 제거
    A.assign(3, 1); // 값 1로 3개의 원소 할당
    A.resize(n, 0); // 크기 n으로 변경후 늘어난 부분 0으로 채움
    B[s].push_back(e);
    B[e].push_back(s);  //필요에 따라 양방향
    
    B.push_back({2,4}); //2차원 배열의 인자 값으로 배열 자체를 넣어줌
    B.emplace_back(6);  //벡터 끝에 값넣음, 메모리 할당 가능

    //pair
    pair <int, int> p;  //기본형
    p=make_pair(1,2);
    //typedef pair 재정의
    typedef pair<int, char> pic;
    vector <pic> vp;   //벡터 안에 넣기
    vector <vector <pic>> vp2;  //2차원 벡터 안에 넣기
    
    vp2[n].push_back(pic(s,e)); //벡터 안에 pair값 넣기

    // 벡터 정렬 
    for (int i = 0; i <= n; ++i) {
		sort(B[i].begin(), B[i].end());
	}
    //배열 
    //리스트

}
