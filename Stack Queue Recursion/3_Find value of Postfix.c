#include<stdio.h>
#include <ctype.h>
#include<string.h>
#define MAXSTACK 100
#define POSTFIXSIZE 100

int stack[MAXSTACK];
int top= -1;

void push(int item);
int pop();
void evaluatePostfix(char postfix[]);
int main(){

    char postfix[POSTFIXSIZE];

    printf("Enter the postfix expression: ");
    scanf("%s",postfix);
    evaluatePostfix(postfix);
    return 0;
}

void evaluatePostfix(char postfix[]){

    int i;
    char ch;
    int value;
    int A, B;
    int len = strlen(postfix);
    for(i=0;i<len;i++){
        ch = postfix[i];
        if(isdigit(ch)){
            push(ch-'0');//get digit rather than ASCII code
        }else if(ch == '^' || ch == '+'|| ch == '-'|| ch == '*'|| ch == '/'){

            A= pop();
            B= pop();
            switch(ch){
                case '^':
                    value = pow(B,A);
                    break;
                case '*':
                    value = B * A;
                    break;
                case '/':
                    value = B / A;
                    break;
                case '+':
                    value = B + A;
                    break;
                case '-':
                    value = B - A;
                    break;
            }
            push(value);
        }
    }
    printf("\n Result: %d \n",pop());
}
void push(int item){

    if(top>=MAXSTACK-1)
        printf("\nOverFlow\n");
    else{
        top++;
        stack[top]=item;
    }
}
int pop(){

    int item;
    if(top < 0 )
        printf("Underflow");
    else{
        item = stack[top];
        top--;
        return item;
    }
}
