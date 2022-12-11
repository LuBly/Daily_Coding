//[Programmers C++] 최솟값 만들기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(),A.end());
    sort(B.rbegin(),B.rend());
    
    for(int k = 0; k<A.size(); k++){
        answer += A[k]*B[k];
    }

    return answer;
}
