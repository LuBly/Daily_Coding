//[BaekJoon C++] 좌표 압축 [정렬] 
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int count;
    cin>>count;
    vector<int> input;
    set<int> check;
    map<int, int> cal;//숫자, idx

    for(int k=0;k<count;k++){
        int num; cin>>num;
        input.push_back(num);
        check.insert(num);
    }

    int idx=0;
    for(auto iter : check){
        cal[iter]=idx;
        idx++;
    }

    for(int j=0; j<count-1;j++){
        cout<<cal[input[j]]<<" ";
    }
    cout<<cal[input[count-1]];
}
