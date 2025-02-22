﻿#include <iostream>
#include "Game.h"
#include <string>
void CursorView(char show) {
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void diplay() {
   
    std::string art[] = {
        "▀█████████▄     ▄████████    ▄███████▄         ▄████████  ▄██████▄     ▄██████▄  ███    █▄     ▄████████  ▄█        ▄█     ▄█   ▄█▄    ▄████████ ",
        "  ███    ███   ███    ███   ███    ███        ███    ███ ███    ███   ███    ███ ███    ███   ███    ███ ███       ███    ███ ▄███▀   ███    ███ ",
        "  ███    ███   ███    █▀    ███    ███        ███    ███ ███    ███   ███    █▀  ███    ███   ███    █▀  ███       ███▌   ███▐██▀     ███    █▀  ",
        " ▄███▄▄▄██▀    ███          ███    ███       ▄███▄▄▄▄██▀ ███    ███  ▄███        ███    ███  ▄███▄▄▄     ███       ███▌  ▄█████▀     ▄███▄▄▄     ",
        "▀▀███▀▀▀██▄  ▀███████████ ▀█████████▀       ▀▀███▀▀▀▀▀   ███    ███ ▀▀███ ████▄  ███    ███ ▀▀███▀▀▀     ███       ███▌ ▀▀█████▄    ▀▀███▀▀▀     ",
        "  ███    ██▄          ███   ███             ▀███████████ ███    ███   ███    ███ ███    ███   ███    █▄  ███       ███    ███▐██▄     ███    █▄  ",
        "  ███    ███    ▄█    ███   ███               ███    ███ ███    ███   ███    ███ ███    ███   ███    ███ ███▌    ▄ ███    ███ ▀███▄   ███    ███ ",
        "▄█████████▀   ▄████████▀   ▄████▀             ███    ███  ▀██████▀    ████████▀  ████████▀    ██████████ █████▄▄██ █▀     ███   ▀█▀   ██████████ ",
        "                                              ███    ███                                                 ▀                ▀                      "
    };

    int input;
    int mod = 1;


    while (true) {
        // 출력

        system("cls");

        for (const auto& line : art) {
            std::cout << line << std::endl;
        }

        if (mod == 1) {
            std::cout << "\n\n\t\t\t\t\t\t\t▶    게임 시작\n\n\t\t\t\t\t\t\t      게임 종료";
        }
        else if (mod == 2) {
            std::cout << "\n\n\t\t\t\t\t\t\t      게임 시작\n\n\t\t\t\t\t\t\t▶    게임 종료";
        }

        input = playHelper::getCommand();

        if (input == 119 || input == 72) {
            mod = 1;
        }
        else if (input == 115 || input == 80) {
            mod = 2;
        }
        else if (input == 13) {
            if (mod == 1) {
                srand(time(0));
                Game g = Game(5);
                g.GameStart();
            }
            else {
                ExitProcess(0);
            }
        }
    }

    

    
}

int main() {
    system("mode con: cols=150 lines=20");
    CursorView(false);
    diplay();



    return 0;
}


