//[Programmers C++] [1차] 비밀지도
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string tmp = "";
    for(int k=0;k<n;k++){//위에서 아래로
        for(int j=0;j<n;j++){
            if(arr1[k]%2==1||arr2[k]%2==1) tmp+="#";
            else tmp+=" ";
            arr1[k]/=2;
            arr2[k]/=2;
        }
        reverse(tmp.begin(), tmp.end());
        answer.push_back(tmp);
        tmp = "";
    }
    return answer;
}