//[Baekjoon C++] 하노이 탑 이동 순서 [재귀]
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void hanoi(int count, int from, int beyond, int to){
    if(count == 1){
        cout << from << " " << to << '\n';
    }
    else{
        hanoi(count - 1, from, to, beyond);
        cout << from << " " << to << '\n';
        hanoi(count -1, beyond, from, to);
    }
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int plateCnt;
    cin >> plateCnt;
    cout << (int)pow(2, plateCnt) - 1 << '\n';
    hanoi(plateCnt, 1,2,3);
}