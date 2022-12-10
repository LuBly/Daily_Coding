//[Programmers C++] 이진 변환 반복하기
#include <string>
#include <vector>
#include <bitset>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
        
    int count = 0; //회차 정보
    int z_count = 0; // 제거할 0의 개수
    
    while(s.size()!=1){
        int length = 0;//각 회차별로 제거 후 길이를 초기화
        vector<int> temp;
        for(int k =0; k < s.size(); k++){ 
            if(s[k] == '1') length++; //0 제거 후의 길이 증가.
            else z_count++; //해당 커서의의 char이 0 이면 제거할 0의 갯수 증가
        }
        //예제 1에 의하면 length 6을 "2진수"로 만들기 
        s.clear();
        s.resize(0);//s vector 초기화
        while(length!=0){
            if(length%2 == 1) temp.push_back(1);
            else temp.push_back(0);
            length /=2;
        }
        while(!temp.empty()){
            s.push_back(temp.back()+'0');//새로운 백터로 채워넣기
            temp.pop_back();
        }
        count++; //회차 정보 추가
    }
    answer.push_back(count); //vector(회차정보)
    answer.push_back(z_count); //vector(회차정보, 제거한 0의 갯수)
    
    return answer;
}
