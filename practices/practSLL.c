#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node {
   int data;
   struct node *next;
} node;

node *createNode(int data){
  node *new_node = (node*)malloc(sizeof(node));
  new_node->next = NULL;
  new_node->data = data;
  return new_node;
}

void push( node **head_ref,int data){
  node *new_node = createNode(data);
  new_node->next = *head_ref;
  *head_ref = new_node;
}
void append(node **head_ref,int data){
  node *new_node = createNode(data);
  node *temp = *head_ref;

  if(*head_ref == NULL){
    new_node->next = NULL;
    *head_ref = new_node;
    return;
  }

  while (true) {
    temp = temp->next;
    if(temp->next == NULL) break;
  }
  //printf("%d\n",temp->data);
  temp->next = new_node;
  new_node->next = NULL;

}
void show(node *head_ref){
    node *temp = head_ref;
    while (temp != NULL) {
      /* code */
      printf("%d\n",temp->data );
      temp = temp->next;
    }
}
int main(int argc, char const *argv[]) {

  node *head = NULL;

  push(&head,10);
  push(&head,101);
  append(&head,11);
//  printf("%d\n",head->next->data);
  //printf("helloworld\n");
  show(head);
  return 0;
}
