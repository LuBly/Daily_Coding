//[Baekjoon C++] 어린왕자 [기하학]
#include <iostream>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int test_cnt;
    cin>>test_cnt;
    for(int k=0;k<test_cnt;k++){
        pair<int,int> st,dt;
        cin>>st.first>>st.second>>dt.first>>dt.second;
        int planetCnt;
        cin>>planetCnt;
        //원의 방정식 - (x-a)^2+(y-b)^2=r^2
        int result = 0;
        for(int j=0;j<planetCnt;j++){
            int cx,cy,r;
            cin>>cx>>cy>>r;
            int R = r*r;
            bool chkSt = ((st.first-cx)*(st.first-cx) + (st.second-cy)*(st.second-cy))<R;
            bool chkDt = ((dt.first-cx)*(dt.first-cx) + (dt.second-cy)*(dt.second-cy))<R;
            if(chkSt&&chkDt) continue; // 둘다 같은 공간에 있으면 더이상 count할 필요 없음
            if(chkSt||chkDt) result++; // 둘 중 하나가 특정 원 내부에 있을경우 나가거나 들어가는 절차 필요
        }
        cout<<result<<'\n';
    }
}