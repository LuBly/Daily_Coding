//���� ��ȭ ��밪 ����
#include <iostream>
#include <stdlib.h>//rand �Լ��� ����ϱ� ���� ���
#include <time.h>//srand(Time(NULL))�� ����ϱ� ���� ��� << �Լ� ȣ�� ������ �ٸ� ���� �ҷ����ִ� ����
#include <cmath>
#include <vector>
#include <algorithm>
#define range 10000
#define MAX 100000000
using namespace std;

int main() {
    //4�������� ��밪(��ȭ Ƚ��)
    //�����ϰ� 10000������ ��ȭ
    //4ī���� ��ȭ Ȯ���� ���غ���
    //10000���� 4ī��ȭ
    //���� ���и� �Ǵ�
    //��ȭ �õ��� random�Լ��� Ȱ���Ͽ� ����, bit ���� �̽��� �� �� ������. float���� �ƴ� ������ ����
    //�Ҽ����� ���� �� �ִ� �������� �ִ��� ����
    //���� ������ ������ 1,000,000
    // 1->2 100% �ν�Ʈ 77.83// ���� Ȯ�� -> 100*78(�ݿø� ���) -> Ȯ�� 778300/1000000 rand() ���� 1,000,000
    // 2->3 81% �ν�Ʈ 69.34// ���� Ȯ�� ->81*70(�ݿø� ���)<<���� ���� 
    // 3->4 64% �ν�Ʈ 69.58// ���� Ȯ�� ->64*70(�ݿø� ���)<<���� ����
    
    int cnt=0, limit=10000000;            // limitȽ�� ��ŭ ��ȭ�� �õ�
    int percentage[3]={100, 81, 64};    // ��ȭ Ȯ�� ����
    //�ݿø��� ����ϱ����� floor(N+0.5)�� ���
    int boost[3]={(int)floor(3+0.5),(int)floor(92.85+0.5),(int)floor(69.58+0.5)};
    int cost[3]={10,10,20};
    // �ٵ� �̰� 1->4�� ��Ʈ�� �ö󰡴� �� �����ϴ� ���� �ƴѰ�? �뷫 23~4���� ������ ���� Ȯ��
    // 4ī���� �뷫 �� ���� Ʈ���̸� �����ϴ��� ����?
    // ������� ��ȭ ����� ����غ���
    // 4ī�� ���� �� ��� ������ ����ؼ� ����� ������.
    // ������ Ȯ���� ���� TLE�� ������ ���� �����ϱ� ���� �ִ� ���� Ƚ���� 100,000,000���� ����
    
    // �Է� �� ����
    // ���Ŀ� 104 105 106 107 108 �ν�Ʈ ��ġ�� �߰��ϰ� �ּ� ��ȭ ������� �ִ��� �ν�Ʈ�� �̴� �˰��� �ۼ��غ���.
    for(int k=0;k<3;k++){
        // ��ȭ �ν�Ʈ ��ġ
        float input;
        cout<<(k+1)<<"->"<<(k+2)<< "ī ��ȭ �ν�Ʈ ��ġ�� �Է��ϼ��� : ";
        cin>>input;
        boost[k]=(int)floor(input+0.5);
        // ��ȭ ��� ���
        cout<<(k+1)<<"->"<<(k+2)<< "ī ��ȭ ����� �Է��ϼ��� : ";
        cin>>cost[k];
    }
    int try_cnt=0; // 4ī�� ����µ� ������ Ƚ��
    int try_max=0; // 4ī�� ����µ� ������ �ִ� Ƚ���� �����ϱ� ���� ����

    int cost_sum=0;// 4ī ���� ��� �� �� >> refactoring �ÿ� ���ϴ� ������ �������� �ѹ��� �����ϰ� �� �� ���� ��?
    int cost_max=0;// 4ī ���� 1Ʈ�� ����� �ִ� �ݾ��� �����ϱ� ���� ����
    int cost_try=0;// 4ī ���� 1Ʈ�� ����� ���.

    int try_over=0;
    srand(time(NULL));
    vector<int> cost_mid;
    //10���� 4ī�� ���鶧 ��� ����� ��� �� ���
    while(cnt<limit){
        try_cnt++;
        try_over++;
        if(try_over>MAX){
            cout<<"Wrong"<<endl;
            return 0;
        }
        int one2two = rand()%range;
        cost_sum+=cost[0];//2ī ��ȭ �õ� ���
        cost_try+=cost[0];
        if(one2two > percentage[0]*boost[0])//���н� �ƿ�
            continue;
        
        int two2three = rand()%range;
        cost_sum+=cost[1];//3ī ��ȭ �õ� ���
        cost_try+=cost[1];
        if(two2three > percentage[1]*boost[1])//���н� �ƿ�
            continue;
        int three2four = rand()%range;
        cost_sum+=cost[2];//4ī ��ȭ �õ� ���
        cost_try+=cost[2];
        if(three2four > percentage[2]*boost[2])//���н� �ƿ�
            continue;
        
        //��� ����ؼ� �ǳʿ��� �� 4ī�� ������ �ǹ���.
        cost_mid.push_back(cost_try);
        cost_max = cost_max>cost_try ? cost_max : cost_try;
        try_max = try_max>try_cnt ? try_max : try_cnt;
        try_cnt=0;
        cost_try=0;
        cnt++;
    }
    sort(cost_mid.begin(),cost_mid.end());
    cout<<"��� ��ȭ ��� : "<<cost_sum/cnt<<" �߰��� : "<<cost_mid[cnt/2]<<" �ִ� ��ȭ ���: "<<cost_max<<" �ִ� ��ȭ Ƚ�� : "<<try_max<<endl;//1ȸ�� ������� ��ȭ���.
    //��� -> ���� 1���̶�� �������� �� 103, 105, 107���� 4ī ��ȭ�� ��밪�� 77��
    //��� -> 104, 106, 108 4ī ��ȭ ��밪 127��
    //
    /* �ѹ濡 4ī���� �����ϴ� Ȯ��
    while(cnt<limit){//�� 1������ ��ȭ �õ�
        //1ī->2ī ��ȭ
        cnt++;
        int one2two = rand()%range;
        if(one2two > percentage[0]*boost[0])//���н� �ƿ�
            continue;
        int two2three = rand()%range;
        if(two2three > percentage[1]*boost[1])//���н� �ƿ�
            continue;
        int three2four = rand()%range;
        if(three2four > percentage[2]*boost[2])//���н� �ƿ�
            continue;
        success++;
    }
    cout<<success;
    */
}