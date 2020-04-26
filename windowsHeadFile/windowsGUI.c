/*** create a windows GUI ***/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define SIZE 40
char *s_gets(char *st, int n);
void gotoxy(int x, int y);
int main(void)
{
    char info[SIZE];
    int x, y;
    hindenCursor();
    gotoxy(10, 10);
    puts("Enter your information:");
    while (s_gets(info, SIZE) && info[0]!='\0')
    {
        gotoxy(10, 16);
        puts("Enter the position:");
        scanf("%d:%d", &x, &y);
        while (getchar() != '\n')
            continue;
        gotoxy(x, y);
        printf("%s", info);
        gotoxy(x, y+1);
        puts("Enter the next info:");
    }
    gotoxy(10, 40);
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