import random



# # bubble sort  Θ(n2)
# # 정렬되지 않은 값 중 최댓값을 맨 뒤로 보내기 반복
# # 인접한 두 값을 반복하여 비교 및 교환
# def bubble_sort(arr):
#     n = len(arr)
#     for a in range(n-1, 0, -1):
#         for i in range(a):
#             if arr[i] > arr[i+1] :
#                 arr[i], arr[i+1] = arr[i+1], arr[i]

 
# # selection sort Θ(n2)
# # 정렬되지 않은 값들 중에서 최솟값 찾아 앞에 놓기 반복
# def selection_sort(arr):
#     n = len(arr)
#     for i in range(n-1) : 
#         min_idx = i
#         min_n = arr[i]
#         for j in range(i+1, n):
#             if arr[j] < min_n :
#                 min_idx = j
#                 min_n = arr[j]
        
#         if min_idx != i :
#             arr[i], arr[min_idx] = arr[min_idx], arr[i]



# # insertion sort Θ(n2)
# # 정렬되지 않은 값들 중 하나를 골라서,  
# # 이미 정렬된 값들 사이에 넣고 뒤는 미루기 반복
# def insertion_sort(arr):
#     n = len(arr)
#     for j in range(n-1):
#         for i in range(n-1):
#             if arr[i] <= arr[i+1]: # 같거나 arr[i]가 더 작으면
#                 break
#             arr[i], arr[i+1] = arr[i+1], arr[i] # 뒤로 미루기




# # merge sort
# # 분할 정복(Divide and Conquer) 정렬 알고리즘  
# # Key Idea: 영역을 나눠서 각각 정렬하고 합친다  
# # 나뉜 영역을 재귀적으로 정렬

# def merge_sort(arr):
#     _merge_sort(arr, 0, len(arr))

# def _merge_sort(arr, l, r):
#     if l + 1 == r: return
#     m = (l + r) // 2
#     _merge_sort(arr, l, m)
#     _merge_sort(arr, m, r)
#     _merge(arr, l, m, r)

# def _merge(arr, l, m, r):
#     tmp = arr[l:r]
#     i, j, k = 0, m-l, l
#     while i < (m-l) and j < (r-l):
#         if tmp[i] < tmp[j]:
#             arr[k] = tmp[i]
#             i += 1; k += 1
#         else:
#             arr[k] = tmp[j]
#             j += 1; k += 1
#     while i < m-l:
#         arr[k] = tmp[i]
#         i += 1; k += 1
#     while j < r-l:
#         arr[k] = tmp[j]
#         j += 1; k += 1

# def merge_sort(arr):
#     # 배열 arr 전체를 정렬하는 함수
#     _merge_sort(arr, 0, len(arr))  # 재귀적 분할 정복 시작

# def _merge_sort(arr, l, r):
#     # 배열의 l부터 r까지 부분을 정렬하는 함수
#     if l + 1 == r: 
#         return  # 배열의 크기가 1이면 정렬할 필요가 없으므로 종료

#     m = (l + r) // 2  # 배열의 중간 인덱스 계산
#     _merge_sort(arr, l, m)  # 왼쪽 절반을 재귀적으로 정렬
#     _merge_sort(arr, m, r)  # 오른쪽 절반을 재귀적으로 정렬
#     _merge(arr, l, m, r)  # 정렬된 두 부분 배열을 병합

# ### 주석 있는 버전
# def _merge(arr, l, m, r):
#     # arr[l:m]과 arr[m:r] 두 정렬된 배열을 병합하는 함수
#     tmp = arr[l:r]  # arr[l:r]의 부분 배열을 복사해 tmp 배열에 저장
#     i, j, k = 0, m - l, l  # i는 왼쪽 배열, j는 오른쪽 배열의 시작점, k는 원래 배열에서의 현재 위치

#     # 두 배열의 값을 비교하면서 더 작은 값을 원래 배열 arr에 채워 넣음
#     while i < (m - l) and j < (r - l):
#         if tmp[i] < tmp[j]:  # 왼쪽 배열의 값이 더 작으면
#             arr[k] = tmp[i]  # 왼쪽 값을 arr에 저장
#             i += 1  # 왼쪽 배열에서 다음 값으로 이동
#         else:  # 오른쪽 배열의 값이 더 작거나 같으면
#             arr[k] = tmp[j]  # 오른쪽 값을 arr에 저장
#             j += 1  # 오른쪽 배열에서 다음 값으로 이동
#         k += 1  # arr에서 다음 위치로 이동

#     # 왼쪽 배열에 남아있는 값들을 arr에 채워 넣음
#     while i < m - l:
#         arr[k] = tmp[i]
#         i += 1
#         k += 1

#     # 오른쪽 배열에 남아있는 값들을 arr에 채워 넣음
#     while j < r - l:
#         arr[k] = tmp[j]
#         j += 1
#         k += 1





