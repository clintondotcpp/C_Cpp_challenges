// Write a program in C to create a singly linked list of n nodes and display it in reverse order.

#include <stdio.h>
#include <stdlib.h>

int counter = 0;
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
    temp->next = *head;
    *head = temp;
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

void reverseNode(struct Node **head)
{
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;
    while (current->next != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void displayNode(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        counter++;
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    // insertNodeAtBeginning(&head, 5);
    insertNodeNth(&head, 9, 1);
    insertNodeNth(&head, 722, 2);
    insertNodeNth(&head, 1, 3);
    insertNodeNth(&head, 122, 4);
    insertNodeNth(&head, 27, 5);
    insertNodeNth(&head, 91, 6);
    displayNode(head);
    printf("This is the number of nodes is %d\n", counter);

    reverseNode(&head);
    displayNode(head);
}