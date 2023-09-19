#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX 101
using namespace std;

// costs[a][0] = from, costs[a][1] = to, costs[a][2] = cost
// cost를 오름차순으로 정렬
// 크루스칼 알고리즘을 활용하여 사이클을 구성하지않는 노드들을 찾는다.
// cost가 낮은 간선들을 우선적으로 채택
// 사이클이 생기지 않으면 간선 채택, 생기면 무시

// 노드들의 부모노드를 저장할 배열
int parent[MAX];

// 최 정상의 부모노드를 찾음
int find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

// 두 노드를 하나의 부모로 묶는다.
void uni(int x, int y){
    x = find(x);
    y = find(y);
    parent[y] = x;
}

bool sameParent(int x, int y){
    x = find(x);
    y = find(y);
    return x == y; // 같으면 true, 다르면 false
}

bool cmp(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), cmp);
    
    for(int k = 0; k < n; k++)
        parent[k] = k;
    
    for(int k = 0; k < costs.size(); k++){
        //같은 부모노드를 가지고 있는게 아니라면(사이클 X)
        if(!sameParent(costs[k][0], costs[k][1])){
            uni(costs[k][0], costs[k][1]);
            answer += costs[k][2];
        }
    }
    
    return answer;
}