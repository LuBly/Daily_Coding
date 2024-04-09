#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int curTime = 0;
    int endTime = attacks.back()[0];
    
    
    map<int,int> atkMap; // 시간, 데미지
    
    int curHealth = health;
    int activeTime = bandage[0];
    int healPerSec = bandage[1];
    int healPerActive = bandage[2];
    
    for(int k = 0; k < attacks.size(); k++){
        atkMap[attacks[k][0]] = attacks[k][1];
    }
    int cont = 0;
    while(curTime <= endTime){
        // 공격이 있다면
        if(atkMap[curTime]){
            // 데미지 적용
            curHealth -= atkMap[curTime];
            if(curHealth <= 0) return -1;
            // 연속힐 초기화
            cont = 0;
            curTime ++;
            continue;
        }
        // 공격이 없다면
        cont++;
        curHealth += healPerSec;
        if(curHealth > health) curHealth = health;
        if(cont == activeTime){
            curHealth += healPerActive;
            if(curHealth > health) curHealth = health;
            cont = 0;
        }
        curTime++;
    }
    
    answer = curHealth;
    return answer;
}