//[BaekJoon C++] 집합의 표현 [유니온 파인드]
#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;

int parent[MAX];

int find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void uni(int x, int y){
    x = find(x);
    y = find(y);
    if(x > y) parent[x] = y;
    else parent[y] = x;
}

bool sameParent(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return true;
    else return false;
}


int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    // N : 원소의 갯수 
    // M : 연산의 갯수 
    int N, M;
    cin >> N >> M;

    for(int k = 1; k <= N; k++){
        parent[k] = k;
    }

    for(int k = 0; k < M; k++){
        int type, a, b;
        cin >> type >> a >> b;
        
        // 합집합 = uni
        if(type == 0){
            uni(a,b);
        }

        else if(type == 1){
            if(sameParent(a,b)){
                cout << "YES" <<'\n';
            }       
            else
                cout << "NO" << '\n';
        }
    }
}    