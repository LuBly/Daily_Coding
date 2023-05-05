#include <string>
#include <vector>

using namespace std;
// 길이를 절반씩 쪼개면서 압축되는지 마는지 check
// 압축되면 z_cnt or f_cnt++
// 길이가 1이되면 반복 종료.

int z_cnt=0, f_cnt=0;
void check(vector<vector<int>> array, int length){
    if(length<1) return;
    // 좌 상단부터 체크
    // 절반씩 쪼개서 전부 같은 숫자면 패스
    // 하나라도 다른 숫자면 재귀
    length/=2;
    int pt1 = array[0][0], pt2 = array[0][length], pt3 = array[length][0], pt4 = array[length][length];
    
    // 좌상단 체크
    vector<vector<int>> arr1;
    bool is_end1 = true;
    for(int y=0;y<length;y++){
        vector<int> tmp;
        for(int x=0;x<length;x++){
            tmp.push_back(array[y][x]);
            if(array[y][x]!=pt1)    // 하나라도 다른 원소가 있다면
                is_end1 = false;    // 계속 반복
        }
        arr1.push_back(tmp);
    }
    if(!is_end1) check(arr1,length);//재귀 반복
    else pt1==0 ? z_cnt++ : f_cnt++;
    // 좌상단 체크 끝
    
    // 우상단 체크
    vector<vector<int>> arr2;
    bool is_end2 = true;
    for(int y=0;y<length;y++){
        vector<int> tmp;
        for(int x=length;x<length*2;x++){
            tmp.push_back(array[y][x]);
            if(array[y][x]!=pt2)    // 하나라도 다른 원소가 있다면
                is_end2 = false;    // 계속 반복
        }
        arr2.push_back(tmp);
    }
    if(!is_end2) check(arr2,length);//재귀 반복
    else pt2==0 ? z_cnt++ : f_cnt++;
    // 우상단 체크 끝
    
    // 좌하단 체크
    vector<vector<int>> arr3;
    bool is_end3 = true;
    for(int y=length;y<length*2;y++){
        vector<int> tmp;
        for(int x=0;x<length;x++){
            tmp.push_back(array[y][x]);
            if(array[y][x]!=pt3)    // 하나라도 다른 원소가 있다면
                is_end3 = false;    // 계속 반복
        }
        arr3.push_back(tmp);
    }
    if(!is_end3) check(arr3,length);//재귀 반복
    else pt3==0 ? z_cnt++ : f_cnt++;
    // 좌하단 체크 끝
    
    // 좌하단 체크
    vector<vector<int>> arr4;
    bool is_end4 = true;
    for(int y=length;y<length*2;y++){
        vector<int> tmp;
        for(int x=length;x<length*2;x++){
            tmp.push_back(array[y][x]);
            if(array[y][x]!=pt4)    // 하나라도 다른 원소가 있다면
                is_end4 = false;    // 계속 반복
        }
        arr4.push_back(tmp);
    }
    if(!is_end4) check(arr4,length);//재귀 반복
    else pt4==0 ? z_cnt++ : f_cnt++;
    // 좌하단 체크 끝
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int cur = arr[0][0];
    bool all_same = true;
    for(int y=0;y<arr.size();y++){
        for(int x=0;x<arr.size();x++){
            if(arr[x][y]!=cur) {
                all_same = false; 
                break;
            }
        }
        if(!all_same) break;
    }
    if(all_same)
        cur==0 ? z_cnt++ : f_cnt++;
    else
        check(arr,arr.size());
    
    answer.push_back(z_cnt);
    answer.push_back(f_cnt);
    return answer;
}