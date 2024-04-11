#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
그 인덱스를 제외한 양 옆으로 2 등분하여 최솟값만 남겨서
그 풍선이 두 풍선의 최솟값보다 큰지 판단한다.
*/
int solution(vector<int> a) {
    int answer = 0;
    
    // left 2 right 최소값 배열
    vector<int> left2Right(a.size());
    // right 2 left 최소값 배열
    vector<int> right2Left(a.size());
    
    // left 2 right 계산
    left2Right[0] = a[0];
    for(int k = 1; k < a.size(); k++){
        left2Right[k] = min(left2Right[k-1], a[k]);
    }
    
    // right 2 left 계산
    right2Left.back() = a.back();
    for(int k = a.size()-2; k >= 0; k--){
        right2Left[k] = min(right2Left[k+1], a[k]);
    }
    
    for(int k = 0; k < a.size(); k++){
        if(a[k] <= left2Right[k] || a[k] <= right2Left[k]) answer++;
    }
    
    return answer;
}