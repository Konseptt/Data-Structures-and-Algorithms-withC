#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    int n, dataToDelete;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    struct Node *head = NULL;
    struct Node *temp = NULL;

    // Create linked list
    for (int i = 0; i < n; i++) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &temp->data);
        temp->next = head;
        head = temp;
    }

    // Print the initial linked list
    printf("Initial linked list: ");
    struct Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    printf("Enter the data value to delete: ");
    scanf("%d", &dataToDelete);

    // Delete node with specified data
    current = head;
    struct Node *previous = NULL;
    while (current != NULL) {
        if (current->data == dataToDelete) {
            if (previous == NULL) {
                // Delete first node
                head = current->next;
                free(current);
            } else {
                // Delete any other node
                previous->next = current->next;
                free(current);
            }
            break; // Exit loop after deletion
        }
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Data value not found in the list.\n");
    }

    // Print the linked list after deletion
    printf("Linked list after deletion: ");
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}