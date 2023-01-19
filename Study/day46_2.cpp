//[Programmers C++] 주차 요금 계산
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string,string> io_map;//차량번호(키), 시간
    map<string,int> fee;//차량 번호, 시간
    //vector<pair<string,string> > park_data;//차량 번호 ,in //마지막에 남아있는 차량 계산 위해서
    for(int a=0;a<records.size();a++){
        int cur=0;
        string tmp="";
        string time="";
        string car_num="";
        for(int b=0;b<records[a].size();b++){
            if(records[a][b]!=' ') tmp+=records[a][b];
            else{
                if(cur==0) {
                    time+=tmp;
                    cur++;
                    tmp="";
                }
                else if(cur==1){
                    car_num+=tmp;
                    cur++;
                    tmp="";
                }
            }
        }
        if(tmp.compare("OUT")==0){//나갈 때 차량 fee 계산
            string hour_str_Now="";
            string min_str_Now="";
            string hour_str_Before="";
            string min_str_Before="";
            for(int c=0;c<2;c++){
                hour_str_Now+=time[c];
                hour_str_Before+=io_map[car_num][c];
            }
            for(int d=3;d<=4;d++){
                min_str_Now+=time[d];
                min_str_Before+=io_map[car_num][d];
            }
            int hour = stoi(hour_str_Now)-stoi(hour_str_Before);
            int min = (60*hour)+stoi(min_str_Now)-stoi(min_str_Before);//총 주차 시간
            
            if(fee[car_num]==0) fee[car_num]=min;
            else fee[car_num]+=min;
            
            io_map.erase(car_num);
            //cout<<"carnum: "<<car_num<<" min: "<<min<<endl;
        }
        else io_map[car_num]=time;//들어온 차량의 번호와 시간 계산
    }
    if(!io_map.empty()){//map에 차가 남아있을 때 io_map;//차량번호(키), 시간
        for(auto iter:io_map){
            string car="";
            string H="";
            string M="";
            car+=iter.first;
            for(int e=0;e<2;e++){
                H+=io_map[car][e];
            }
            for(int f=3;f<=4;f++){
                M+=io_map[car][f];
            }
            int h=23-stoi(H);
            int m=(h*60)+59-stoi(M);
            fee[car]+=m;
        }
    }
    for(auto iter:fee){//fees -> 기본시간, 기본요금, 단위시간, 단위요금
        int payment;
        if(iter.second>fees[0]) {
            int cal=((iter.second-fees[0])%fees[2]==0)?(iter.second-fees[0])/fees[2]:((iter.second-fees[0])/fees[2])+1;
            payment=fees[1]+cal*fees[3];
        }
        else payment = fees[1];
        answer.push_back(payment);
    }
    return answer;
}