//[Baekjoon C++] 유기농 배추 [DFS]
#include <iostream>
#include <vector>
#include <string>
#include <cmath> 
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int line_cnt, width;
    cin>>line_cnt>>width;
    vector<string> data;
    for(int k=0;k<line_cnt;k++){
        string input;
        cin>>input;
        data.push_back(input);
    }    
    //1. 각줄을 순회하며 한 줄에 같은 숫자가 존재하는지 chk
    //2. 같은 숫자가 존재한다면 세로로 check
    //3. 거기에도 있으면 넓이 update

    int answer = 1;
    for(int a=0;a<line_cnt;a++){//50
        for(int b=0;b<width-1;b++){//50
            char cur = data[a][b];//기준점
            for(int c=b+1;c<width;c++){//같은 라인에서 기준점과 같은 원소가 있는지 check
                char next = data[a][c];
                if(cur == next){//같은 원소가 있다면?
                    int length = c-b;
                    if(a+length>=line_cnt) continue;//범위 바깥 체크
                    if(cur == data[a+length][b]&&cur == data[a+length][c])
                        answer = answer>pow(length+1,2) ? answer : pow(length+1,2);//max연산
                }
            }
        }
    }
    cout<<answer;
}