//[Programmers C++] 뒤에 있는 큰 수 찾기
/*
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(int a=0;a<numbers.size()-1;a++){
        for(int b=a+1;b<numbers.size();b++){
            if(numbers[a]<numbers[b]){
                answer.push_back(numbers[b]);
                break;
            }
            else if(b==numbers.size()-1) answer.push_back(-1);
        }
    }
    answer.push_back(-1);
    return answer;
}
*/// 시간초과

#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    stack<pair<int,int>> st;//숫자, index
    
    for(int a=0;a<numbers.size();a++){
        if(st.empty()||st.top().first>=numbers[a]) st.push(make_pair(numbers[a],a));
        else if(st.top().first<numbers[a]){
            while(!st.empty() && st.top().first<numbers[a]){
                answer[st.top().second]=numbers[a];
                st.pop();
            }
            st.push(make_pair(numbers[a],a));
        }
    }
    while(!st.empty()){
        answer[st.top().second]=-1;
        st.pop();
    }
    return answer;
}
