//[Baekjoon C++] 녹색 옷 입은 애가 젤다지? [다익스트라]
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

vector<vector<int>> dijkstra(vector<vector<int>> cave, vector<vector<int>> cost){
    priority_queue<pair<int, pair<int, int>>, 
                vector<pair<int, pair<int, int>>>, 
                greater<pair<int, pair<int, int>>>> pq;

    vector<vector<int>> resCost = cost;
    int caveSize = cave[0].size();
    // 최초 시작 포인트 입력
    pq.push({cave[0][0], {0,0}});
    resCost[0][0] = cave[0][0];
    while(!pq.empty()){
        int curCost             = pq.top().first;
        pair<int, int> curNode  = pq.top().second;
        pq.pop();

        if(curCost > resCost[curNode.first][curNode.second]) continue;

        for(int k = 0 ; k < 4; k++){
            pair<int, int> nextNode = {curNode.first + dy[k], curNode.second + dx[k]};
            // 범위 밖으로 나갈 경우 계산 x
            if(nextNode.first >= caveSize || nextNode.second >= caveSize || nextNode.first < 0 || nextNode.second < 0) continue;
            int nextCost = curCost + cave[nextNode.first][nextNode.second];
            if(nextCost < resCost[nextNode.first][nextNode.second]){
                resCost[nextNode.first][nextNode.second] = nextCost;
                pq.push({nextCost, nextNode});
            }
        }
    }

    return resCost;
}


int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    // 정답 출력을 위한 vector
    vector<int> answer;
    while(true){
        int caveSize;
        cin >> caveSize;

        if(caveSize == 0) break;
        // 도둑루피를 세워둘 cave 정보를 입력해주기 위한 vector
        // 테스트마다 cave의 정보를 다르게 설정해야 하기 떄문에, cave vector를 while문 내부에 배치
        vector<vector<int>> cave(caveSize, vector<int>(caveSize));
        vector<vector<int>> cost(caveSize, vector<int>(caveSize, INF));
        for(int y = 0; y < caveSize; y++){
            for(int x = 0; x < caveSize; x++){
                cin >> cave[y][x];
            }
        }
        vector<vector<int>> res = dijkstra(cave, cost);
        answer.push_back(res[caveSize-1][caveSize-1]);
    }

    for(int k = 0; k < answer.size(); k++){
        cout << "Problem " << k+1 << ": " << answer[k] << '\n';
    }
}