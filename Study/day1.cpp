//[백준 c++] 2908 상수
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
int main() {
	using namespace std;
	char a[4] = {NULL};
	char b[4] = {NULL};
	char tempA;
	char tempB;

	scanf("%s %s", &a, &b);
	
	tempA = a[2];
	a[2] = a[0];
	a[0] = tempA;

	tempB = b[2];
	b[2] = b[0];
	b[0] = tempB;

	int outA = stoi(a);
	int outB = stoi(b);

	int result = max(outA, outB);

	printf("%d", result);
	return 0;
}
