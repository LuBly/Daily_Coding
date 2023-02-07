//[BaekJoon C++] 나이순 정렬 [정렬] 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(pair<int,string> a, pair<int,string> b){
    return a.first<b.first;
}

int main() {
    int count;
    int age;
    string name;
    vector<pair<int,string>> data;

    cin>>count;
    for(int k=0;k<count;k++){
        cin>>age>>name;
        data.push_back(make_pair(age, name));
    }
    stable_sort(data.begin(),data.end(),cmp);

    for(int j=0;j<count;j++) cout<<data[j].first<<" "<<data[j].second<<"\n";
}
