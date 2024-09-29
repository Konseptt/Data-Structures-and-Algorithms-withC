#include <stdio.h>
#include <stdlib.h>

struct Node {
    int d;
    struct Node* n;
};

int main() {
    int num, i, pos;
    struct Node *h = NULL, *t = NULL, *new = NULL, *prev = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        new = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &new->d);
        new->n = NULL;
        if (h == NULL) h = new;
        else {
            t = h;
            while (t->n != NULL) t = t->n;
            t->n = new;
        }
    }

    // Delete a node at the end
    if (h != NULL) {
        if (h->n == NULL) {
            free(h);
            h = NULL;
        } else {
            t = h;
            while (t->n->n != NULL) t = t->n;
            free(t->n);
            t->n = NULL;
        }
    }

    // Delete a node at the start
    if (h != NULL) {
        t = h;
        h = h->n;
        free(t);
    }

    // Delete a node at a given position
    printf("Enter the position to delete the node (0-based index): ");
    scanf("%d", &pos);

    if (pos == 0 && h != NULL) {
        t = h;
        h = h->n;
        free(t);
    } else {
        t = h;
        for (i = 0; i < pos - 1 && t != NULL; i++) t = t->n;
        if (t != NULL && t->n != NULL) {
            prev = t->n;
            t->n = t->n->n;
            free(prev);
        } else {
            printf("Position out of bounds\n");
        }
    }

    for (t = h; t != NULL; t = t->n) printf("%d -> ", t->d);
    printf("NULL\n");

}