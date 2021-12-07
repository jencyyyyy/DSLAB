#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#define SIZE 50

int numbers[SIZE],tn=-1,to=-1;
char op[SIZE];

void push_number(int n){
    numbers[++tn]=n;
}

void push_op(int n){
    op[++to] =n;
}

int pop_number(){
    return numbers[tn--];
}
int pop_op(){
    return op[to--];
}

int infix_eval(int numbers[50], char op[50]){
    int x,y;
    char ope;

    x=pop_number();
    y=pop_number();
    ope= pop_op();

    switch(ope){
        case '+': return y+x;

        case '-': return y-x;

        case '*': return y*x;

        case '/': if(x==0){
                        printf("Can't divide by 0\n");
                        exit(0);
                        }
                        else{
                            return y/x;
                        }

        case '^': return pow(x,y);

    }
    return 0;
}


int is_operator(char ch){
    if(ch=='+' || ch== '-'|| ch== '*' || ch == '/' || ch == '^'){
        return 1;
    }else
        return 0;
}

int precedence(char c){
    switch(c){
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '^': return 3;
    }
    return -1;
}

int eval(char exp[20]){

    int i,num,output,r;
    char c;
    for(i=0;exp[i]!='\0';i++){
        c = exp[i];
        if(isdigit(c)!=0){
            num = 0;
            while(isdigit(c)){
                num = num*10 + (c-'0');
                i++;
                if(i<strlen(exp))
                    c= exp[i];
                else
                    break;
            }
            i--;

           push_number(num);
        }
        else if(c=='('){
                push_op(c);
        }else if( c== ')'){
            while(op[to]!='('){
                    r= infix_eval(numbers,op);
                    push_number(r);
                  }
                  pop_op();
        }else if(is_operator(c)){
            while((to!=-1) && (precedence(c)<= precedence(op[to]))){
                output = infix_eval(numbers,op);
                push_number(output);
            }
            push_op(c);
        }
    }
    while(to!= -1){
        output = infix_eval(numbers,op);
        push_number(output);
    }
    return pop_number();
}


int main(){
    char exp[50];
    printf("Enter infix expression: ");
    gets(exp);
    printf("Output: %d",eval(exp));
    return 0;
}
