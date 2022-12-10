#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int count=0;
    vector<vector<int>> in_Data;
    cin >> count;

    for(int k =0; k < count; k++){
        int input_id, input_gas;
        vector<int> tmp;
        cin >> input_id >> input_gas;

        tmp.push_back(input_id);
        tmp.push_back(input_gas);
        in_Data.push_back(tmp);
    }

    sort(in_Data.begin(),in_Data.end());

    for(int j=0; j < count; j++){
        cout << in_Data[j][0] << " " << in_Data[j][1] << endl;
    }
}
