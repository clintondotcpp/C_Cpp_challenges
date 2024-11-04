// Write a C program that converts a singly linked list into a string and returns it.
#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insertNodeBeginning(struct Node** head, int data){
    struct Node* temp = createNode(data);
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void insertNodeLast(struct Node** head, int data){
    struct Node* temp = createNode(data);
    temp->data = data;
    if(*head == NULL){
        *head = temp; //Make the new node the head node
        return;
    }

    struct Node* temp2 = *head;
    while(temp->next != NULL){
        temp2 = temp2->next;
    }
    temp2->next = temp;
}

void insertNodeNth(struct Node ** head, int data, int position){
    struct Node* temp = createNode(data);
    temp->data = data;
    temp->next = NULL;
    if(position == 1){
        temp->next = *head;
        *head = temp;
        return;
    }

    struct Node* temp2 = *head;
    for(int i = 0; i < position - 2; i++){
        temp2 = temp2->next;
    }

    temp->next = temp2->next;
    temp2->next = temp;
}

void deleteNodeNth(struct Node** head, int position){
    struct Node* temp = *head;
    if(position == 1){
        *head = temp;
        free(temp);
        return;
    }

    if(temp == NULL || temp->next == NULL){
        return;
    }

    for(int i = 0; temp != NULL && i < position - 2; i++){
        temp = temp->next;
    }
 
    struct Node* temp2 = temp->next->next;

    free(temp->next);
    temp->next = temp2;

}

void deleteLast(struct Node** head){
    struct Node* temp = *head;
    if(*head = NULL){
        *head = temp;
        free(temp);
        return;
    }

    while(temp->next->next != NULL){
        temp = temp->next;
    }

    free(temp->next->next);
    temp->next = NULL;
}

void PrintList(struct Node** head){
    struct Node* temp = *head;

    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    
}

int main()
{
    struct Node* head = NULL;

    insertNodeBeginning(&head, 5);
    insertNodeNth(&head, 10, 2);
    insertNodeNth(&head, 91, 3);
    //insertNodeLast(&head, 403);
    
    PrintList(&head);
}
