//[Programmers C++] 바탕화면 정리

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    vector<int> x_vec;
    vector<int> y_vec;
    
    for(int k=0;k<wallpaper.size();k++){
        for(int j=0;j<wallpaper[k].size();j++){
            if(wallpaper[k][j]=='#'){
                x_vec.push_back(k);
                y_vec.push_back(j);
            }        
        }
    }
    
    sort(x_vec.begin(),x_vec.end());
    sort(y_vec.begin(),y_vec.end());
    
    answer.push_back(x_vec.front());
    answer.push_back(y_vec.front());
    answer.push_back(x_vec.back()+1);
    answer.push_back(y_vec.back()+1);
    
    return answer;
}