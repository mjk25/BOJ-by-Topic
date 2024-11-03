#include <iostream>
#include <vector>
#include <algorithm>
# include <cmath>


using namespace std;

// Bubble Sort
// 정렬되지 않은 값 중 최댓값을 맨 뒤로 보내기 반복
// 인접한 두 값을 반복하여 비교 및 교환
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
} 




// Selection Sort
// 정렬되지 않은 값들 중에서 최솟값 찾아 앞에 놓기 반복
// Unstable 함 !!
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}





// Insertion Sort
// 정렬되지 않은 값들 중 하나를 골라서,  이미 정렬된 값들 사이에 끼워넣기 반복

// while문, 마지막에 값을 올바른 위치에 넣는 코드
void insertionSort(vector<int>& arr) {
    int n = arr.size();  // 배열의 크기를 n에 저장
    for (int i = 1; i < n; i++) {  // 두 번째 원소부터 배열 끝까지 반복
        int tmp = arr[i];          // 현재 정렬할 원소를 임시 변수 tmp에 저장
        int j = i - 1;          // 정렬된 부분의 마지막 원소 인덱스

        // tmp보다 큰 원소들을 한 칸씩 뒤로 이동
        while (j >= 0 && arr[j] > tmp) {
            arr[j + 1] = arr[j];  // 현재 원소를 뒤로 한 칸 이동
            j--;                // 인덱스 j를 하나씩 감소하여 이전 원소와 비교
        }
        arr[j + 1] = tmp;  // tmp 값을 올바른 위치에 삽입
    }
}


// 추천 !
// for문 2개, 바로바로 swap하는 버전 코드
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {  // 두 번째 원소부터 시작
        for (int j = i; j > 0; j--) {
            if (arr[j - 1] <= arr[j]) {
                break;  // 앞의 원소가 현재 원소보다 작거나 같으면 정렬 완료
            }
            swap(arr[j - 1], arr[j]);
        }  // 현재 원소가 더 작으면 두 원소를 교체
    }
}





// Merge Sort
// 분할 정복(Divide and Conquer) 정렬 알고리즘  
// Key Idea: 영역을 나눠서 각각 정렬하고 합친다  
// 나뉜 영역을 재귀적으로 정렬
// 배열의 두 부분을 병합하는 함수
void merge(vector<int>& arr, int l, int m, int r) {
    // cout << "merge"<<endl;
    // cout << "l "<<l <<",m "<<m<<" ,r "<<r<<endl;
    // 임시 배열 tmp에 arr의 부분 배열 [l, r) 복사
    vector<int> tmp(arr.begin() + l, arr.begin() + r);
    
    int i = 0, j = m - l, k = l;  // i: 왼쪽 부분, j: 오른쪽 부분, k: 병합할 arr의 인덱스
    
    // 왼쪽과 오른쪽 부분 배열을 비교하여 작은 값부터 arr에 다시 병합
    while (i < m - l && j < r - l) {
        // cout << i<< ":tmp[i] "<< tmp[i]<<" " <<j<<":tmp[j] " << tmp[j]<<endl;
        // cout << "k "<<k <<endl;
        if (tmp[i] < tmp[j]) {
            arr[k] = tmp[i];  // 왼쪽 값이 작으면 arr에 복사
            i += 1;
        } else {
            arr[k] = tmp[j];  // 오른쪽 값이 작거나 같으면 arr에 복사
            j += 1;
        }
        k += 1;  // 인덱스 k 증가
    }
    
    // 왼쪽 부분에 남은 값들을 arr에 복사
    while (i < m - l) {
        // cout<< "왼쪽 남는 ";
        // cout << i<< ":tmp[i] "<< tmp[i] << endl;
        arr[k] = tmp[i];
        i += 1;
        k += 1;
    }
    
    // 오른쪽 부분에 남은 값들을 arr에 복사
    while (j < r - l) {
        // cout<< "오른쪽 남는 ";
        // cout << j<< ":tmp[j] "<< tmp[j] << endl;
        arr[k] = tmp[j];
        j += 1;
        k += 1;
    }
}

// 배열을 분할하여 정렬하는 함수 (Merge Sort)
void _merge_sort(vector<int>& arr, int l, int r) {
    if (l + 1 == r) return;  // 부분 배열이 1개 원소면 더 이상 분할할 필요 없음
    
    int m = (l + r) / 2;  // 중간 인덱스 계산
    // cout << "mergesort "<<endl;
    // cout << "l "<<l <<",m "<<m<<" ,r "<<r<<endl;
    _merge_sort(arr, l, m);  // 왼쪽 절반 재귀적으로 정렬
    _merge_sort(arr, m, r);  // 오른쪽 절반 재귀적으로 정렬
    
    // 정렬된 두 부분을 병합
    merge(arr, l, m, r);
}


void mergeSort(vector<int>& arr) {
    _merge_sort(arr, 0, arr.size());
}






// Quick Sort
// 분할 정복(Divide and Conquer) 정렬 알고리즘  
// Key Idea: Pivot을 기준으로 영역을 나눠서 각각 정렬  
// 나뉜 영역을 재귀적으로 정렬 partition
// 배열을 분할하여 피벗을 기준으로 작은 값과 큰 값으로 나누는 함수

// // while문 사용 : 비추
int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[(left + right) / 2];  // 피벗은 중간값으로 설정
    while (left <= right) {  // 좌측과 우측이 교차할 때까지 반복
        // 피벗보다 작은 값을 찾기 위해 좌측 인덱스를 증가
        while (arr[left] < pivot) left++;
        // 피벗보다 큰 값을 찾기 위해 우측 인덱스를 감소
        while (arr[right] > pivot) right--;
        // left와 right가 교차하지 않은 상태라면 두 값을 교환
        if (left <= right) {
            swap(arr[left], arr[right]);  // 좌측 값과 우측 값을 교환
            left++;  // 좌측 인덱스 증가
            right--;  // 우측 인덱스 감소
        }
    }
    return left;  // 교차된 이후의 좌측 인덱스를 반환
}

