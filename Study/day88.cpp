//[BaekJoon C++] 문자열 집합 [집합과 맵]
#include <iostream>
#include <map>
using namespace std;

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N,M;
    int answer=0;
    string tmp_A,tmp_B;
    map<string,bool> data;//S집합에 string이 포함되어 있으면 true, 없으면 0;
    
    cin>>N>>M;
    for(int k=0;k<N;k++){
        cin>>tmp_A;
        data[tmp_A] = true;
    }

    for(int j=0;j<M;j++){
        cin>>tmp_B;
        if(data[tmp_B]) answer++;
    }

    cout<<answer;
}    