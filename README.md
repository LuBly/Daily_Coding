# Daily_Coding

VS Code c++ 셋팅 

https://jhnyang.tistory.com/440

오늘의 교훈 : 안될 때는 초기화를 하자.

## 사용한 함수
- #include <algorithm> 의 sort() 함수 > quick sort 방식을 자동적으로 적용시켜줌
- sort의 Unique 함수 - 중복되는 원소들을 뒤로 빼는 함수
- string to int 
1. stoi(str)
2. sstream의 stringstream과 getline을 활용
```c++
    istringstream ss(s);
    while (getline(ss, stringBuffer, ' '))
    {
        int tmp;
        stringstream ssInt(stringBuffer);
        ssInt >> tmp;
        num.push_back(tmp);
    }
```
- int to string > 

## 개념
- 행렬의 곱셈 -> 간단하지만 생각외로 복잡했다. 
```c++
for(int a = 0; a < arr1.size(); a++){
        vector<int> row;
        for(int b = 0; b < arr2[0].size(); b++){
            int row_tmp = 0;
            for(int c = 0; c < arr2.size(); c++){
                row_tmp += arr1[a][c]*arr2[c][b];//이 부분에서 계산을 위해 arr1의 a, arr2의 b를 가져와야한다
            }
            row.push_back(row_tmp);    
        }
        answer.push_back(row);
    }
```

