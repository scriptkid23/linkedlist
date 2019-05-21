#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct sv {
  int  mssv;
  char name[30];
  char lop[30];
}sv;
typedef struct node {
  sv *data;
  struct node *next;
  struct node *prev;
}node;
node *createNode(int obj_mssv,char obj_name[30],char obj_lop[30]){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = (sv*)malloc(sizeof(sv));
    new_node->data->mssv = obj_mssv;
    strcpy(new_node->data->name,obj_name);
    strcpy(new_node->data->lop,obj_lop);
    new_node->next = new_node->prev =  NULL;
    return new_node;
}
void push(node **head_ref,int obj_mssv,char obj_name[30],char obj_lop[30]){
  node *new_node = createNode(obj_mssv,obj_name,obj_lop);
  if(*head_ref == NULL){
    new_node->next = new_node->prev = NULL;
    *head_ref = new_node;
    return;
  }
  new_node->next = *head_ref;
  (*head_ref)->prev = new_node;
  *head_ref =new_node;
}
void reverse(char *obj_,char *obj__){

}
void sortForName(node **head_ref){
  node *temp = *head_ref;
  node *temp_;
  while (temp != NULL) {

  }

}
void showList(node **head_ref){
  node *temp = *head_ref;
  while (temp != NULL) {
    /* code */
    printf("%d\t%s\t%s\t\n",temp->data->mssv,temp->data->name,temp->data->lop);
    temp = temp->next;
  }
}
int main(int argc, char const *argv[]) {

  node *head = NULL;
  push(&head,9,"hello world","world");
  push(&head,3,"hello world1","world");
  push(&head,5,"hello world2","world");
  push(&head,1,"hello world3","world");
  push(&head,18,"hello world5","world");
  push(&head,3,"hello world6","world");

 //printf("%s\n",head->next->next->prev->data->name);
 showList(&head);
  return 0;
}
