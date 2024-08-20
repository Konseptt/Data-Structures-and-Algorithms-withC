#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *newNode, *temp;
    int data, position, count;

    while (1) {
        printf("Enter data (or -1 to exit): ");
        scanf("%d", &data);
        if (data == -1) break;

        printf("Enter position: ");
        scanf("%d", &position);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;

        if (position == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            temp = head;
            count = 1;
            while (temp != NULL && count < position - 1) {
                temp = temp->next;
                count++;
            }

            if (temp == NULL) {
                printf("Invalid position\n");
            } else {
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }

        printf("Linked list: ");
        temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}