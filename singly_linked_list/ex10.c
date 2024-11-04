// Write a program in C to search for an existing element in a singly linked list.

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

    struct Node *temp2 = *head;
    for (int i = 0; i < position - 2; i++)
    {
        temp2 = temp2->next;
    }

    temp->next = temp2->next;
    temp2->next = temp;
}

void insertNodeBeginning(struct Node **head, int data)
{
    struct Node *temp = createNode(data);
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void insertNodeEnd(struct Node **head, int data)
{
    struct Node *temp = createNode(data);
    if (*head == NULL)
    {
        *head = temp; // Make the new node the head node
        return;
    }

    struct Node *temp2 = *head;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;
}

void deleteNodeNth(struct Node **head, int position)
{
    if (*head == NULL)
        return;

    struct Node *temp = *head;
    // If we are to delete the head position
    if (position == 1)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    if (temp == NULL || temp->next == NULL)
    {
        return;
    }

    for (int i = 0; temp != NULL && i < position - 2; i++)
    {
        temp = temp->next;
    }

    struct Node *temp2 = temp->next->next;

    // unlink the node
    free(temp->next);
    temp->next = temp2;
}

void deleteNodeKey()
{
}

void deleteLastNode(struct Node **head)
{
    if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }

    //Find the second last node
    struct Node* temp = *head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    //Delete the last node
    free(temp->next);
    temp->next = NULL;
}

void reverseNode(struct Node **head)
{
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current; // move prev one node
        current = next; // move current node one forward
    }
    *head = prev;
}

void reverseNodeRecursive(struct Node** head)
{
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void displayList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("Null\n");
}

int main()
{
    struct Node *head = NULL;
    insertNodeBeginning(&head, 122);
    insertNodeNth(&head, 11, 2);
    insertNodeNth(&head, 23, 3);
    insertNodeNth(&head, 89, 4);
    insertNodeNth(&head, 91, 5);
    insertNodeNth(&head, 49, 6);
    insertNodeEnd(&head, 273915);

    printf("Position 7 and 4 are deleted:\n");
    deleteNodeNth(&head, 7);
    deleteNodeNth(&head, 4);

    printf("Third node is deleted\n");
    deleteLastNode(&head);

    displayList(head);

    printf("Node is reversed:\n");
    reverseNode(&head);

    displayList(head);
}
