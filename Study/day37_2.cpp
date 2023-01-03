//[Programmers C++] [카카오 인턴] 키패드 누르기
#include <string>
#include <vector>
//#include <iostream>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int Left=10;
    int Right=12;
    int L_cnt;
    int R_cnt;
    for(int a=0;a<numbers.size();a++){
        if(numbers[a]==1||numbers[a]==4||numbers[a]==7) {
            Left=numbers[a];
            answer+='L';
        }
        else if(numbers[a]==3||numbers[a]==6||numbers[a]==9) {
            Right=numbers[a];
            answer+='R';
        }
        else{
            if(numbers[a]==0) numbers[a]=11;
            
            int L_x,L_y,R_x,R_y,M_y;
            Left%3==1?L_x=1:L_x=0;
            Right%3==0?R_x=1:R_x=0;
            Right%3==0?R_y=Right/3-1:R_y=Right/3;
            L_y=Left/3; M_y=numbers[a]/3;
        
            if(L_y>M_y) L_cnt=L_x+(L_y-M_y);
            else L_cnt=L_x+(M_y-L_y);
            
            if(R_y>M_y) R_cnt=R_x+(R_y-M_y);
            else R_cnt=R_x+(M_y-R_y);
            
            if(L_cnt<R_cnt) {
                Left=numbers[a];
                answer+='L';       
            }
            else if(L_cnt==R_cnt){
                if(hand.compare("right")==0) {
                    Right=numbers[a];
                    answer+='R';
                }
                else {
                    Left=numbers[a];
                    answer+='L';
                }
            }
            else {
                Right=numbers[a];
                answer+='R';
            }
            
        }
            //cout<<"Left: "<<Left<<" Right: "<<Right<<" L_cnt: "<<L_cnt<<" R_cnt: "<<R_cnt<<endl;
        
    }
    return answer;
}