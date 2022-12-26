//[Programmers C++] 영어 끝말잇기
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> tmp;
    int player = 0;
    int count = 0;
    tmp.push_back(words[0]);
    for(int k=1;k<words.size();k++){
        if(words[k-1].back()!=words[k].front()){//끝말잇기 기본 규칙 적용
            player = k%n+1;//걸렸을 때 체크하기 위함
            count = k/n+1;        
            answer.push_back(player);
            answer.push_back(count);
            return answer;
        }
        
        for(int j=0;j<tmp.size();j++){//이전에 들어왔던 단어들과 비교
            if(tmp[j].compare(words[k])==0){//지금 들어온 단어가 이전에 들어왔던 단어라면
                player = k%n+1;//걸렸을 때 체크하기 위함
                count = k/n+1;        
                answer.push_back(player);
                answer.push_back(count);
                return answer;
            }
        }
        
        tmp.push_back(words[k]);
    }
    answer.push_back(player);
    answer.push_back(count);
    return answer;
}