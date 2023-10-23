//[Baekjoon C++] 잃어버린 괄호 [그리디]
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

/*
송도에 사는 상근이와 친구들은 송도에서 열리는 펜타포트 락 페스티벌에 가려고 한다. 
올해는 맥주를 마시면서 걸어가기로 했다. 출발은 상근이네 집에서 하고, 맥주 한 박스를 들고 출발한다. 
맥주 한 박스에는 맥주가 20개 들어있다. 목이 마르면 안되기 때문에 50미터에 한 병씩 마시려고 한다. 
즉, 50미터를 가려면 그 직전에 맥주 한 병을 마셔야 한다.

상근이의 집에서 페스티벌이 열리는 곳은 매우 먼 거리이다. 
따라서, 맥주를 더 구매해야 할 수도 있다. 

미리 인터넷으로 조사를 해보니 다행히도 맥주를 파는 편의점이 있다. 
편의점에 들렸을 때, 빈 병은 버리고 새 맥주 병을 살 수 있다. 
하지만, 박스에 들어있는 맥주는 20병을 넘을 수 없다. 
편의점을 나선 직후에도 50미터를 가기 전에 맥주 한 병을 마셔야 한다.

편의점, 상근이네 집, 펜타포트 락 페스티벌의 좌표가 주어진다. 
상근이와 친구들이 행복하게 페스티벌에 도착할 수 있는지 구하는 프로그램을 작성하시오.
*/

// 특이사항
// board의 범위가 -32768 < x, y < 32767
// -> 0 0 ~ RANGE*2 RANGE*2
// 시작 좌표 += RANGE
// 범위 의미 X

// 시작 -> sto1 -> sto2 -> dt
// bfs => 시작 포인트 -> nextNode 
// 

bool BFS(pair<int,int> start, pair<int,int> dest, vector<pair<int,int>> store){
    int storeCnt = store.size();
    vector<bool> isVisit(storeCnt, false);
    // 좌표
    queue<pair<int,int>> q;
    q.push(start);

    while(!q.empty()){
        pair<int,int> curNode = q.front();
        q.pop();

        if((abs(dest.first - curNode.first) + abs(dest.second - curNode.second)) <= 1000) return true;

        for(int k = 0; k < storeCnt; k++){
            pair<int,int> nextNode = store[k];
            int cost = abs(curNode.first - nextNode.first) + abs(curNode.second - nextNode.second);
            if(isVisit[k]) continue;

            if(cost <= 1000){
                isVisit[k] = true;
                q.push({nextNode});
            }
        }
    }

    return false;
}


int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int testCaseCnt;
    cin >> testCaseCnt;

    for(int k = 0; k < testCaseCnt; k++){
        int storeCnt;
        cin >> storeCnt;
        
        pair<int,int> start, dest;
        cin >> start.first >> start.second;
        vector<pair<int,int>> store;
        for(int j = 0 ; j < storeCnt; j++){
            int x, y;
            cin >> x >> y;
            store.push_back({x,y});
        }
        cin >> dest.first >> dest.second;

        if(BFS(start, dest, store)) cout << "happy\n";
        else cout << "sad\n";
    }
}