#include<iostream>


class Node{
public:
    Node * last;
    Node * next;
    int value = 0;
    static Node * newNode(int num){
        Node * node = new Node;
        node->value = num;
        node->next = NULL;
        return node;
    }
};

class LinkedList{
public:
    Node * head;
    int count = 0;
    Node * iterator;
    void appendNode(int num){
        if (count == 0){
            head = Node::newNode(num);
            count++;
        }
        else{
            iterator = head;
            while(iterator->next != NULL){
                iterator = iterator->next;
            }
            iterator->next = Node::newNode(num);
            count++;
            iterator = head;
        }
    }
    void PrintList(){
        std::cout << "linked List values: \n"<< head->value << std::endl;
        iterator = head;
        while(iterator->next != NULL){
            iterator = iterator->next;
            std::cout << iterator->value  << std::endl;
        }
    }


};


int main (){
    LinkedList myLinkedList;
    myLinkedList.appendNode(2);
    myLinkedList.appendNode(3);
    myLinkedList.PrintList();
    return 0;
}
