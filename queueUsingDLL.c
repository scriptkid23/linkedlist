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
  deQueue(queueRoot);
  deQueue(queueRoot);
  deQueue(queueRoot);

//printf("%d",queueRoot->rear->prev->prev->prev->next->data);

//printf("%d",queueRoot->front->data);
  showQueue(queueRoot);
  printf("LENGTH OF QUEUE: %d\n",lengthQueue(queueRoot));
  return 0;
}
