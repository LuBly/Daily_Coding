//[Baekjoon C++] 별자리 만들기 [MST]
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 101
using namespace std;

// 프림 알고리즘? 크루스칼?
// 거리 구하기 최대 node 100개
// 100*99/2 = 4950
// Sqrt((y2-y1)^2 + (x2-x1)^2)
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

double distance(pair<double,double> p1, pair<double,double> p2){
    double dist = sqrt(pow(p2.first-p1.first, 2) + pow(p2.second-p1.second, 2));
    return dist;
}


int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int starCnt;
    cin >> starCnt;
    vector<pair<double,double>> starData(starCnt);
    for(int k = 0; k < starCnt; k++){
        cin >> starData[k].first >> starData[k].second;
    }

    vector<pair<double,pair<int,int>>> board; // cost, node번호 a,b
    // 길이를 전부 비교하면서 board에 저장
    for(int a = 0; a < starCnt-1; a++){
        for(int b = a + 1; b < starCnt; b++){
            double dist = distance(starData[a], starData[b]);
            board.push_back({dist, {a,b}});
        }
    }

    sort(board.begin(), board.end());
    
    for(int k = 1; k <= starCnt; k++){
        parent[k] = k;
    }

    double result = 0;
    for(int k = 0; k < board.size(); k++){
        if(!sameParent(board[k].second.first, board[k].second.second)){
            uni(board[k].second.first, board[k].second.second);
            result += board[k].first;
        }
    }

    //결과 값 소숫점 자리 2자리 숫자까지
    printf("%.2f",result);

}