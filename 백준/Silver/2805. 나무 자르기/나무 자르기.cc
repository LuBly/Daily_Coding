//[Baekjoon C++] 나무 자르기 [이분탐색]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//일일히 다 계산하면 리소스가 너무 크다.
// 규칙성 -> end를 밑으로 내리면 잘리는 양이 많아진다. (end -1 당 treeCnt만큼 증가한다.)
long long cutLength(long long mid, vector<long long> trees){
    long long res = 0;
    for(auto tree : trees){
        if(tree > mid){
            res += (tree - mid);
        }
    }

    return res;
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);    
    long long treeCnt, targetLength;
    cin >> treeCnt >> targetLength;

    vector<long long> trees(treeCnt);
    for(long long k = 0; k < treeCnt; k++){
        cin >> trees[k];
    }

    int start = 0, end = *max_element(trees.begin(), trees.end()), mid, result;

    
    //logN = log 2 * 10^9 = 9 * log2 = 10~
    while(start <= end){
        mid = (start + end) / 2;
        long long res = cutLength(mid, trees);
        if(res == targetLength){
            result = mid;
            break;
        }
        if(res > targetLength){
            result = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    cout << result;
    /*
    높이를 계산
    start 가장 낮은 나무
    end 가장 높은 나무

    나무 잘라보기, 
    end를 밑으로 내리면, 잘리는 양이 많아진다.
    start를 위로 올리면, 잘리는 양이 적어진다.

    계산한 값이 target보다 클 경우
    -> start = mid + 1;
    계산한 값이 target보다 작을 경우
    -> end = mid - 1;
    */


}