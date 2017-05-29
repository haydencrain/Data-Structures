#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node_t;

void Insert(Node_t** headPtr, int x) {
  Node_t* temp = (Node_t*)malloc(sizeof(Node_t));
  temp->data = x;
  temp->next = *headPtr;
  *headPtr = temp;
}

void Print(Node_t* head) {
  printf("List is:");
  while (head != NULL) {
    printf(" %d", head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {
  Node_t* head = NULL;
  printf("How many numbers? > ");
  int n, i, x;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    printf("Enter the number > ");
    scanf("%d", &x);
    Insert(&head, x);
    Print(head);
  }
}
