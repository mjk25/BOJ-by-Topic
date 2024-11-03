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



/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void counting_sort(vector<int>& v) {
	int max_v = *max_element(v.begin(), v.end()); // 입력 배열의 원소들의 최대 값을 산출한다. 
	vector<int> count(max_v+1,0);// 최대값을 통하여 카운팅 배열을 만든다.
	for (int i = 0; i < v.size(); i++) { 
		count[v[i]]++; //카운팅 배열을 입력 배열의 원소의 갯수를 구한다.
	}
	for (int i = 1; i < count.size(); i++) { 
		count[i] =  count[i]+count[i - 1] ; //카운팅 배열의 누적합을 구한다.
	}
	vector<int> sorted_v(v.size(),0);
	for (int i =0; i< sorted_v.size(); ++i) {
		sorted_v[count[v[i]]-1] = v[i]; //누적 합(카운팅 배열)통해 정렬하기 위한 입력 배열의 인덱싱을 구하여 새롭게 정렬할 배열에 저장한다. 
		count[v[i]]--; // 입력 배열이 접근한 누적합(카운팅 배열)의 카운팅 개수를 뺀다.
	}
	v = sorted_v;
}
int main()
{
	vector<int> v = { 10,412,345,100,23,149,23 };
	counting_sort(v);
	for (auto& e : v) {
		cout << e << endl;
	}
	return 0;
}
*/