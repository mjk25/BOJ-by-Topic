## 정렬 시간복잡도 
<img src="https://github.com/user-attachments/assets/2203a1fa-01ee-416e-87b3-a4a17511d8d3">
  
### 구조체 vector 생성
- 10825 참조  

'''c++
struct AAA { 
  string name;
  int a, b, c;
}
  
vector<AAA> v(5);
'''  
  
### sort와 compare 함수
- 10825 참조  
오름차순 <, 내림차순 >  

'''c++
bool compare(x, y){
  if ...
  return x > y;
}
sort(a, b, compare);
'''  

### vector 중복 값 제거
- 18870 참조
1. 벡터를 `sort` 한다.
2. `unique` 함수를 통해 중복된 값들을 벡터의 뒷부분으로 보낸다.
3. `erase` 함수를 통해 중복된 값을 제거한다.  

'''
sort(p.begin(), p.end());
p.erase(unique(p.begin(), p.end()), p.end());
'''  

### lower_bound 함수
- 18870 참조  

이진탐색기반.
정렬된 원소에 이진 탐색을 적용하여, 특정 값 이상이 처음 나타나는 위치를 탐색하여 위치를 반환한다. 반대로, upper_bound도 가능.  

반환형은 iterator이므로 index를 구하기위해서는 
lowet_bound 값에서 배열 첫번째 주소를 가리키는 배열의 이름을 빼주어야 한다.  

'''
lower_bound(p.begin(), p.end(), p2[i]) - p.begin() 
'''
