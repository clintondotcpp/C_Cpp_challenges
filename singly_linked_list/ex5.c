// Write a program in C to insert a new node at the end of a Singly Linked List.

#include <stdio.h>
#include <stdlib.h>

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

void insertAtEnd(struct Node **head, int data)
{
    struct Node *temp = createNode(data); // newly created node
    if (*head == NULL)
    { // if node is empty
        *head = temp;
        return;
    }
    struct Node *temp2 = *head;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;
}

void insertNodeNth(struct Node **head, int data, int position)
{
    struct Node *temp = createNode(data);
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

void displayNode(struct Node *head)
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
    insertNodeNth(&head, 54, 1);
    insertNodeNth(&head, 33, 2);
    insertNodeNth(&head, 19, 3);
    insertNodeNth(&head, 11, 4);
    insertAtEnd(&head, 69);
    displayNode(head);
}