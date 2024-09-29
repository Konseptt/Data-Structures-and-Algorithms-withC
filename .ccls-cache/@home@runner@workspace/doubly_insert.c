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
            while (t->n != NULL) t = t->n;
            t->n = new;
            new->p = t;
        }
    }

    // Insert a new node at the end
    new = (Node*)malloc(sizeof(Node));
    printf("Enter data for the new node to insert at the end: ");
    scanf("%d", &new->d);
    new->n = new->p = NULL;
    if (h == NULL) h = new;
    else {
        t = h;
        while (t->n != NULL) t = t->n;
        t->n = new;
        new->p = t;
    }

    // Insert a new node at the start
    new = (Node*)malloc(sizeof(Node));
    printf("Enter data for the new node to insert at the start: ");
    scanf("%d", &new->d);
    new->n = h;
    if (h != NULL) h->p = new;
    h = new;

    // Insert a new node at a given position
    printf("Enter the position to insert the new node (0-based index): ");
    scanf("%d", &pos);
    new = (Node*)malloc(sizeof(Node));
    printf("Enter data for the new node to insert at position %d: ", pos);
    scanf("%d", &new->d);

    if (pos == 0) {
        new->n = h;
        if (h != NULL) h->p = new;
        h = new;
    } else {
        t = h;
        for (i = 0; i < pos - 1 && t != NULL; i++) t = t->n;
        if (t != NULL) {
            new->n = t->n;
            new->p = t;
            if (t->n != NULL) t->n->p = new;
            t->n = new;
        } else {
            printf("Position out of bounds\n");
            free(new);
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