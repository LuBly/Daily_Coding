#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> div;
    for(int k =1; k*k<=yellow;k++){
        if(yellow%k==0) div.push_back(k);
        
    }
    for(int j=0;j<div.size();j++){
        //cout << div[j] << " "<< yellow/div[j] <<" ";
        if(div[j]+(yellow/div[j])==(brown-4)/2){
            answer.push_back(yellow/div[j]+2);
            answer.push_back(div[j]+2);
            break;
        }
    }
    
    return answer;
}