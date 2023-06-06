#include <string>
#include <vector>
#include <iostream>
using namespace std;
int N,M,board_size;
vector<vector<int>> rotate_key(vector<vector<int>> key, int M){
    vector<vector<int>> tmp(M,vector<int>(M));//M,M 배열 선언
    for(int y=0;y<M;y++){
        for(int x=0;x<M;x++){
            tmp[y][x] = key[M-x-1][y];
        }
    }
    return tmp;
}

bool putKey(int y, int x, vector<vector<int>> key, vector<vector<int>> board){
    for(int sty=y;sty<y+M;sty++){
        for(int stx=x;stx<x+M;stx++){
            board[sty][stx]+=key[sty-y][stx-x];//미리 만들어놓은 board에 key배열을 가져다 대본다. 
        }
    }
    //맞는 경우 board에서 Lock부분이 모두 1일것이고 1이 아니라면 false
    for(int y=M-1;y<M-1+N;y++){//Lock의 구역
        for(int x=M-1;x<M-1+N;x++){//Lock의 구역
            if(board[y][x]==1) continue;//그냥 board[y][x]로 해놓으면 2여도 true로 처리됨
            return false;//Lock부분이 1이 아닌경우가 발생하면 false return
        }
    }
    return true;//Lock부분이 모두 1이라면 true return
    
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    //회전 체크_우회전(원본, 90도, 180도, 270도)
    //이동 체크_key size -1만큼까지
    N = lock.size(); M = key.size(); board_size = N+(M-1)*2;//key를 이동시켜줄 board를 따로 생성 최대 size 20 + (20-1)*2 = 20 + 38 = 58
    
    vector<vector<int>> board(board_size,vector<int>(board_size,0));//map[boardsize][boardsize] 생성
    //key를 비교해볼 board 생성
    for(int y=M-1;y<M-1+N;y++){//Lock의 구역
        for(int x=M-1;x<M-1+N;x++){//Lock의 구역
            board[y][x]=lock[y-M+1][x-M+1];
        }
    }
    
    for(int cnt=0;cnt<4;cnt++){//회전
        //이동하면서 비교
        for(int y=0;y<=board_size-M;y++){
            for(int x=0;x<=board_size-M;x++){
                if(putKey(y,x,key,board))
                    return true;
            }
        }   
        key = rotate_key(key,M);//key 회전     
    }
    return answer;
}