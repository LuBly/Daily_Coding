//[Baekjoon C++] 이전순열 [구현]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int num;
    cin>>num;
    vector<int> input(num,0);
    for(int k=0;k<num;k++)
        cin>>input[k];
    
    if(prev_permutation(input.begin(),input.end())){//이전 순열이 없다면 false, 있으면 true
        for(int k=0;k<num;k++)
            cout<<input[k]<<" ";
        cout<<'\n';
    }
    else
        cout<<"-1"<<'\n';
}