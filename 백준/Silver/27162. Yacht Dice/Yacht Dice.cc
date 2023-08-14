//[Baekjoon C++] Yacht Dice [구현]
#include <iostream>
#include <algorithm>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	string pedigree; // 족보
    cin>>pedigree;

    int fixedDice1, fixedDice2, fixedDice3;
    cin>> fixedDice1 >> fixedDice2 >> fixedDice3;
    
    // 12 체크, dice 종류 36 * 12 = 144*3 = 532
    int maxResult = 0;
    for(int randomDice1 = 1; randomDice1 <= 6; randomDice1++){
        for(int randomDice2 =1; randomDice2 <= 6; randomDice2++){
            // 족보 사용 여부 체크
            int dices[5] = {fixedDice1, fixedDice2, fixedDice3, randomDice1, randomDice2};
            int diceCnt[7] = {0,};
            // 주사위 눈 수별로 몇개씩 들어있는지 check
            // ex ) 1->0개, 2->3개, 3->2개, 4->0개, 5~~
            
            int sum = 0;
            for(int k = 0; k < 5; k++){
                diceCnt[dices[k]]++;
                sum += dices[k];
            }

            for(int idx = 0; idx < 12; idx++){
                if(pedigree[idx]=='N') continue;
                int result = 0;
                bool isLittleStraight = true;
                bool isBigStraight = true;

                switch(idx){
                    case 0 : // 1의 총합
                        result = diceCnt[1];
                        break;

                    case 1 : // 2의 총합
                        result = diceCnt[2] * 2;
                        break;

                    case 2 : // 3의 총합
                        result = diceCnt[3] * 3;
                        break;

                    case 3 : // 4의 총합
                        result = diceCnt[4] * 4;
                        break;

                    case 4 : // 5의 총합
                        result = diceCnt[5] * 5;
                        break;

                    case 5 : // 6의 총합
                        result = diceCnt[6] * 6;
                        break;

                    case 6 : // 같은 숫자 4개 이상
                        for(int k = 1; k <= 6; k++){
                            if(diceCnt[k]>=4){
                                result = k * 4;
                                break;
                            }
                        }
                        break;

                    case 7 : // Full House정확히 두 종류 3, 2개
                        for(int k = 1; k <= 5; k++){
                            if(diceCnt[k] == 3 || diceCnt[k] == 2){
                                for(int j = k+1; j <= 6; j++){
                                    if(diceCnt[k] + diceCnt[j] == 5){
                                        result = sum;
                                        break;
                                    }
                                }
                            }
                        }
                        break;

                    case 8 : // Little Straight 12345 조합
                        for(int k = 1; k <= 5; k++){
                            if(diceCnt[k]==1) continue;
                            else {
                                isLittleStraight = false;
                                break;
                            }
                        }
                        if(isLittleStraight) result = 30;
                        break;

                    case 9 : // Big Straight 23456 조합
                        for(int k = 2; k <= 6; k++){
                            if(diceCnt[k]==1) continue;
                            else {
                                isBigStraight = false;
                                break;
                            }
                        }
                        if(isBigStraight) result = 30;
                        break;

                    case 10 : // Yacht 같은 수 5개
                        for(int k = 1; k <= 6; k++){
                            if(diceCnt[k] == 5){
                                result = 50;
                                break;
                            }
                        }
                        break;

                    case 11 : // Choice 모든 숫자 합
                        result = sum;
                        break;
                }
                maxResult = max(maxResult, result);
            }
        }
    }

    cout<<maxResult;
}