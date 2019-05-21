#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
  int data;
  struct node *next;

}node;

typedef struct queue{
  node *rear;
  node *front;

}queue;
node *createNode (int data){
  node *new_node = (node*)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}
queue *createQueue(){
    queue *new_queue = (queue*)malloc(sizeof(queue));
    new_queue->rear = new_queue->front = NULL;
    return new_queue;
}
void enQueue(queue *obj,int data){
  node *new_node = createNode(data);
  if(obj->front == NULL){
    obj->front = obj->rear = new_node;
    return;
  }
  obj->rear->next = new_node;
  obj->rear = new_node;

}
void deQueue(queue *obj){
    if(obj->front == NULL){
      printf("NOT DEQUEUE ???\n");
      return;
    }
    node *temp = obj->front;
    obj->front = obj->front->next;
    free(temp);
}
int main(int argc, char const *argv[]) {
  queue *queueRoot = createQueue();
  enQueue(queueRoot,10);
  enQueue(queueRoot,15);
  enQueue(queueRoot,16);
  enQueue(queueRoot,17);
  enQueue(queueRoot,18);
  deQueue(queueRoot);
  deQueue(queueRoot);
  deQueue(queueRoot);
  deQueue(queueRoot);
  deQueue(queueRoot);
  deQueue(queueRoot);
  printf("%d\n",queueRoot->front->data);
  return 0;
}
