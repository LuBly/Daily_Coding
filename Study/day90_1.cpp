//[BaekJoon C++] 참외밭 [기하]
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int count, dir, length;
    int big=1;
    int small=1;
    cin>>count;
    map<int,vector<int>> data;
    vector<pair<int,int>> input;

    for(int k=0;k<6;k++){
        cin>>dir>>length;
        data[dir].push_back(length);
        input.push_back(make_pair(dir,length));
    }

    for(auto iter:data){
        if(iter.second.size()==1) big*=iter.second.front();
    }

    for(int j=0;j<input.size()*2-3;j++){//하나씩 체크
        if(input[j%6].first==input[(j+2)%6].first&&input[(j+1)%6].first==input[(j+3)%6].first) 
            small=input[(j+1)%6].second*input[(j+2)%6].second;
    }
    cout<<(big-small)*count;
}    