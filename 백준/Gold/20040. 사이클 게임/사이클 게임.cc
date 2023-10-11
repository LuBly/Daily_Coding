//[Baekjoon C++] 특정 거리의 도시 찾기 [그래프 탐색]
#include <iostream>
#include <vector>
#define MAX 500001
using namespace std;

vector<int> parent(MAX);

int find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void uni(int x, int y){
    x = find(x);
    y = find(y);
    // parent를 작은쪽으로 결합
    if(x > y) parent[x] = y;
    else parent[y] = x;
}

bool isCycle(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return true;
    else return false;
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);    
    // pointCnt : 점의 개수
    // turnCnt  : 진행된 차례의 수 
    int pointCnt, turnCnt;
    cin >> pointCnt >> turnCnt;
    vector<pair<int,int>> data(turnCnt);
    for(int k = 0; k < pointCnt; k++){
        parent[k] = k;
    }
    
    
    for(int k = 0; k < turnCnt; k++){
        cin >> data[k].first >> data[k].second;
    }

    int result = 0;
    for(int k = 0; k < turnCnt; k++){
        int x = data[k].first, y = data[k].second;
        if(isCycle(x,y)){
            result = k+1;
            break;
        }
        uni(x,y);
    }

    cout << result;
    
    return 0;
}