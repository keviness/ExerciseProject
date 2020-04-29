/*** my snake game ***/
/*
*@author: keviness
*@version: snake1.0
*@date: 2020.4.29
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>
#define WIDTH 118
#define HEIGHT 29
#define MAXSNAKE 100
#define NAME 20

struct snakes{
    unsigned int len;
    unsigned int speed;
    unsigned int x[MAXSNAKE];
    unsigned int y[MAXSNAKE];
}snake;

struct foods{
    unsigned int x;
    unsigned int y;
}food;

unsigned int score;
unsigned int key = 72;
unsigned int changeFlag = 0;

void welcome(void);
void initGraph(void);
void createFood(void);
void eatFood(void);
void movingSnake(void);
void controlSnake(void);
void gotoxy(int x, int y);
void hidenCursor(void);
bool snakeStatus(void);

/************************ main function **************************/
int main(void)
{
    system("color 0A");
    hidenCursor();
    welcome();
    initGraph();
    while (true)
    {
        controlSnake();
        if (!snakeStatus())
        {
            break;
        }
        eatFood();
        Sleep(snake.speed);
    }
    gotoxy(WIDTH/2, HEIGHT/2);
    printf("Game Over~");
    gotoxy(WIDTH/2, HEIGHT/2+1);
    printf("The score is:%u ", score);
    Sleep(500);

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

void hidenCursor(void)
{
    HANDLE handle;
    CONSOLE_CURSOR_INFO cursor = {1, 0};
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(handle, &cursor);
}

void welcome(void)
{
    char name[NAME];
    gotoxy(WIDTH/2, HEIGHT/2);
    printf("Welcome to you");
    gotoxy(WIDTH/2, HEIGHT/2+1);
    printf("Enter your name:");
    while (scanf("%s", name) != 1)
    {
        gotoxy(WIDTH/2, HEIGHT/2+2);
        printf("The error input, try again:");
    }
    gotoxy(WIDTH/2, HEIGHT/2+2);
    printf("Hello %s, have a nice day", name);
    Sleep(1000);
    system("cls");
}

/****************** graph user interface *****************/
void initGraph(void)
{
    for (int i=0; i<=WIDTH; i+=2)  /*herzontrol*/
    {
        gotoxy(i, 0);
        printf("#");
        gotoxy(i, HEIGHT);
        printf("#");
    }
    for (int i=0; i<HEIGHT; i++)
    {
        gotoxy(0, i);
        printf("#");
        gotoxy(WIDTH, i);
        printf("#");
    }

    /***** food initialize ****/
    createFood();

    /****** initialize snake *******/
    snake.speed = 1000;
    snake.len = 3;
    snake.x[0] = WIDTH/2 + 1;
    snake.y[0] = HEIGHT/2;
    gotoxy(snake.x[0], snake.y[0]);
    printf("#");
    for (int i=1; i<snake.len; i++)
    {
        snake.x[i] = snake.x[i-1]+2;
        snake.y[i] = snake.y[i-1];
        gotoxy(snake.x[i], snake.y[i]);
        printf("*");
    }

    
}

/****************** food create ***********************/
void createFood(void)
{
    while (true)
    {
        int flag = 1;
        srand((unsigned int)time(NULL));
        food.x = rand()%(WIDTH-4) + 2;
        food.y = rand()%(HEIGHT-2) + 1;

        for (int i=0; i<snake.len; i++)
        {
            if (food.x==snake.x[i] && food.y==snake.y[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag && food.x%2 == 0)
            break;
    }
    gotoxy(food.x, food.y);
    printf("@");
}

/******************* snake control ********************/
void controlSnake(void)
{
    unsigned int pre_key = key;
    if (_kbhit())
    {
        fflush(stdin);
        key = _getch();
        key = _getch();
    }

    movingSnake();

    if (pre_key==72 && key==80)
        key = 72;
    if (pre_key==75 && key==77)
        key = 75;
    if (pre_key==80 && key==72)
        key = 80;
    if (pre_key==77 && key==75)
        key = 77;
    
    switch (key)
    {
        case 72: snake.y[0]--; break;
        case 80: snake.y[0]++; break;
        case 75: snake.x[0] -= 2; break;
        case 77: snake.x[0] += 2; break;
    }

     /********* print snake head **********/
    gotoxy(snake.x[0], snake.y[0]);
    printf("#");

    changeFlag = 0;

}

void movingSnake(void)
{
    if (changeFlag == 0)
    {
        gotoxy(snake.x[snake.len-1], snake.y[snake.len-1]);
        printf(" ");
    }
    for (int i=snake.len-1; i>0; i--)
    {
        snake.x[i] = snake.x[i-1];
        snake.y[i] = snake.y[i-1];
        gotoxy(snake.x[i], snake.y[i]);
        printf("*");
    }

}

void eatFood(void)
{
    if (snake.x[0]==food.x && snake.y[0]==food.y)
    {
        createFood();

        score += 10;
        snake.speed -= 5;
        snake.len++;
        changeFlag = 1;
    }
}

bool snakeStatus(void)
{
    if (snake.x[0]==0 || snake.x[0]==WIDTH)
        return false;
    if (snake.y[0]==0 || snake.y[0]==HEIGHT)
        return false;
    for (int i=1; i<snake.len; i++)
    {
        if (snake.x[0]==snake.x[i] && snake.y[0]==snake.y[i])
            return false;
    }
    return true;
}