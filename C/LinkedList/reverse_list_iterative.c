/*******************************************************************************
Header Files
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*******************************************************************************
List Structure
*******************************************************************************/
typedef struct Node {
  int data;
  struct Node* next;
} Node_t;

/*******************************************************************************
Function Prototypes
*******************************************************************************/
void Insert(Node_t** headPtr, int x);
void Reverse(Node_t** headPtr);
void Print(Node_t* head);

/*******************************************************************************
Main
*******************************************************************************/
int main() {
  Node_t* head = NULL;
  Insert(&head, 2);
  Insert(&head, 4);
  Insert(&head, 6);
  Insert(&head, 5);
  Print(head);
  Reverse(&head);
  printf("Reversing List...\n");
  Print(head);
}

/*******************************************************************************
Insert Function
*******************************************************************************/
void Insert(Node_t** headPtr, int x) {
  Node_t* temp = (Node_t*)malloc(sizeof(Node_t));
  temp->data = x;
  temp->next = *headPtr;
  *headPtr = temp;
}

/*******************************************************************************
Reverse Function
*******************************************************************************/
void Reverse(Node_t** headPtr) {
  Node_t *current, *prev, *next;
  current = *headPtr;
  prev = NULL;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *headPtr = prev;
}

/*******************************************************************************
Print Function
*******************************************************************************/
void Print(Node_t* head) {
  printf("List is:");
  while (head != NULL) {
    printf(" %d", head->data);
    head = head->next;
  }
  printf("\n");
}
