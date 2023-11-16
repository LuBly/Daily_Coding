#include <iostream>
using namespace std;


int n, k;//물품의 갯수, 준서가 버틸 수 있는 무게
int product[101][2];//물건의 무게와 가치 배열 [번호][0=무게, 1=가치]
int dp[101][100001];//알고리즘을 위한 배열 dp[물건번호][무게합]

#define max(a,b) (a>=b)?a:b

void solve() {
	int max_value = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = dp[i-1][j];
			if (product[i - 1][0] <= j) {
				dp[i][j] = max(dp[i][j], product[i - 1][1] + dp[i - 1][j - product[i - 1][0]]);
			}
			max_value = max(max_value, dp[i][j]);
		}
	}
	cout << max_value;

}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> product[i][0] >> product[i][1];
	}
	solve();
}