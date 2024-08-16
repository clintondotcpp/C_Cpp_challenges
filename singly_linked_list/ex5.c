// Write a program in C to insert a new node at the end of a Singly Linked List.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insertAtEnd(){

}

void insertNodeNth(struct Node** head, int data, int position){
    struct Node* temp = createNode;
    temp->next = NULL;
    if(position == 1){
        temp->next = *head;
        *head = temp;
    }

}

void displayNode(){

}

int main()
{
}