//[Programmers C++] 주식가격
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    vector<int> pr_stack;
    int time=0;
    for(int a=0;a<prices.size()-1;a++){//기준 가격
        for(int b=a+1;b<prices.size();b++){//새로 들어오는 가격
            //cout<<prices[a]<<" "<<prices[b]<<endl;
            if(prices[b]>=prices[a]) time++;//새로들어오는 가격이 기준 가격보다 높거나 같을 때
            else{//새로 들어오는 가격이 기준 가격보다 낮을 때
                time++;
                break;
            }
        }
        answer.push_back(time);
        time=0;
    }
    answer.push_back(0);
    return answer;
}