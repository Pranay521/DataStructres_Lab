#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 200

char stack[SIZE];
int top = -1, isValid = 1;

void push(char item)
{
    if (top >= SIZE - 1)
    {
        printf("\nStack Overflow.");
    }
    else
    {
        top = top + 1;
        stack[top] = item;
    }
}
char pop()
{
    char item;
    if (top < 0)
    {
        printf("Invalid infix expression");
        isValid = 0;
        return '0';
    }
    else
    {
        item = stack[top];
        top = top - 1;
        return item;
    }
}

int isOperator(char symbol)
{
    if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char symbol)
{
    if (symbol == '^')
    {
        return (3);
    }
    else if (symbol == '*' || symbol == '/')
    {
        return (2);
    }
    else if (symbol == '+' || symbol == '-')
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

void InfixToPostfix(char infix_exp[], char postfix_exp[])
{
    int i, j;
    char item;
    char x;
    push('(');
    strcat(infix_exp, ")");

    i = 0;
    j = 0;
    item = infix_exp[i];

    while (item != '\0')
    {
        if (item == '(')
        {
            push(item);
        }
        else if (isdigit(item) || isalpha(item))
        {
            postfix_exp[j] = item;
            j++;
        }
        else if (isOperator(item) == 1)
        {
            if (j == 0)
            {
                isValid = 0;
                return;
            }
            x = pop();
            while (isOperator(x) == 1 && precedence(x) >= precedence(item))
            {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
            push(x);
            push(item);
        }
        else if (item == ')')
        {
            x = pop();
            while (x != '(')
            {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
        }
        else
        {
            printf("\nInvalid infix Expression.\n");
            isValid = 0;
            return;
        }
        i++;

        item = infix_exp[i];
    }
    if (top > 0)
    {
        printf("\nInvalid infix Expression.\n");
        isValid = 0;
        return;
    }
    postfix_exp[j] = '\0';
}

void reverse(char infix[])
{
    int i, j, n = strlen(infix) - 2;
    char temp[SIZE];
    for (i = n, j = 0; i + 1 != 0; --i, ++j)
    {
        temp[j] = infix[i];
    }
    temp[j] = '\0';
    strcpy(infix, temp);
}

void infixtoprefix(char infix[], char prefix[])
{
    int i, j = 0;
    char symbol;
    stack[++top] = '#';
    reverse(infix);
    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        if (isOperator(symbol) == 0)
        {
            prefix[j] = symbol;
            j++;
        }
        else
        {
            if (symbol == ')')
            {
                push(symbol);
            }
            else if (symbol == '(')
            {
                while (stack[top] != ')')
                {
                    prefix[j] = pop();
                    j++;
                }
                pop();
            }
            else
            {
                if (precedence(stack[top]) <= precedence(symbol))
                {
                    push(symbol);
                }
                else
                {
                    while (precedence(stack[top]) >= precedence(symbol))
                    {
                        prefix[j] = pop();
                        j++;
                    }
                    push(symbol);
                }
            }
        }
    }

    while (stack[top] != '#')
    {
        prefix[j] = pop();
        j++;
    }
    prefix[j] = '\0';
}

void reversePrefix(char prefix[])
{
    int i, j, n = strlen(prefix) - 1;
    char temp[SIZE];
    for (i = n, j = 0; i + 1 != 0; --i, ++j)
    {
        temp[j] = prefix[i];
    }
    temp[j] = '\0';
    strcpy(prefix, temp);
}

int main()
{

    char infix[SIZE], postfix[SIZE], prefix[SIZE];
    char infixReverse[SIZE];

    printf("\nEnter Infix expression : ");
    gets(infix);

    InfixToPostfix(infix, postfix);

    if (isValid)
    {
        printf("Entered Expression is Valid");
        printf("\nPostfix Expression: ");
        puts(postfix);
        top = -1;

        infixtoprefix(infix, prefix);
        reversePrefix(prefix);
        printf("\nPrefix Expression: ");
        puts(prefix);
    }
    else
    {
        printf("Expression is Invalid");
    }
    return 0;
}
