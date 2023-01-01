//[Programmers C++] 실패율
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool compare(const pair<float, int> &a, const pair<float, int> &b)
{
    if (a.first == b.first) // first 값이 같다면?
    {
        return a.second < b.second; //second 값 오름차순
    }
    return a.first > b.first; // first 값 내림차순
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<float,int>> fail_Rate;
    float stage_Size = stages.size();
    for(int k=1;k<=N;k++){
        float count=0;
        for(int j=0;j<stages.size();j++){
            if(stages[j]==k) {
                count++;
                stages[j]=N+1;
            }
        }
        if(stage_Size<=0) {
            fail_Rate.push_back(make_pair(0,k));
            continue;
        }
        fail_Rate.push_back(make_pair(count/stage_Size,k));
        stage_Size-=count;
    }
    sort(fail_Rate.begin(),fail_Rate.end(),compare);
    for(int p=0;p<fail_Rate.size();p++){
        answer.push_back(fail_Rate[p].second);
        //cout <<"rate: "<< fail_Rate[p].first<<" k: "<<fail_Rate[p].second<< endl;
    }
    
    return answer;
}