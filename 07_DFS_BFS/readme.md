### 배열 초기화  

- 1012 참조  

백준 BOJ는 VScode의 g++과 다르게 c++표준의 strict한 컴파일러여서
VS에서 되던 배열 여러번 초기화가 안됨  

```c++
//백준에서는 불가능  
farm[51][51] = {false,}; 
```  

결론 : 코테를 대비해서 c++의 표준대로 for문 혹은 fill_n , memset 등을 사용하자  
  
---
### 배열 복사
  
- 14502 참조  

```c++
copy(&map_o[0][0], &map_o[0][0]+64, &map_ing[0][0]);
```
  
원본 시작, 원본 끝, 값 넣을 배열의 시작  
  
---
### pair가 들어있는 큐
  
```c++
queue <pair<int,int>> q;
q.push({i,j});
q.front().first;
q.front().second;
q.pop();
```
  
---

