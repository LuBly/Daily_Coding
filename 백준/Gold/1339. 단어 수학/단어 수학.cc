#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
int n;
int a[26];
bool cmp(int a, int b){
	return a > b;
}
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		int v = 1;
		for(int j=s.size()-1; j>=0; j--){
			a[s[j] - 'A'] += v;
			v *= 10;
		}
	}
	sort(a, a+26, cmp);
	int num = 9;
	int ret = 0;
	for(int i=0; i<26; i++){
		if(a[i] == 0) break;
		ret += a[i] * num--;
	}
	cout << ret;
	return 0;
}