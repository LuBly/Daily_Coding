//[Programmers C++] [1차] 캐시
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    /*
    for(int a=0;a<cacheSize;a++){
        cache.push_back(cities[a]);
        answer+=5;
    }
    */
    for(int b=0;b<cities.size();b++){
        bool is_hit=false;
        int cur;
        
        for(int c=0;c<cache.size();c++){
            if(strcasecmp(cities[b].c_str(),cache[c].c_str())==0){//대소문자 구분없이 문자열 비교
                is_hit=true;
                cur=c;
                break;
            }
        }
        
        if(is_hit) {
            cache.erase(cache.begin()+cur);
            cache.push_back(cities[b]);
            answer++;
        }
        else{
            if(cache.size()<cacheSize) cache.push_back(cities[b]);
            else if(!cache.empty()){
                cache.erase(cache.begin());
                cache.push_back(cities[b]);    
            }
            answer+=5;
        }
        /*
        for(int k=0;k<cache.size();k++){
            cout <<cache[k]<<" ";
        }
        cout<<endl;
        */
    }
    
    return answer;
}