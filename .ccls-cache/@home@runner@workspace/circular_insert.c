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
        if (!h) {
            h = new;
            new->n = h;
        } else {
            t = h;
            while (t->n != h) t = t->n;
            t->n = new;
            new->n = h;
        }
    }

    // Insert a new node at the end
    new = (Node*)malloc(sizeof(Node));
    printf("Enter data for the new node to insert at the end: ");
    scanf("%d", &new->d);
    t = h;
    while (t->n != h) t = t->n;
    t->n = new;
    new->n = h;

    // Insert a new node at the start
    new = (Node*)malloc(sizeof(Node));
    printf("Enter data for the new node to insert at the start: ");
    scanf("%d", &new->d);
    t = h;
    while (t->n != h) t = t->n;
    new->n = h;
    t->n = new;
    h = new;

    // Insert a new node at a given position
    printf("Enter the position to insert the new node (0-based index): ");
    scanf("%d", &pos);
    new = (Node*)malloc(sizeof(Node));
    printf("Enter data for the new node to insert at position %d: ", pos);
    scanf("%d", &new->d);

    if (pos == 0) {
        t = h;
        while (t->n != h) t = t->n;
        new->n = h;
        t->n = new;
        h = new;
    } else {
        t = h;
        for (i = 0; i < pos - 1 && t->n != h; i++) t = t->n;
        if (t->n != h) {
            new->n = t->n;
            t->n = new;
        } else {
            printf("Position out of bounds\n");
            free(new);
        }
    }

    // Search for a node
    printf("Enter the value to search for: ");
    scanf("%d", &search_val);
    t = h;
    do {
        if (t->d == search_val) {
            printf("Value %d found at index %d.\n", search_val, index);
            break;
        }
        t = t->n;
        index++;
    } while (t != h);
    if (t == h) printf("Value %d not found in the list.\n", search_val);

    // Count the number of nodes
    t = h;
    do {
        count++;
        t = t->n;
    } while (t != h);
    printf("Total number of nodes: %d\n", count);

    t = h;
    do {
        printf("%d -> ", t->d);
        t = t->n;
    } while (t != h);
    printf("(back to head)\n");

    // Free the nodes
    t = h;
    Node* next;
    do {
        next = t->n;
        free(t);
        t = next;
    } while (t != h);

    return 0;
}