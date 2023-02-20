//[Programmers C++] 테이블 해시 함수
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int col_data;

bool cmp(vector<int> &a,vector<int> &b){
    if(a[col_data]==b[col_data]) return a[0] > b[0];
    else return a[col_data] < b[col_data];
        
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    col_data=col-1;
    sort(data.begin(),data.end(),cmp);
    /*
    for(auto iter: data){
        for(auto in_iter: iter) cout<<in_iter<<" ";
        cout<<'\n';
    }
    */
    for(int k=row_begin;k<=row_end;k++){
        int tmp=0;
        for(int j=0;j<data[0].size();j++){
            tmp+=data[k-1][j]%k;
        }
        answer ^= tmp;
    }
    return answer;
}