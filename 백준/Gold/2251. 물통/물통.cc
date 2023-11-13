//[Baekjoon C++] 물통 [BFS]
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
using namespace std;
int chk[201][201][201] = {0,};
int A, B, C;
set<int> res;
queue<tuple<int,int,int>> q;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> A >> B >> C;
    q.push({0,0,C});
    while(!q.empty()){
        tuple<int,int,int> cur = q.front();
        int a = get<0>(cur), b = get<1>(cur), c = get<2>(cur);
        q.pop();
        if(chk[a][b][c]) continue;
        chk[a][b][c] = 1;

        if(a == 0) res.insert(c);

        //a to b
		if(a+b>B) q.push({a+b-B,B,c});
		else q.push({0,a+b,c});
		//a to c
		if(a+c>C) q.push({a+c-C,b,C});
		else q.push({0,b,a+c});
		//b to a
		if(b+a>A) q.push({A,b+a-A,c});
		else q.push({b+a,0,c});
		//b to c
		if(b+c>C) q.push({a,b+c-C,C});
		else q.push({a,0,b+c});
		//c to a
		if(c+a>A) q.push({A,b,c+a-A});
		else q.push({c+a,b,0});
		//c to b
		if(c+b>B) q.push({a,B,c+b-B});
		else q.push({a,c+b,0});
    }

    for(auto iter : res){
        cout << iter << " ";
    }
    // 0 0 C
    /*
    ans : 10, 1, 9, 8
    
    경우의 수
    // 끝나는 조건을 어떻게 하지?
    c -> a 0
    a -> c 1

    c -> b 2
    b -> c 3

    a -> b 4
    b -> a 5

    
    c -> a
    - c -> b
    - a -> b
    - b -> a
    - b -> c

    
    
    8 9 10

    0 0 10
    8 0 2
    0 8 2
    0 0 10

    0 0 10
    0 9 1
    8 1 1
    0 1 9
    /////
    0 9 1
    8 1 1

    묶어서
    a -> b 면 
    b -> a X

    a -> c
    c -> a

    b -> c
    c -> a
    */
}