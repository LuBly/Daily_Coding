//[BaekJoon C++] 덩치 [브루트 포스]
#include <iostream>
#include <vector>
using namespace std;

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int count;
    int rank=1;
    vector<pair<int,int>> data; 
    cin >> count;
    for(int k=0; k<count; k++){
        int weight, height;
        cin>> weight >> height;
        data.push_back(make_pair(weight,height));
    }

    for(int a=0;a<count;a++){
        for(int b=0;b<count;b++){
            if(data[a].first < data[b].first && data[a].second < data[b].second) rank++;
        }
        cout<<rank<<" ";
        rank = 1;
    }
}    