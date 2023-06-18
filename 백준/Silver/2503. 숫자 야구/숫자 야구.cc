//[Baekjoon C++] 숫자 야구 [구현]
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    //숫자야구
    //스트라이크 = 위치도 같고, 숫자도 같은 것
    //볼 = 위치는 틀리고, 숫자는 같은 것
    int cnt;
    cin>>cnt;
    vector<pair<string,pair<int,int>>> data;
    for(int k=0;k<cnt;k++){
        string input;
        int strike, ball;
        cin>>input>>strike>>ball;
        data.push_back({input,{strike,ball}});
    }
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    int answer=0;
    do{//9P3의 순열로 숫자들을 하나하나 구하는 과정
        string num = "";
        for(int k=0;k<3;k++){
            num+=to_string(nums[k]);
        }
        bool is_answer=true;
        for(int k=0;k<cnt;k++){
            int strike=0, ball=0;
            string cmp_num = data[k].first;
            int cmp_strike = data[k].second.first;
            int cmp_ball = data[k].second.second;
            map<char,int> mp;

            for(int a=0;a<3;a++)
                mp[cmp_num[a]]++;//중복 제거를 위해 이미 있는 문자인지 check

            for(int a=0;a<3;a++){
                char cur = num[a];
                if(mp[cur]){//해당 문자가 비교 문자에 있으면
                    //위치 비교
                    if(cur==cmp_num[a]) strike++;//같은 자리면 strike++
                    else ball++;//다른 자리면 ball++
                }                
            }
            if(strike==cmp_strike&&ball==cmp_ball) continue;
            else{
                is_answer=false;
                break;
            }
        }
        if(is_answer) answer++;
        reverse(nums.begin()+3,nums.end());
    }while(next_permutation(nums.begin(),nums.end()));
    //거꾸로 생각하지 말고 숫자를 있는 그대로 진행
    //123~987까지 중복X 3개 순열 사용
    cout<<answer;
}