//[Programmers C++] 연속 부분 수열 합의 개수
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int cur = 0;
    int leng = 1;
    vector<int> tmp;
    
    while(leng<=elements.size()){
        if(leng!=elements.size()){
            for(int start = 0; start < elements.size(); start++){
                int sum = 0;
                for(int k = 0; k < leng; k++){
                    sum += elements[(start+k)%elements.size()];
                }
                tmp.push_back(sum);
            }
        }
        else{
            int F_sum = 0;
            for(int j = 0; j < leng; j++){
                F_sum += elements[j];
            }
            tmp.push_back(F_sum);
        }
        leng++;
    }
    sort(tmp.begin(),tmp.end());
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    answer = tmp.size();
    
    return answer;
}
