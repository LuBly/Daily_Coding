#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#define INF 987654321
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    // 보석 이름과 수를 계산하기 위해 사용
    // 정렬은 필요X
    unordered_map<string, int> gemData; 
    for(int k = 0; k < gems.size(); k++){
        gemData[gems[k]]++;
    }
    
    // 결과 저장 및 계산을 위한 변수들
    // st     : 시작점
    // dt     : 끝 점
    // dist   : 구간 길이(최소 길이를 계산하고자함)
    // curCnt : 현재 보석의 종류 갯수 
    // gemCnt : 모든 보석의 종류 갯수
    
    // if(curCnt < gemCnt)
    // dt를 뒤로 
    // if(curCnt == gemCnt)
    // st를 뒤로 
    // 
    int i;
    int st = 0, dt = 0, dist = INF, gemCnt = gemData.size();
    // 구간 체크를 위한 데이터map
    unordered_map<string, int> chkData;
    
    while(true){
        // end 포인터 업데이트
        for(i = dt; i < gems.size(); i++){
            chkData[gems[i]]++;
            if(chkData.size() == gemCnt){
                dt = i;
                break;
            }
        }
        
        // end 포인터가 업데이트되지 않았다면 종료
        if(i == gems.size()) break;
        
        // start포인터 업데이트
        for(i = st; i < gems.size(); i++){
            if(chkData[gems[i]] == 1){
                st = i;
                break;
            }
            else chkData[gems[i]]--;
        }
    
        if(dt - st < dist){
            answer[0] = st + 1;
            answer[1] = dt + 1;
            dist = dt - st;
        }
        
        chkData.erase(gems[st]);
        st++;
        dt++;
    }
    
    
    return answer;
}