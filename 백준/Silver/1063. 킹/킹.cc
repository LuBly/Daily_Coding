//[Baekjoon C++] 킹 [구현]
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    map<char,pair<int,int>> move;//움직임 comment, 좌표(y,x)
    //RT, LT 와 같은 혼합 이동의 결과는 map을 혼합하여 이동하는 것으로 함
    //{y,x}
    move['R']={0,1};    //오른쪽 이동
    move['L']={0,-1};   //왼쪽 이동
    move['B']={-1,0};   //아래로 이동
    move['T']={1,0};    //위로 이동

    //width  -> A~H 0~7
    //height -> 1~8
    string king, rock;//king과 rock의 좌표
    int mv_cnt;//움직일 횟수
    cin>>king>>rock>>mv_cnt;

    //string 좌표를 숫자로 변경(x,y)
    pair<int,int> king_pt = {king[0]-'A',king[1]-'0'};
    pair<int,int> rock_pt = {rock[0]-'A',rock[1]-'0'};
    
    //이동
    for(int k=0;k<mv_cnt;k++){
        string input;
        cin>>input;
        int king_y = king_pt.second; int king_x = king_pt.first;
        int rock_y = rock_pt.second; int rock_x = rock_pt.first;

        //king의 이동
        for(auto ch : input){
            king_y+=move[ch].first;
            king_x+=move[ch].second;
        }

        //이동 후에 king이 체스판 밖으로 나갈 경우 이동 건너뛰기
        if(king_y>8||king_x>7||king_y<1||king_x<0) continue;

        //이동 위치에 돌이 있는 경우 돌맹이 out
        if(king_y==rock_y&&king_x==rock_x){
            for(auto ch : input){
                rock_y+=move[ch].first;
                rock_x+=move[ch].second;
            }   
        }
        //이동 후에 rock이 체스판 밖으로 나갈 경우 이동 건너뛰기
        if(rock_y>8||rock_x>7||rock_y<1||rock_x<0) continue;
        king_pt.second = king_y; king_pt.first = king_x;
        rock_pt.second = rock_y; rock_pt.first = rock_x;
    }
    //int형으로 되어있는 좌표를 다시 string 형태로 변환
    string result_king="", result_rock="";
    
    result_king+=(king_pt.first+'A');
    result_king+=(king_pt.second+'0');

    result_rock+=(rock_pt.first+'A');
    result_rock+=(rock_pt.second+'0');
    cout<<result_king<<'\n'<<result_rock;
}