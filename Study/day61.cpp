//[BaekJoon C++] 단어 정렬 [정렬]
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

struct cmp{
    bool operator()(const string &a, const string &b) const{
        if(a.size()==b.size()) return a<b;
        else return a.size()<b.size();
    }
};

int main() {
    ios::sync_with_stdio(false);
    set<string,cmp> str;
    int count;
    string tmp;
    cin>>count;
    for(int k=0;k<count;k++){
        cin>>tmp;
        str.insert(tmp);
    }

    for(auto iter:str){
        cout<<iter<<'\n';
    }
}
