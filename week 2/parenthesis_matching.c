#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPairMatching(char i, char j)
{
    if ((i == '(' && j == ')') || (i == '{' && j == '}') || (i == '[' && j == ']'))
    {
        return true;
    }
    return false;
}

bool isValidPattern(char *str)
{
    char stack[1000];
    int top = -1, i = 0;
    while (str[i])
    {

        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
        {
            top++;
            stack[top] = str[i];
        }
        else if (str[i] == '}' || str[i] == ')' || str[i] == ']')
        {

            if (top < 0)
                return 0;

            else if (!isPairMatching(stack[top], str[i]))
            {
                return 0;
            }
            top--;
        }
        else
        {
            printf("String has Invalid char\n");
            return false;
        }

        i++;
    }

    if (top >= 0)
        return false;
    return true;
}

int main()
{
    char str[1000];
    printf("Enter the String : ");
    scanf("%[^\n]%*c", str);
    if (isValidPattern(str))
    {
        printf("true\n\n\n");
    }
    else
    {
        printf("false\n\n\n");
    }

    return 0;
}
