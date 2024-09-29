#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int d;
    struct Node* n;
} Node;

int main() {
    int num, i, pos, search_val, count = 0, index = 0;
    Node *h = NULL, *t = NULL, *new = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        new = (Node*)malloc(sizeof(Node));
        scanf("%d", &new->d);
        new->n = NULL;
        if (h == NULL) h = new;
        else {
            t = h;
            while (t->n != NULL) t = t->n;
            t->n = new;
        }
    }



    // Search for a node
    printf("Enter the value to search for: ");
    scanf("%d", &search_val);
    for (t = h; t != NULL; t = t->n, index++) {
        if (t->d == search_val) {
            printf("Value %d found at index %d.\n", search_val, index);
            break;
        }
    }
    if (t == NULL) printf("Value %d not found in the list.\n", search_val);

    // Count the number of nodes
    for (t = h; t != NULL; t = t->n) count++;
    printf("Total number of nodes: %d\n", count);

    for (t = h; t != NULL; t = t->n) printf("%d -> ", t->d);
    printf("NULL\n");

    while (h != NULL) {
        t = h;
        h = h->n;
        free(t);
    }

    return 0;
}