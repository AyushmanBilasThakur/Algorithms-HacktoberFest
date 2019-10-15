#include<stdio.h>
#include<string.h>
#include<math.h>

#define MAX 20
#define POP_ERR 9999

int operand_stack[MAX];
int top = -1;

int pop(){
    if(top == -1){
        // printf("nothing to pop");
        return POP_ERR;
    }
    else{
        int popped = operand_stack[top];
        top = top - 1;
        return popped;
    }
}

int return_top(){
    if(top == -1){
        // printf("nothing to pop");
        return POP_ERR;
    }
    else{
        return operand_stack[top - 1];
    }
}

void push(int char_to_push){
    if(top == MAX){
        // printf("nothing to add");
    }
    else{
        top += 1;
        operand_stack[top] = char_to_push;
    }
}

//returns 1 for operand and 0 for operator
int operator_or_operand(char c){
    switch(c){
        case '^':
        case '*':
        case '%':
        case '/':
        case '+':
        case '-':
            return 0;
        default:
            return 1;
    }
}

int calculate_from_result(int a, int b, char operator){
    switch (operator)
    {
        case '^':
            return pow(a,b);
        case '*':
            return a * b;
        case '%':
            return a % b;
        case '/':
            return a / b;
        case '+':
            return a + b;
        case '-':
            return a - b;
    }
}

int result_from_prefix(char* exp){
    int i = 0;
    int operand1, operand2, result;
    char current_letter;
    for(i = strlen(exp) - 1; i >= 0; i--){
        current_letter = *(exp + i);
        if(operator_or_operand(current_letter) == 1){
            push((int) (current_letter - '0'));
        }
        else{
            operand1 = pop();
            operand2 = pop();
            result = calculate_from_result(operand1, operand2, current_letter);
            push(result);
        }
    }
    return pop();
}

int main(){
    char expression[MAX];
    int res;
    printf("Enter the prefix expression: ");
    gets(expression);
    res = result_from_prefix(expression);
    printf("%d",res);
    return 0;
}