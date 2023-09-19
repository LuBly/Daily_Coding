//[Baekjoon C++] 최소 스패닝 트리 [MST]
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;

// MST 
// 크루스칼 알고리즘 - 간선 선택
// 간선이 적은 그래프를 MST로 만들 때 적합함
// 사이클 검사가 필요하다 (간선을 선택하므로 트리가 여러개 생길 수 있음, 사이클이 생기지 않도록 선택해야한다.)
// 1. 가중치 순서대로 간선들을 오름차순 정렬한다.
// 2. 오름차순 정렬된 간선들을 차례대로 살펴보며 두 정점이 아직 연결되어 있지않은, 즉 사이클을 형성하지 않는 간선이면 선택
// 2.1. 정점들의 부모가 같다면(같은 그룹이라 서로 통행이 가능하다면) 사이클이 형성되는 것이고
// 2.1. 부모가 같지 않다면 사이클이 형성 X
// 3. 선택한 간선을 MST 집합에 Union 시킨다.
// 2~3과정을 선택한 간선의 개수가 n-1개가 될 때까지 반복

// 프림 알고리즘 - 정점 선택
// 간선이 많은 그래프를 MST로 만들 때 적합
// 시작 정점을 정해두고 시작한다.
// 사이클 검사가 필요하지 않다.
// (인접한 정점들 중에서 선택해 나가므로 트리는 시작정점에서 발생했던 단 하나의 트리만 유지되며 
//  정점들을 선택해 나감으로써 트리를 확장해나가는 식이다. 따라서 이 과정에서는 사이클이 생길일이 없다.)

// [Node]의 parent가 무엇인지 저장할 배열
int parent[MAX];
int find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void uni(int x, int y){
    x = find(x);
    y = find(y);
    parent[y] = x;
}

bool sameParent(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return true;
    else return false;
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    // V : 정점의 개수
    // E : 간선의 개수
    int V, E;
    cin >> V >> E;
    int result = 0;

    vector<pair<int,pair<int,int>>> board;
    for(int k = 0; k < E; k++){
        int from, to, cost;
        cin >> from >> to >> cost;
        board.push_back({cost,{from,to}});
    }
    // board의 cost를 오름차순으로 정렬
    sort(board.begin(),board.end());
    
    // parent 초기화.
    for(int k = 1; k <= V; k++){
        parent[k] = k;
    }

    for(int k = 0; k < E; k++){
        // 같은 부모가 아니라면(사이클이 아니라면 uni-find를 통해 노드들을 묶어준다.)
        if(!sameParent(board[k].second.first, board[k].second.second)){
            uni(board[k].second.first, board[k].second.second);
            result += board[k].first;
        }
    }

    cout << result;
}