#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool compare(string a, string b){
	return a+b>b+a;
}

int main(void){
    int n;
	int a;
	cin>>n;
	vector <string> v;
	for(int i=0;i<n;i++){
		cin>>a;
		v.push_back(to_string(a));
	}
	sort(v.begin(),v.end(),compare);
	string ans="";
	if(v[0]=="0") {
		cout<<"0";
		return 0;
	}
	for(int i=0;i<v.size();i++){
		ans+=v[i];
	}
	cout<< ans;
	return 0;
}