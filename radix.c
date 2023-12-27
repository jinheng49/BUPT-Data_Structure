#include <stdio.h>
void sort(int a[], int n, int exp);
int main()
{
    int x = 0;
    char y;
    int a[20];
    int top = -1;
    while ((y = getchar()) != '\n')
    {
        if (y != ','){
            x = x * 10 + y - '0';
        }
        else{
            a[++top] = x;
            x = 0;
        }
    }
    int n = top + 1;
    int max = a[0];
    for (int i = 1; i < n; i++){
        if (max < a[i])
        {
            max = a[i];
        }
    }
    int times = 0;
    int k;
    scanf("%d",&k);
    for (int exp = 1; max / exp > 0; exp = exp * 10)
    {
        sort(a, n, exp);
        times++;
        if (times == k)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d,", a[j]);
            }
        }
    }

    return 0;
}
void sort(int a[], int n, int exp)
{
    int bucket[10] = {0};
    int output[n]; 
    for (int i = 0; i < n; i++)
    {
        int last = (a[i] / exp) % 10;
        bucket[last]++;
    }
    for (int i = 1; i < 10; i++)
    {
        bucket[i] = bucket[i] + bucket[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int index, last;
        last = (a[i] / exp) % 10;
        index = bucket[last] - 1;
        output[index] = a[i];
        bucket[last]--;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = output[i];
    }
}
