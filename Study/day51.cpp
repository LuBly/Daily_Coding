//[Programmers C++] 피로도
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    sort(dungeons.begin(),dungeons.end());
    do{
        int count=0;
        int orig=k;
        /*
        for(int j=0;j<dungeons.size();j++) cout<<dungeons[j][0]<<" ";
        cout<<endl;
        */
        for(int a=0;a<dungeons.size();a++){
            int need = dungeons[a][0];
            int use = dungeons[a][1];
            if(orig>=need) {
                orig-=use;
                count++;
            }
            else break;
        }
        answer=max(answer,count);
    }while(next_permutation(dungeons.begin(),dungeons.end()));
    
    return answer;
}