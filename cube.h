#ifndef CUBE_H
#define CUBE_H

void reset_cube(char cube[][3][3]);
void print_piece(char piece);
void copy(char v1[3], char v2[3]);
void copy2(char m1[][3], int col, char v2[3]);
void show_cube(char cube[][3][3]);

void front_clockwise(char cube[][3][3]);
void front_inverted(char cube[][3][3]);
void right_clockwise(char cube[][3][3]);
void right_inverted(char cube[][3][3]);
void up_clockwise(char cube[][3][3]);
void up_inverted(char cube[][3][3]);
void bottom_clockwise(char cube[][3][3]);
void bottom_inverted(char cube[][3][3]);
void left_clockwise(char cube[][3][3]);
void left_inverted(char cube[][3][3]);
void down_clockwise(char cube[][3][3]);
void down_inverted(char cube[][3][3]);

#endif // CUBE_H
