//[백준 c++] 11557 Yangjojang of The Year
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

struct Data
{
	char school[100];
	int Drink_Cnt;
};

int main() {
	int Test_Cnt = 0;
	int Sch_Cnt = 0 ;
	
	cin >> Test_Cnt;
	

	for (int k = 0; k < Test_Cnt; k++){
		int Max_Cur = 0;
		cin >> Sch_Cnt;
		Data* DataArr = new Data[Sch_Cnt];

		for (int j = 0; j < Sch_Cnt; j++) {
			char School_Name[100];
			int Drink_Data;
			cin >> School_Name >> Drink_Data;
			
			strcpy(DataArr[j].school,School_Name);
			DataArr[j].Drink_Cnt = Drink_Data;
			
			if (j != 0) {
				if (Drink_Data > DataArr[j - 1].Drink_Cnt) {
					Max_Cur = j;
				};
			}
			else Max_Cur = j;
		}
		cout << DataArr[Max_Cur].school << "\n";
	}
}
