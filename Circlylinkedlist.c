#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *next;
}node;

void push(node **head_ref,int data){
  node *new_node = (node*)malloc(sizeof(node));
  node *temp = *head_ref;
  node *temp_;
  new_node->data = data;
  if(*head_ref == NULL){
        new_node->next = new_node;
        *head_ref = new_node;
        printf("PUSH DATA: %d\n",new_node->data);
        return;
  }
  while (true) {
    temp_ = temp;
    temp = temp->next;
    if(temp == (*head_ref)) break;
  }
  temp_->next = new_node;
  new_node->next = *head_ref;
  *head_ref = new_node;
  printf("PUSH DATA: %d\n",new_node->data);
}
int lengthNode(node **head_ref){
  node *temp = *head_ref;
  int counter = 0;
  while (true) {

    counter++;
    temp = temp->next;
    if(temp == *head_ref) break;

  }
  return counter;
}
void insertFrontData(node **head_ref, int data, int i_data){
    //TODO: CODE FAIL
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = i_data;
    node *temp = *head_ref;
    node *temp_;
    while (true) {
      temp_ =temp;
      temp = temp->next;
      if(temp == *head_ref || temp->data == data) break;
    }
    //printf("temp: %d\n",temp->data);
    //printf("temp_: %d\n",temp_->data);

    new_node->next = temp_->next;

    temp_->next = new_node;
    //new_node->next = temp->next;
    //temp->next = new_node;

}
void pop(node **head_ref){
  node *temp = *head_ref;
  node *temp_;
  while (true) {
    /* code */
    temp_ =temp;
    temp = temp->next;
    if(temp == *head_ref) break;
  }
//  printf("TEMP DATA: %d\n",temp->data);
//  printf("TEMP_ DATA %d\n",temp_->data);
  *head_ref  = temp->next;
  temp_->next = *head_ref;
  free(temp);
}
void deleleOfData(node **head_ref,int data){
 node *temp = *head_ref;
 node *temp_;
 if(temp->data == data){
   pop(head_ref);
   return;
 }
 while (true) {
   temp_ = temp;
   temp =temp->next;
   if(temp == *head_ref || temp->data == data) break;
 }
// printf("temp_: %d\n",temp_->data);
// printf("temp : %d \n",temp->data);
  temp_->next = temp->next;
  free(temp);


}


int getHead(node **obj){
  return (*obj)->data;
}
void showCirclyNode(node **head_ref) {
  node *temp = *head_ref;
  while (true) {
    printf("%d\n",temp->data);
    temp = temp->next;
    if(temp == (*head_ref)) break;

  }
}

int main(int argc, char const *argv[]) {
  node *head = NULL;
//  push(&head,5);
  push(&head,15);
  push(&head,88);
  push(&head,53);
  push(&head,9);
  push(&head,5);
  push(&head,6);
  push(&head,55);
  push(&head,55);
  push(&head,555);
  printf("\n");
//  insertFrontData(&head,555,55555);
//  insertFrontData(&head,555,565);
  //printf("%d",lengthNode(&head));
  pop(&head);
  pop(&head);
  deleleOfData(&head,53);
  showCirclyNode(&head);

  return 0;
}
