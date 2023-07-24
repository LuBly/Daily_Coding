//[Baekjoon C++] 행렬 [그리디]
#include <iostream>
#include <vector>
#include <map>
using namespace std;


int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int length, width;
    cin>>length>>width;
    vector<vector<char>> matA(length,vector<char>(width));
    vector<vector<char>> matB(length,vector<char>(width));

    for(int y=0;y<length;y++){
        for(int x=0;x<width;x++)
            cin>>matA[y][x];
    }
    
    for(int y=0;y<length;y++){
        for(int x=0;x<width;x++)
            cin>>matB[y][x];
    }

    //A 행렬을 순회하면서 B 행렬과 다르다면 flip
    int flip = 0;
    for(int y=0;y<length-2;y++){
        for(int x=0;x<width-2;x++){
            if(matA[y][x]==matB[y][x]) continue;
            //A와 B 행렬 비교 중 다른 값을 만난 경우
            //3*3 행렬 flip
            for(int k=y;k<y+3;k++){
                for(int j=x;j<x+3;j++){
                    if(matA[k][j]=='1')matA[k][j]='0';
                    else if(matA[k][j]=='0')matA[k][j]='1';
                }
            }
            flip++;
        }
    }
    for(int y=0;y<length;y++){
        for(int x=0;x<width;x++){
            if(matA[y][x]!=matB[y][x])
                flip=-1;
        }
    }

    cout<<flip;
}