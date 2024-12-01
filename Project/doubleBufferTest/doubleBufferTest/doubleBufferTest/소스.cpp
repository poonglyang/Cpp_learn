#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

const int WIDTH = 50;
const int HEIGHT = 20;

// 버퍼를 두 개 준비
HANDLE buffer1, buffer2;
bool activeBuffer = true; // 활성화된 버퍼 플래그

void InitDoubleBuffering() {
    // 두 개의 콘솔 버퍼 생성
    buffer1 = CreateConsoleScreenBuffer(GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    buffer2 = CreateConsoleScreenBuffer(GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    // 기본 화면 버퍼 크기 설정
    SMALL_RECT windowSize = { 0, 0, WIDTH - 1, HEIGHT - 1 };
    SetConsoleWindowInfo(buffer1, TRUE, &windowSize);
    SetConsoleWindowInfo(buffer2, TRUE, &windowSize);
}

void SwapBuffers() {
    // 활성화된 버퍼 결정
    HANDLE active = activeBuffer ? buffer1 : buffer2;
    HANDLE inactive = activeBuffer ? buffer2 : buffer1;

    // 활성화된 버퍼를 표시
    SetConsoleActiveScreenBuffer(active);
    activeBuffer = !activeBuffer; // 버퍼 스왑
}

void DrawToBuffer(HANDLE buffer, const string& content) {
    // 화면 버퍼를 지우기
    COORD coord = { 0, 0 };
    DWORD charsWritten;
    FillConsoleOutputCharacterA(buffer, ' ', WIDTH * HEIGHT, coord, &charsWritten);

    // 내용을 버퍼에 쓰기
    DWORD bytesWritten;
    WriteConsoleOutputCharacterA(buffer, content.c_str(), content.size(), coord, &bytesWritten);
}

int main() {
    InitDoubleBuffering();

    string frame1 = "Frame 1\n";
    string frame2 = "Frame 2\n";

    // 애니메이션 루프
    for (int i = 0; i < 10; i++) {
        // 현재 프레임 데이터 선택
        string content = (i % 2 == 0) ? frame1 : frame2;

        // 백그라운드 버퍼에 그리기
        HANDLE backBuffer = activeBuffer ? buffer2 : buffer1;
        DrawToBuffer(backBuffer, content);

        // 버퍼 스왑
        SwapBuffers();

        Sleep(500); // 0.5초 대기
    }

    return 0;
}
