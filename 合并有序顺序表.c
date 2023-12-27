// 合并有序顺序表
#include<stdio.h>
#include<stdlib.h>

int main(){
    int a , b;
    scanf("%d",&a);
    int arraya[a];
    for (int i = 0; i < a; i++){
        scanf("%d",&arraya[i]);
    }
    scanf("%d",&b);
    int arrayb[b];
    for (int j = 0; j < b; j++){
        scanf("%d",&arrayb[j]);
    }
    int ka = 0,kb = 0, k = 0;
    int ans[a + b];
    while(ka < a && kb < b){
        if(arraya[ka] < arrayb[kb]){
            ans[k] = arraya[ka];
            ka++;
            k++;
        }
        else if(arraya[ka] > arrayb[kb]){
            ans[k] = arrayb[kb];
            kb++;
            k++;
        }
        else{
            ans[k] = arraya[ka];
            ans[k+1] = arrayb[kb];
            ka++;
            kb++;
            k+=2;
        }
    }
    if(ka != a){
        for( ;k < a+b;k++,ka++){
            ans[k] = arraya[ka];
        }
    }
    if(kb != b){
        for( ;k < a+b;k++,kb++){
            ans[k] = arrayb[kb];
        }
    }
    for(int i = 0;i < a+b; i++){
        printf("%d ",ans[i]);
    }
    return 0;

}