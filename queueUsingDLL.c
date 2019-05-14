#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node {

  int data;
  struct node *next;
  struct node *prev;
}node;
typedef struct queue{
  node *front;
  node *rear;
}queue;

node *createNode(int data){
  node *new_node =  (node*)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = new_node->prev = NULL;
  return new_node;
}
queue *createQueue(){
  queue *new_queue = (queue*)malloc(sizeof(queue));
  new_queue->front = new_queue->rear = NULL;
  return new_queue;
}
int lengthQueue(queue *obj){
  int counter = 0;
  node *temp = obj->front;
 while (temp != NULL) {
   counter++;
   temp = temp->next;
//   if(temp == NULL) break;
  }
  return counter;
}

void enQueue(queue *obj,int data){
  node *new_node = createNode(data);
  if(obj->front == NULL){
    obj->front = obj->rear = new_node;
    return;
  }
    node *temp ;
    obj->rear->next = new_node;
    temp = obj->rear;
    obj->rear = new_node;
    obj->rear->prev = temp;
    obj->rear->next = NULL;
}
void deQueue(queue *obj){
  if(obj->front == NULL) return;
  node *temp = obj->front;
  obj->front = obj->front->next;
  obj->front->prev = NULL;
//  printf("FRONT :%d",obj->front->data);
free(temp);
}
//
bool checkExist(queue *obj,int data){
  node *temp = obj->front;
  int counter = 0;
  while (temp!= NULL && temp->data != data) {
    counter++;
    temp = temp->next;
  }
  if(counter == lengthQueue(obj)){
    return false;
  }else{
    return true;
  }
}
//
void deleteOfData(queue *obj, int data){
  node *temp = obj->rear;
if(obj->front->data == data) {deQueue(obj); return;}
if(temp->data == data){
  printf("DELETE NOT SUCCESS\n");
  return;
}
if(!checkExist(obj,data)){
  printf("DATA NOT FOUND TO DELETE\n");
  return;
}
while (obj->front != NULL && temp->data != data) {
  /* code */
  temp = temp->prev;
}
temp->next->prev = temp->prev;
temp->prev->next = temp->next;
free(temp);
}

void insertOfData(queue *obj,int data,int i_data){
  //TODO:
  node *new_node = createNode(i_data);
  new_node->prev = NULL;
  if(obj->front->data  == data){
    new_node->next = obj->front;
    obj->front->prev  = new_node;
    obj->front = new_node;
    return;
  }
  if(!checkExist(obj,data)){
    printf("DATA NOT FOUND TO INSERT\n");
    return;
  }
  node *temp = obj->rear;
  while (obj->front != NULL && temp->data != data) {
    temp = temp->prev;
  }
  new_node->next = temp;
  new_node->prev = temp->prev;
  temp->prev->next = new_node;
  temp->prev = new_node;

  //printf("%d\n",temp->data );
}

void showQueue(queue *obj){
   node *temp = obj->rear;
   printf("rear----->");
   while (temp != NULL) {
     /* code */
     printf("%d\t",temp->data);
     temp = temp->prev;
   }
   printf("----->front\n");
}
int main(int argc, char const *argv[]) {
  queue *queueRoot = createQueue();
  enQueue(queueRoot,10);
  enQueue(queueRoot,15);
  enQueue(queueRoot,16);
  enQueue(queueRoot,18);
  enQueue(queueRoot,17);
  deleteOfData(queueRoot,555);
  insertOfData(queueRoot,565,15);
  //insertOfData(queueRoot,15,119);
//printf("%d",queueRoot->rear->prev->prev->prev->next->data);

//printf("%d",queueRoot->front->data);
 showQueue(queueRoot);
  //printf("LENGTH OF QUEUE: %d\n",lengthQueue(queueRoot));
  return 0;
}
