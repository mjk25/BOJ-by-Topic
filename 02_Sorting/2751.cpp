#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// C++ : 1초에 10억번 연산 가능
// 2초, 100만개의 수 
// O(100만**2) = 0이 12개... 10조
// O(100만*log100만/log2) = 100만*19.93 < 2천만
// sort정렬 시간 복잡도 : nlogn
//   => intro sort 방식 = quick sort기반으로 heap sort와 insertion sort 섞은 방식

int N;
int m;


int main()
{
    //freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >> N;
    vector <int> v;

    for (int i=0; i<N; i++){
        cin >> m;
        v.push_back(m);
    }
    sort(v.begin(), v.end());

    for (int i=0; i<N; i++){
        cout << v[i] << "\n";
    }
    
}