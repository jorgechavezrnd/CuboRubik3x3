#include "cube.h"
#include <stdio.h>
#include <string.h>
#include "tools.h"

void reset_cube(char cube[][3][3])
{
    char newCube[6][3][3]= {
                            {
                                { 'W', 'W', 'W' },
                                { 'W', 'W', 'W' },
                                { 'W', 'W', 'W' }
                            },
    {
        { 'O', 'O', 'O' },
        { 'O', 'O', 'O' },
        { 'O', 'O', 'O' }
    },
                            {
                                { 'G', 'G', 'G' },
                                { 'G', 'G', 'G' },
                                { 'G', 'G', 'G' }
                            },
                                                    {
                                                        { 'R', 'R', 'R' },
                                                        { 'R', 'R', 'R' },
                                                        { 'R', 'R', 'R' }
                                                    },
                                                                            {
                                                                                { 'B', 'B', 'B' },
                                                                                { 'B', 'B', 'B' },
                                                                                { 'B', 'B', 'B' }
                                                                            },
                            {
                                { 'Y', 'Y', 'Y' },
                                { 'Y', 'Y', 'Y' },
                                { 'Y', 'Y', 'Y' }
                            }
            };

    for (int i = 0; i < 6; i++)
    {
        memcpy(&cube[i], &newCube[i], sizeof(newCube[0]));
    }
}

void print_piece(char piece)
{
    switch (piece) {
    case 'Y':
        textcolor(YELLOW);
        break;
    case 'O':
        textcolor(ORANGE);
        break;
    case 'B':
        textcolor(BLUE);
        break;
    case 'R':
        textcolor(RED);
        break;
    case 'G':
        textcolor(GREEN);
        break;
    case 'W':
        textcolor(WHITE);
        break;
    default:
        textcolor(DEFAULT);
        break;
    }

    printf("%c ", piece);
}

void copy(char v1[3], char v2[3])
{
    v1[0] = v2[0];
    v1[1] = v2[1];
    v1[2] = v2[2];
}

void copy2(char m1[][3], int col, char v2[3])
{
    m1[0][col] = v2[0];
    m1[1][col] = v2[1];
    m1[2][col] = v2[2];
}

void show_cube(char cube[][3][3])
{
    for (int i = 0; i < 3; i++)
    {
        printf("         ");
        print_piece(cube[0][i][0]);
        print_piece(cube[0][i][1]);
        print_piece(cube[0][i][2]);
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        printf("  ");
        print_piece(cube[1][i][0]);
        print_piece(cube[1][i][1]);
        print_piece(cube[1][i][2]);
        printf(" ");
        print_piece(cube[2][i][0]);
        print_piece(cube[2][i][1]);
        print_piece(cube[2][i][2]);
        printf(" ");
        print_piece(cube[3][i][0]);
        print_piece(cube[3][i][1]);
        print_piece(cube[3][i][2]);
        printf(" ");
        print_piece(cube[4][i][0]);
        print_piece(cube[4][i][1]);
        print_piece(cube[4][i][2]);
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        printf("         ");
        print_piece(cube[5][i][0]);
        print_piece(cube[5][i][1]);
        print_piece(cube[5][i][2]);
        printf("\n");
    }

    printf("\n");

    printf("\n");

    textcolor(DEFAULT);
}

void front_clockwise(char cube[][3][3])
{
    char v1[3] = { cube[0][2][0], cube[0][2][1], cube[0][2][2] };
    char v2[3] = { cube[3][2][0], cube[3][1][0], cube[3][0][0] };
    char v3[3] = { cube[5][0][0], cube[5][0][1], cube[5][0][2] };
    char v4[3] = { cube[1][2][2], cube[1][1][2], cube[1][0][2] };

    copy(cube[0][2], v4);
    copy2(cube[3], 0, v1);
    copy(cube[5][0], v2);
    copy2(cube[1], 2, v3);

    char v5[3] = { cube[2][0][0], cube[2][0][1], cube[2][0][2] };
    char v6[3] = { cube[2][2][2], cube[2][1][2], cube[2][0][2] };
    char v7[3] = { cube[2][2][0], cube[2][2][1], cube[2][2][2] };
    char v8[3] = { cube[2][2][0], cube[2][1][0], cube[2][0][0] };

    copy(cube[2][0], v8);
    copy2(cube[2], 2, v5);
    copy(cube[2][2], v6);
    copy2(cube[2], 0, v7);
}

