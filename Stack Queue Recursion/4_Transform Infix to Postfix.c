#include<stdio.h>
#include<ctype.h>
#define MAX 100
char stack[MAX];
int top =-1;
void push(char x);
char pop();
int precedenceIp(char symbol);
int precedenceSk(char symbol);

int main(){
    char infix[MAX], postfix[MAX],ch, element;
    int i=0,k=0;
    printf("Enter the infix Expression: ");
    scanf("%s",infix);
    push('#');
    while((ch= infix[i]) != '\0'){
        if(ch == '('){
            push(ch);
        }else if(isalnum(ch)){
            postfix[k++]=ch;
        }else if( ch == ')'){
            while(stack[top]!= '('){
                    postfix[k++]=pop();
                  }
            element = pop();
        }else{
            while(precedenceIp(ch)<=precedenceSk(stack[top])){
                postfix[k++]=pop();
            }
            push(ch);
        }
        i++;
    }

    while(stack[top] != '#'){
        postfix[k++]=pop();
    }
    postfix[k]='\0';

    printf("Postfix: %s",postfix);

    return 0;
}
void push(char x){
    top++;
    stack[top]=x;
    //stack[++top]=x;
}
char pop(){
    char x;
    x= stack[top];
    top--;
    return x;
    //return stack([top--]);
}

int precedenceIp(char symbol){
    if(symbol == '^'){
        return 6;
    }else if(symbol == '*' || symbol == '/'){
        return 3;
    }else if(symbol == '+' || symbol == '-'){
        return 1;
    }else{
        return 0;
    }
}

int precedenceSk(char symbol){
    if(symbol == '^'){
        return 5;
    }else if(symbol == '*' || symbol == '/'){
        return 4;
    }else if(symbol == '+' || symbol == '-'){
        return 2;
    }else{
        return 0;
    }
}
