#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N;
long long arr[500001], arr2[500001], result;

long long func(int start, int end) {
	if (start == end)
		return 0;

	int i, j, idx, mid;
	mid = (start + end) / 2;	i = start;	j = mid + 1;	idx = 0;

	result = func(start, mid) + func(mid + 1, end);

	while (i <= mid || j <= end) {
		if (i <= mid && (j > end || arr[i] <= arr[j]))
			arr2[idx++] = arr[i++];
		else {
			result += (mid - i + 1);
			arr2[idx++] = arr[j++];
		}
	}

	for (int k = start; k <= end; k++)
		arr[k] = arr2[k - start];

	return result;
}

int main(){
    freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >> N;

    for (int i=0; i<N; i++){
        cin >> arr[i];
    }
    int answer = func(0, N-1);
    cout << answer;
}