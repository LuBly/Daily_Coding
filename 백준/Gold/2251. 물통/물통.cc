//[Baekjoon C++] 물통 [BFS]
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define MAX 201
using namespace std;

struct Water{
    int a;
    int b;
    int c;
};
bool chk[MAX][MAX][MAX] = {false,};
int A, B, C;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);    
    cin >> A >> B >> C;
    queue<Water> q;
    set<int> res;
    q.push({0,0,C});
    
    while(!q.empty()){
        int curA = q.front().a, curB = q.front().b, curC = q.front().c;
        q.pop();

        if(chk[curA][curB][curC]) continue;
        chk[curA][curB][curC] = true;
        if(curA == 0) res.insert(curC);

        //C->A
        if(curC + curA > A){
            q.push({A, curB, curC + curA - A});
        }
        else{
            q.push({curA + curC, curB, 0});
        }

        //C->B
        if(curC + curB > B){
            q.push({curA, B, curC + curB - B});
        }
        else{
            q.push({curA, curB + curC, 0});
        }

        //B->A
        if(curB + curA > A){
            q.push({A, curB + curA - A, curC});
        }
        else{
            q.push({curB + curA, 0, curC});
        }

        //B->C
        if(curB + curC > C){
            q.push({curA, curB + curC - C, C});
        }
        else{
            q.push({curA, 0, curB + curC});
        }

        //A->B
        if(curA + curB > B){
            q.push({curA + curB - B, B, curC});
        }
        else{
            q.push({0, curA + curB, curC});
        }

        //A->C
        if(curA + curC > C){
            q.push({curA + curC - C, curB, C});
        }
        else{
            q.push({0, curB, curA + curC});
        }
    }
    
    for(auto iter : res){
        cout << iter << " ";
    }
}