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
void InsertAtNth(Node_t** headPtr, int data, int n);
void Print(Node_t* head);

/*******************************************************************************
Main
*******************************************************************************/
int main() {
  Node_t* head = NULL;
  printf("How many numbers? > ");
  int n, i, x, y;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    printf("Enter the number > ");
    scanf("%d", &x);
    printf("Where should it be placed? > ");
    scanf("%d", &y);
    InsertAtNth(&head, x, y);
    Print(head);
  }
}

/*******************************************************************************
Insert at nth position Function
*******************************************************************************/
void InsertAtNth(Node_t** headPtr, int data, int n) {
  Node_t* temp1 = (Node_t*)malloc(sizeof(Node_t));
  temp1->data = data;
  temp1->next = NULL;
  if (n == 0) {
    temp1->next = *headPtr;
    *headPtr = temp1;
    return;
  }
  Node_t* temp2 = *headPtr;
  int i;
  for (i = 0; i < n - 1; i++) {
    temp2 = temp2->next;
  }
  temp1->next = temp2->next;
  temp2->next = temp1;
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
