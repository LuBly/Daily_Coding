#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// 이모티콘 계산 최대 4^7
int ratio[4]={10,20,30,40};//할인률
int sz;
int result[101]={0,};
vector<pair<int,int>> result_data; // plus 가입 수, 총 구매 비용 

void dfs(vector<vector<int>> user, vector<int> emo, int cnt){
    if(cnt == sz){
        int sum = 0, plus = 0;
        for(int j=0;j<user.size();j++){
            int user_sum = 0;
            for(int k=0;k<sz;k++){//이모티콘 할인률
                if(result[k]>=user[j][0]){//비율이 높다면 구매
                    user_sum+=(100-result[k])*emo[k]/100;
                    if(user_sum>=user[j][1]){
                        plus++;
                        user_sum = 0;
                        break;
                    }
                }
            }
            sum += user_sum;
        }
        result_data.push_back({plus,sum});
        return;
    }
    for(int k=0;k<4;k++){
        result[cnt]=ratio[k];
        dfs(user,emo,cnt+1);
    }
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    sz=emoticons.size();
    dfs(users,emoticons,0);
    sort(result_data.rbegin(),result_data.rend());
    
    answer.push_back(result_data[0].first);
    answer.push_back(result_data[0].second);
    return answer;
}