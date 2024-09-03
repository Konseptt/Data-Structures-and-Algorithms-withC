#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
  int data;
  struct Node *next;
};

// Define the Circular Linked List structure
struct CircularLinkedList {
  struct Node *last;
};

// Function to initialize the Circular Linked List
void initialize(struct CircularLinkedList *list) { list->last = NULL; }

// Function to add a Node to the Circular Linked List
void addNode(struct CircularLinkedList *list, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  if (list->last == NULL) {
    newNode->next = newNode;
    list->last = newNode;
  } else {
    newNode->next = list->last->next;
    list->last->next = newNode;
    list->last = newNode;
  }
}

// Function to delete a Node from the Circular Linked List
void deleteNode(struct CircularLinkedList *list, int key) {
  if (list->last == NULL) {
    printf("List is empty.\n");
    return;
  }

  struct Node *temp = list->last, *prev;
  if (temp->next == temp && temp->data == key) {
    free(temp);
    list->last = NULL;
    return;
  }

  if (temp->next->data == key) {
    prev = temp->next;
    temp->next = temp->next->next;
    free(prev);
    return;
  }

  while (temp->next != list->last && temp->next->data != key) {
    temp = temp->next;
  }

  if (temp->next->data == key) {
    prev = temp->next;
    temp->next = temp->next->next;
    if (prev == list->last) {
      list->last = temp;
    }
    free(prev);
  } else {
    printf("Node with data %d not found.\n", key);
  }
}

// Function to display the Circular Linked List
void display(struct CircularLinkedList *list) {
  if (list->last == NULL) {
    printf("List is empty.\n");
    return;
  }

  struct Node *temp = list->last->next;
  do {
    printf("%d -> ", temp->data);
    temp = temp->next;
  } while (temp != list->last->next);
  printf("\n");
}

// Main function
int main() {
  struct CircularLinkedList list;
  initialize(&list);

  int choice, data;
  while (1) {
    printf("1. Add Node\n2. Delete Node\n3. Display List\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter data to add: ");
      scanf("%d", &data);
      addNode(&list, data);
      break;
    case 2:
      printf("Enter data to delete: ");
      scanf("%d", &data);
      deleteNode(&list, data);
      break;
    case 3:
      display(&list);
      break;
    case 4:
      exit(0);
    default:
      printf("Invalid choice.\n");
    }
  }

  return 0;
}