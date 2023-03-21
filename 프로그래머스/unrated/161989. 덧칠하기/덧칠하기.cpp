#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    while(section.size()>0){
        int cur=section[0];
        int limit=cur+m-1;
        int idx=0;
        //cout<<"cur: "<<cur<<" limit: "<<limit<<endl;
        for(int k=0;k<section.size();k++){
            //cout<<"check: "<<section[k]<<endl;
            if(section[k]<=limit)     
                idx++;
        }
        section.erase(section.begin(),section.begin()+idx);
        //for(auto iter : section) cout<<iter<<" ";
        //cout<<endl;
        answer++;
    }
    
    return answer;
}