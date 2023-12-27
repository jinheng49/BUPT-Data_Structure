// Balancing Symbols
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node* next;
}Node;

typedef struct Stack
{
    Node* top;
}Stack;

void InitStack(Stack *stack);
void push(Stack* stack,char data);
char peek(Stack* stack);
char pop(Stack* stack);
int isEmpty(Stack* stack);


int main(){
    int ans[50] = {0};
    int num = 0;
    char s[50];
    char pairs[128] = {'0'}; 
    pairs[')'] = '(';
    pairs[']'] = '[';
    pairs['}'] = '{';
    scanf("%s",s);
    int i = 0;
    int j = -1;
    Stack st;
    InitStack(&st);
    while(s[i] != '\0'){
        if(s[i] == '('||s[i] == ')'||s[i] == '['||s[i] == ']'||s[i] == '{'||s[i] == '}'){
            if(pairs[s[i]] == 0){
                push(&st,s[i]);
            }
            else{
                switch (s[i])
                {
                case ')':
                    if(peek(&st) == pairs[')']){
                        pop(&st);
                    }
                    else{
                        ans[++j] = 1;
                        num++;
                    }
                    break;
                case ']':
                    if(peek(&st) == pairs[']']){
                        pop(&st);
                    }
                    else{
                        ans[++j] = 2;
                        num++;
                    }
                    break;
                case '}':
                    if(peek(&st) == pairs['}']){
                        pop(&st);
                    }
                    else{
                        ans[++j] = 3;
                        num++;
                    }
                    break;
                default:
                    break;
                }
            }
        }
        i++;

    }
    while(!isEmpty(&st)) {
            char popped = pop(&st); // 弹出元素并存储在变量中
            if (popped == '(') {
                ans[++j] = 1;
            } else if (popped == '[') {
                ans[++j] = 2;
            } else if (popped == '{') {
                ans[++j] = 3;
            }
            num++;
        }
    if(num == 0){
        printf("0");
    }
    else{
        for (int a = 1; a < num; a++) {
        int key = ans[a];
        int b = a - 1;

        while (b >= 0 && ans[b] > key) {
            ans[b + 1] = ans[b];
            b--;
        }

        ans[b + 1] = key;
        }
        for(int k = 0; k < num;k++){
            printf("%d,",ans[k]);
        }
    }
    
    
    return 0;
}

void InitStack(Stack *stack){
    stack->top = NULL;
}
void push(Stack* stack,char data){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode -> next = stack ->top;
    stack ->top = newnode;
}
char peek(Stack* stack){
    if (!isEmpty(stack)) {
        return stack->top->data;
    }
    return '\0';
}
char pop(Stack* stack){
    if(!isEmpty(stack)){
        Node* poped = stack->top;
        char popedValue = poped ->data;
        stack->top = poped ->next;
        free(poped);
        return popedValue;
    }
    return '\0';
}
int isEmpty(Stack* stack){
    return stack->top == NULL;
}
