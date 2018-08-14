#ifndef TOOLS_H
#define TOOLS_H

#include <windows.h>

enum colors
{
    YELLOW = 14,
    ORANGE = 13,
    BLUE = 9,
    RED = 12,
    GREEN = 10,
    WHITE = 15,
    DEFAULT = 7
};

inline void gotoxy(short x, short y)
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

inline void textcolor(WORD col)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}

#endif
