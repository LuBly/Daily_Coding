//[BaekJoon C++] 체스판 다시 칠하기 [브루트 포스]
#include <iostream>
#include <vector>

using namespace std;

string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};

vector<string> board;

int WB_cnt(int x, int y){
    int cnt = 0;
    for(int k=0; k<8; k++){
        for(int j=0; j<8; j++){
            if(board[x+k][y+j]!=WB[k][j]) cnt++;
        }
    }
    return cnt;
}

int BW_cnt(int x, int y){
    int cnt = 0;
    for(int k=0; k<8; k++){
        for(int j=0; j<8; j++){
            if(board[x+k][y+j]!=BW[k][j]) cnt++;
        }
    }
    return cnt;
}

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int row, col;//높이, 가로
    int result=100;
    
    cin >> row >> col;
    for(int p=0; p<row; p++){
        string input;
        cin>>input;
        board.push_back(input);
    }
    
    //starting pos 정하기
    for(int a=0;a<=row-8;a++){
        for(int b=0;b<=col-8;b++){
            int tmp = min(WB_cnt(a,b),BW_cnt(a,b));
            if(tmp<result) result=tmp;
        }
    }
    cout<<result;
}    