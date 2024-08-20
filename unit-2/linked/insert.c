#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *temp;
    int n, i, data, pos;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = data;

        if (head == NULL) {
            head = temp;
            temp->next = NULL;
        } else {
            temp->next = head;
            head = temp;
        }
    }

    printf("Linked list before insertion: ");
    struct Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    printf("Enter the element to insert: ");
    scanf("%d", &data);

    printf("Enter the position to insert: ");
    scanf("%d", &pos);

    if (pos > n + 1 || pos < 1) {
        printf("Invalid position\n");
    } else {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = data;

        if (pos == 1) {
            temp->next = head;
            head = temp;
        } else {
            struct Node *current = head;
            for (i = 1; i < pos - 1; i++) {
                current = current->next;
            }
            temp->next = current->next;
            current->next = temp;
        }

        printf("Linked list after insertion: ");
        struct Node *current = head;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}