#include <iostream>
#include <algorithm>
/*
1. �÷��̾ �ִ�
2. ��ǻ�Ͱ� �ִ�
3. ������ ����(0~9)
4. ��ǻ�ʹ� ������ ���� 3���� �޴´�
    1. ���� �����Ͱ� 2, 3, 5�� ������ ���
    2. �÷��̾ ���ǿ� ���� �����
        1. �÷��̾ 3 2 7�� �Է��� ���
        2. ��ǻ���� 2, 3, 5�� �� (�������)
        3. ���ڸ� ���ٸ� ball 
        4. ���ڵ� ���� �ڸ����� ���ٸ� ��Ʈ����ũ
        5. �ƹ��͵� ������ ���ϴ� ��� ���� �� ���ñݾ��� 2�踸ŭ ���� �Ҵ´�
5. ����
    1. ���þ�
    2. ������ : 10000���� �ִٰ� ����
    3. �翬�� �����ݺ��� ���þ��� ���� �� ����
    4. �ּ� ���ñݾ��� �ִ�.
    5. ���� ����
    6. ��Ʈ����ũ�� ���� ��� ��Ʈ����ũ�� �����ʹ� ��� ���� ���� �ݾ׿� * 2��ŭ ����
6. ���� ����
    1. �ּ� ���ñݾ׺��� ���� ������ �ִ� ���� ������ ����
    2. 10���� ��
*/

/// <summary>
/// �÷��̾ �Է��� ���� ��ȯ�ϴ� �Լ�
/// </summary>
/// <param name="arrN">�迭�� �ε���</param>
/// <returns>�Է��� ��</returns>
int Choice(int arrN);

/// <summary>
/// �÷��̾�� ��ǻ�Ͱ� ������ ���� �������� ��Ʈ����ũ�� �� ������ Ȯ���ϴ� �Լ�
/// </summary>
/// <param name="Choices">���ð��� ����ִ� �迭</param>
/// <returns>��Ʈ����ũ ����</returns>
int CountStrike(int Choices[][3]);

/// <summary>
/// �÷��̾�� ��ǻ�Ͱ� ������ ���� �������� ���� �� ������ Ȯ���ϴ� �Լ�
/// </summary>
/// <param name="Choices">���ð��� ����ִ� �迭</param>
/// <returns>���� ����</returns>
int CountBall(int Choices[][3]);

/// <summary>
/// �� �� ������ Ȯ���ϴ� �Լ�
/// </summary>
/// <param name="currentMoney">���� ���� ������ �ִ� ��</param>
/// <returns>���� �ݾ�</returns>
int Bet(int currentMoney);

/// <summary>
/// �迭�� �����ִ� �Լ�
/// </summary>
/// <param name="arr">���� �迭</param>
/// <returns>���� �迭</returns>
int* Shuffle(int arr[10]);

/// <summary>
/// �迭�� �����ִ� �Լ� 2
/// </summary>
/// <param name="arr">���� �迭</param>
void Shuffle2(int arr[10]);

int main() {

    srand(time(0));

    int money = 10000;

    std::cout << "���� �߱� �����Դϴ�" << std::endl << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << std::endl << i+1 << "��° �����Դϴ�" << std::endl;
        int numArr[10] = {0,1,2,3,4,5,6,7,8,9};
        int Choices[2][3];
        int bet = Bet(money);
        money -= bet;
        
        Shuffle2(numArr);

        //int* shuffleArr = Shuffle(numArr);

        std::cout << "���� �迭 : ";
        for (int i = 0; i < 10; i++) {
            std::cout << numArr[i];
        }
        std::cout << std::endl;

        // �÷��̾�� ��ǻ���� ����
        for (int j = 0; j < sizeof(Choices[0]) / sizeof(int); j++) {
            Choices[0][j] = Choice(j);      // �÷��̾� ����  
            Choices[1][j] = numArr[j];    // ��ǻ�� ����
            //Choices[1][j] = j;    // ��ǻ�� ����
        }

        // �÷��̾� ���� ���
        std::string text[2] = { "\n�÷��̾� : " , "\n��ǻ��\t : " };

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

        std::cout << strikeCount << " ��Ʈ����ũ, " << ballCount << " ��" << std::endl;
        
        if (strikeCount > 0) {
            std::cout << "���� ����!" << std::endl;
            money += bet * 2;
        }
        else if(ballCount > 0){
            std::cout << "���̶� �־ �����̴�(���ñ� ��������)" << std::endl;
            money += bet;
        }
        else {
            std::cout << "���� �Ҿ���.." << std::endl;
            money -= bet;
        }

        if (money < 500) {
            std::cout << "���� �� ��������";
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
    std::cout << "������ �ݾ��� �Է��� �ּ���(���� �ݾ� : " << currentMoney << " �ּ� �ݾ� 500) : ";

    while (true) {
        std::cin >> bet;
        if (currentMoney >= bet && bet >= 500) {
            break;
        }
        else {
            std::cout << "�ùٸ� �ݾ��� �Է��� �ּ���\n\n ������ �ݾ��� �Է��� �ּ��� : " << currentMoney << " �ּ� �ݾ� 500) : ";
        }
    }

    return bet;
}

int Choice(int arrN) {

    int choice;

    std::cout << arrN + 1<< "��° ���ڸ� �Է��ϼ��� (���� : 0~9) : ";
    while (true) {
        std::cin >> choice;
        if (0 <= choice && choice <= 9) {
            break;
        }
        std::cout << "0 ~ 9 ������ ������ �Է����ּ���. : ";
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
                //std::cout << "��ī��Ʈ ����" << std::endl;
                count++;
            }
        }
    }

    return count;
}

