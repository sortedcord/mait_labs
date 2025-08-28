#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Node structure
struct Node {
  int roll;
  int age;
  char name[50];
  struct Node *next;
};

// Function to create a new node
struct Node *createNode(char name[], int age, int roll) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->roll = roll;
  newNode->age = age;
  strcpy(newNode->name, name);
  newNode->next = NULL;
  return newNode;
}

// Insert a node at a given position
void insertAtPos(struct Node **head, int pos, char name[], int age, int roll) {
  struct Node *newNode = createNode(name, age, roll);

  if (pos == 1) {
    newNode->next = *head;
    *head = newNode;
    return;
  }

  struct Node *temp = *head;
  for (int i = 1; temp != NULL && i < pos - 1; i++) {
    temp = temp->next;
  }

  if (temp == NULL) {
    printf("Position out of range\n");
    free(newNode);
    return;
  }

  newNode->next = temp->next;
  temp->next = newNode;
}

// Delete a node by roll number
void deleteByRoll(struct Node **head, int roll) {
  struct Node *temp = *head, *prev = NULL;

  while (temp != NULL && temp->roll != roll) {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL) {
    printf("Roll number %d not found\n", roll);
    return;
  }

  if (prev == NULL) {
    *head = temp->next;
  } else {
    prev->next = temp->next;
  }

  free(temp);
}

// Reverse the linked list
void reverseList(struct Node **head) {
  struct Node *prev = NULL;
  struct Node *curr = *head;
  struct Node *next = NULL;

  while (curr != NULL) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  *head = prev;
}

// Print the linked list
void printList(struct Node *head) {
  struct Node *temp = head;
  while (temp != NULL) {
    printf("Roll: %d, Name: %s, Age: %d\n", temp->roll, temp->name, temp->age);
    temp = temp->next;
  }
}

int main() {
  struct Node *head = NULL;

  insertAtPos(&head, 1, "Elon", 19, 0);
  insertAtPos(&head, 2, "Mark", 20, 1);
  insertAtPos(&head, 3, "Sam", 18, 2);

  printf("Original list:\n");
  printList(head);

  insertAtPos(&head, 4, "Namo", 21, 1);
  printf("\nAfter insertion at position 1:\n");
  printList(head);

  deleteByRoll(&head, 2);
  printf("\nAfter deletion of Roll no 2:\n");
  printList(head);

  reverseList(&head);
  printf("\nAfter Reversal:\n");
  printList(head);

  printf("Aditya Gupta CST789");
  return 0;
}


