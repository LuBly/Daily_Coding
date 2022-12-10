//[백준 c++] 10757 큰 수 A+B
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string inputA, inputB;
	int tmp, cur=0;
	vector<int> a;
	vector<int> b;
	vector<int> result;

	int max_Size;
	cin >> inputA >> inputB;
		
	max_Size = inputA.size()>inputB.size() ? inputA.size() : inputB.size();
	
	for (int i = 0; i < inputA.size(); i++) {
		a.push_back(inputA[i] - '0');
	}
	for (int j = 0; j < inputB.size(); j++) {
		b.push_back(inputB[j] - '0');
	}

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	for (int k = 0; k < max_Size; k++) {
		if (a.size() <= k + 1) a.push_back(0);
		if (b.size() <= k + 1) b.push_back(0);
		tmp = a[k] + b[k] + cur;
		if (tmp > 9) {
			cur = 1;
			result.push_back(tmp % 10);
		}
		else {
			cur = 0;
			result.push_back(tmp);
		}
	}
	if (cur == 1) result.push_back(1);
	reverse(result.begin(), result.end());
	
	for (int p = 0; p < result.size(); p++) {
		cout << result[p];
	}
	
	return 0;
}
