#include <stdio.h>

int main() {
    int arr1[50];
    int arr2[50];
    int m = 0, n = 0, num = 0;

    while (1) {
        int ch = getchar();
        if (ch == ',' ) {
            arr1[m] = num;
            m++;
            num = 0;
        } else if (ch >= '0' && ch <= '9') {
            num = num * 10 + (ch - '0');
            }else if (ch == '\n') {
                break;
                }
    }

    while (1) {
        int ch = getchar();
        if (ch == ',' ) {
            arr2[n] = num;
            n++;
            num = 0;
        } else if (ch >= '0' && ch <= '9') {
            num = num * 10 + (ch - '0');
        }else if (ch == '\n' || ch == EOF) {
                break;
            }
    }
    int merged_array[m + n];
    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            merged_array[k] = arr1[i];
            i++;
        } else {
            merged_array[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < m) {
        merged_array[k] = arr1[i];
        i++;
        k++;
    }

    while (j < n) {
        merged_array[k] = arr2[j];
        j++;
        k++;
    }

    for (int i = 0; i < m + n; i++) {
        printf("%d,", merged_array[i]);
    }

    return 0;
}
