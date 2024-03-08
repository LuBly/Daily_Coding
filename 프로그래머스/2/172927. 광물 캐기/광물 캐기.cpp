#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <iostream>
using namespace std;
/*
mineral을 돌면서 5개씩 체크 최대 10회 * 종류 3개 30회
1.
d d d i i / d i s
=> dia 1 1 1 1 1 = 5 / 1 1 1 = 3
=> iron 5 5 5 1 1 = 27 / 5 1 1 = 7
=> stone 25 25 25 5 5 = 85 / 25 5 1 = 31
[d 1, i 3, s 2]
d = 5 / i = 7
1. 5개씩 광물 곡괭이별 소모 피로도를 계산

2.1. 무조건 각 파트별 가장 많은 광물 우선 순위로 광물 캐기 X
ex)
d d d d d / i i d d s / d
1 1 1 1 1 / 1 1 1 1 1 / 1
5 5 5 5 5 / 1 1 5 5 1 / 5

if d -> i -> d 인경우
5 + 13 + 1 = 19
d -> d -> i
5 + 5 + 5 = 15
[d 2 i 1]

2.2. 모든 경우의 수 계산
ex)
d -> i -> i
d -> i -> s
d -> s -> i
i -> 
O(3^10)
3. bfs / dfs로 탐색하며 모든 경우의 수 체크
*/
/* [Wrong]
vector<int> pickData;
vector<vector<int>> costs;
int answer = 987654321;

void FindMinimum(int result, int idx){
    for(int k = 0; k < 3; k++){
        if(pickData[k] > 0 && idx < costs[0].size()){
            pickData[k]--;
            FindMinimum(result + costs[k][idx], idx+1);
            pickData[k]++;
        }
    }
    if(idx == 2) answer = min(answer, result);
}

int solution(vector<int> picks, vector<string> minerals) {
    pickData = picks;
    //광물 캐는 소모 피로도 계산
    int costSize = minerals.size() % 5 == 0 ? minerals.size() / 5 : (minerals.size() / 5) + 1;
    costs.resize(3, vector<int>(costSize,0));
    for(int k = 0; k < 3; k++){
        int costIdx = 0;
        for(int j = 0; j < minerals.size(); j++){
            if(j%5 == 0 && j != 0) costIdx++;
            
            //다이아 
            if(k == 0){
                costs[k][costIdx] += 1;
            }
            
            //철
            else if(k == 1){
                if(minerals[j] == "diamond") costs[k][costIdx] += 5;
                else costs[k][costIdx] += 1;
            }
            
            //돌
            else if(k == 2){
                if(minerals[j] == "diamond") costs[k][costIdx] += 25;
                else if(minerals[j] == "iron") costs[k][costIdx] += 5;
                else costs[k][costIdx] += 1;
            }
        }
    } 
    FindMinimum(0, 0);
    
    return answer;
}
*/

//[Answer]출처: https://ljhyunstory.tistory.com/275 [오늘도 열시미!:티스토리]

#include <string>
#include <vector>
#include <map>

#include <iostream>
using namespace std;

map<string, int>MineralList;                //광물들 이름
int AllList[3][3]={{1,1,1},{5,1,1},{25,5,1}}; // 각각 피로도


vector<int>MineralsIntList;

int ListSize=0;
int answer = 1250;

//5 개씩 광물을 캔다....
//곡갱이의 갯수 picks   >> [다이아곡갱이 갯수, 철곡갯수, 돌곡갯수]
// 광물들의 순서 minerals   >> [순서~~~]
// 최소의 피로도는?


// >>> dfs로 찾기 가능?

void dfs(vector<int> &picks, int location,int sum){ // 곡갱이들, 현재 위치
    int sumList[3]={0,}; // 피로도 저장
    int savePoint=0;
    
    if(ListSize<=location || picks[0]+picks[1]+picks[2]==0){// 끝까지가거나 곡갱이다씀
        
        answer=min(answer,sum);
        return;
    }
    
    
    for(int i=location;i<location+5;i++){
        
        if(i>=ListSize){
            savePoint=i;
            break;
        }
        sumList[0]+=AllList[0][MineralsIntList[i]];
        sumList[1]+=AllList[1][MineralsIntList[i]];
        sumList[2]+=AllList[2][MineralsIntList[i]];  // 각각의 곡갱이로 일을한것!
        
        savePoint=i;
    }
    
    
    
    for(int i=0;i<3;i++){//각각 출발
        if(picks[i]!=0){
            picks[i]-=1;
            dfs(picks,savePoint+1,sum+sumList[i]);
            picks[i]+=1;
        }
    }
    
    
}

int solution(vector<int> picks, vector<string> minerals) {
    
    
    MineralList["diamond"]=0; //단어 처리
    MineralList["iron"]=1;
    MineralList["stone"]=2;
    
    ListSize=minerals.size();
    
    //5개씩 나눠야되네!
    //그럼 5개씩 해서 해결피로도 구하면 되는거 아닌감?
    
    
    for(string i : minerals){
        MineralsIntList.push_back(MineralList[i]);
    }
    
    
    
    dfs(picks,0,0);
    
    
    return answer;
}
