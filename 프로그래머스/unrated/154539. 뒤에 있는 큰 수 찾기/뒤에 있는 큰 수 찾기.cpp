#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(),-1);
    stack<pair<int,int>> st;//idx, num
    for(int k=0;k<numbers.size();k++){
        int cur = numbers[k];
        //stack이 차있고, stack의 top에 있는 숫자가 지금 들어온 숫자보다 작으면 지금 들어온 숫자가 answer의 idx를 대체
        while(!st.empty()){
            if(st.top().second < cur){
                int idx = st.top().first;
                answer[idx]=numbers[k];
                st.pop();    
            }
            else break;
        }
        st.push(make_pair(k,cur));
    }
    
    return answer;
}