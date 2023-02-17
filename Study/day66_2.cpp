//[BaekJoon C++] ATM [그리디]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> time;
    int count;
    int sum=0;
    int answer=0;
    cin>>count;
    for(int k=0; k<count;k++){
        int num;
        cin>>num;
        time.push_back(num);
    }
    sort(time.begin(),time.end());
    for(int j=0;j<time.size();j++){
        sum+=time[j];
        answer+=sum;
    }
    cout<<answer;
}