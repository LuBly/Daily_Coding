//[BaekJoon C++] 좌표 정렬하기 2 [정렬]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    vector<pair<int, int>> yx_map;
    int count;
    cin>>count;
    for(int k=0;k<count;k++){
        int x,y;
        cin>>x>>y;
        yx_map.push_back(make_pair(y,x));
    }
    sort(yx_map.begin(),yx_map.end());

    for(int j=0;j<yx_map.size();j++){
        cout<<yx_map[j].second<<" "<<yx_map[j].first<<"\n";
    }
}