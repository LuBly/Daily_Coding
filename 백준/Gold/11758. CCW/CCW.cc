//[Baekjoon C++] CCW [수학]
#include <iostream>
#include <vector>
using namespace std;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int a = x1 * y2 + x2 * y3 + x3 * y1;
	int b = y1 * x2 + y2 * x3 + y3 * x1;
	return a - b;
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    vector<pair<int,int>> lines;
    for(int k=0;k<3;k++){
        int a,b;
        cin>>a>>b;
        lines.push_back(make_pair(a,b));
    }
    int result = ccw(lines[0].first,lines[0].second,lines[1].first,lines[1].second,lines[2].first,lines[2].second);
    
    if(result>0) cout<<1;
    else if(result==0) cout<<0;
    else cout<<-1;
}