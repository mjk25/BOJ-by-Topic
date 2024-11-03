#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
// LCS 3 : 문자역 3개의 LCS

using namespace std;

string s;
string t;
string u;
int n,m,p;
int table[101][101][101];

int main(){
    freopen("/home/user/cpp_baekjoon/input.txt", "r", stdin);
    cin >> s >> t>> u;
    n = s.length();
    m = t.length();
    p = u.length();


    for (int i=1; i<n+1; i++){
        for (int j=1; j<m+1; j++){
            for (int k=1; k<p+1; k++){
                if ((s[i-1] == t[j-1])&&(t[j-1] == u[k-1])){
                    table[i][j][k] = table[i-1][j-1][k-1] + 1;
                }
                else{
                    table[i][j][k] = max({table[i-1][j][k], table[i][j-1][k], table[i][j][k-1]});
                }

            }
        }
    }

    cout << table[n][m][p];
    
}


