#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, idx;
int cnt[10001] = {};

int main()
{
	freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);

    // 입출력 시간 줄이기 : C 표준 스트림 버퍼와의 동기화를 끊음
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
	
	cin >> n;

	// 반복문 하나에서 입력 받으면서 정렬
	for (int i = 1; i <= n; i++) // n개 입력 받기
	{
		cin >> idx;	
		cnt[idx] += 1;	// counting 
	}

	// 오름차순
	for (int i = 0; i < 6; i++) // i는 max 원본 숫자까지
	{	
		//cnt의 index(i) = 원본 숫자, cnt[i]값이 숫자의 개수
		for (int j = 1; j <= cnt[i]; j++) // 숫자 개수만큼 반복출력
		{
			// 따라서, 작은 수 부터 => 작은 i부터
			// 숫자 개수 만큼 => cnt[i] 값만큼 출력
			cout << i <<"\n"; // 원본 숫자
		} 
	}
}