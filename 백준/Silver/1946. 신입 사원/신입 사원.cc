//[BaekJoon C++] 신입 사원 [그리디]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int test_cnt;
    cin>>test_cnt;
    for(int k=0;k<test_cnt;k++){
        int user_cnt;
        cin>>user_cnt;
        vector<pair<int,int>> data;
        //데이터 저장
        for(int j=0;j<user_cnt;j++){
            int a, b;
            cin>>a>>b;
            data.push_back({a,b});
        }
        // 데이터 가공(a기준 내림차순) 둘중 하나는 고정시켜놓고 나머지 원소로 판단.
        // ex) 일단 a를 기준으로 정렬, 동석차X
        // !선발 = 모두 떨어지는 사람
        //5 5 x
        //4 1 o
        //3 2 o
        //2 3 o
        //1 4 << 어차피 뽑히는 사람
        //자기 이후의 배열에서 second가 자기보다 작은게 하나라도 있으면 떨어지는거
        //->본인의 second값이 위에 있는 사람들의 최소값보다 작은가
        //1 4 o<< 어차피 뽑히는 사람 min =4
        //2 5 x min = 4
        //3 6 x min = 4
        //4 2 o min = 2
        //5 7 x min = 2
        //6 1 o min = 1
        //7 3 x
        sort(data.begin(),data.end()); //O(NlogN)
        int answer = user_cnt;
        int min = data[0].second;
        for(int p=1;p<user_cnt;p++){
            int cur = data[p].second;
            if(cur<min) min = cur;
            else answer--;
        }
        cout<<answer<<'\n';
    }    
}
