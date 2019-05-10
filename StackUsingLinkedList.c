#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// khởi tạo 2 đối tượng node và stack
typedef struct node {
  int data;
  struct node *next;
}snode;

typedef struct stack {
  snode *top;
}stack;
// tạo một node mới
snode *createNode(int data){
  snode *new_node = (snode*)malloc(sizeof(snode));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}
// tạo 1 con trỏ top trỏ vào node mới tạo
stack *createStack(){
  stack *s = (stack*)malloc(sizeof(stack));
  s->top = NULL;
  return s;
}
// đẩy dữ liệu
void push(stack *obj,int data){
  snode *s_nodeNew = createNode(data);
  if(obj->top == NULL){
    obj->top = s_nodeNew;
    return;
  }
  s_nodeNew->next = obj->top;
  obj->top = s_nodeNew;

}
// xóa dữ liệu ở top
void pop(stack *obj){
  if(obj->top == NULL) return;
  snode *temp = obj->top;
  obj->top = obj->top->next;
  free(temp);
}
// hàm xóa node theo giá trị
void deleteOfdata(stack *obj,int data){
  // nếu mà giá trị cần xóa là top thì sử dụng hàm pop

  if(obj->top != NULL && obj->top->data == data){
    pop(obj);
    return; // thoát hàm ngay lập tức
  }
  snode *temp = obj->top;
  snode *temp_;
  while (temp != NULL && temp->data != data) {
    /* code */
    temp_ = temp; // lấy giá trị trước giá trị cần xóa
    temp = temp->next; // đây là giá trị cần xóa
  }
  temp_->next = temp->next;
  free(temp);
}
// trả về độ dài của stack
int lengthStack(stack *obj){

  snode *temp = obj->top ;
  int result = 0;
  while (temp != NULL) {
    /* code */
    result++;
    temp = temp->next;
  }
  return result;
}
// chèn 1 giá trị trước 1 giá trị nào đó
void insertOfFrontData(stack *obj,int data,int i_data){
  snode *temp = obj->top;
  snode *temp_;
  snode *new_node = createNode(i_data);
  if(temp!=NULL && temp->data == data){
    push(obj,i_data);
  }
  while (temp != NULL & temp->data != data) {
    temp_ = temp;
    temp = temp->next;
  }
  new_node->next = temp;
  temp_->next = new_node;

}
// update 1 giá trị mới
void updateOfData(stack *obj, int data,int n_data){
  snode *temp = obj->top;

  if(temp != NULL && temp->data == data) {
    /* code */
    temp->data = n_data;
    return;
  }
  while (temp != NULL && temp->data != data) {
    /* code */
    temp = temp->next;
  }
  temp->data = n_data;

}
// hiện các giá trị trong stack
void showStack(stack *obj){
  while (obj->top != NULL) {
    /* code */
    printf("|%-6d|\n",obj->top->data);
    printf("--------\n");
    obj->top = obj->top->next;
  }
}
// main
int main(int argc, char const *argv[]) {
  stack *stackRoot = createStack();
  push(stackRoot,10);
  push(stackRoot,13);
  push(stackRoot,15);
  push(stackRoot,16);

  push(stackRoot,18);


  //insertOfFrontData(stackRoot,10,150);
  //showStack(stackRoot);
  int len = lengthStack(stackRoot);
  updateOfData(stackRoot,15,100);
  showStack(stackRoot);
  printf("%d\n",len);
  return 0;
}
