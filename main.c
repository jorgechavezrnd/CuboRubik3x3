#include <stdio.h>
#include <Windows.h>
#include "cube.h"

int options(char cube[][3][3])
{
    int option = 13;

    printf("                    RUBIK'S CUBE 3x3\n");
    printf("                    ------- ---- ---\n\n");
    printf("1.  Front Clockwise   (F)  \t 2.  Right Clockwise   (R)  \n");
    printf("3.  Up Clockwise      (U)  \t 4.  Bottom Clockwise  (B)  \n");
    printf("5.  Left Clockwise    (L)  \t 6.  Down Clockwise    (D)  \n");
    printf("7.  Front Inverted    (F') \t 8.  Right Inverted    (R') \n");
    printf("9.  Up Inverted       (U') \t 10. Bottom Inverted   (B') \n");
    printf("11. Left Inverted     (L') \t 12. Down Inverted     (D') \n");
    printf("13. Reset                  \t 14. Exit                 \n\n");

    show_cube(cube);

    printf("OPTION ---> ");
    scanf_s("%i", &option);

    return option;
}

void menu(char cube[][3][3])
{
    int option = 13;

    do
    {
        system("cls");

        option =  options(cube);

        switch (option) {
        case 1:
            front_clockwise(cube);
            break;
        case 2:
            right_clockwise(cube);
            break;
        case 3:
            up_clockwise(cube);
            break;
        case 4:
            bottom_clockwise(cube);
            break;
        case 5:
            left_clockwise(cube);
            break;
        case 6:
            down_clockwise(cube);
            break;
        case 7:
            front_inverted(cube);
            break;
        case 8:
            right_inverted(cube);
            break;
        case 9:
            up_inverted(cube);
            break;
        case 10:
            bottom_inverted(cube);
            break;
        case 11:
            left_inverted(cube);
            break;
        case 12:
            down_inverted(cube);
            break;
        case 13:
            reset_cube(cube);
            break;
        case 14:
            printf("BYE\n\n");
            break;
        default:
            printf("\nINVALID OPTION\n\n");
            system("pause");
            break;
        }
    } while(option != 14);
}

int main()
{
    char cube[6][3][3];

    reset_cube(cube);

    menu(cube);

    return 0;
}
