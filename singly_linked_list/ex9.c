// Write a program in C to delete the last node of a Singly Linked List.

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

void insertNodeNth(struct Node **head, int data, int position)
{
    struct Node *temp = createNode(data);
    temp->data = data;
    temp->next = NULL;
    if (position == 1)
    {
        temp->next = *head;
        *head = temp;
        return;
    }

    struct Node *iterate = *head;

    for (int i = 0; i < position - 2; i++)
    {
        iterate = iterate->next;
    }

    temp->next = iterate->next;
    iterate->next = temp;
}

void deleteNodeNth(struct Node **head, int position)
{
    if (*head == NULL)
        return;

    struct Node *temp = *head;
    // if head is to be deleted
    if (position == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    // if node is empty
    if (temp == NULL || temp->next == NULL)
        return;

    // Find previous node of node to be deleted
    for (int i = 0; i < position - 2; i++)
    {
        temp = temp->next;
    }

    // Node to be deleted
    struct Node *iterate = temp->next->next;

    // unlink node
    free(temp->next);
    temp->next = iterate;
}

void deleteNodeLast(struct Node** head){
    if(*head == NULL){
        return;
    }

    struct Node* temp = *head;
    while(temp != NULL){
        temp = temp->next;
    }

    struct Node* temp2 = temp->next;
    temp->next = temp2;
    free(temp);
}

void reverseNode(struct Node **head)
{
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;
    while (current != NULL)
    {                         // Traverse the list
        next = current->next; // store the next node
        current->next = prev; // reverse the current's node pointer
        prev = current;       // Move the prev node one step forward
        current = next;       // Move the current node one step forward
    }
    *head = prev; // Update the head to the new first node
}

void displayList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    insertNodeNth(&head, 115, 1);
    insertNodeNth(&head, 2235, 2);
    insertNodeNth(&head, 925, 3);
    insertNodeNth(&head, 52, 4);
    insertNodeNth(&head, 725, 5);

    insertNodeNth(&head, 1025, 6);
    insertNodeNth(&head, 111, 7);
    insertNodeNth(&head, 392, 8);
    insertNodeNth(&head, 825, 9);
    insertNodeNth(&head, 20, 10);
    insertNodeNth(&head, 23, 11);
    insertNodeNth(&head, 505, 12);

    deleteNodeLast(&head);

    

    //deleteNodeNth(&head, 3);
    //deleteNodeLast(&head, 4);
   // deleteNodeLast(&head, 12);

    

    reverseNode(&head);

    displayList(head);
}
