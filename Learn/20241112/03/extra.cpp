#include <iostream>
using namespace std;

// 별찍기 모음! IDE는 내가 맞았는지 출력 확인용으로만 사용할것

// 백준 2441
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

// 백준 2442
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

// 백준 2443
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

// 백준 2444
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

// 백준 2445
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