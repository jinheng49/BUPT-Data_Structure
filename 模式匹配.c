// 串的模式匹配
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long strStr(char* haystack, char* needle) {
    long n = strlen(haystack), m = strlen(needle);
    if (m == 0) {
        return 0;
    }
    long pi[m];
    pi[0] = 0;
    for (long i = 1, j = 0; i < m; i++) {
        while (j > 0 && needle[i] != needle[j]) {
            j = pi[j - 1];
        }
        if (needle[i] == needle[j]) {
            j++;
        }
        pi[i] = j;
    }
    for (long i = 0, j = 0; i < n; i++) {
        while (j > 0 && haystack[i] != needle[j]) {
            j = pi[j - 1];
        }
        if (haystack[i] == needle[j]) {
            j++;
        }
        if (j == m) {
            return i - m + 1;
        }
    }
    return -1;
}


int main(){
    char s[1000001];
    scanf("%s", s);
    int n;
    scanf("%d", &n);
    getchar();
    char** patterns = (char**)malloc(n * sizeof(char*));  
    for (int i = 0; i < n; i++) {  
        patterns[i] = (char*)malloc(100001 * sizeof(char));  
        scanf("%s", patterns[i]);  
    }  
    for(int i = 0;i < n;i++){
        long result = strStr(s, patterns[i]);
            if(result == -1){
                printf("Not Found\n");
            }
            else{
                printf("%s\n",s + result);
            }
    }


    return 0;
}
