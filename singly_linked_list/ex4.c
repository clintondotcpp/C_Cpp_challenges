// Write a program in C to insert a new node at the beginning of a Singly Linked List.
#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insertNodeAtBeginning(struct Node **head, int data)
{
    struct Node* temp = createNode(data);
    temp->next = *head;
    *head = temp;
}

void displayNode(struct Node* head)
{
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node* head = NULL;
    insertNodeAtBeginning(&head, 5);
    displayNode(head);
}