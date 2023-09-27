//[BaekJoon C++] 여행 가자 [UnionFind]
#include <iostream>
#include <vector>
#define MAX 201
using namespace std;

int parent[MAX];
int find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void uni(int x, int y){
    x = find(x);
    y = find(y);

    // 부모노드를 작은쪽으로 정렬
    if(x > y) parent[x] = y;
    else parent[y] = x;
}

bool isSameParent(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return true;
    else return false;
}

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int cityCnt, planCnt;
    cin >> cityCnt >> planCnt;

    vector<vector<int>> board(cityCnt+1, vector<int>(cityCnt+1));
    for(int y = 1; y <= cityCnt; y++){
        for(int x = 1; x <= cityCnt; x++){
            cin >> board[y][x];
        }
    }

    for(int k = 1; k <= cityCnt; k++){
        parent[k] = k;
    }

    for(int y = 1; y <= cityCnt; y++){
        for(int x = y; x <= cityCnt; x++){
            if(board[y][x]) 
                uni(x,y);
        }
    }

    int start;
    cin >> start;

    for(int k = 1; k < planCnt; k++){
        int cmp;
        cin >> cmp;
        if(!isSameParent(start, cmp)){
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}
