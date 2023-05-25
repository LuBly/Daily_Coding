#include <string>
#include <vector>

using namespace std;
// 9/2 4, 4+1 홀수면?
// 9/3 3 3 3 27
// 9/4 2,3 4 5
// -> x+y+z+d = 9 
// 10/2 5 5
// 10/3 3 4 5
//
vector<int> solution(int n, int s) {
    vector<int> answer;
    if(s/n==0) answer.push_back(-1);//2 1
    else{
        while(n>0){
            int num = s/n--;
            answer.push_back(num);
            s-=num;
        }
    }
    return answer;
}