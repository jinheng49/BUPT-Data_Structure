#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char stack[100];
    double stack2[100];
    char array[20];
    for (int i = 0; i < 20; i++)
    {
        array[i] = '\0';
    }
    int top = -1;
    int top2 = -1;
    int p = -1;
    char x;
    while ((x = getchar()) != '\n' && x != EOF)
    {
        if (x >= '0' && x <= '9')
        {
            p++;
            array[p] = x;
        }
        else
        {
            if (x == '(')
            {
                top++;
                stack[top] = x;
            }
            if (x == ')')
            {
                while (stack[top] != '(')
                {
                    p++;
                    array[p] = stack[top];
                    top--;
                }
                top--;
            }

            if (x == '*' || x == '/')
            {
                while (stack[top] == '*' || stack[top] == '/')
                {
                    p++;
                    array[p] = stack[top];
                    top--;
                }
                top++;
                stack[top] = x;
            }
            if (x == '+' || x == '-')
            {
                while (top != -1 && stack[top] != '(')
                {
                    p++;
                    array[p] = stack[top];
                    top--;
                }

                top++;
                stack[top] = x;
            }
        }
    }

    while (top != -1)
    {
        p++;
        array[p] = stack[top];
        top--;
    }

    double x1, x2, result;
    for (int i = 0; array[i] != '\0'; i++)
    {
        if (array[i] >= '0' && array[i] <= '9')
        {
            top2++;
            stack2[top2] = (array[i] - '0');
        }
        else if (array[i] == '+')
        {
            x1 = stack2[top2--];
            x2 = stack2[top2--];
            result = x1 + x2;
            stack2[++top2] = result;
        }
        else if (array[i] == '-')
        {

            x2 = stack2[top2--];
            result = x2 - x1;
            stack2[++top2] = result;
        }
        else if (array[i] == '*')
        {
            x1 = stack2[top2--];
            x2 = stack2[top2--];
            result = x1 * x2;
            stack2[++top2] = result;
        }
        else if (array[i] == '/')
        {
            x1 = stack2[top2--];
            x2 = stack2[top2--];
            result = x2 / x1;
            stack2[++top2] = result;
        }
    }
    printf("%.2f", stack2[0]);
    printf("\n");
    for (int i = 0; array[i] != '\0'; i++)
    {
        printf("%c ", array[i]);
    }

    return 0;
}
