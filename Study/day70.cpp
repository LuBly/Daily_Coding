//[BaekJoon C++] 절대값 힙 [우선순위 큐]
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct cmp{
    bool operator()(int a, int b){
        if(abs(a)!=abs(b)) return abs(a)>abs(b);
        else if(abs(a)==abs(b)) return a>b;
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<int,vector<int>,cmp> queue;
    vector<int> answer;
    int count;
    cin>>count;
    for(int k=0;k<count;k++){
        int num;
        cin>>num;
        if(num==0){
            if(queue.empty()) answer.push_back(0);
            else {
                answer.push_back(queue.top());
                queue.pop();    
            }
        }
        else queue.push(num);
    }

    for(auto iter: answer){
        cout<<iter<<'\n';
    }
}