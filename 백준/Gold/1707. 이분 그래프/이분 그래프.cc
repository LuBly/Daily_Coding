//[BaekJoon C++] 이분 그래프 [그래프 탐색]
#include <iostream>
#include <vector>
#include <queue>
#define MAX 20001
#define RED 1
#define BLUE 2
using namespace std;

/* 이분그래프
// 인접한 정점끼리 서로 다른 색으로 칠해서 모든 정점을 두가지 색으로만 칠할 수 있는 그래프
// 1. BFS, DFS를 통해 노드를 방문할 때마다 두 가지 색 중 하나를 칠한다
// 2. 다음 정점을 방문하면서 자신과 인접한 정점은 자신과 다른 색으로 칠한다
// 3. 탐색을 진행할 때 자신과 인접한 정점의 색이 자신과 동일하면 이분 그래프 X
// 3.1. BFS의 경우 정점을 방문하다가 만약 같은 레벨에서 정점을 다른 색으로 칠해야 한다면 무조건 이분 그래프가 아니다.
// 4. 모든 정점을 다 방문했는데 위와 같은 경우가 없다면 이분 그래프이다.
*/  
vector<vector<int>> board(MAX);// edge 정보를 보관할 board 벡터 선언
vector<int> isVisit(MAX, 0);   // 방문 정보를 저장할 벡터 (Default : 0)

void BFS(int start){    
    int color = RED;
    queue<int> q;

    isVisit[start] = color;
    q.push(start);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if(isVisit[cur] == RED){
            color = BLUE;
        }
        else if(isVisit[cur] == BLUE){
            color = RED;
        }

        for(int k = 0; k < board[cur].size(); k++){
            int next = board[cur][k];
            if(!isVisit[next]){
                isVisit[next] = color;
                q.push(next);
            }
        }
    }
}

// 이분 그래프인지 확인하는 함수
bool isBipartite(int node){
	// 모든 정점들을 돌아보면서 인접한 정점과의 색이 같은지 확인
    for(int cur = 1; cur <= node; cur++){
        for(int i = 0; i < board[cur].size(); i++){
            int next = board[cur][i];
            // 만일 인접한 정점과 색이 같다면 이분 그래프가 아님
            if(isVisit[cur] == isVisit[next])   return false;
        }
    }
    return true;
}

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int testCase;
    cin >> testCase;
    for(int cnt = 0; cnt < testCase; cnt++){
        int node, edge;
        cin >> node >> edge;
        
        // 그래프 정보 저장
        for(int i = 0; i < edge; i++){
            int from, to;
            cin >> from >> to;
            board[from].push_back(to);
            board[to].push_back(from);
        }
        // 판별
        for(int i = 1; i <= node; i++){
            if(!isVisit[i]){
                BFS(i);
            }
        }
        if(isBipartite(node)) cout << "YES" << '\n';
        else cout << "NO" << '\n';

        //TestCase가 여러개이므로 Vector 초기화
        for(int i = 0; i <= node; i++){
            board[i].clear();
            isVisit[i] = 0;
        }
    }
}    