void front_inverted(char cube[][3][3])
{
    char v1[3] = { cube[0][2][2], cube[0][2][1], cube[0][2][0] };
    char v2[3] = { cube[3][0][0], cube[3][1][0], cube[3][2][0] };
    char v3[3] = { cube[5][0][2], cube[5][0][1], cube[5][0][0] };
    char v4[3] = { cube[1][0][2], cube[1][1][2], cube[1][2][2] };

    copy(cube[0][2], v2);
    copy2(cube[3], 0, v3);
    copy(cube[5][0], v4);
    copy2(cube[1], 2, v1);

    char v5[3] = { cube[2][0][2], cube[2][0][1], cube[2][0][0] };
    char v6[3] = { cube[2][2][2], cube[2][1][2], cube[2][0][2] };
    char v7[3] = { cube[2][2][2], cube[2][2][1], cube[2][2][0] };
    char v8[3] = { cube[2][0][0], cube[2][1][0], cube[2][2][0] };

    copy(cube[2][0], v6);
    copy2(cube[2], 2, v7);
    copy(cube[2][2], v8);
    copy2(cube[2], 0, v5);
}

void right_clockwise(char cube[][3][3])
{
    char v1[3] = { cube[0][2][2], cube[0][1][2], cube[0][0][2] };
    char v2[3] = { cube[4][2][0], cube[4][1][0], cube[4][0][0] };
    char v3[3] = { cube[5][0][2], cube[5][1][2], cube[5][2][2] };
    char v4[3] = { cube[2][0][2], cube[2][1][2], cube[2][2][2] };

    copy2(cube[0], 2, v4);
    copy2(cube[4], 0, v1);
    copy2(cube[5], 2, v2);
    copy2(cube[2], 2, v3);

    char v5[3] = { cube[3][0][0], cube[3][0][1], cube[3][0][2] };
    char v6[3] = { cube[3][2][2], cube[3][1][2], cube[3][0][2] };
    char v7[3] = { cube[3][2][0], cube[3][2][1], cube[3][2][2] };
    char v8[3] = { cube[3][2][0], cube[3][1][0], cube[3][0][0] };

    copy(cube[3][0], v8);
    copy2(cube[3], 2, v5);
    copy(cube[3][2], v6);
    copy2(cube[3], 0, v7);
}

void right_inverted(char cube[][3][3])
{
    char v1[3] = { cube[0][0][2], cube[0][1][2], cube[0][2][2] };
    char v2[3] = { cube[4][2][0], cube[4][1][0], cube[4][0][0] };
    char v3[3] = { cube[5][2][2], cube[5][1][2], cube[5][0][2] };
    char v4[3] = { cube[2][0][2], cube[2][1][2], cube[2][2][2] };

    copy2(cube[0], 2, v2);
    copy2(cube[4], 0, v3);
    copy2(cube[5], 2, v4);
    copy2(cube[2], 2, v1);

    char v5[3] = { cube[3][0][2], cube[3][0][1], cube[3][0][0] };
    char v6[3] = { cube[3][2][2], cube[3][1][2], cube[3][0][2] };
    char v7[3] = { cube[3][2][2], cube[3][2][1], cube[3][2][0] };
    char v8[3] = { cube[3][0][0], cube[3][1][0], cube[3][2][0] };

    copy(cube[3][0], v6);
    copy2(cube[3], 2, v7);
    copy(cube[3][2], v8);
    copy2(cube[3], 0, v5);
}

void up_clockwise(char cube[][3][3])
{
    char v1[3] = { cube[1][0][0], cube[1][0][1], cube[1][0][2] };
    char v2[3] = { cube[2][0][0], cube[2][0][1], cube[2][0][2] };
    char v3[3] = { cube[3][0][0], cube[3][0][1], cube[3][0][2] };
    char v4[3] = { cube[4][0][0], cube[4][0][1], cube[4][0][2] };

    copy(cube[1][0], v2);
    copy(cube[2][0], v3);
    copy(cube[3][0], v4);
    copy(cube[4][0], v1);

    char v5[3] = { cube[0][0][0], cube[0][0][1], cube[0][0][2] };
    char v6[3] = { cube[0][2][2], cube[0][1][2], cube[0][0][2] };
    char v7[3] = { cube[0][2][0], cube[0][2][1], cube[0][2][2] };
    char v8[3] = { cube[0][2][0], cube[0][1][0], cube[0][0][0] };

    copy(cube[0][0], v8);
    copy2(cube[0], 2, v5);
    copy(cube[0][2], v6);
    copy2(cube[0], 0, v7);
}

