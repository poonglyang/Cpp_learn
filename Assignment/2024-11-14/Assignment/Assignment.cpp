#include <iostream>
#include <algorithm>
/*
1. 플레이어가 있다
2. 컴퓨터가 있다
3. 숫자의 범위(0~9)
4. 컴퓨터는 임의의 숫자 3개를 받는다
    1. 만약 컴포터가 2, 3, 5가 나왔을 경우
    2. 플레이어가 조건에 따라 맞춘다
        1. 플레이어가 3 2 7을 입력한 경우
        2. 컴퓨터의 2, 3, 5를 비교 (순서대로)
        3. 숫자만 같다면 ball 
        4. 숫자도 같고 자리까지 같다면 스트라이크
        5. 아무것도 맞추지 못하는 경우 내가 건 배팅금액의 2배만큼 돈을 잃는다
5. 배팅
    1. 배팅액
    2. 소지금 : 10000원이 있다고 가정
    3. 당연히 소지금보다 배팅액이 높을 수 없다
    4. 최소 배팅금액이 있다.
    5. 따는 조건
    6. 스트라이크가 있을 경우 스트라이크의 갯수와는 상관 없이 배팅 금액에 * 2만큼 딴다
6. 종료 조건
    1. 최소 배팅금액보다 내가 가지고 있는 돈이 적으면 종료
    2. 10판을 함
*/

/// <summary>
/// 플레이어가 입력한 값을 반환하는 함수
/// </summary>
/// <param name="arrN">배열의 인덱스</param>
/// <returns>입력한 값</returns>
int Choice(int arrN);

/// <summary>
/// 플레이어와 컴퓨터가 선택한 값을 바탕으로 스트라이크가 몇 개인지 확인하는 함수
/// </summary>
/// <param name="Choices">선택값이 들어있는 배열</param>
/// <returns>스트라이크 갯수</returns>
int CountStrike(int Choices[][3]);

/// <summary>
/// 플레이어와 컴퓨터가 선택한 값을 바탕으로 볼이 몇 개인지 확인하는 함수
/// </summary>
/// <param name="Choices">선택값이 들어있는 배열</param>
/// <returns>볼의 갯수</returns>
int CountBall(int Choices[][3]);

/// <summary>
/// 얼마 걸 것인지 확인하는 함수
/// </summary>
/// <param name="currentMoney">현재 내가 가지고 있는 돈</param>
/// <returns>배팅 금액</returns>
int Bet(int currentMoney);

/// <summary>
/// 배열을 섞어주는 함수
/// </summary>
/// <param name="arr">섞을 배열</param>
/// <returns>섞인 배열</returns>
int* Shuffle(int arr[10]);

/// <summary>
/// 배열을 섞어주는 함수 2
/// </summary>
/// <param name="arr">섞을 배열</param>
void Shuffle2(int arr[10]);

int main() {

    srand(time(0));

    int money = 10000;

    std::cout << "숫자 야구 게임입니다" << std::endl << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << std::endl << i+1 << "번째 게임입니다" << std::endl;
        int numArr[10] = {0,1,2,3,4,5,6,7,8,9};
        int Choices[2][3];
        int bet = Bet(money);
        money -= bet;
        
        Shuffle2(numArr);

        //int* shuffleArr = Shuffle(numArr);

        std::cout << "섞인 배열 : ";
        for (int i = 0; i < 10; i++) {
            std::cout << numArr[i];
        }
        std::cout << std::endl;

        // 플레이어와 컴퓨터의 선택
        for (int j = 0; j < sizeof(Choices[0]) / sizeof(int); j++) {
            Choices[0][j] = Choice(j);      // 플레이어 선택  
            Choices[1][j] = numArr[j];    // 컴퓨터 선택
            //Choices[1][j] = j;    // 컴퓨터 선택
        }

        // 플레이어 선택 출력
        std::string text[2] = { "\n플레이어 : " , "\n컴퓨터\t : " };

        for (int k = 0; k < 2; k++) {
            std::cout << text[k];
            for (int j = 0; j < sizeof(Choices[0]) / sizeof(int); j++) {
                std::cout << Choices[k][j] << " ";
            }
        }

        std::cout << std::endl;
        std::cout << std::endl;


        int strikeCount = CountStrike(Choices);
        int ballCount = CountBall(Choices);

        std::cout << strikeCount << " 스트라이크, " << ballCount << " 볼" << std::endl;
        
        if (strikeCount > 0) {
            std::cout << "돈을 땄다!" << std::endl;
            money += bet * 2;
        }
        else if(ballCount > 0){
            std::cout << "볼이라도 있어서 다행이다(배팅금 돌려받음)" << std::endl;
            money += bet;
        }
        else {
            std::cout << "돈을 잃었다.." << std::endl;
            money -= bet;
        }

        if (money < 500) {
            std::cout << "돈이 다 떨어졌다";
            break;
        }

    }
}

int* Shuffle(int arr[10]) {
    int temp, index1, index2;
    for (int i = 0; i < 50; i++) {
        index1 = rand() % 10;
        index2 = rand() % 10;
        temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }
    return arr;
}

void Shuffle2(int arr[10]) {
    int temp, index1, index2;
    for (int i = 0; i < 50; i++) {
        index1 = rand() % 10;
        index2 = rand() % 10;
        temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }
}

int Bet(int currentMoney) {
    int bet;
    std::cout << "배팅할 금액을 입력해 주세요(보유 금액 : " << currentMoney << " 최소 금액 500) : ";

    while (true) {
        std::cin >> bet;
        if (currentMoney >= bet && bet >= 500) {
            break;
        }
        else {
            std::cout << "올바른 금액을 입력해 주세요\n\n 배팅할 금액을 입력해 주세요 : " << currentMoney << " 최소 금액 500) : ";
        }
    }

    return bet;
}

int Choice(int arrN) {

    int choice;

    std::cout << arrN + 1<< "번째 숫자를 입력하세요 (범위 : 0~9) : ";
    while (true) {
        std::cin >> choice;
        if (0 <= choice && choice <= 9) {
            break;
        }
        std::cout << "0 ~ 9 사이의 범위를 입력해주세요. : ";
    }

    return choice;
}

int CountStrike(int Choices[][3]) {

    int count = 0;

    for (int i = 0; i < sizeof(Choices[0]) / sizeof(int); i++) {
        if (Choices[0][i] == Choices[1][i]) {
            count++;
        }
    }
    return count;
}

int CountBall(int Choices[][3]) {
    int count = 0;
    for (int i = 0; i < sizeof(Choices[0]) / sizeof(int); i++) {
        for (int j = 0; j < sizeof(Choices[1]) / sizeof(int); j++) {
            //std::cout << i << " : " << Choices[0][i] <<", " << j << " : " << Choices[1][j] << std::endl;

            if (i != j && Choices[0][i] == Choices[1][j]) {
                //std::cout << "볼카운트 증가" << std::endl;
                count++;
            }
        }
    }

    return count;
}

