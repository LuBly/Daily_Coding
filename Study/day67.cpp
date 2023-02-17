//[BaekJoon C++] 최소 힙 [우선순위 큐]
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<int, vector<int>, greater<>> P_queue;
    int count;
    cin>>count;

    for(int k=0;k<count;k++){
        int num;
        cin>>num;
        if(num!=0) P_queue.push(num);
        else {
            if(!P_queue.empty()){
                cout<<P_queue.top()<<'\n';
                P_queue.pop();
            }
            else{
                cout<<0<<'\n';
            }
        }
    }
}