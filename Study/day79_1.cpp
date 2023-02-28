//[BaekJoon C++] 구간 합 구하기 5 [누적 합]
#include <iostream>
#include <vector>
using namespace std;

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int size,count;
    vector<vector<int>> mat;

    cin>>size>>count;
    for(int k=0;k<size;k++){//2차원 배열 선언 , 각 Line별로 누적합 계산
        vector<int> tmp;
        int sum=0;
        for(int j=0;j<size;j++){
            int input;
            cin>>input;
            sum+=input;
            tmp.push_back(sum);
        }
        mat.push_back(tmp);
    }
    
    for(int j=0;j<count;j++){
        int x_1,x_2,y_1,y_2;
        int result = 0;

        cin>>x_1>>y_1>>x_2>>y_2;

        if(y_1!=1){//x_1->y_1,
            for(int x=x_1;x<=x_2;x++){
                result += mat[x-1][y_2-1]-mat[x-1][y_1-2];
            }
        }
        else{
            for(int x=x_1;x<=x_2;x++) 
                result += mat[x-1][y_2-1];
        }

        cout<<result<<'\n';
    }
}