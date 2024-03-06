#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int MakeTimeToInt(string time){
    int hour = stoi(time.substr(0,2));
    int min = stoi(time.substr(3,2));
    
    return hour*60 + min;
}

string MakeIntToTime(int time){
    string res = "";
    if(time/60 < 10) res += "0";
    res += to_string(time/60);
    res += ":";
    if(time%60 < 10) res += "0";
    res += to_string(time%60);
    
    return res;
}
/* [시뮬레이션]
int형 배열에 도착 시간에 따른 인원 수 저장
1. 출발시간 9시 고정
2. 시간 간격 t
3. 횟수 n
4. 탑승 정원 m

출발 시간 = 9 + t*n
timetable중 출발시간 이전에 도착한 인원 전부 탑승
셔틀 출발시간 고정
셔틀 출발시간 이전에 온 인원들 전원 탑승

[priority queue활용]
timetable 오름차순 정렬 -> queue에 데이터입력

if(다음 회차버스가 있을 경우)
탑승가능한 인원만큼 pop()
else(다음 회차 버스가 없을 경우)
탑승가능한 인원만큼 pop() -> 배열에 저장
저장된 배열의 크기가 탑승정원보다 클 경우 저장된 배열 값중 가장 작은 값-> min(arr[0], start) -1 가 정답
*/

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int k = 0; k < timetable.size(); k++){
        pq.push(MakeTimeToInt(timetable[k])); 
    }
    int start = 540; // 09 : 00
    
    //다음에 탈 차량이 있는 경우 인원들 미리 다 빼놓기
    while(n>1){
        int maxP = m;
        //차량에 인원 탑승
        while(true){
            if(maxP == 0 || pq.empty()) break;
            
            int curTime = pq.top();
            if(curTime <= start){
                pq.pop();    
                maxP--;
            }
            else break;
        }
        start += t;
        n--;
    }
    
    // 이제 더 이상 올 차량이 없을 경우
    int maxP = m;
    vector<int> last;
    vector<int> map(24*60, 0);
    //차량에 인원 탑승
    while(true){
        if(maxP == 0 || pq.empty()) break;

        int curTime = pq.top();
        if(curTime <= start){
            last.push_back(curTime);
            map[curTime]++;
            pq.pop();    
            maxP--;
        }
        else break;
    }
    
    if(last.size() < m){
        answer = MakeIntToTime(start);
    }
    
    else{
        int ansTime = 1;
        int cnt = 0;
        while(true){
            if(cnt == m) break;
            cnt += map[ansTime++];
        }
        answer = MakeIntToTime(ansTime - 2);
    }
        
    return answer;
}