#include <stdio.h>
#include <stdlib.h>

void shellSort(int arr[], int n) {
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] < temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        
        for (int k = 0; k < n; k++) {
            printf("%d,", arr[k]);
        }
        printf("\n");
    }
}

int main() {
    int num_keys;
    scanf("%d", &num_keys);

    int *keys = (int *)malloc(num_keys * sizeof(int));

    for (int i = 0; i < num_keys; i++) {
        scanf("%d,", &keys[i]);
    }

    shellSort(keys, num_keys);

    free(keys);
    return 0;
}
