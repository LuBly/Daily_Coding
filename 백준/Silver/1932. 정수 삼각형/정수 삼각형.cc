//[BaekJoon C++] 정수 삼각형 [DP]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int line;
    cin>>line;
    vector<vector<int>> triangle;
    //삼각형 입력받기
    for(int k=0;k<line;k++){    
        //vector을 생성하고 줄에 해당하는 수만큼 숫자 입력
        vector<int> input;
        for(int j=0;j<k+1;j++){
            int a;
            cin>>a;
            input.push_back(a);
        }
        triangle.push_back(input);
    }
    
    for(int k=1;k<line;k++){
        for(int idx=0;idx<triangle[k].size();idx++){
            if(idx==0) triangle[k][idx]+=triangle[k-1][idx];
            else if(idx==triangle[k].size()-1) triangle[k][idx]+=triangle[k-1][idx-1];
            else triangle[k][idx]+=max(triangle[k-1][idx],triangle[k-1][idx-1]);
        }
    }

    //계산된 triangle의 마지막 줄만 따로 저장
    vector<int> result = triangle.back();
    //내림차순 정렬
    sort(result.rbegin(),result.rend()); 
    cout<<result[0];
}
