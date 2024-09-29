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

    // Delete a node at the end
    if (h) {
        t = h;
        while (t->n->n != h) t = t->n;
        free(t->n);
        t->n = h;
    }

    // Delete a node at the start
    if (h) {
        t = h;
        while (t->n != h) t = t->n;
        Node* first = h;
        h = h->n;
        t->n = h;
        free(first);
    }

    // Delete a node at a given position
    printf("Enter the position to delete the node (0-based index): ");
    scanf("%d", &pos);
    if (pos == 0 && h) {
        t = h;
        while (t->n != h) t = t->n;
        Node* first = h;
        h = h->n;
        t->n = h;
        free(first);
    } else {
        t = h;
        for (i = 0; i < pos - 1 && t->n != h; i++) t = t->n;
        if (t->n != h) {
            Node* del = t->n;
            t->n = del->n;
            free(del);
        } else {
            printf("Position out of bounds\n");
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