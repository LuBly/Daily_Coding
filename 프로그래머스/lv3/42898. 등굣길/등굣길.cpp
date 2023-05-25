#include <string>
#include <vector>
#include <iostream>
#define div 1000000007
using namespace std;

//dp[n][m]=dp[n-1][m]+dp[n][m-1]
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    bool is_puddle[101][101]={false,};
    int path[101][101];
    fill_n(&path[0][0],101*101,0);//path 초기화
    for(int k=0;k<puddles.size();k++){
        int x = puddles[k][0], y = puddles[k][1];
        is_puddle[y][x]=true;
        path[y][x]=0;
    }
    
    path[1][1]=1;
    for(int y=2;y<=n;y++){//x가 1일 때
        if(!is_puddle[y][1])
            path[y][1] = path[y-1][1];
    }
    for(int x=2;x<=m;x++){//y가 1일 때
        if(!is_puddle[1][x])
            path[1][x] = path[1][x-1];
    }
    
    for(int y=2;y<=n;y++){
        for(int x=2;x<=m;x++){
            if(!is_puddle[y][x])
                path[y][x] = ((path[y-1][x])%div+(path[y][x-1])%div)%div;
        }
    }
    
    answer = path[n][m];
    return answer;
}