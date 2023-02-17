//[BaekJoon C++] 스택 수열 [스택]
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack<int> st;
    vector<char> answer; 
    int count;
    int st_num=1;
    cin>>count;
    for(int k=0;k<count;k++){
        int num;
        cin>>num;
        while(st_num<=num){
            st.push(st_num);
            st_num++;
            answer.push_back('+');
        }
        if(st.top()==num){
            st.pop();
            answer.push_back('-');
        }
        else{
            cout<<"NO";
            return 0;
        }
    }

    for(auto iter:answer){
        cout<<iter<<'\n';
    }
}