#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first<b.first;
}

int solution(vector<int> priorities, int location) {
    int answer = 1;
    vector<pair<int,int>> data;//priority , idx 를 저장하는 vector
    for(int k=0;k<priorities.size();k++){
        data.push_back(make_pair(priorities[k],k));//값과 idx를 저장
    }
    //최대값인지 체크하고 아니면 맨 앞 원소 지우고(idx만 ++해주는 방법도 괜찮아보임) 맨뒤로 push
    auto max = *max_element(data.begin(),data.end(),cmp);//최초 max값
    int idx=0;
    
    while(true){
        if(data[idx].first==max.first){//지금 체크하는 값이 최대값일 경우
            if(data[idx].second==location) break;
            else {
                //data.erase(data.begin()+idx);
                max=*max_element(data.begin()+(++idx),data.end(),cmp);
                answer++;
            }
        }
        else{
            data.push_back(data[idx++]);//최대값이 아닐경우 맨뒤로 하나씩 넣으면서 idx++
        }
    }
    
    
    return answer;
}