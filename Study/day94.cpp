//[Baekjoon C++] 패션왕 신해빈 [집합과 맵]
#include <iostream>
#include <map>
using namespace std;
int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int testCase;

    cin>>testCase;
    for(int k=0;k<testCase;k++){
        map<string,int> clothes;
        int count;
        int answer = 1;
        cin>>count;
        
        for(int j=0;j<count;j++){
            string name, type;
            cin>>name>>type;
            clothes[type]++;
        }
        
        for(auto iter:clothes) answer*=iter.second+1;
        cout<<answer-1<<'\n';
        
    }
}