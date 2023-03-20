# Daily_Coding

VS Code c++ 셋팅 

https://jhnyang.tistory.com/440

오늘의 교훈 : 안될 때는 초기화를 하자.
문제에서 주는대로 생각 + 창의적으로 문제를 해결하려는 생각

230321 백준허브(BaekjoonHub)를 사용하여 코드 제출 시 해당 문제와 코드를 자동으로 github에 연동하는 기능 사용.

## 사용한 함수
- sort() 함수 > quick sort 방식을 자동적으로 적용시켜줌
- Unique - 중복되는 원소들을 뒤로 빼는 함수
- string to int 
    - stoi(str)
    - sstream의 stringstream과 getline을 활용
- int to string 
    - string 라이브러리의 to_string()함수 활용
- pow_제곱, sqrt_제곱근 함수
- bitset 라이브러리의 bitset<비트사이즈> 변수명
    - 비트사이즈가 고정된 상태
- strcasecmp(str A.c_str(), str B.c_str()); 
    - 대소문자를 구별하지 않고 문자열 비교
- priority_queue<타입, 구조, 함수> 
    - 우선순위에 따라 queue를 정렬해줌
- next_permutation(arr.begin(), arr.end())
    - 오름차순으로 순열을 구해줌. (완전 탐색에서 활용 가능, 하지만 모든 경우의 수를 구하는 만큼 시간복잡도가 높음)

## 사용한 라이브러리
- algorithm
    - sort
    - min, max
    - unique
    - erase
    - next_permutation
- map 
    - map<key,value> 키 값을 기준으로 데이터를 저장 많은 데이터들을 저장하고 열람하기에 용이함.
- set
    - 데이터들을 중복없이 저장하기에 용이함 ex)set(string) 하면 자동으로 중복된 string 값들을 제거함.
- queue
    - priority_queue
- cstring
    - strcasecmp
- cmath
    - pow, sqrt


    
## 개념
- 행렬의 곱셈
- 제곱, 제곱근
- 최대공약수 : 유클리드 호제법 //day14_1멀쩡한 사각형
- 2진수 만들기 //day18_1 숫자의 표현
- 재귀함수는 편리하긴 하지만, 반복문에 비해 반복작업 속도가 느리다.
- 모듈러 함수 공식 **(A + B) % C ≡ ( ( A % C ) + ( B % C) ) % C**
- Stack (First In Last Out)
- map

