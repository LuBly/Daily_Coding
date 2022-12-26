//[Programmers C++] 햄버거 만들기
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> tmp;
    for(int k=0;k<ingredient.size();k++){
        tmp.push_back(ingredient[k]);
        if(tmp.size()>3&&ingredient[k]==1){
            if(tmp[tmp.size()-2]==3&&tmp[tmp.size()-3]==2&&tmp[tmp.size()-4]==1){
                for(int j=0;j<4;j++) tmp.pop_back();
                answer++;
            }
        }
    }
    return answer;
}