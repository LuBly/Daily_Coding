//[BaekJoon C++] 최소비용 구하기 [구현]
#include <iostream>
#include <map>
using namespace std;



int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int aCnt, numCnt;
    cin >> aCnt;
    
    map<int,int> mp;
    for(int k = 0; k < aCnt; k++){
        int num;
        cin >> num;
        mp[num]++;
    }

    cin >> numCnt;
    /*
    오름차순 정렬을하고
    check
    */
    for(int k = 0; k < numCnt; k++){
        int num;
        cin >> num;
        if(mp[num] > 0)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    
}   
