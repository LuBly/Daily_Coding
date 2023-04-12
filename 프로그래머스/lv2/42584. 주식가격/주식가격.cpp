#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int k=0;k<prices.size()-1;k++){
        int time = 0;
        for(int j=k+1;j<prices.size();j++){
            if(prices[k]<=prices[j]) time++;
            else{
                time++;
                break;
            }
        }
        answer.push_back(time);
    }
    answer.push_back(0);
    return answer;
}