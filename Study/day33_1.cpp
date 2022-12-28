//[Programmers C++] 음양 더하기
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    for(int k =0; k<signs.size();k++){
        if(!signs[k]) absolutes[k]*=-1;
        answer+=absolutes[k];
    }
    return answer;
}