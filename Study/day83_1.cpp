//[BaekJoon C++] 블랙잭 [브루트 포스]
#include <iostream>
#include <vector>

using namespace std;

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int count, max, answer;
    vector<int> deck;

    cin>> count >> max;
    for(int k=0;k<count;k++){
        int num;
        cin >> num;
        deck.push_back(num);
    }
    answer=0;
    for(int a=0;a<count-2;a++){
        for(int b=a+1;b<count-1;b++){
            for(int c=b+1;c<count;c++){
                int total = deck[a]+deck[b]+deck[c];
                if(total<=max && total>answer){
                    answer=total;
                }
            }
        }
    }
    cout<<answer;
}