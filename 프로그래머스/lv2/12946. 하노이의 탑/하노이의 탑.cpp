#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;
void hanoi(int n, int from, int by, int to){
    vector<int> tmp;
    if(n==1){
        tmp.push_back(from); tmp.push_back(to);
        answer.push_back(tmp);
    }
    else{
        hanoi(n-1,from,to,by);
        tmp.push_back(from); tmp.push_back(to);
        answer.push_back(tmp);
        hanoi(n-1,by,from,to);
    }
}
vector<vector<int>> solution(int n) {
    hanoi(n,1,2,3);
    return answer;
}