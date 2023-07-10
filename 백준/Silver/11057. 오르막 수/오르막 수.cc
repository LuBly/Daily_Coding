//[BaekJoon C++] 오르막 수 [DP]
#include <iostream>
#include <vector>
#include <algorithm>
#define div 10007
using namespace std;

//dp[1]=[0 1 2 3 4 5 6 7 8 9] = 10
//dp[2]=[11 12 13 14 15 16 17 18 19] 10 9 8 7 6 5 4 3 2 1 = 55 1~10까지의 합
//      [22 23 24 25 26 27 28 29]
//      [33 34 35 36 37 38 39]        
//      [44 45 ~~]
//dp[3]=[111 112 113 114 115 116 117 118 119] 9 ~ 45
//      [122 123 124~~]
//      [133 134 ~~]
//      [144 145 ~~]
//      [155 156 ~~]
//      [166 167 ~~]
//      [222 223 224~~] 8 => 36
//      [233 ~~] 
//      [333 334 ~~] 7 =>28
//      [444 445 ~~] 6 =>21
//      [555] 5 =>15
//      [666] 4 =>10
//      [777] 3 =>6
//      [888] 2 =>3
//      [999] 1 =>1  
//dp[4]=45
//  0 1 2 3 4 5 6 7 8 9 //끝의 자리수
//0 1 1 1 1 1 1 1 1 1 1*
//1 1 2 3 4 5 6 7 8 9 10*
//2 1 3 6 10 15 21 28 36 45 55*
//3 1 4 10 20 35 56 84 120 165 220*
//n 1 [n-1][1]+[n][0]~~ [n-1][9]+[n][8]*


void solve(int input, vector<vector<int>> board){
    for(int y=1;y<=input;y++){
        for(int x=1;x<10;x++){
            board[y][x]=(board[y-1][x]%div+board[y][x-1]%div)%div;
        }
    }
    cout<<board[input][9];
}


int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int input;
    cin>>input;
    vector<vector<int>> board(input+1, vector<int>(10,1));
    solve(input, board);
}
