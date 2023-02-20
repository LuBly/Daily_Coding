//[Programmers C++] N_Queen
#include <string>
#include <vector>
using namespace std;

int col[15];
int answer=0;
int chess_size;
bool check(int level){
    for(int k=0;k<level;k++){
        if(col[k]==col[level]//같은 열에 있는 경우 ex) 0 - Q x Q x
           ||abs(col[level]-col[k])==level-k)//대각선에 있는 경우 평균변화량을 기준으로 판단(기울기= delta(y)/delta(x))
            return false;
    }
    return true;
}

void nQueen(int level){
    if(level == chess_size){
        answer++;
        return;
    }
    for(int column=0;column<chess_size;column++){
        col[level]=column;
        if(check(level)) nQueen(level+1);
    }
}

int solution(int n) {
    chess_size = n;
    nQueen(0);
    return answer;
}