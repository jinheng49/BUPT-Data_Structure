#include<stdio.h>

void sink(int a[],int k,int top);
int main(){
    int a[100];
    int m = 1,n;
    int num = 0;
    while (1) {
        int ch = getchar();
        if (ch == ',' ) {
            a[m] = num;
            m++;
            num = 0;
        } 
        else if (ch >= '0' && ch <= '9') {
            num = num * 10 + (ch - '0');
        }
        else if (ch == '\n' || ch == EOF) {
            break;
        }
    }
    m--;
    scanf("%d",&n);
    for(int i = m / 2;i >= 1;i--){
        sink(a,i,m);
    }
    if(n == 1){
        for (int k = 1; k <= m; k++){
            printf("%d,", a[k]);
        }
        printf("\n");
    }
    int top = m;
    int round = 1;
    for (int i = m; i >= 1; i--)
    {
        int temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        sink(a, 1, --top);
        round++;
        if (n == round)
        {
            for (int k = 1; k <= m; k++)
            {
                printf("%d,", a[k]);
            }
            printf("\n");
        }
    }
    return 0;
}

void sink(int a[],int k,int top){
    while(2 * k <= top){
        int j = 2 * k;
        if(j < top && a[j] < a[j + 1]) j++;
        if(a[k] > a[j]) break;
        int temp = a[j];
        a[j] = a[k];
        a[k] = temp;
        k = j;
    }
}