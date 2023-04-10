//[Baekjoon C++] 두 수의 합 [투 포인터]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> num;
int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int num_size, target;
    cin>>num_size;
    for(int k=0;k<num_size;k++){
        int tmp;
        cin>>tmp;
        num.push_back(tmp);
    }
    cin>>target;

    sort(num.begin(),num.end());
    int head=num_size-1,tail=0,cnt=0;//head 끝, tail 시작
    while(head>tail){
        int sum = num[head]+num[tail];
        if(sum==target){//sum이 target이랑 같을 때
            cnt++;
            head--;
            tail++;
        }
        else if(sum<target)//sum이 target보다 작을 때 => 작은값을 키워준다
            tail++;
        else//sum이 target보다 클 때 => 큰값을 줄여준다
            head--;
    }
    cout<<cnt;
}