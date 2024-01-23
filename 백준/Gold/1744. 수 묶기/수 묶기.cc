//[BaekJoon C++] 수 묶기 [그리디] 13 00
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
/*

4 -1 2 1 3

내림차순 정렬
3 2 1 -1
6 1 -1 = 6

5 4 3 2 1 0
20 6 1 0 = 27


2개씩 체크 더하는거랑 곱하는거랑
더하는거면 결과값에 PlusArr[i] 더하고 PlusIdx+1
곱하는거면 결과값에 PlusArr[i] * PlusArr[i+1] 더하고 PlusIdx+2
음수 따로 양수 따로 계산해서 더하기?
*/
int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int numCnt;
    cin >> numCnt;

    vector<ll> PlusArr;
    vector<ll> MinusArr;
    for(int k = 0; k < numCnt; k++){
        ll input;
        cin >> input;
        if(input > 0)
            PlusArr.push_back(input);
        else
            MinusArr.push_back(input);
    }
    //내림차순 정렬
    sort(PlusArr.rbegin(), PlusArr.rend());
    sort(MinusArr.begin(), MinusArr.end());
    ll answer = 0;
    int PlusIdx = 0;
    int MinusIdx = 0;

    while(PlusIdx < PlusArr.size()){
        if(PlusIdx == PlusArr.size() -1){
            answer += PlusArr[PlusIdx];
            break;
        }
        if(PlusArr[PlusIdx] + PlusArr[PlusIdx+1] < PlusArr[PlusIdx] * PlusArr[PlusIdx+1]){
            answer += PlusArr[PlusIdx] * PlusArr[PlusIdx+1];
            PlusIdx+=2;
        }
        else{
            answer += PlusArr[PlusIdx];
            PlusIdx+=1;
        }
    }

    while(MinusIdx < MinusArr.size()){
        if(MinusIdx == MinusArr.size() -1){
            answer += MinusArr[MinusIdx];
            break;
        }
        if(MinusArr[MinusIdx] + MinusArr[MinusIdx+1] < MinusArr[MinusIdx] * MinusArr[MinusIdx+1]){
            answer += MinusArr[MinusIdx] * MinusArr[MinusIdx+1];
            MinusIdx+=2;
        }
        else{
            answer += MinusArr[MinusIdx];
            MinusIdx+=1;
        }
    }


    cout << answer;
}    