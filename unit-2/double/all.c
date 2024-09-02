#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
};

struct Node *head = NULL;

// Function to create a new node
struct Node *newNode(int data) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->prev = NULL;
  node->next = NULL;
  return node;
}

// Function to insert a node after a given node
void insertAfter(struct Node *prevNode, int data) {
  if (prevNode == NULL) {
    printf("Previous node cannot be NULL.\n");
    return;
  }

  struct Node *node = newNode(data);
  node->next = prevNode->next;
  prevNode->next = node;
  node->prev = prevNode;

  if (node->next != NULL) {
    node->next->prev = node;
  }
}

// Function to insert a node before a given node
void insertBefore(struct Node *nextNode, int data) {
  if (nextNode == NULL) {
    printf("Next node cannot be NULL.\n");
    return;
  }

  struct Node *node = newNode(data);
  node->prev = nextNode->prev;
  node->next = nextNode;
  nextNode->prev = node;

  if (node->prev != NULL) {
    node->prev->next = node;
  } else {
    // Update the head if new node is inserted at the beginning
    head = node;
  }
}

// Function to insert a node at the end of the linked list
void insertAtEnd(int data) {
  if (head == NULL) {
    head = newNode(data);
    return;
  }

  struct Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }

  insertAfter(temp, data);
}

// Function to display the list in forward order
void displayForward() {
  struct Node *temp = head;
  if (temp == NULL) {
    printf("List is empty\n");
    return;
  }

  while (temp != NULL) {
    printf("%d <-> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

// Function to display the list in reverse order
void displayReverse() {
  struct Node *temp = head;
  if (temp == NULL) {
    printf("List is empty\n");
    return;
  }

  // Move to the last node
  while (temp->next != NULL) {
    temp = temp->next;
  }

  // Traverse back to the head
  while (temp != NULL) {
    printf("%d <-> ", temp->data);
    temp = temp->prev;
  }
  printf("NULL\n");
}

int main() {
  int choice, data, position, n, i;
  struct Node *node = NULL;

  printf("Enter the number of nodes: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    printf("Enter data for node %d: ", i + 1);
    scanf("%d", &data);
    insertAtEnd(data);
  }

  while (1) {
    printf("\nMenu:\n");
    printf("1. Insert After a Given Node\n");
    printf("2. Insert Before a Given Node\n");
    printf("3. Display Forward\n");
    printf("4. Display Reverse\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter data to insert: ");
      scanf("%d", &data);
      printf("Enter the position after which to insert: ");
      scanf("%d", &position);
      node = head;
      for (i = 1; i < position && node != NULL; i++) {
        node = node->next;
      }
      if (node != NULL) {
        insertAfter(node, data);
      } else {
        printf("Invalid position\n");
      }
      printf("Linked list after insertion: ");
      displayForward();
      break;
    case 2:
      printf("Enter data to insert: ");
      scanf("%d", &data);
      printf("Enter the position before which to insert: ");
      scanf("%d", &position);
      node = head;
      for (i = 1; i < position && node != NULL; i++) {
        node = node->next;
      }
      if (node != NULL) {
        insertBefore(node, data);
      } else {
        printf("Invalid position\n");
      }
      printf("Linked list after insertion ");
      displayForward();
      break;
    case 3:
      printf("Linked list in forward order: ");
      displayForward();
      break;
    case 4:
      printf("Linked list in reverse order: ");
      displayReverse();
      break;
    case 5:
      exit(0);
    default:
      printf("Invalid choice\n");
    }
  }
}