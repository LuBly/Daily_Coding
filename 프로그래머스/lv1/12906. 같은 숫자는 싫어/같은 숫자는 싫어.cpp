#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int tmp=arr[0];
    for(int k=1; k<arr.size();k++){
        if(arr[k]==tmp) continue;
        else{
            answer.push_back(tmp);
            tmp=arr[k];
        }
    }
    answer.push_back(tmp);
    return answer;
}