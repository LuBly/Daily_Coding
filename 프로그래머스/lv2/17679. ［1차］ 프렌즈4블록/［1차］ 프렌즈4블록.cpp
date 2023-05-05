#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool is_end = false;
    
    while(!is_end){
        is_end=true;
        bool arr[30][30] = {false,};
        
        for(int y=0;y<m-1;y++){
            for(int x=0;x<n-1;x++){
                char cur = board[y][x];
                if(cur == ' ') continue;
                if(cur == board[y][x+1] && cur == board[y+1][x] && cur == board[y+1][x+1]){
                    arr[y][x]=true;
                    arr[y][x+1]=true;
                    arr[y+1][x]=true;
                    arr[y+1][x+1]=true;
                    is_end=false;
                }
            }
        }
        
        for(int y=0;y<m;y++){
            for(int x=0;x<n;x++){
                if(arr[y][x]){
                    answer++;
                    for(int k=y-1;k>=0;k--){
                        board[k+1][x]=board[k][x];
                        board[k][x]=' ';    
                    }
                }
            }
        }
        if(is_end) break;
    }
    return answer;
}