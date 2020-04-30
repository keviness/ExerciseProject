/*** create a windows GUI ***/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define SIZE 40
//char *s_gets(char *st, int n);
void gotoxy(int x, int y);
void gotoprint(int height, int width);
void hidenCursor(void);
int main(void)
{
    char info[SIZE];
    int width, height;
    hindenCursor();
    gotoxy(10, 10);
    puts("Enter the width and the height rectangle:");
    gotoxy(10, 12);
    while (scanf("%d:%d", &width, &height) == 2)
    {
        system("cls");
        gotoprint(width, height);
        gotoxy(10, 16);
        puts("Enter the next width and height of the rectangle:");
        gotoxy(10, 22);
        while (getchar() != '\n')
        {
            continue;
        }
    }
    gotoxy(10, 30);
    puts("The done~");

    return 0;
}

void gotoxy(int x, int y)
{
    HANDLE handle;
    COORD coord;
    coord.X = x;
    coord.Y = y;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle, coord);
}

void hindenCursor(void)
{
    HANDLE handle;
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(handle, &cursor_info);
}

void gotoprint(int width, int height)
{
    int i;
    for (i=0; i<=width; i+=2)
    {
        gotoxy(i, 0);
        printf("-");
        gotoxy(i, height);
        printf("-");
    }
    for (i=1; i<height; i++)
    {
        gotoxy(0, i);
        printf("|");
        gotoxy(width, i);
        printf("|");
    }
}

/*
char *s_gets(char *str, int num)
{
    char *ptr;
    ptr = fgets(str, num, stdin);
    if (ptr)
    {
        while (*str!='\0' && *str!='\n')
            str++;
        if (*str == '\n')
            *str = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }
    return ptr;
}
*/