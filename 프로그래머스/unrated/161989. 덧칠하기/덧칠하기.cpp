#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    while(section.size()>0){//section에 남은 값이 없을때 까지 계속해서 반복을 수행
        int cur=section[0];
        int limit=cur+m-1;
        int idx=0;//erase를 활용하기 위해 section을 순회하면서 limit보다 작다는 조건을 만족할 경우 idx를 하나씩 증가시킴 
        
        for(int k=0;k<section.size();k++){//section 벡터를 순회하면서 limit 값보다 작은 부분을 삭제
            if(section[k]<=limit)     
                idx++;
        }
        section.erase(section.begin(),section.begin()+idx);//시작부터 증가된 idx까지 section을 erase하는 작업 수행
        //한번 붓질을 통해 칠할 수 있는 벽면을 section에서 삭제함
        answer++;
    }
    
    return answer;
}
