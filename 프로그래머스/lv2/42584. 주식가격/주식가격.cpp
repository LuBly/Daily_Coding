#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size);
    stack<int> st;//인덱스 값을 저장하는 스택
    
    for(int k=0;k<size;k++){
        while(!st.empty()&&prices[st.top()]>prices[k]){
            answer[st.top()]=k-st.top();
            st.pop();
        }
        st.push(k);
    }
    while(!st.empty()){
        answer[st.top()]=size-st.top()-1;
        st.pop();
    }
    return answer;
}