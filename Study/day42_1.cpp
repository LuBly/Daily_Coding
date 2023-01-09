//[Programmers C++] 위장
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string,vector<string>> data;
    for(int a=0;a<clothes.size();a++){
        data[clothes[a][1]].push_back(clothes[a][0]);
    }
    
    int tmp =1;
    for(auto iter : data){
        tmp*=iter.second.size()+1;
    }   
    answer+=tmp-1;
    return answer;
}