#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> order;//player의 이름을 통해 order을 찾는 map
    map<int, string> name;//player의 order를 통해 이름을 찾는 map
    for(int k=0;k<players.size();k++){
        order[players[k]]=k;
        name[k]=players[k];
    }
    for(int k=0;k<callings.size();k++){
        string cur_player = callings[k];
        int no = order[cur_player];//no에는 현재 불린 선수의 등수 저장
        string swap_player = name[no-1];
        
        name[no-1]=cur_player; name[no]=swap_player; //name map에서 각 번호에 해당하는 선수 swap
        order[cur_player]--; order[swap_player]++; // order map에서 각 선수에 해당하는 번호 변경
    }
    for(auto iter:name){
        answer.push_back(iter.second);
    }
    return answer;
}