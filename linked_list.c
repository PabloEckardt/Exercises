#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int val;
  struct node *next;
  struct node *last;
}node;

typedef struct linkedList{
  int count;
  struct node * head;
}LinkedList;

LinkedList *newLinkedList(){
  LinkedList * list = malloc (16);
  list -> count = 0;
  list -> head = NULL;
  return list;
}

node*  create_node(int value){// a value for the new node.
  node * new = malloc(24); // the node structure takes 24 bytes.
  (*new).val = value;
  (*new).next = NULL;
  (*new).last = NULL;
  return new;
}

void addNode(node * first,int val){ // performs the specific action of joining two nodes.
  node* nod =   create_node(val);
  (*first).next = nod;
  ((*nod)).last = first;
}

void add(LinkedList * list, int val){ //adds a node to the end of the linked list.
  list -> count++;
  if(list->count ==1){
    list->head = create_node(val);
  }
  else if (list->count >1 ){
    node * first = list->head;
    while((*first).next !=  NULL){
      first = (*first).next;
    }
      addNode(first,val);
  }
}

void removeLast(LinkedList * list ){ // removes the last element of the linked list
  if(list -> count == 0){
    printf("cannot remove elements from empty list.\n");
  }
  else if (list -> count == 1){
    list->count--;
    free(list->head);
  }
  else {
    list->count--;
    node * first = list->head;
    node * last = NULL;
    while((*first).next !=  NULL){
      last = first;
      first = first->next;
    }
    last->next = NULL;
    free(first);
  }
}
void print_linked_list(LinkedList * list){ // prints the values of the linked list
  node * first = list->head;
  if (list->count == 0){
    printf("can't print empty list \n" );
  }
  else if(list->count == 1){
    printf("%d\n", list->head->val);
  }
  else {
    node * first = list->head;
    while((*first).next !=  NULL){
      printf("%d\n",(*first).val);
      first = (*first).next;
    }
    printf("%d\n",(*first).val);
  }
}
int main(){

  LinkedList * list = newLinkedList(); // generate linked list data structure

  for (size_t i = 1; i <= 5; i++) {
      add(list,i);  //add five elements to the linked list.
  }
  for (size_t i = 1; i <= 5; i++) {
      removeLast(list);  //remove five elements to the linked list.
  }
  for (size_t i = 1; i <= 5; i++) {
      add(list,i);  //add five elements to the linked list.
  }
  print_linked_list(list);
  return 0;
}
