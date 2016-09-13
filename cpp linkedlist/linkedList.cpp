#include<iostream>


class Node{
public:
    Node * left;
    Node * right;
    int value = 0;
    Node(){
        left = NULL;
        right = NULL;
        value = 0;
    }
    static Node * newNode(int num){
        Node * node = new Node;
        node->value = num;
        node->right = NULL;
        node->left = NULL;
        return node;
    }
};

class LinkedList{
public:
    Node * head;
    Node * tail;
    int count = 0;
    Node * iterator;
    void appendNode(int num){
        if (count == 0){
            head = Node::newNode(num);
            tail = head;
            count++;
        }
        else{
            iterator = head;
            //remove the iteration and have the tail simply expand one to the right
            while(iterator->right != NULL){
                iterator = iterator->right;
            }
            iterator->right = Node::newNode(num);
            tail = iterator-> right;
            count++;
            iterator->right->left = iterator;
            //reset iteratorp
            iterator = head;
        }
    }

    void removeLast(){
        tail = tail->left;
        delete(tail->right);
        tail->right = NULL;
    }

    void printList(){
        std::cout << "linked List values: \n"<< head->value << std::endl;
        iterator = head;
        while(iterator->right != NULL){
            iterator = iterator->right;
            std::cout << iterator->value  << std::endl;
        }
    }
    void reversePrint(){
        iterator = head;
        while(iterator->right != NULL){
            iterator = iterator->right;
        }
        std::cout << "linked List reverse values: \n"<< iterator->value << std::endl;
        while( iterator->left != NULL){
            iterator = iterator->left;
            std::cout << iterator->value << std::endl;
        }
    }

};

class stack{
public:
    Node * node;
    Node * pop(){

    }
};

int main (){
    LinkedList myLinkedList;
    myLinkedList.appendNode(1);
    myLinkedList.appendNode(2);
    myLinkedList.appendNode(3);
    myLinkedList.printList();
    myLinkedList.reversePrint();
    myLinkedList.removeLast();
    myLinkedList.printList();

    return 0;
}
