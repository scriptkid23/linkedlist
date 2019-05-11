#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
  int data;
  struct node *next;
}qnode;

typedef struct queue{
  qnode *front, *rear;
}queue;

qnode *createNode(int data){
  qnode *node = (qnode*)malloc(sizeof(qnode));
  node->data = data;
  node->next = NULL;
  return node;
}

queue *createQueue(){
  queue *nqueue = (queue*)malloc(sizeof(queue));
  nqueue->front = nqueue->rear = NULL;
  return nqueue;
}
//tạo 1 queue mới
void enQueue(queue *obj, int data){
  qnode *new_node = createNode(data);
  if(obj->front == NULL){
    obj->front = obj->rear = new_node;
    return;
  }
  obj->rear->next = new_node;
  obj->rear = new_node;
}
// đẩy queue ra ngoài
void deQueue(queue *obj) {
  /* code */
  qnode *temp = obj->front;
  obj->front = obj->front->next;
  free(temp);
}
//độ dài của queue
int lengthQueue(queue *obj){
  qnode *temp = obj->front;
  int counter = 0;
  while (temp != NULL) {
    counter++;
    temp = temp->next;
  }
  return counter;
}

void deleteOfdata(queue *obj,int data){
  qnode *temp = obj->front;
  qnode *temp_;
  if(temp != NULL && temp->data == data){
    deQueue(obj);
    return;
  }
  int counter = 0;
  while (temp != NULL && temp->data != data) {
    counter++;
    temp_ = temp ;
    temp = temp->next;
  }
  if(counter == lengthQueue(obj))
   {
     printf("NOT FOUND TO DELETE !!!");
     return;
   }
  temp_->next = temp->next;
  free(temp);
}

void insertOfFrontData(queue *obj,int data, int i_data){
  qnode *temp = obj->front;
  qnode *temp_;
  qnode *new_node = createNode(i_data);
  if(temp != NULL && obj->rear->data == data){
    enQueue(obj,i_data);
    return;
  }
  while(temp != NULL && temp->data != data){
    temp_ = temp;
    temp = temp->next;
  }
  //printf("%d",temp_->data);
  new_node->next = temp_->next;
  temp_->next = new_node;
}
void updateOfData(queue *obj,int data,int n_data){
  qnode *temp = obj->front;
  while (temp != NULL && temp->data != data) {
    /* code */temp = temp->next;
  }
  temp->data = n_data;
}

int getRear(queue *obj){
  return obj->rear->data;
}

int getFront(queue *obj){
  return obj->front->data;
}
void showQueue(queue*obj){
  qnode *temp = obj->front;
  printf("front<-----");
  while (temp != NULL) {
    /* code */
    printf("%d ",temp->data);
    temp = temp->next;
  }
  printf("<-----rear");
}

int main(int argc, char const *argv[]) {
  queue *queueRoot = createQueue();
  enQueue(queueRoot,10); // 18<-18<-17<-16<-15<-10
  enQueue(queueRoot,15);
  enQueue(queueRoot,16);
  enQueue(queueRoot,17);
  enQueue(queueRoot,18);
  enQueue(queueRoot,18);
  insertOfFrontData(queueRoot,17,16);
  updateOfData(queueRoot,17,16);
  showQueue(queueRoot);
//  printf("%d\n",getFront(queueRoot));
  return 0;
}
