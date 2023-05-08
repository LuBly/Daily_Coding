#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int ratio[3] = { 2, 4, 3 };
int divider[3] = { 1, 3, 2 };

long long solution(vector<int> weights) {
    long long answer = 0;
    //완전 탐색X 
    //횟수를 줄인다고 쳐도 50,000,000,000 회 정도의 반복이 수행된다.
    //중복없이 모든 두 쌍을 확인하는 방법?
    //정렬? 100 100 180 270 360
    // 100 100, 100 180 x, 100 270 x, 100 360
    // LW*r == RW*l(왼쪽 무게 * 오른쪽 길이, 오른쪽 무게 * 왼쪽 길이) 
    // 1. 단순 완전 탐색으로 구현(시간 초과 날 것 같긴 함)
    // 계산량이 많아 시간초과 발생 10 11 13 14 15
    // 2. weights map을 선언하고 1중 for문으로 각 weight들이 가질 수 있는 무게들을 저장
    // ex 100 -> 200 300 400
    // ex 180 -> 360 540 720
    // ex 360 -> 720 1080 ##
    // ex 100 -> 중복 제거 answer++
    // ex 270 -> 540 810 1080
    // ex 540 -> 1080 
    // 중복, 540(2C2=1) 720(2C2=1) 1080(3C2 = (3*2/2) = 3{360 270//270 540//360 540})  4개
    map<int, int> weight2cnt;
    set<int> weightSet;
    for (int weight : weights)
    {
        weightSet.insert(weight);
        weight2cnt[weight]++;
    }
    
    for (int weight : weightSet)
    {
        long long weightSize = weight2cnt[weight];
        answer += (weightSize * (weightSize - 1)) / 2;
        
        for (int i = 0; i < 3; i++)
        {
            if (weight % divider[i])
            {
                continue;
            }
            
            int calculatedWeight = (weight / divider[i]) * ratio[i];
            long long size = weight2cnt[calculatedWeight];
            answer += weightSize * size * 1LL;
        }
    }
    
    /*
    for(int k=0;k<weights.size()-1;k++){
        for(int j=k+1;j<weights.size();j++){
            int LW = weights[k], RW = weights[j];
            bool is_answer = false;
            for(int l=2;l<=4;l++){
                for(int r=2;r<=4;r++){
                    if(LW*r==RW*l){
                        answer++;
                        is_answer=true;
                        break;
                    }
                }
                if(is_answer) break;
            }
        }
    }
    */
    return answer;
}