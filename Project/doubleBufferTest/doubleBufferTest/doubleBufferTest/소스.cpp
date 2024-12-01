#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

const int WIDTH = 50;
const int HEIGHT = 20;

// ���۸� �� �� �غ�
HANDLE buffer1, buffer2;
bool activeBuffer = true; // Ȱ��ȭ�� ���� �÷���

void InitDoubleBuffering() {
    // �� ���� �ܼ� ���� ����
    buffer1 = CreateConsoleScreenBuffer(GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    buffer2 = CreateConsoleScreenBuffer(GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    // �⺻ ȭ�� ���� ũ�� ����
    SMALL_RECT windowSize = { 0, 0, WIDTH - 1, HEIGHT - 1 };
    SetConsoleWindowInfo(buffer1, TRUE, &windowSize);
    SetConsoleWindowInfo(buffer2, TRUE, &windowSize);
}

void SwapBuffers() {
    // Ȱ��ȭ�� ���� ����
    HANDLE active = activeBuffer ? buffer1 : buffer2;
    HANDLE inactive = activeBuffer ? buffer2 : buffer1;

    // Ȱ��ȭ�� ���۸� ǥ��
    SetConsoleActiveScreenBuffer(active);
    activeBuffer = !activeBuffer; // ���� ����
}

void DrawToBuffer(HANDLE buffer, const string& content) {
    // ȭ�� ���۸� �����
    COORD coord = { 0, 0 };
    DWORD charsWritten;
    FillConsoleOutputCharacterA(buffer, ' ', WIDTH * HEIGHT, coord, &charsWritten);

    // ������ ���ۿ� ����
    DWORD bytesWritten;
    WriteConsoleOutputCharacterA(buffer, content.c_str(), content.size(), coord, &bytesWritten);
}

int main() {
    InitDoubleBuffering();

    string frame1 = "Frame 1\n";
    string frame2 = "Frame 2\n";

    // �ִϸ��̼� ����
    for (int i = 0; i < 10; i++) {
        // ���� ������ ������ ����
        string content = (i % 2 == 0) ? frame1 : frame2;

        // ��׶��� ���ۿ� �׸���
        HANDLE backBuffer = activeBuffer ? buffer2 : buffer1;
        DrawToBuffer(backBuffer, content);

        // ���� ����
        SwapBuffers();

        Sleep(500); // 0.5�� ���
    }

    return 0;
}
