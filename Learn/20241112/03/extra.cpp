#include <iostream>
using namespace std;

// ����� ����! IDE�� ���� �¾Ҵ��� ��� Ȯ�ο����θ� ����Ұ�

// ���� 2441
/*
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        for (int j = 1; j <= i*2-1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}
*/

// ���� 2442
/*
int main() {
    int n;
    cin >> n;
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        for (int j = 1; j <= i * 2 - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}
*/

// ���� 2443
/*
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        for (int j = 1; j <= i * 2 - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = n-1; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        for (int j = 1; j <= i * 2 - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}
*/

// ���� 2444
/*
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        for (int j = n - i -1; j > 0; j--)
            cout << " ";

        for (int j = n - i -1; j > 0; j--)
            cout << " ";

        for (int j = 0; j <= i; j++) {
            cout << "*";
        }

        cout << endl;
    }
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        for (int j = n - i; j > 0; j--)
            cout << " ";

        for (int j = n - i; j > 0; j--)
            cout << " ";

        for (int j = 0; j < i; j++) {
            cout << "*";
        }

        cout << endl;
    }
}
*/

// ���� 2445
/*
in main() {
    int n;
    std::cin >> n;

    for (int i = n; i > 0; i--) {
        for (int j = 0; j < n - i; j++) {
            std::cout << " ";
        }
        for (int j = 0; j < i * 2 - 1; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = n - i; j > 0; j--) {
            std::cout << " ";
        }
        for (int j = 0; j < i * 2 - 1; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

*/

int main() {
    int num1 = 28;
    int num2 = 11;

    std::cout << (num1 | num2) << std::endl;
}