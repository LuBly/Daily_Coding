//[Baekjoon C++] 마인크래프트 [브루트포스]
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 257
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	// 높이 정보를 기준으로 time 계산
    // input에서 높이 정보만 저장 
    
    int height, width, blockCnt;
    cin>>height>>width>>blockCnt;
    vector<int> board(MAX,0);
    int curH;
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            cin>>curH;
            board[curH]++;
        }
    }
    
    long long time = 999999999;
    int maxHeight = 0;

    for(int y=0;y<MAX;y++){//만들 땅의 높이 
        long long subCnt = 0; //파야하는 수
        long long sumCnt = 0; //채워넣어야 하는 수
        //만들 땅의 높이보다 높은거
        for(int k=y+1;k<MAX;k++)
            subCnt += (k-y)*board[k];
        
        //만들 땅의 높이보다 낮은거
        for(int k=0;k<y;k++)
            sumCnt += (y-k)*board[k];

        if(sumCnt<=subCnt+blockCnt){
            if(time >= sumCnt + subCnt*2){
                time = sumCnt + subCnt*2;
                maxHeight = y;
            }
        }
    }

    cout<<time<<" "<<maxHeight;
}