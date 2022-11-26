//[백준 c++] 1408 24
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main() {
	char Cur_Time[9];
	char Start_Time[9];
	vector<char> R_H_String;
	vector<char> R_M_String;
	vector<char> R_S_String;
	vector<int> Cur;
	vector<int> Start;
	int Current_Cur = 0; 
	int Start_Cur = 0;

	cin.getline(Cur_Time, 9);
	cin.getline(Start_Time, 9);
	
	char* cur_ptr = strtok(Cur_Time, ":");
		
	while (cur_ptr != NULL) {
		int cur_int = (cur_ptr[0]-'0') * 10 + (cur_ptr[1]-'0');
		Cur.push_back(cur_int);
		cur_ptr = strtok(NULL, ":");
	}
	int Cur_Hour = Cur[0];
	int Cur_Min = Cur[1];
	int Cur_Sec = Cur[2];

	char* start_ptr = strtok(Start_Time, ":");

	while (start_ptr != NULL) {
		int start_int = (start_ptr[0] - '0') * 10 + (start_ptr[1] - '0');
		Start.push_back(start_int);
		start_ptr = strtok(NULL, ":");
	}
	int Start_Hour = Start[0];
	int Start_Min = Start[1];
	int Start_Sec = Start[2];
	
	int R_Hour = Start_Hour - Cur_Hour;
	int R_Min = Start_Min - Cur_Min;
	int R_Sec = Start_Sec - Cur_Sec;

	if (R_Sec < 0) {
		R_Sec += 60;
		R_Min -= 1;
	}
	if (R_Min < 0) {
		R_Min += 60;
		R_Hour -= 1;
	}
	if (R_Hour < 0) {
		R_Hour += 24;
	}
	
	cout.width(2); cout.fill('0');
	cout << R_Hour << ":";
	cout.width(2); cout.fill('0');
	cout << R_Min << ":";
	cout.width(2); cout.fill('0');
	cout << R_Sec << endl;

}
