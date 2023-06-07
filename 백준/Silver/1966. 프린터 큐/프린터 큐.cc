//[BaekJoon C++] 프린터 큐 [구현]
#include <iostream>
#include <queue>
using namespace std;

//1. 현재 Queue에 있는 가장 앞에 있는 문서의 중요도 체크
//2. 나머지 문서들 중 현재 문서보다 중요도가 높은 문서가 있다면
//-> 현재 문서가 최대값이 아니라면 ==>Priority Queue를 사용?
//-> Queue의 가장 뒤에 재배치한다.
int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int test_cnt;//테스트 케이스의 수
    cin>>test_cnt;
    //Test case 하나씩 진행
    for(int k=0;k<test_cnt;k++){
        int docu_size, docu_idx;//문서의 갯수, 찾고자 하는 문서의 idx
        cin>>docu_size>>docu_idx;

        //최대값 계산을 위한 priority queue + 테스트 케이스별로 각각 존재해야하므로 반복문 내에 존재
        priority_queue<int> pq;
        //원하는 문서가 언제 출력되는지 확인하기 위한 queue
        queue<pair<int,int>> q; // 중요도, idx

        //데이터 입력받기
        for(int idx=0;idx<docu_size;idx++){
            int num;
            cin>>num;
            pq.push(num);
            q.push({num,idx});
        }
        int answer = 0;

        //인쇄작업 시작
        while(!q.empty()){
            //현재 확인하고 있는 문서의 중요도가 max값인지 check
            int cur_num = q.front().first;
            int cur_idx = q.front().second;
            q.pop();
            if(cur_num == pq.top()){//최대값이라면 출력
                answer++;// 출력 순서 ++
                pq.pop();// 최대값 갱신
                if(cur_idx==docu_idx){//출력되는 문서가 원하는 문서라면 해당 문서의 출력 순서 출력
                    cout<<answer<<'\n';
                    break;
                }
            }
            else
                q.push({cur_num,cur_idx});//최대값이 아니면 앞에서 pop했던 값을 다시 뒤에 push
        }
    }
}
