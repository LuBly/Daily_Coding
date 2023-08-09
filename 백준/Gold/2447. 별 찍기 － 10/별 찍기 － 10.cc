//[Baekjoon C++] 별 찍기 - 10 [재귀]
#include <iostream>
using namespace std;

void makePattern(int x, int y, int input){
    // N의 크기가 1인 경우엔 더 이상 탐색할 수 없으므로 * 출력
    if(input == 1)
        cout<<"*";
    // 1. 현재 좌표가 크기 N의 정사각형을 기준으로 중앙 공백 좌표인지 확인
    // -> (x / (N/3)) % 3 == 1 && (y / (N/3)) % 3 == 1
    else if((x / (input/3)) % 3 == 1 && (y / (input/3)) % 3 == 1)
        cout<<" ";
    else
        makePattern(x, y, input/3);
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int input;
    cin>>input;
    // 별 찍기의 패턴
    // 1. 현재 좌표가 크기 N의 정사각형을 기준으로 중앙 공백 좌표인지 확인
    // -> (x / (N/3)) % 3 == 1 && (y / (N/3)) % 3 == 1
    // 2. 아니라면 정사각형의 크기를 N/3으로 줄인뒤, N/3 정사각형 기준으로 중앙 공백 좌표인지 확인
    // 3. 1~2과정을 반복하며, x,y 가 중앙 공백 좌표인 경우에는 공백을 출력
    // 3.1 N의 크기가 1이된 경우에는, 더 이상 탐색할 수 없으므로 * 출력
    
    for(int x = 0; x < input; x++){
        for(int y = 0; y < input; y++){
            makePattern(x, y, input);
        }
        cout<<'\n';
    }
    
}