# # quick sort
# # 분할 정복(Divide and Conquer) 정렬 알고리즘  
# # Key Idea: Pivot을 기준으로 영역을 나눠서 각각 정렬  
# # 나뉜 영역을 재귀적으로 정렬 partition

def quick_sort(arr):
    quicksort(arr, 0, len(arr) - 1)

def quicksort(arr, l, r):
    if l < r:
        # 배열을 분할한 후 피벗 인덱스를 기준으로 재귀 호출
        p_index = partition(arr, l, r)
        quicksort(arr, l, p_index - 1)  # 왼쪽 부분 정렬
        quicksort(arr, p_index + 1, r)  # 오른쪽 부분 정렬

def partition(arr, l, r):
    # 피벗을 랜덤하게 선택
    pivot_index = random.randint(l, r)
    arr[pivot_index], arr[r] = arr[r], arr[pivot_index]  # 피벗을 마지막으로 이동

    pivot = arr[r]  # 피벗을 마지막 요소로 설정
    i = l - 1  # 피벗보다 작은 값들을 추적하는 인덱스
    print(pivot ,i)
    for j in range(l, r):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]  # 작은 값과 교체
    # 피벗을 작은 값과 큰 값 사이에 위치시킴

    arr[i + 1], arr[r] = arr[r], arr[i + 1]
    return i + 1  # 새로운 피벗 위치 반환








# heap sort

def heap_sort(arr):
    n = len(arr)  # 배열의 길이를 저장

    # 최대 힙을 구성하는 과정
    # 부모 노드는 자식 노드의 인덱스보다 항상 작아야 하므로,
    # 마지막 부모 노드부터 시작하여 힙을 구축
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)  # 현재 인덱스에서 최대 힙을 구성

    # 하나씩 꺼내서 최대 힙을 정렬하는 과정
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # 루트(최대 값)와 마지막 요소를 교환
        heapify(arr, i, 0)  # 교환된 부분을 제외한 나머지 힙을 재구성

def heapify(arr, n, i):
    largest = i  # 현재 노드의 인덱스를 저장
    l = 2 * i + 1  # 왼쪽 자식의 인덱스 계산
    r = 2 * i + 2  # 오른쪽 자식의 인덱스 계산

    # 왼쪽 자식이 현재 노드보다 크면 largest를 왼쪽 자식으로 업데이트
    if l < n and arr[l] > arr[largest]:
        largest = l
    
    # 오른쪽 자식이 현재 largest 값보다 크면 largest를 오른쪽 자식으로 업데이트
    if r < n and arr[r] > arr[largest]:
        largest = r

    # 만약 largest가 현재 노드가 아니라면
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # 현재 노드와 largest를 교환
        heapify(arr, n, largest)  # 교환된 노드에서 다시 힙 구조를 유지




# counting sort
# 값들이 r이하의 음이 아닌 정수일 때
# 각 값의 개수를 세어, 값마다 들어갈 위치를 미리 계산

def counting_sort(arr, r):
    n = len(arr)
    cnts = [0] * (r + 1)

    # 각 요소의 빈도를 계산
    for x in arr:
        cnts[x] += 1

    # 누적합 계산 (인덱스 1부터 시작)
    for i in range(1, r + 1):
        cnts[i] += cnts[i - 1]

    # 정렬된 배열을 만들기 위한 배열
    sorted_arr = [0] * n

    # 뒤에서부터 처리하여 정렬된 배열 채우기
    for x in reversed(arr):
        cnts[x] -= 1
        sorted_arr[cnts[x]] = x

    # 원본 배열에 정렬된 값 복사
    arr[:] = sorted_arr



# radix sort
# 값들이 모두 k자릿수 이하의 음이 아닌 정수일때 r진수 (10진수)
# 낮은 자릿수LSD부터 높은 자릿수MSD 순서대로 자릿수를 기준으로 안정 정렬
def radix_sort(arr, k, r):
    for i in range(k):
        stable_sort_by_digit(arr, i, r)

def stable_sort_by_digit(arr, k, r):
    n = len(arr)
    cnts = [0] * r
    rtok = r ** k  # k번째 자리수를 추출하기 위한 값

    for x in arr:
        digit = (x // rtok) % r  # k번째 자리수 추출
        cnts[digit] += 1

    for i in range(1, r):
        cnts[i] += cnts[i - 1]

    sorted_arr = [0] * n

    for x in reversed(arr):
        digit = (x // rtok) % r  # 다시 자리수 추출
        cnts[digit] -= 1
        sorted_arr[cnts[digit]] = x

    arr[:] = sorted_arr


arr = [101,193,237,492,395,159]
# #arr = [1,3,7,2,5,9]
# counting_sort(arr,500)
# #radix_sort(arr, 3, 10)
quick_sort(arr)
print(arr)







