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
void PrintReverse(Node_t* head);

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
  printf("Reverse Print...\n");
  PrintReverse(head);
  return 0;
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
Print Reverse Function (using recursion)
*******************************************************************************/
void PrintReverse(Node_t* p) {
  if (p == NULL) {
    return;
  }
  PrintReverse(p->next);
  printf(" %d", p->data);
}
/*******************************************************************************
Print Function (using recursion)
*******************************************************************************/
void Print(Node_t* p) {
  if (p == NULL) {
    printf("\n");
    return;
  }
  printf(" %d", p->data);
  Print(p->next);
}
