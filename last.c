// 约瑟夫问题
#include<stdio.h>
#include<stdlib.h>

typedef struct Node *PtrToNode;
struct Node {
    int num;
    PtrToNode prev;
    PtrToNode next;
};

PtrToNode creat(int n);
int main(){
    int n,i;
    scanf("%d,%d",&n,&i);
    PtrToNode list = creat(n);
    for(int k = 1;k<= n;k++){
        for(int j = 0;j < i;j++){
            list = list->next;
        }
        printf("%d",list->num);
        if(list->next != list){
            printf(",");
        }
        list->prev->next = list->next;
        list->next->prev = list->prev;
        list = list->next;
        }
    return 0;
}

PtrToNode creat(int n){ 
    PtrToNode head = (PtrToNode)malloc(sizeof(struct Node));
    head->num = 1;
    head ->next = NULL;
    head ->prev = NULL;
    PtrToNode current = head;
    int i;
    for(i = 2;i <= n;i++){
        PtrToNode newnode = (PtrToNode)malloc(sizeof(struct Node));
        newnode->num = i;
        newnode->next = head;
        newnode->prev = current;
        head->prev = newnode;
        current->next = newnode;
        current = newnode;
    }
    return head;
}
