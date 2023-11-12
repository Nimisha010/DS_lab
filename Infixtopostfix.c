#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define size 20

int top = -1;
char s[size],postfix[size];

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

int InfixToPostfix(char exp[], char postfix[])
{
    int i = 0, j = 0;
    char symb;

    while (exp[i] != '\0')
    {
        symb = exp[i];
        if (isalpha(symb) || isdigit(symb))
        {
            postfix[j++] = symb;
        }
        else if (symb == ')')
        {
            while (s[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop(); // pop the '('
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
                    postfix[j++] = pop();
                }
                push(symb);
            }
        }
        i++;
    }
    while (top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // null character of postfix expression
}

int evaluatepostfix(char postfix[])
{
    int stack[size], top = -1,i=0, result;
    int operand,op1,op2;
    char str[2];
    
    
    while(postfix[i]!='\0')
    {
        char x = postfix[i];
        printf("%c\n", x);
        if(isdigit(x))
        {   
          
            str[0] = x;
            str[1] = 0;
            operand = atoi(str);
         
            stack[++top] = operand;
        }
        else if((x=='+')||(x=='-')||(x=='*')||(x=='/'))
        {
             op2 = stack[top--];
             op1 = stack[top--];
        
        
           switch(x)
           {
             case '+' : result= op1 + op2;
                        break;
             case '-' : result = op1 - op2;
                        break;
             case '*' : result= op1 * op2;
                        break;
             case '/' : result= op1 / op2;
                        break;
             case '^' : result = (int)pow(op1,op2);
                        break;  
              default : printf("Invalid operator in the expression\n");   
                        return -1; 
                                  
           }
        stack[++top] = result;
       }
        i++;
    } 
    return stack[top];
}



int main() {
    char exp[size];
    char postfix[size];
    top=-1;

    printf("Enter infix expression:\n");
    scanf("%[^\n]", exp);

    InfixToPostfix(exp, postfix);
    printf("Postfix form: %s\n", postfix);
    
    int result= evaluatepostfix(postfix);
    printf("The evaluation of the postfix expression is %d\n",result);

    return 0;
}


    
