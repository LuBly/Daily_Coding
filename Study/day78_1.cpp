//[Baekjoon C++] 구간 합 구하기 4
#include <iostream>
#include <vector>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int Line_num,count;
    cin>>Line_num>>count;
    vector<int> intSum;
    int sum=0;
    for(int k=0;k<Line_num;k++){
        int input;
        cin>>input;
        sum+=input;
        intSum.push_back(sum);//0~k까지의 합을 계속해서 입력
    }

    for(int j=0;j<count;j++){
        int start,end;
        cin>>start>>end;
        start--;
        end--;
        if(start!=0){
            cout<<intSum[end]-intSum[start-1];
        }
        else cout<<intSum[end];
        cout<<'\n';
    }
    
}