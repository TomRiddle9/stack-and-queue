#include<stdio.h>
#include<stdlib.h>
int max_size = 100;

int stack[100];
int top = -1;

int isfull(){
    if(top== max_size)
        return 1;
    else
        return 0;
}

int isempty(){

    if(top == -1)
        return 1;
    else
        return 0;
}

int peek(){
    return stack[top];
}

int pop(){
    int data;
    if(!isempty()){
            data = stack[top];
            top = top -1;
            return data;
    }
}

int push(int data){
    if(!isfull()){
            top = top+1;
            stack[top] = data;
    }
}

int main(){

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    printf("\n Topmost element is ---- %d", peek());
    printf("\n ALL the stack elements are (LIFO) -   ");
    while(!isempty()){
            int data = pop();
            printf("\n %d", data);
    }
    return 0;
}
