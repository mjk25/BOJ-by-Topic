# Counting Sort
### 수 정렬하기 10989 : Counting Sort

```cpp
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
```

# 수 정렬하기 3

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞힌 사람 | 정답 비율 |
| --- | --- | --- | --- | --- | --- |
| 5 초 ([하단 참고](https://www.acmicpc.net/problem/10989#)) | 8 MB ([하단 참고](https://www.acmicpc.net/problem/10989#)) | 319320 | 76428 | 58311 | 23.840% |

## 문제

N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

## 입력

첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다. 이 수는 10,000보다 작거나 같은 자연수이다.

## 출력

첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.

## 예제 입력 1 복사

```
10
5
2
3
1
4
2
3
5
1
7

```

## 예제 출력 1 복사

```
1
1
2
2
3
3
4
5
5
7
```

### Counting Sort 기본

```cpp
#include <iostream>

#define MAX_SIZE 1000
#define MAX_NUM 10000

using namespace std;

int N;
int origin[MAX_SIZE + 1];
int answer[MAX_SIZE + 1];
int count[MAX_NUM + 1];
int count_sum[MAX_NUM + 1];

int main()
{
    cin >> N;
    for (int i = 0; i <= N; i++)    // 입력받을 수의 범위 0-N까지 가능
        count[i] = 0;
   
    // Counting
    for (int i = 1; i <= N; i++)
    {
        cin >> origin[i];   // 입력받기 인덱스는 1~N번 까지 존재
        count[origin[i]]++; // 숫자 개수 conuting하기
    }
  
    // Counting Sum
    count_sum[0] = count[0];    
    for (int i = 1; i <= MAX_NUM; i++){
        count_sum[i] = count_sum[i - 1] + count[i];
    }

    // Sorting
    for (int i = N; i >= 1; i--)
    {
        // origin[i]] = 원본 숫자
        // count_sum[원본 숫자] = 누적된 합의 값
        answer[count_sum[origin[i]]] = origin[i];
        count_sum[origin[i]]--;
    }

    for (int i = 1; i <= N; i++)
        cout << answer[i] << " ";
}

```