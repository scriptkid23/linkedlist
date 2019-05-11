#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct doublyNode{
  int data;
  struct doublyNode *next;
  struct doublyNode *prev;
}d_node;

void push(d_node **head,int data){
    //todo:
    d_node *new_node = (d_node*)malloc(sizeof(d_node));
    new_node->next = *head;
    new_node->prev = NULL;
    new_node->data = data;

    if(*head != NULL){
      (*head)->prev = new_node;
    }
    (*head) = new_node;
}
int  lengthDnode(d_node **head){
  d_node *temp = *head;
  int counter = 0;
  while (temp != NULL) {
    counter++;
    temp = temp->next;
  }
//  printf("%d\n",counter);
return counter;
}
void insertFrontData(d_node **head,int data,int i_data){
  //TODO:
  d_node *new_node = (d_node*)malloc(sizeof(d_node));
  d_node *temp = *head;
  int counter =0;
  while (temp != NULL && temp->data != data) {

              counter++;

    /* code */temp = temp->next;

  }
  if(counter == lengthDnode(head)){
    printf("NOT FOUND");
  return;
}
  new_node->data = i_data;
  new_node->next = temp->next;
  new_node->prev =temp;
  temp->next->prev = new_node;
  temp->next = new_node;

  //printf("%d",temp->data);
}
void deleteDnode(d_node **head,int data){
  d_node *temp = *head;
  if(temp != NULL && temp->data ==data) {
  (*head) = temp->next;
  free(temp);
  return;  /* code */
  }
  while (temp!= NULL && temp->data != data) {
    /* code */
    temp = temp->next;
  }
  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
  free(temp);
  //printf("%d", temp->data);
}
void showNode(d_node **head){
  d_node *temp = *head;
  printf("head<-");
  while (temp != NULL) {
   printf("%d\t",temp->data);
   temp = temp->next;
  }
}

//void insertFrontData(d_node)
int main(int argc, char const *argv[]) {
  d_node *head = NULL;
  push(&head,10);
  push(&head,15);
  push(&head,16);
  push(&head,17);
  push(&head,18);
insertFrontData(&head,13,19);
  showNode(&head);
  printf("\n");
  lengthDnode(&head);
  deleteDnode(&head,15);
  showNode(&head);

  return 0;
}
