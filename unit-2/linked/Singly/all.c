#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *head = NULL;

// Function to create a new node
struct Node *newNode(int data) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  return node;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(int data) {
  printf("Inserting %d at the beginning...\n", data);
  struct Node *node = newNode(data);
  node->next = head;
  head = node;
  printf("Linked list after insertion: ");
  printList();
}

// Function to insert a node at the end of the linked list
void insertAtEnd(int data) {
  printf("Inserting %d at the end...\n", data);
  struct Node *node = newNode(data);
  if (head == NULL) {
    head = node;
    // printf("Linked list after insertion: ");
    // printList();
    return;
  }
  struct Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = node;
  // printf("Linked list after insertion: ");
  // printList();
}

// Function to insert a node at a given position
void insertAtPosition(int data, int position) {
  printf("Inserting %d at position %d...\n", data, position);
  if (position < 1) {
    printf("Invalid position\n");
    return;
  }
  if (position == 1) {
    insertAtBeginning(data);
    return;
  }
  struct Node *node = newNode(data);
  struct Node *temp = head;
  int count = 1;
  while (count < position - 1 && temp->next != NULL) {
    temp = temp->next;
    count++;
  }
  if (count == position - 1) {
    node->next = temp->next;
    temp->next = node;
    printf("Linked list after insertion: ");
    printList();
  } else {
    printf("Invalid position\n");
  }
}

// Function to delete a node at the beginning of the linked list
void deleteAtBeginning() {
  printf("Deleting node at the beginning...\n");
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }
  struct Node *temp = head;
  head = head->next;
  free(temp);
  printf("Linked list after deletion: ");
  printList();
}

// Function to delete a node at the end of the linked list
void deleteAtEnd() {
  printf("Deleting node at the end...\n");
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }
  if (head->next == NULL) {
    free(head);
    head = NULL;
    printf("Linked list after deletion: ");
    printList();
    return;
  }
  struct Node *temp = head;
  while (temp->next->next != NULL) {
    temp = temp->next;
  }
  free(temp->next);
  temp->next = NULL;
  printf("Linked list after deletion: ");
  printList();
}

// Function to delete a node at a given position
void deleteAtPosition(int position) {
  printf("Deleting node at position %d...\n", position);
  if (position < 1) {
    printf("Invalid position\n");
    return;
  }
  if (position == 1) {
    deleteAtBeginning();
    return;
  }
  struct Node *temp = head;
  int count = 1;
  while (count < position - 1 && temp->next != NULL) {
    temp = temp->next;
    count++;
  }
  if (count == position - 1 && temp->next != NULL) {
    struct Node *toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
    printf("Linked list after deletion: ");
    printList();
  } else {
    printf("Invalid position\n");
  }
}

// Function to print the linked list
void printList() {
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }
  struct Node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  int choice, data, position, n, i;
  printf("Enter the number of nodes: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    printf("Enter data for node %d: ", i + 1);
    scanf("%d", &data);
    insertAtEnd(data);
  }
  printf("Linked list: ");
  printList();
  while (1) {
    printf("\nMenu:\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert at Position\n");
    printf("4. Delete at Beginning\n");
    printf("5. Delete at End\n");
    printf("6. Delete at Position\n");
    printf("7. Print List\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter data to insert: ");
      scanf("%d", &data);
      insertAtBeginning(data);
      break;
    case 2:
      printf("Enter data to insert: ");
      scanf("%d", &data);
      insertAtEnd(data);
      break;
    case 3:
      printf("Enter data to insert: ");
      scanf("%d", &data);
      printf("Enter position to insert: ");
      scanf("%d", &position);
      insertAtPosition(data, position);
      break;
    case 4:
      deleteAtBeginning();
      break;
    case 5:
      deleteAtEnd();
      break;
    case 6:
      printf("Enter position to delete: ");
      scanf("%d", &position);
      deleteAtPosition(position);
      break;
    case 7:
      printf("Linked list: ");
      printList();
      break;
    case 8:
      exit(0);
    default:
      printf("Invalid choice\n");
    }
  }
}