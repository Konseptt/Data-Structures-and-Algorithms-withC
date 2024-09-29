#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int d;
    struct Node *n, *p;
} Node;

int main() {
    int num, i, pos, search_val, count = 0, index = 0;
    Node *h = NULL, *t = NULL, *new = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        new = (Node*)malloc(sizeof(Node));
        scanf("%d", &new->d);
        new->n = new->p = NULL;
        if (h == NULL) h = new;
        else {
            t = h;
            while (t->n) t = t->n;
            t->n = new;
            new->p = t;
        }
    }

    // Delete a node at the end
    if (h) {
        t = h;
        while (t->n) t = t->n;
        if (t->p) t->p->n = NULL;
        else h = NULL;
        free(t);
    }

    // Delete a node at the start
    if (h) {
        t = h;
        h = h->n;
        if (h) h->p = NULL;
        free(t);
    }

    // Delete a node at a given position
    printf("Enter the position to delete the node (0-based index): ");
    scanf("%d", &pos);
    if (pos == 0 && h) {
        t = h;
        h = h->n;
        if (h) h->p = NULL;
        free(t);
    } else {
        t = h;
        for (i = 0; i < pos && t; i++) t = t->n;
        if (t) {
            if (t->p) t->p->n = t->n;
            if (t->n) t->n->p = t->p;
            free(t);
        } else {
            printf("Position out of bounds\n");
        }
    }

    // Search for a node
    printf("Enter the value to search for: ");
    scanf("%d", &search_val);
    for (t = h; t; t = t->n, index++) {
        if (t->d == search_val) {
            printf("Value %d found at index %d.\n", search_val, index);
            break;
        }
    }
    if (!t) printf("Value %d not found in the list.\n", search_val);

    // Count the number of nodes
    for (t = h; t; t = t->n) count++;
    printf("Total number of nodes: %d\n", count);

    for (t = h; t; t = t->n) printf("%d -> ", t->d);
    printf("NULL\n");

    while (h) {
        t = h;
        h = h->n;
        free(t);
    }

    return 0;
}