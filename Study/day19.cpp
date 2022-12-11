#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> tmp;
    int answer = 0;
    int mod = 1234567;
    tmp.push_back(0);//n=1, index = 0
    tmp.push_back(1);//n=2, index = 1
    for(int k=2; k<=n; k++){
        tmp.push_back((tmp[k-1]%mod+tmp[k-2]%mod)%mod);
    }
    answer = tmp[n];
    return answer;
}