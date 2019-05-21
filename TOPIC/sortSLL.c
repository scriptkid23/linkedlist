#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct node{
  int data;
  struct node *next;
}node;

node *createNode(int data){
  node *new_node = (node*)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}
void push(node **head,int data){
  node *new_node = createNode(data);

  new_node->next = *head;
  *head = new_node;
}
int length(node **head_ref){
  int counter = 0;
  node *temp = *head_ref;
  while (temp != NULL) {
    counter++;
    temp = temp->next;

    /* code */
  }
  return counter;
}
void reverse(node **head_ref){
  node *prev,*current, *next;
  current = *head_ref;
  prev = NULL;
  while (current != NULL) {
    /* code */
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;

  }
  *head_ref = prev;
}
void show(node **head_ref){
    node *temp = *head_ref;
    while (temp != NULL) {
        printf("%d  ",temp->data);
        temp = temp->next;
    }

}
void update(node **head_ref,int late_data,int new_data){
  node *temp = *head_ref;

  while (temp != NULL && temp->data != late_data) {
    /* code */
    temp= temp->next;
  }
    temp->data = new_data;

}
void reverseData(int *obj_,int *obj__){
  int temp;
   temp = *obj_;
   *obj_ = *obj__;
   *obj__  = temp;
}
void sort(node **head_ref) {
  node *prev = *head_ref;
  node *next;
  while (prev != NULL) {
    next = prev->next;
    while (next != NULL) {
      if(prev->data > next->data){
        reverseData((&prev->data),(&next->data));
      }
      next = next->next;
    }
    prev = prev->next;
  }
}
int main(int argc, char const *argv[]) {
  node *head = NULL;
  int arr[] = {15,25,35,4,5,6,7,80,9,10,100,101,-5,8,55};
  for (int i = 0; i < 15;i++){
    push(&head,arr[i]);
  }
 reverse(&head);

  //show(&head);
  //reverse(&head);

  show(&head);
  printf("\n");
  //update(&head,5,10);
  sort(&head);
  show(&head);
  return 0;
}