void up_inverted(char cube[][3][3])
{
    char v1[3] = { cube[1][0][0], cube[1][0][1], cube[1][0][2] };
    char v2[3] = { cube[2][0][0], cube[2][0][1], cube[2][0][2] };
    char v3[3] = { cube[3][0][0], cube[3][0][1], cube[3][0][2] };
    char v4[3] = { cube[4][0][0], cube[4][0][1], cube[4][0][2] };

    copy(cube[1][0], v4);
    copy(cube[2][0], v1);
    copy(cube[3][0], v2);
    copy(cube[4][0], v3);

    char v5[3] = { cube[0][0][2], cube[0][0][1], cube[0][0][0] };
    char v6[3] = { cube[0][2][2], cube[0][1][2], cube[0][0][2] };
    char v7[3] = { cube[0][2][2], cube[0][2][1], cube[0][2][0] };
    char v8[3] = { cube[0][0][0], cube[0][1][0], cube[0][2][0] };

    copy(cube[0][0], v6);
    copy2(cube[0], 2, v7);
    copy(cube[0][2], v8);
    copy2(cube[0], 0, v5);
}

void bottom_clockwise(char cube[][3][3])
{
    char v1[3] = { cube[0][0][2], cube[0][0][1], cube[0][0][0] };
    char v2[3] = { cube[1][0][0], cube[1][1][0], cube[1][2][0] };
    char v3[3] = { cube[3][0][2], cube[3][1][2], cube[3][2][2] };
    char v4[3] = { cube[5][2][2], cube[5][2][1], cube[5][2][0] };

    copy2(cube[1], 0, v1);
    copy(cube[5][2], v2);
    copy2(cube[3], 2, v4);
    copy(cube[0][0], v3);

    char v5[3] = { cube[4][0][0], cube[4][0][1], cube[4][0][2] };
    char v6[3] = { cube[4][2][2], cube[4][1][2], cube[4][0][2] };
    char v7[3] = { cube[4][2][0], cube[4][2][1], cube[4][2][2] };
    char v8[3] = { cube[4][2][0], cube[4][1][0], cube[4][0][0] };

    copy(cube[4][0], v8);
    copy2(cube[4], 2, v5);
    copy(cube[4][2], v6);
    copy2(cube[4], 0, v7);
}

void bottom_inverted(char cube[][3][3])
{
    char v1[3] = { cube[0][0][0], cube[0][0][1], cube[0][0][2] };
    char v2[3] = { cube[1][2][0], cube[1][1][0], cube[1][0][0] };
    char v3[3] = { cube[3][2][2], cube[3][1][2], cube[3][0][2] };
    char v4[3] = { cube[5][2][0], cube[5][2][1], cube[5][2][2] };

    copy2(cube[1], 0, v4);
    copy(cube[5][2], v3);
    copy2(cube[3], 2, v1);
    copy(cube[0][0], v2);

    char v5[3] = { cube[4][0][2], cube[4][0][1], cube[4][0][0] };
    char v6[3] = { cube[4][2][2], cube[4][1][2], cube[4][0][2] };
    char v7[3] = { cube[4][2][2], cube[4][2][1], cube[4][2][0] };
    char v8[3] = { cube[4][0][0], cube[4][1][0], cube[4][2][0] };

    copy(cube[4][0], v6);
    copy2(cube[4], 2, v7);
    copy(cube[4][2], v8);
    copy2(cube[4], 0, v5);
}

