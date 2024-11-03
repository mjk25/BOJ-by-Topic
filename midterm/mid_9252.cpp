#include <iostream>
#include <stdio.h>
# include <algorithm>

using namespace std;

string s, t;
int l1, l2;
int table[1001][1001];
string ans = "";

// 최대공통부분 문자열
// tabulation 방식으로 구현 (bottom up)
int main(){
    freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >> s;
    cin >> t;
    
    l1 = s.length();
    l2 = t.length();

    for (int i=1; i<l1+1; i++){
        for (int j=1; j<l2+1; j++){
            if (s[i-1] == t[j-1]){
                table[i][j] = table[i-1][j-1] + 1;
            }else{
                table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
    }
    cout << table[l1][l2]<<endl;


    int i=l1;
    int j=l2;
    while (i>=1 && j>=1){
        if (table[i][j] == table[i - 1][j]) {
            i-=1;
        } else if (table[i][j] == table[i][j - 1]) {
            j-=1;
        }
        else {
            ans += s[i-1];
            i -=1;
            j -=1;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}



