//피파 강화 기대값 계산기
#include <iostream>
#include <stdlib.h>//rand 함수를 사용하기 위해 사용
#include <time.h>//srand(Time(NULL))을 사용하기 위해 사용 << 함수 호출 때마다 다른 값을 불러와주는 역할
#include <cmath>
#include <vector>
#include <algorithm>
#define range 10000
#define MAX 100000000
using namespace std;

int main() {
    //4강까지의 기대값(강화 횟수)
    //무식하게 10000만번의 강화
    //4카까지 강화 확률을 구해보자
    //10000번의 4카강화
    //성공 실패만 판단
    //강화 시도는 random함수를 활용하여 진행, bit 연산 미스가 날 수 있으니. float값이 아닌 정수로 진행
    //소숫점이 나올 수 있는 나눗셈은 최대한 생략
    //랜덤 변수의 범위는 1,000,000
    // 1->2 100% 부스트 77.83// 최종 확률 -> 100*78(반올림 계산) -> 확률 778300/1000000 rand() 범위 1,000,000
    // 2->3 81% 부스트 69.34// 최종 확률 ->81*70(반올림 계산)<<변동 가능 
    // 3->4 64% 부스트 69.58// 최종 확률 ->64*70(반올림 계산)<<변동 가능
    
    int cnt=0, limit=10000000;            // limit횟수 만큼 강화를 시도
    int percentage[3]={100, 81, 64};    // 강화 확률 고정
    //반올림을 계산하기위해 floor(N+0.5)를 사용
    int boost[3]={(int)floor(3+0.5),(int)floor(92.85+0.5),(int)floor(69.58+0.5)};
    int cost[3]={10,10,20};
    // 근데 이건 1->4가 원트에 올라가는 걸 가정하는 것이 아닌가? 대략 23~4프로 나오는 것을 확인
    // 4카까지 대략 몇 번의 트라이를 진행하는지 가정?
    // 평균적인 강화 비용을 계산해보자
    // 4카를 만들 때 드는 비용들을 계산해서 평균을 내보자.
    // 극한의 확률로 인해 TLE가 터지는 것을 방지하기 위해 최대 수행 횟수를 100,000,000으로 제한
    
    // 입력 값 생성
    // 차후에 104 105 106 107 108 부스트 수치를 추가하고 최소 강화 비용으로 최대의 부스트를 뽑는 알고리즘 작성해보자.
    for(int k=0;k<3;k++){
        // 강화 부스트 수치
        float input;
        cout<<(k+1)<<"->"<<(k+2)<< "카 강화 부스트 수치를 입력하세요 : ";
        cin>>input;
        boost[k]=(int)floor(input+0.5);
        // 강화 비용 계산
        cout<<(k+1)<<"->"<<(k+2)<< "카 강화 비용을 입력하세요 : ";
        cin>>cost[k];
    }
    int try_cnt=0; // 4카를 만드는데 실패한 횟수
    int try_max=0; // 4카를 만드는데 실패한 최대 횟수를 저장하기 위한 변수

    int cost_sum=0;// 4카 제작 비용 총 합 >> refactoring 시에 더하는 과정을 마지막에 한번만 진행하게 할 수 있을 듯?
    int cost_max=0;// 4카 제작 1트에 사용한 최대 금액을 저장하기 위한 변수
    int cost_try=0;// 4카 제작 1트에 사용한 비용.

    int try_over=0;
    srand(time(NULL));
    vector<int> cost_mid;
    //10만번 4카를 만들때 드는 비용의 평균 값 계산
    while(cnt<limit){
        try_cnt++;
        try_over++;
        if(try_over>MAX){
            cout<<"Wrong"<<endl;
            return 0;
        }
        int one2two = rand()%range;
        cost_sum+=cost[0];//2카 강화 시도 비용
        cost_try+=cost[0];
        if(one2two > percentage[0]*boost[0])//실패시 아웃
            continue;
        
        int two2three = rand()%range;
        cost_sum+=cost[1];//3카 강화 시도 비용
        cost_try+=cost[1];
        if(two2three > percentage[1]*boost[1])//실패시 아웃
            continue;
        int three2four = rand()%range;
        cost_sum+=cost[2];//4카 강화 시도 비용
        cost_try+=cost[2];
        if(three2four > percentage[2]*boost[2])//실패시 아웃
            continue;
        
        //모두 통과해서 건너왔을 때 4카가 됐음을 의미함.
        cost_mid.push_back(cost_try);
        cost_max = cost_max>cost_try ? cost_max : cost_try;
        try_max = try_max>try_cnt ? try_max : try_cnt;
        try_cnt=0;
        cost_try=0;
        cnt++;
    }
    sort(cost_mid.begin(),cost_mid.end());
    cout<<"평균 강화 비용 : "<<cost_sum/cnt<<" 중간값 : "<<cost_mid[cnt/2]<<" 최대 강화 비용: "<<cost_max<<" 최대 강화 횟수 : "<<try_max<<endl;//1회당 평균적인 강화비용.
    //결론 -> 전부 1복이라고 가정했을 때 103, 105, 107로의 4카 강화의 기대값은 77억
    //결론 -> 104, 106, 108 4카 강화 기대값 127억
    //
    /* 한방에 4카까지 성공하는 확률
    while(cnt<limit){//약 1만번의 강화 시도
        //1카->2카 강화
        cnt++;
        int one2two = rand()%range;
        if(one2two > percentage[0]*boost[0])//실패시 아웃
            continue;
        int two2three = rand()%range;
        if(two2three > percentage[1]*boost[1])//실패시 아웃
            continue;
        int three2four = rand()%range;
        if(three2four > percentage[2]*boost[2])//실패시 아웃
            continue;
        success++;
    }
    cout<<success;
    */
}