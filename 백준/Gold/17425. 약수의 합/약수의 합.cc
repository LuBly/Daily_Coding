//[Baekjoon C++] 약수의 합 [누적 합]
#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;

long long dp[MAX];

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j * i < MAX; j++) {
				dp[i * j] += i;
		}
		dp[i] += dp[i - 1];
	}
	int num,x;
	cin >> num;
	for (int i = 1; i <= num; i++) {
		cin >> x;
		cout << dp[x] << '\n';
	}
}