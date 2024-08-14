### i와 i+1이 겹치면 안될때  

- 1149 참조  

'''
color[i][0]+=min(color[i-1][1],color[i-1][2]);
color[i][1]+=min(color[i-1][0],color[i-1][2]);
color[i][2]+=min(color[i-1][0],color[i-1][1]);
'''  

i-1과 i, i와 i+1이 겹치면 안되고 최소값을 구하고 싶을때 사용  

for문 돌리면 값이 축적되어서 마지막 color[n] 3개의 최소값 구하면,
i가 1부터 n까지 이웃끼리 색이 겹치지않게 최소 비용을 구할 수 있음