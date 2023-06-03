#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//dfs를 돌면서 is_visit chk//N의 크기가 너무 크다. O(N)만 해도 2억
// 수학적으로 접근?
// 1. 전체 길이 N
// 2. 하나의 안테나가 관리할 수 있는 범위 2*w+1 
// 3. 빈 구간에 필요한 안테나의 개수 계산
// -> ex1) 4에 안테나 ->1~2까지 총 길이 2/3 = 0.6 올림 -> 1개
// -> ex1) 6~9까지 총 길이 4/3 = 1.3 올림 -> 2개

// -> ex2) 1~6까지 총 길이 6/5 = 1.2 올림 -> 2개
// -> ex2) 12~16까지 총 길이 5/5 = 1 -> 1개

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    vector<float> invalid;
    float start = 1, end = n;
    float div = 2*(float)w+1;
    if((stations[0]-w) > 1){//맨 처음 방문하는 기지국
        invalid.push_back(stations[0]-w-start);
    }
    for(int k=1;k<stations.size();k++){
        if((stations[k-1]+w) < (stations[k]-w)){//두 기지국의 범위가 겹치지 않는 경우
            float length = (stations[k]-w) - (stations[k-1]+w) - 1;
            invalid.push_back(length);
        }
    }
    if((stations.back()+w) < n){
        invalid.push_back(n-(stations.back()+w));
    }
    
    for(auto iter : invalid){
        answer+=ceil(iter/div);
    }
    
    
    return answer;
}