#include <stdio.h>
#include <stdlib.h>
#define leaf 1
struct Node;
typedef struct Node *ptrtoNode;
typedef ptrtoNode position;
typedef ptrtoNode tree;
struct Node
{
    char x;
    position left, right;
    int kind;
};

int main()
{
    tree T = malloc(sizeof(struct Node));
    position p2 = malloc(sizeof(struct Node));
    position p3 = malloc(sizeof(struct Node));
    position p4 = malloc(sizeof(struct Node));
    position p5 = malloc(sizeof(struct Node));
    position p6 = malloc(sizeof(struct Node));
    position p7 = malloc(sizeof(struct Node));
    position p8 = malloc(sizeof(struct Node));
    position p9 = malloc(sizeof(struct Node));
    position p10 = malloc(sizeof(struct Node));
    position p11 = malloc(sizeof(struct Node));
    position p12 = malloc(sizeof(struct Node));
    position p13 = malloc(sizeof(struct Node));
    position p14 = malloc(sizeof(struct Node));
    position p15 = malloc(sizeof(struct Node));

    p4->kind = leaf;
    p4->x = 'b';

    p5->kind = leaf;
    p5->x = 'g';

    p7->kind = leaf;
    p7->x = 'e';

    p11->kind = leaf;
    p11->x = 'd';

    p12->kind = leaf;
    p12->x = 'a';

    p13->kind = leaf;
    p13->x = 'h';

    p14->kind = leaf;
    p14->x = 'c';

    p15->kind = leaf;
    p15->x = 'f';

    T->left = p2;
    T->right = p3;

    p2->left = p4;
    p2->right = p5;

    p3->left = p6;
    p3->right = p7;

    p6->left = p8;
    p6->right = p9;

    p8->left = p10;
    p8->right = p11;

    p9->left = p12;
    p9->right = p13;

    p10->left = p14;
    p10->right = p15;

    char a;
    position p = T;
    while ((a = getchar()) != '\n' && a != EOF)
    {
        if (a == '0')
        {
            p = p->left;
        }
        else if (a == '1')
        {
            p = p->right;
        }
        if (p->kind == leaf)
        {
            printf("%c", p->x);
            p = T;
        }
    }

    return 0;
}
