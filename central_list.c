// central list
#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node
{
    char num;
    PtrToNode prev;
    PtrToNode next;
};

int main(){
    PtrToNode head = (PtrToNode)malloc(sizeof(struct Node));
    head ->next = NULL;
    head ->prev =NULL;
    PtrToNode dum = head;
    char x;
    x = getchar();
    while(x != '\n'){
        if(x !=','){
            PtrToNode newnode = (PtrToNode)malloc(sizeof(struct Node));
            newnode -> num = x;
            head ->next = newnode;
            newnode->prev = head;
            newnode->next = NULL;
            head = newnode;
        }
        x = getchar();
    }
   PtrToNode last = head;
    head = dum->next;
    int flag = 1;
    while(head != last && head->prev != last->next){
        if(head->num != last->num){
            flag = 0;
            break;
        }
        head = head->next;
        last = last->prev;
    }
    if(flag){
        printf("Yes");
    }
    else{
        printf("No");
    }

    return 0;



}
