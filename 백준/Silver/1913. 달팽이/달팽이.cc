//[BaekJoon C++] 달팽이 [구현]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N,num,cur=1;
    cin>>N>>num;
    vector<vector<int>> board(N,vector<int>(N,0));
    pair<int,int> result;
    int y=N/2, x=N/2;
    if(num==1) result = {y,x};
    board[y][x]=cur++;
    //up right 1/ down left 2/ up right 3/ down left 4/ up right 5/
    int cnt=1;//홀수 : up right, 짝수 : down left
    while(true){
        if(cnt==N){//마지막의 경우 cnt=N 일 때 up or down의 경우
            for(int k=1;k<cnt;k++){
                board[--y][x]=cur++;//up
                if(cur-1==num) result={y,x};
            }
            break;
        }
        
        if(cnt%2==0){//짝수
            for(int k=0;k<cnt;k++){
                board[++y][x]=cur++;
                if(cur-1==num) result={y,x};
            }
            for(int k=0;k<cnt;k++){
                board[y][--x]=cur++;
                if((cur-1)==num) result={y,x};
            }
        }
        else{//홀수
            for(int k=0;k<cnt;k++){
                board[--y][x]=cur++;
                if(cur-1==num) result={y,x};
            }
            for(int k=0;k<cnt;k++){
                board[y][++x]=cur++;
                if(cur-1==num) result={y,x};
            }
        }
        cnt++;
    }

    for(int y=0;y<N;y++){
        for(int x=0;x<N;x++)
            cout<<board[y][x]<<" ";
        cout<<'\n';
    }
    cout<<(result.first+1)<<" "<<(result.second+1);
}   
