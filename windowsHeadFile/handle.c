#include <stdio.h>
#include <windows.h>
#define LEN 25
void HideCursor();
void Gotoxy(int x, int y);
void DrawBox();
int main(void)
{
    int len;
    HideCursor();
    for(len = 1; len <= LEN; len++){
        Gotoxy(1 * len, 1    );
        printf("#");
        Gotoxy(21, 4);
        printf("Have finished:%d%%", 4 * len);
        Sleep(1000);
    }
    Gotoxy(21, 4);
    printf("The done~");
    return 0;
}
//隐藏光标
void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};//后边的0代表光标不可见
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
//光标移动
void Gotoxy(int x, int y)
{
    HANDLE hout; //定义句柄变量hout
    COORD coord; //定义结构体coord
    coord.X = x;
    coord.Y = y;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);//获得标准输出（屏幕）句柄
    SetConsoleCursorPosition(hout, coord);//移动光标
}
//画边框
void DrawBox()
{
   
    printf("|                                                  |");
    putchar('\n');
   
}