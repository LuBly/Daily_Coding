#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<int> now;
    vector<int> start;
    vector<int> date;
    vector<pair<char,int>> terms_pair;
    string tmp="";
    ////////////////////today 저장/////////////////////
    for(int a=0;a<today.size();a++){
        if(today[a]!='.') {
            tmp+=today[a];
            //cout<<tmp<<endl;
        }
        else {
            now.push_back(stoi(tmp));//2022 05 19 로 저장
            tmp="";
            continue;
        }
    }
    now.push_back(stoi(tmp));
    //////////////////////////////////////////////////
    //now [year, month, day]
    
    //terms 페어로 만들기
    for(int c=0;c<terms.size();c++){
        string term_tmp="";
        for(int d=2;d<terms[c].size();d++){
            term_tmp+=terms[c][d];
        }
        terms_pair.push_back(make_pair(terms[c].front(),stoi(term_tmp)));
    }
    /////////////////////////////////////////////////// 
    
    for(int k=0;k<privacies.size();k++){
        bool is_end = false;
        int cur = 0;
        char term;
        int limit;
        tmp="";
        for(int j=0;j<privacies[k].size();j++){//하나하나 세부항목 체크
            if(privacies[k][j]!='.'&&privacies[k][j]!=' '){//시작 연 월 일 체크
                tmp+=privacies[k][j];
            }
            else{
                date.push_back(now[cur]-stoi(tmp));
                cur++;
                tmp="";
                if(privacies[k][j]!=' ') is_end=true;
                continue;
            }
            if(is_end) term=privacies[k].back();//약관 확인
        }
        
        for(int p=0;p<terms_pair.size();p++){
            if(terms_pair[p].first==term){
                limit=terms_pair[p].second;
                break;
            }
        }
        /*
        ///////개인정보 수집 일자부터 지금까지의 시간 계산///////
        int month;
        month=date[1];
        month+=12*date[0];
        
        if(date[2]>=0) month++;
        else month--;
        /////////////////////////////////////////////////// 
        cout<<"month: "<<month<<" limit: "<<limit<<endl;
        if(month>limit) answer.push_back(k+1);
        */
        int month,day;
        int during;
        
        month=date[1];
        day=date[2];
        month+=12*date[0];
        
        if(day<0){
            month--;
            day+=28;
        }
        
        during=month*28+day;
        cout<<"during: "<<during<<" limit: "<<limit*28<<endl;
        if(during>=limit*28) answer.push_back(k+1);
        
        
        date.clear();
    }
    return answer;
}