//[Baekjoon C++] 어두운 건 무서워 [누적합]
#include <iostream>
#include <vector>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);    
    int length, width, testCnt;
    cin>>length>>width>>testCnt;
    vector<vector<int>> board(length, vector<int>(width,0));
    //데이터 입력받기
    for(int y = 0; y < length; y++){
        for(int x = 0; x < width; x++){
            cin>>board[y][x];
        }
    }
    //Prefix 생성
    //한줄 한줄씩 사각형 단위로 Prefix 생성
    //가로 Prefix
    for(int y = 0; y < length; y++){
        for(int x = 1; x < width; x++){
            board[y][x]+=board[y][x-1];
        }
    }

    //세로 Prefix
    for(int y = 1; y < length; y++){
        for(int x = 0; x < width; x++){
            board[y][x]+=board[y-1][x];
        }
    }

    for(int k = 0; k < testCnt; k++){
        int r1, c1, r2, c2;
        cin>>r1>>c1>>r2>>c2;
        int ColorSum;
        //예외처리
        if(r1==1&&c1==1){
            ColorSum = board[r2-1][c2-1];
        }
        else if(r1==1){
            ColorSum = board[r2-1][c2-1] - board[r2-1][c1-2];
        }
        else if(c1==1){
            ColorSum = board[r2-1][c2-1] - board[r1-2][c2-1];
        }
        else{
            ColorSum = board[r2-1][c2-1] - board[r2-1][c1-2] - board[r1-2][c2-1] + board[r1-2][c1-2];
        }
        
        int ColorSize = (r2 - r1 + 1) * (c2 - c1 + 1);
        cout<<ColorSum/ColorSize<<'\n';
    }
    
}