//[BaekJoon C++] N과 M [백트래킹] 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int num, pick;
    vector<int> perm;
    cin>>num>>pick;

    for(int k=1;k<=num;k++) perm.push_back(k);

    do{
        for(int j=0;j<pick;j++) cout<<perm[j]<<" ";
        cout<<"\n";

        reverse(perm.begin()+pick,perm.end());
    } while(next_permutation(perm.begin(),perm.end()));
}