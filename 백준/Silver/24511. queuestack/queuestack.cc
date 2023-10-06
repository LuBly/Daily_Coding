//[Baekjoon C++] queuestack [큐/스택]
#include <iostream>
#include <vector>
#include <deque>
using namespace std;


int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int cnt;
    cin >> cnt;
    
    vector<int> type(cnt); // 수열 A : 자료구조의 종류를 나타낸다.
    
    // 0 : queue(FIFO), 1 : stack(FILO)
    for(int k = 0; k < cnt; k++){
        cin >> type[k];
    }

    deque<int> dq;
    for(int k = 0; k < cnt; k++){
        int num;
        cin >> num;
        if(!type[k]){//type 이 queue인 경우만 dq에 입력
            dq.push_back(num);
        }
    }

    int numCnt;
    cin >> numCnt;
    for(int k = 0; k < numCnt; k++){
        int num;
        cin >> num;
        dq.push_front(num);
        cout<<dq.back()<<" ";
        dq.pop_back();
    }
}