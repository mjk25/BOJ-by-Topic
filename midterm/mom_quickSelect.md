## mom을 이용한 파티션 함수 코드1

```python
# Quickselect : 배열에서 i번째로 작은 원소를 찾는 재귀 함수 
# MoM : 배열을 다섯 개씩 그룹으로 나눈 뒤, 
# 각 그룹의 중간값을 구하여 다시 그룹을 만들어 그 중간값을 피벗으로 선택

#1. mom을 이용한 파티션 함수
def partition(arr, l, r):
	
    # MoM 기반으로 피벗을 선택하는 함수
	def median_of_medians(arr, l, r):
		
		# 배열이 작은 경우 : 정렬 후 중간값을 반환
		if r - l <= 5:
			sublist = arr[l:r]
			sublist.sort()  # timesort : 평균 nlogn 복잡도
			return sublist[len(sublist) // 2] 
		
        # 5개씩 나누어 각 그룹의 중간값을 찾음
        medians = []
        for i in range(l, r, 5):
            sub_r = min(i + 5, r)
            sublist = arr[i:sub_r]
            sublist.sort()
            medians.append(sublist[len(sublist) // 2])
    
        # 중간값들로 재귀적으로 MoM 호출
        return median_of_medians(medians, 0, len(medians))

    # MoM으로 피벗을 선택
    pivot = median_of_medians(arr, l, r)

    # 피벗의 인덱스를 찾음
    pivot_index = arr.index(pivot, l, r)

    # 피벗을 맨 끝으로 보냄 (partition 알고리즘을 위해)
    arr[pivot_index], arr[r-1] = arr[r-1], arr[pivot_index]

    # 주어진 partition 알고리즘 수행
    p = arr[r-1]
    i = l
    for j in range(l, r-1):
        if arr[j] <= p:
            arr[j], arr[i] = arr[i], arr[j]
            i += 1

    arr[i], arr[r-1] = arr[r-1], arr[i]
    
    return i

def quickselect(arr, l, r, i):
	if l+1==r:
	    return arr[l]
	
    p = partition(arr, l, r)
	
	if p==i:
		return arr[p]
	elif i<p:
		return quickselect(arr, l, p, i)
	else:
		return quickselect(arr, p+1, r, i)

```