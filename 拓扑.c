#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define N 11

int g[N][N] = {
//   S  A  B  C  D  E  F  G  H  I  T
    {0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0}, // S
    {0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0}, // A
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, // B
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // C
    {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // D
    {0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0}, // E
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1}, // F
    {0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0}, // G
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0}, // H
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1}, // I
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}  // T
};

char vertex[] = {'S', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'T'};

int inDegree[N] = {0}; 

void calculateInDegree() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (g[i][j] == 1) {
                inDegree[j]++;
            }
        }
    }
}

void topologicalSort() {
    calculateInDegree();

    int queue[N];
    int front = 0, rear = -1;

    for (int i = 0; i < N; i++) {
        if (inDegree[i] == 0) {
            queue[++rear] = i;
        }
    }

    int result[N];
    int index = 0;

    while (front <= rear) {
        int current = queue[front++];

        result[index++] = current;

        for (int i = 0; i < N; i++) {
            if (g[current][i] == 1) {
                if (--inDegree[i] == 0) {
                    queue[++rear] = i;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%c,", vertex[result[i]]);
    }

}

void removeEdge(int start, int end) {
    g[start][end] = 0;
}

int main() {
    char start, end;
    int st, en;
    scanf("%c,%c", &start, &end);

    if (start == 'S') {
        st = 0;
    } else if (start == 'T') {
        st = 10;
    } else {
        st = start - 'A' + 1;
    }

    if (end == 'T') {
        en = 10;
    } else {
        en = end - 'A' + 1;
    }

    removeEdge(st, en);

    topologicalSort();

    return 0;
}
