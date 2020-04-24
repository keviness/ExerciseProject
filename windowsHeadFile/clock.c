/*** clock ***/
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#define LEN 40
#define MAX 10
char *s_gets(char *st, int n);
//void gotoxy(void);
void clock(int seconds);
int main(void)
{
    char things[LEN];
    int count = 0;
    long seconds;
    puts("Enter The thing you will be do:");
    while (s_gets(things, LEN) && things[0]!='\0' && count<MAX)
    {
        puts("Enter the time of the clock running:");
        scanf("%d", &seconds);
        clock(seconds);
        if (count < MAX)
        {
            puts("Enter the next things:");
        }
        count++;
    }
    puts("The done~");

    return 0;
}

void clock(int seconds)
{
    puts("The thing begins:");
    for (int i=0; i<seconds; i++)
    {
        printf("*");
        printf("%5d\b\b\b\b\b", i+1);
        Sleep(1000);
    }
    putchar('\n');
    printf("The thing end~");
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