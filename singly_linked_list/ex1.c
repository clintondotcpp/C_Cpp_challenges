// Write a program in C to create and display a Singly Linked List.

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

void insertNodeAtBeginning(struct Node **head, int data)
{
    struct Node *temp = createNode(data);
    // temp->data = data;
    temp->next = *head;
    *head = temp;
}

void insertNodeAtNth(struct Node **head, int data, int position)
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
    insertNodeAtNth(&head, 5, 1);
    insertNodeAtNth(&head, 5, 2);
    insertNodeAtNth(&head, 5, 3);
    insertNodeAtNth(&head, 5, 4);
    insertNodeAtNth(&head, 5, 5);
    insertNodeAtNth(&head, 5, 6);

    // insertNodeAtBeginning(&head, 5);
    displayNode(head);
}