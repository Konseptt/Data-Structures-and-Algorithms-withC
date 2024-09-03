#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(Node **head, int data) {
  Node *newNode = createNode(data);
  if (*head != NULL) {
    (*head)->prev = newNode;
    newNode->next = *head;
  }
  *head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(Node **head, int data) {
  Node *newNode = createNode(data);
  if (*head == NULL) {
    *head = newNode;
    return;
  }
  Node *temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->prev = temp;
}

// Function to insert a node at a given position
void insertAtPosition(Node **head, int data, int position) {
  if (position == 1) {
    insertAtBeginning(head, data);
    return;
  }
  Node *newNode = createNode(data);
  Node *temp = *head;
  for (int i = 1; i < position - 1 && temp != NULL; i++) {
    temp = temp->next;
  }
  if (temp == NULL) {
    printf("Position out of bounds\n");
    return;
  }
  newNode->next = temp->next;
  if (temp->next != NULL) {
    temp->next->prev = newNode;
  }
  temp->next = newNode;
  newNode->prev = temp;
}

// Function to delete a node from the beginning
void deleteFromBeginning(Node **head) {
  if (*head == NULL) {
    printf("List is empty\n");
    return;
  }
  Node *temp = *head;
  *head = (*head)->next;
  if (*head != NULL) {
    (*head)->prev = NULL;
  }
  free(temp);
}

// Function to delete a node from the end
void deleteFromEnd(Node **head) {
  if (*head == NULL) {
    printf("List is empty\n");
    return;
  }
  Node *temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  if (temp->prev != NULL) {
    temp->prev->next = NULL;
  } else {
    *head = NULL;
  }
  free(temp);
}

// Function to delete a node from a given position
void deleteFromPosition(Node **head, int position) {
  if (*head == NULL) {
    printf("List is empty\n");
    return;
  }
  Node *temp = *head;
  for (int i = 1; i < position && temp != NULL; i++) {
    temp = temp->next;
  }
  if (temp == NULL) {
    printf("Position out of bounds\n");
    return;
  }
  if (temp->prev != NULL) {
    temp->prev->next = temp->next;
  } else {
    *head = temp->next;
  }
  if (temp->next != NULL) {
    temp->next->prev = temp->prev;
  }
  free(temp);
}

// Function to search for a node
Node *search(Node *head, int data) {
  Node *temp = head;
  while (temp != NULL) {
    if (temp->data == data) {
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}

// Function to count the number of nodes
int countNodes(Node *head) {
  int count = 0;
  Node *temp = head;
  while (temp != NULL) {
    count++;
    temp = temp->next;
  }
  return count;
}

// Function to display the list
void displayList(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// Main function
int main() {
  Node *head = NULL;
  int choice, data, position;

  while (1) {
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert at Position\n");
    printf("4. Delete from Beginning\n");
    printf("5. Delete from End\n");
    printf("6. Delete from Position\n");
    printf("7. Search\n");
    printf("8. Count Nodes\n");
    printf("9. Display List\n");
    printf("10. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter data: ");
      scanf("%d", &data);
      insertAtBeginning(&head, data);
      break;
    case 2:
      printf("Enter data: ");
      scanf("%d", &data);
      insertAtEnd(&head, data);
      break;
    case 3:
      printf("Enter data: ");
      scanf("%d", &data);
      printf("Enter position: ");
      scanf("%d", &position);
      insertAtPosition(&head, data, position);
      break;
    case 4:
      deleteFromBeginning(&head);
      break;
    case 5:
      deleteFromEnd(&head);
      break;
    case 6:
      printf("Enter position: ");
      scanf("%d", &position);
      deleteFromPosition(&head, position);
      break;
    case 7:
      printf("Enter data to search: ");
      scanf("%d", &data);
      Node *foundNode = search(head, data);
      if (foundNode != NULL) {
        printf("Node found\n");
      } else {
        printf("Node not found\n");
      }
      break;
    case 8:
      printf("Number of nodes: %d\n", countNodes(head));
      break;
    case 9:
      displayList(head);
      break;
    case 10:
      exit(0);
    default:
      printf("Invalid choice\n");
    }
  }

  return 0;
}