// Ver2. for문 사용 : 이걸로 공부!!!!
int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];  // 피벗을 배열의 가장 오른쪽 값으로 설정
    int i = left;  // 작은 값들이 위치할 인덱스
    // cout <<"pivot "<<pivot <<", i "<< i<< endl;

    // left부터 right-1까지 배열을 순회
    for (int j = left; j < right; j++) {  // right를 제외한 범위
        // 현재 값이 피벗보다 작거나 같으면 i 위치에 교환
        if (arr[j] <= pivot) {
            // cout << i<< " : swap "<< arr[i]<<endl;
            // cout << j<< " : swap "<< arr[j]<<endl;
            swap(arr[i], arr[j]);
            i++;  // i를 증가시켜 작은 값의 위치를 이동
        }
    }

    // 마지막으로 피벗을 올바른 위치에 놓음
    swap(arr[i], arr[right]);

    return i;  // 피벗이 위치한 인덱스를 반환
}

// 퀵소트를 수행하는 함수
void quickSort(vector<int>& arr, int left, int right) {
    // cout << "quicksort" <<left << right <<endl;
    if (left < right) {
        int part = partition(arr, left, right);  // 배열을 분할하고 분할 위치를 얻음

        quickSort(arr, left, part - 1);  // 좌측 부분 재귀적으로 정렬
        quickSort(arr, part + 1, right);  // 우측 부분 재귀적으로 정렬
    }
}

// Ver3. 
//피벗 중앙값으로 설정
int partition(vector<int>& arr, int left, int right) {
    int mid = (left + right) / 2;  // 중간값 인덱스를 계산
    int pivot = arr[mid];  // 중간값을 피벗으로 설정

    // 피벗을 배열의 끝으로 이동 (right로 이동시켜 나중에 올바른 위치로 옮김)
    swap(arr[mid], arr[right]);

    int i = left;  // 작은 값들이 위치할 인덱스

    // left부터 right-1까지 배열을 순회
    for (int j = left; j < right; j++) {  // 피벗을 제외한 범위 탐색
        if (arr[j] <= pivot) {  // 피벗보다 작은 값들은 왼쪽으로
            swap(arr[i], arr[j]);
            i++;  // i를 증가시켜 작은 값의 위치를 이동
        }
    }

    // 마지막으로 피벗을 올바른 위치에 놓음
    swap(arr[i], arr[right]);  // 피벗을 제자리에 위치시킴

    return i;  // 피벗이 위치한 인덱스를 반환
}







// Heap Sort
void heapify(vector<int>& arr, int parent, int last) {
    int left, right, largest;
    while (parent * 2 + 1 <= last) {
        left = parent * 2 + 1;
        right = parent * 2 + 2;
        largest = parent;
        if (left <= last && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right <= last && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest != parent) {
            swap(arr[parent], arr[largest]);
            parent = largest;
        } else {
            break;
        }
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, i, n - 1);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i - 1);
    }
}



// Radix Sort
// 값들이 모두 k자릿수 이하의 음이 아닌 정수일때 r진수 (10진수)
// 낮은 자릿수LSD부터 높은 자릿수MSD 순서대로 자릿수를 기준으로 안정 정렬
void stable_sort_by_digit(vector<int>& arr, int k, int r) {
    int n = arr.size();
    vector<int> cnts(r, 0);
    int rtok = pow(r, k);

    for (int x : arr) {
        int digit = (x / rtok) % r;
        cnts[digit]++;
    }

    for (int i = 1; i < r; i++) {
        cnts[i] += cnts[i - 1];
    }

    vector<int> sorted_arr(n);
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / rtok) % r;
        sorted_arr[--cnts[digit]] = arr[i];
    }

    arr = sorted_arr;
}

void radixSort(vector<int>& arr, int k, int r) {
    for (int i = 0; i < k; i++) {
        stable_sort_by_digit(arr, i, r);
    }
}




// Counting Sort
// 값들이 r이하의 음이 아닌 정수일 때
// 각 값의 개수를 세어, 값마다 들어갈 위치를 미리 계산
// 계수 정렬(counting sort) 알고리즘의 개념

// 계수정렬은 숫자들간 비교를 하지 않고 정렬을 하는 알고리즘
// 일일이 비교를 하지 않고 각 숫자가 몇개인지 센 다음에 정렬함
// 배열내 최대 값+1 만큼의 길이만큼의 메모리가 필요함
void countingSort(vector<int>& arr, int maxValue) {
    int n = arr.size();
    vector<int> count(maxValue + 1, 0);
    vector<int> output(n);

    // 각 값의 출현 빈도를 카운트
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // count 배열을 수정하여 각 값이 최종적으로 위치할 인덱스를 계산
    for (int i = 1; i <= maxValue; i++) {
        count[i] += count[i - 1];
    }

    // output 배열에 정렬된 결과 저장
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // 원래 배열에 정렬된 값을 복사
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}




// main

int main() {
    //vector<int> arr = {101, 193, 237, 492, 395, 159};
    vector<int> arr = {4, 3, 9, 8, 7, 2, 5, 6};

    int mx = *max_element(arr.begin(), arr.end());

    //bubbleSort(arr);
    //selectionSort(arr);
    insertionSort(arr);
    //mergeSort(arr);
    //quickSort(arr, 0, arr.size()-1);
    // heapSort(arr);
    //radixSort(arr, 3, 10);
    // countingSort(arr, mx);

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