void left_clockwise(char cube[][3][3])
{
    char v1[3] = { cube[0][0][0], cube[0][1][0], cube[0][2][0] };
    char v2[3] = { cube[2][0][0], cube[2][1][0], cube[2][2][0] };
    char v3[3] = { cube[4][2][2], cube[4][1][2], cube[4][0][2] };
    char v4[3] = { cube[5][2][0], cube[5][1][0], cube[5][0][0] };

    copy2(cube[0], 0, v3);
    copy2(cube[2], 0, v1);
    copy2(cube[5], 0, v2);
    copy2(cube[4], 2, v4);

    char v5[3] = { cube[1][0][0], cube[1][0][1], cube[1][0][2] };
    char v6[3] = { cube[1][2][2], cube[1][1][2], cube[1][0][2] };
    char v7[3] = { cube[1][2][0], cube[1][2][1], cube[1][2][2] };
    char v8[3] = { cube[1][2][0], cube[1][1][0], cube[1][0][0] };

    copy(cube[1][0], v8);
    copy2(cube[1], 2, v5);
    copy(cube[1][2], v6);
    copy2(cube[1], 0, v7);
}

void left_inverted(char cube[][3][3])
{
    char v1[3] = { cube[0][2][0], cube[0][1][0], cube[0][0][0] };
    char v2[3] = { cube[2][0][0], cube[2][1][0], cube[2][2][0] };
    char v3[3] = { cube[4][2][2], cube[4][1][2], cube[4][0][2] };
    char v4[3] = { cube[5][0][0], cube[5][1][0], cube[5][2][0] };

    copy2(cube[0], 0, v2);
    copy2(cube[2], 0, v4);
    copy2(cube[5], 0, v3);
    copy2(cube[4], 2, v1);

    char v5[3] = { cube[1][0][2], cube[1][0][1], cube[1][0][0] };
    char v6[3] = { cube[1][2][2], cube[1][1][2], cube[1][0][2] };
    char v7[3] = { cube[1][2][2], cube[1][2][1], cube[1][2][0] };
    char v8[3] = { cube[1][0][0], cube[1][1][0], cube[1][2][0] };

    copy(cube[1][0], v6);
    copy2(cube[1], 2, v7);
    copy(cube[1][2], v8);
    copy2(cube[1], 0, v5);
}

void down_clockwise(char cube[][3][3])
{
    char v1[3] = { cube[1][2][0], cube[1][2][1], cube[1][2][2] };
    char v2[3] = { cube[2][2][0], cube[2][2][1], cube[2][2][2] };
    char v3[3] = { cube[3][2][0], cube[3][2][1], cube[3][2][2] };
    char v4[3] = { cube[4][2][0], cube[4][2][1], cube[4][2][2] };

    copy(cube[1][2], v4);
    copy(cube[2][2], v1);
    copy(cube[3][2], v2);
    copy(cube[4][2], v3);

    char v5[3] = { cube[5][0][0], cube[5][0][1], cube[5][0][2] };
    char v6[3] = { cube[5][2][2], cube[5][1][2], cube[5][0][2] };
    char v7[3] = { cube[5][2][0], cube[5][2][1], cube[5][2][2] };
    char v8[3] = { cube[5][2][0], cube[5][1][0], cube[5][0][0] };

    copy(cube[5][0], v8);
    copy2(cube[5], 2, v5);
    copy(cube[5][2], v6);
    copy2(cube[5], 0, v7);
}

void down_inverted(char cube[][3][3])
{
    char v1[3] = { cube[1][2][0], cube[1][2][1], cube[1][2][2] };
    char v2[3] = { cube[2][2][0], cube[2][2][1], cube[2][2][2] };
    char v3[3] = { cube[3][2][0], cube[3][2][1], cube[3][2][2] };
    char v4[3] = { cube[4][2][0], cube[4][2][1], cube[4][2][2] };

    copy(cube[1][2], v2);
    copy(cube[2][2], v3);
    copy(cube[3][2], v4);
    copy(cube[4][2], v1);

    char v5[3] = { cube[5][0][2], cube[5][0][1], cube[5][0][0] };
    char v6[3] = { cube[5][2][2], cube[5][1][2], cube[5][0][2] };
    char v7[3] = { cube[5][2][2], cube[5][2][1], cube[5][2][0] };
    char v8[3] = { cube[5][0][0], cube[5][1][0], cube[5][2][0] };

    copy(cube[5][0], v6);
    copy2(cube[5], 2, v7);
    copy(cube[5][2], v8);
    copy2(cube[5], 0, v5);
}
