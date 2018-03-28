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
void Delete(Node_t** headPtr, int n);
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
  int n;
  printf("Enter a Position > ");
  scanf("%d", &n);
  Delete(&head, n);
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
Delete Function
*******************************************************************************/
void Delete(Node_t** headPtr, int n) {
  Node_t* temp1 = *headPtr;
  if (n == 0) {
    *headPtr = temp1->next;
    free(temp1);
  }
  int i;
  for (i = 0; i < n - 1; i++) {
    temp1 = temp1->next;
  }
  Node_t* temp2 = temp1->next;
  temp1->next = temp2->next;
  free(temp2);
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
