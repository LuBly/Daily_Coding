//[Programmers C++] 기능개발
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> fin;
    for(int k=0;k<progresses.size();k++){
        int num=(100-progresses[k])/speeds[k];
        if((100-progresses[k])%speeds[k]!=0) num++;
        fin.push_back(num);
    }
    int max=fin[0];
    int count = 1;
    for(int j=1;j<fin.size();j++){
        if(fin[j]>max){//answer.push_back 타이밍
            max=fin[j];
            answer.push_back(count);
            count=1;
        }
        else{
            count++;
        }
    }
    answer.push_back(count);
    return answer;
}