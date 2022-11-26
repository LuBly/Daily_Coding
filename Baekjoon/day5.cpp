#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int>p2) {
	if (p1.first == p2.first) return p1.second < p2.second;
	else return p1.first < p2.first;
}

int main() {

	int count,x,y;
	cin >> count;
	vector<pair<int, int>> matrix;

	for (int i = 0; i < count; i++) {
		scanf("%d %d", &x, &y);
		matrix.push_back({x,y});
	}

	sort(matrix.begin(), matrix.end(),cmp);

	for (int k = 0; k < count; k++) {
		printf("%d %d\n", matrix[k].first, matrix[k].second);
	}


	
}