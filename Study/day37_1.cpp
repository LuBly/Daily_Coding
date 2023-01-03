//[Programmers C++] 명예의 전당(1)
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> honor;
    for(int a=0;a<score.size();a++){
        honor.push_back(score[a]);
        sort(honor.begin(),honor.end());
        if(honor.size()<k) answer.push_back(honor[0]);
        else{
            //cout << "im in";
            answer.push_back(honor[honor.size()-k]);
        }
    }
    
    return answer;
}