#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int n;
vector <int> num;

int partition(vector<int>& arr, int l, int r) {
    int pivot_index = (l + r)/2;
    swap(arr[pivot_index], arr[r]);

    int pivot = arr[r];
    int i = l-1;
    for (int j =l; j < r; j++) {
        if (arr[j] <= pivot) {
            i += 1;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return (i+1);
}

void quicksort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int p_index = partition(arr, l, r);
        quicksort(arr, l, p_index - 1);
        quicksort(arr, p_index + 1, r);
    }
}

int main() {
    freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >> n;
    num.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    quicksort(num, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << num[i] << "\n"; 
    }

    return 0;
}
