#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<pair<double,double>> map;
    map.push_back({0,k});
    int cnt = 1;
    while(k>1){
        if(k%2==0)
            k/=2;
        else k = k*3+1;
        map.push_back({cnt++,k});
    }
    int limit = map.size();
    vector<double> data(limit,0);
    for(int k=1;k<limit;k++){
        data[k]=data[k-1]+(map[k-1].second+map[k].second)/2;
    }
    
    for(int k=0;k<ranges.size();k++){
        int st = ranges[k][0], dt = limit+ranges[k][1]-1;
        
        if(ranges[k][0]==0&&ranges[k][1]==0)            // 전범위 체크인 경우
            answer.push_back(data[limit-1]);
        else if(st > dt){                               // 시작 점이 끝 점보다 클 경우
            answer.push_back(-1);
        }
        else{                                           // 일반적인 상황
            answer.push_back(data[dt]-data[st]);
        }
    }
    
    return answer;
}