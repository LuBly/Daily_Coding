//[BaekJoon C++] 최대 힙 [우선순위 큐]
#include <iostream>
#include <queue>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<int> P_queue;
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