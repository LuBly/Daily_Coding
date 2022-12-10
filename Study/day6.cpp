//[백준 c++] 1929 소수 구하기
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int first, last;
	cin >> first >> last;
	vector<bool> isPrime(last + 1, true);
	isPrime[0] = false;
	isPrime[1] = false;

	for (int k = 2; k*k <= last; k++) {
		if (isPrime[k]) {
			for (int j = k * k; j <= last; j+=k) {
				isPrime[j] = false;
			}
		}
	}
	for (int a = first; a <= last; a++) {
		if (isPrime[a]) printf("%d\n",a);
	}
}
