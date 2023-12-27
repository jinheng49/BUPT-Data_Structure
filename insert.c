#include<stdio.h>

void printarray(int arr[],int n){
    for(int i = 0;i < n;i++){
        printf("%d,",arr[i]);
        if(i == n - 1){
            printf("\n");
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int seq[n];
    for(int i = 0; i < n;i++){
        scanf("%d,",&seq[i]);
    }
    for(int i = 1;i < n;i++){
        for(int j = 0;j < i;j++){
            if(seq[i] < seq[j]){
                int temp = seq[i];
                for(int k = i;k > j;k--){
                    seq[k] =seq[k - 1]; 
                }
                seq[j] = temp;
            }
        }
        printarray(seq,n);
    }
    return 0;
}