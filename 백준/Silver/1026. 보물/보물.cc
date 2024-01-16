//[Baekjoon C++] 보물 [그리디]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
결국 최소값을 찾는 문제
A 오름차순
0 1 1 1 6
B 내림차순
8 7 3 2 1

1 1 3
30 20 10 

0 0 3 5 15 26 31 39 100
13 12 11 9 5 4 3 2 1

33 45 75 104 93 78 100
78 179 171 100
257 271
528

*/
int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int numCnt;
    cin >> numCnt;

    vector<int> A(numCnt);
    vector<int> B(numCnt);

    for(int k = 0; k < numCnt; k++){
        cin >> A[k];
    }

    for(int k = 0; k < numCnt; k++){
        cin >> B[k];
    }

    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());

    int answer = 0;
    for(int k = 0; k < numCnt; k++){
        answer += A[k] * B[k];
    }
    cout << answer;
}