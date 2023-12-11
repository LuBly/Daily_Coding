#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std; 
int m, n;
int map[500][500]; 
int v[500][500]; 
int dx[4] = { 0,0,-1,1 }; 
int dy[4] = { 1,-1,0,0 }; 
int dp[500][500]; 
int dfs(int y, int x) {
	if (y == m - 1 && x == n - 1) {
		return 1; 
	}
	int& ret = dp[y][x]; 
	if (ret!=-1)return ret; 
	ret = 0; 
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y; 
		int nx = dx[i] + x; 
		if (ny < 0 || ny >= m || nx < 0 || nx >= n)continue; 
		if (map[ny][nx] >= map[y][x])continue; 
		ret += dfs(ny, nx); 
	}
	return ret; 
}
int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0); 
	cin >> m >> n; 
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j]; 
			dp[i][j] = -1; 
		}
	}
	//memset(dp, -1, sizeof(dp)); 
	v[0][0] = 1; 
	cout<<dfs(0,0); 
	return 0; 

}