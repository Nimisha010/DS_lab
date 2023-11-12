
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define size 20

int top = -1;
char s[size],prefix[size];
int i;
char srev[size];


void stringrev(char exp[])
{
    int len = strlen(exp),j=0;
    
    for(i=len-1;i>=0;i--)
    {
        srev[j++] = exp[i];
    }
    srev[j] = '\0';
}
int push(char x)
{
    if(top==size-1)
    {   printf("Stack overflow\n");
        return -1;
    } 
        s[++top] = x;
        return 0;
         
}

int pop()
{
    char store;
    if (top == -1)
    {
        printf("Stack empty\n");
        return -1;
    }

    store = s[top--];
    return store;
}

int Isp(char x)
{
    switch(x)
    {
        case '+' : 
        case '-' : return 2;
        case '*' : 
        case '/' : return 4;
        case '^' : return 5;
        case '(' : return 0;
        //case ')' : break;
        default : return -1;
    }    
}

int Icp(char x)
{
    switch(x)
    {
        case '+' : 
        case '-' : return 1;
        case '*' : 
        case '/' : return 3;
        case '^' : return 6;
        case '(' : return 7;
        case ')' : return 0;
        default : return-1;
    }
}

int InfixToPrefix(char exp[], char prefix[])
{
    char symb;
    int j=0;

    while (srev[i] != '\0')
    {
        symb = srev[i];
        if (isalpha(symb) || isdigit(symb))
        {
            prefix[j++] = symb;
        }
        else if (symb == ')')
        {
            push(symb);
        }  
        else if (symb == '(') 
        {
            while (s[top] != ')')
            {
                prefix[j++] = pop();
            }
            pop(); // pop the ')'
        }
        else
        {
            if (top == -1 || s[top] == '(' || Isp(s[top]) < Icp(symb))
            {
                push(symb);
            }
            else
            {
                while (top != -1 && s[top] != '(' && Isp(s[top]) > Icp(symb))
                {
                    prefix[j++] = pop();
                }
                push(symb);
            }
        }
        i++;
    }
    while (top != -1)
    {
        prefix[j++] = pop();
    }
    prefix[j] = '\0'; // null character of prefix expression
}


int main() {
    char exp[size];
    char prefix[size];
    top=-1;

    printf("Enter infix expression:\n");
    scanf("%[^\n]", exp);
    stringrev(exp);
    InfixToPrefix(exp, prefix);
    stringrev(prefix); 
    printf("Prefix form: %s\n", srev);
    
    return 0;
}
