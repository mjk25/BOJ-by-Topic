## mom을 이용한 파티션 함수 코드2 : 교수님 ppt 기반 코드

```python
# MoM 기반 피벗 선택 후 partition 수행 함수
def partition(arr, l, r):
    pivot = arr[r-1]  # 피벗은 배열의 가장 끝에 있는 값
    i = l
    for j in range(l, r-1):
        if arr[j] <= pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
    arr[i], arr[r-1] = arr[r-1], arr[i]  # 피벗을 제자리에 놓기
    return i  # 피벗의 위치 반환

# 중앙값의 중앙값(Median of Medians)을 선택하는 함수
def median_of_medians(arr, l, r):
    # 배열이 작으면 그냥 정렬 후 중앙값 반환
    if r - l <= 5:
        sublist = arr[l:r]
        sublist.sort()
        return sublist[(r - l) // 2]

    # 5개씩 그룹으로 나누어 각 그룹의 중앙값 구함
    medians = []
    for i in range(l, r, 5):
        sub_r = min(i + 5, r)
        sublist = arr[i:sub_r]
        sublist.sort()
        medians.append(sublist[(sub_r - i) // 2])  # 각 그룹의 중앙값 추가

    # 중앙값들의 중앙값을 재귀적으로 구함
    return median_of_medians(medians, 0, len(medians))

# MoM을 사용하여 i번째 작은 값을 찾는 함수
def mom_select(arr, l, r, i):
    # 배열의 길이가 5로 나누어 떨어지지 않으면 큰 값들을 뒤로 보냄
    while (r - l) % 5 != 0:
        for j in range(l, r-1):
            if arr[j] > arr[r-1]:
                arr[j], arr[r-1] = arr[r-1], arr[j]
        if i == r-1:
            return arr[i]  # 찾으려는 i번째 값이 마지막 값이면 바로 반환
        r -= 1  # 배열의 크기를 줄임

    # MoM으로 피벗 선택
    pivot = median_of_medians(arr, l, r)
    
    # 피벗을 배열의 끝으로 이동
    pivot_index = arr.index(pivot, l, r)
    arr[pivot_index], arr[r-1] = arr[r-1], arr[pivot_index]

    # 피벗을 기준으로 partition 수행
    p = partition(arr, l, r)

    # 피벗 위치가 i번째 값과 같으면 반환
    if p == i:
        return arr[p]
    # i번째 값이 피벗보다 작으면 왼쪽 부분 배열에서 찾기
    elif i < p:
        return mom_select(arr, l, p, i)
    # i번째 값이 피벗보다 크면 오른쪽 부분 배열에서 찾기
    else:
        return mom_select(arr, p + 1, r, i)

# 사용 예시
# arr = [12, 3, 5, 7, 4, 19, 26]
arr = [11, 1, 9, 7, 13, 12, 8, 6, 3, 10]

i = 3  # 3번째로 작은 값 찾기 (0-based index)
result = mom_select(arr, 0, len(arr), i)
print(f"{i+1}번째로 작은 값: {result}")
```