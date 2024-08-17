// 프로그래머스 국민대 코딩역량인증시험 - 2번 문제

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int water=0;
int side;
vector <pair<int, int>> w;


int solution(vector<int> h) {
    vector<int> m;
    m = h;
    int leng = h.size();
    int num;
    w.resize(leng);
    int dp[leng];
    int num[leng];  //내림차순 정렬 시 원본의 index
    // bool visited[leng] = {false,};
    sort(m.begin(), m.end(), greater<int>());

    num[0] = find(h.begin(), h.end(), m[0]) - h.begin();

    for (int i=0; i<leng-1; i++){
        num[i+1] = find(h.begin(), h.end(), m[i]) - h.begin();
        if (m[i] < m[i+1]){
            int wt = (num[i+1] - num[i])*m[i+1];
            for (int j=num[i]; j<num[i+1]; j++){
                dp[j] = wt;
                //max(wt, dp[j]);
            }
        }else {
            int wt = (num[i] - num[i+1])*m[i+1];
            for (int j=num[i+1]; j<num[i]; j++){
                dp[j] =wt;
                // max(wt, dp[j]);
            }
        }
        if (dp[i]!=0) continue;
    }
    
    for (int i=0; i<leng-1; i++){
        water += dp[i];
    }
    //int answer = find(h.begin(), h.end(), m[0]) - h.begin();
    // //w[0].second;
    return water;
}

// for (int i=0; i<leng; i++){
//         w[i] = {i, h[i]};
//     }
//     sort(m.begin(), m.end(), greater<int>());

//     for (int i=0; i<leng; i++){
//         if (!visited[] )
//         if (w[i].first < w[i+1].first){
//             side = w[i+1].first-w[i].first;
//         }else side = w[i].first-w[i+1].first;

//         water += (w[i+1].second)*side;
//     }