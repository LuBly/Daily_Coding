#include <string>
#include <vector>
#include <iostream>
using namespace std;
// 총 갯수
// 2차원 벡터를 활용하여 문제 풀이
// 방향 -> 하향(y++)-> 우측(x++)-> 상향(x--, y--);
vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> data(n,vector<int>(n, 0));
    int cnt = n, num=1, dir=0, x=0,y=0;
   
    while(cnt>0){
        if(dir%3==0){//하향일 때 --> 우측
            for(int k=0;k<cnt;k++)
                data[y++][x] = num++;
            y--; x++;
        }
        else if(dir%3==1){//우측일 때 --> 상향
            for(int k=0;k<cnt;k++)
                data[y][x++] = num++;
            y--; x-=2;
        }
        else{//상향일 때 --> 하향
            for(int k=0;k<cnt;k++)
                data[y--][x--] = num++;
            x++; y+=2;
        }
        dir++;
        cnt--;
    }
    for(int k=0;k<data.size();k++){
        for(int j=0;j<data[k].size();j++){
            if(data[k][j]!=0) answer.push_back(data[k][j]);
        }
    }
    
    return answer;
}