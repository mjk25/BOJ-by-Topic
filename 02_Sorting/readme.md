## 정렬 시간복잡도 
![bigO](img src="https://github.com/user-attachments/assets/2203a1fa-01ee-416e-87b3-a4a17511d8d3")
  
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
