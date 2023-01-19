//[Programmers C++] 할인 행사
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string,int> want_map;
    map<string,int> discount_map;
    
    for(int k=0;k<want.size();k++) want_map[want[k]]=number[k];
    for(int j=0;j<10;j++) discount_map[discount[j]]++;//초기 비교값
    

    for(int a=9;a<discount.size();a++){//시작포인트
        bool is_full=true;
        /*
        for(auto iter:discount_map){
            cout<<iter.first<<" "<<iter.second<<" ";
        }
        cout<<" enter: "<<discount[a]<<" out: "<<discount[a-9]<<endl;
        */
        for(auto iter:want_map){
            //cout<<"menu: "<<iter.first<<" want: "<<iter.second<<" discount: "<<discount_map[iter.first]<<endl;
            if(iter.second>discount_map[iter.first]) {
                is_full=false;
                break;
            }
        }
        //cout<<endl;
        if(is_full) answer++;
        if(a<discount.size()-1) discount_map[discount[a+1]]++;
        discount_map[discount[a-9]]--;
    }
    
    return answer;
}