// Write a program in C to delete a node from the middle of a Singly Linked List.

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
    // if the list is empty
    if (*head == NULL)
        return;

    struct Node *temp = *head;
    // if it is the head to be deleted
    if (position == 1)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    if (temp == NULL || temp->next == NULL)
    { // if list is empty
        return;
    }

    // Find the previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 2; i++)
    {
        temp = temp->next;
    }

    struct Node *next = temp->next->next;

    // unlink the node
    free(temp->next);
    temp->next = next;
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
    insertNodeNth(&head, 51, 1);
    insertNodeNth(&head, 15, 2);
    insertNodeNth(&head, 522, 3);
    insertNodeNth(&head, 3454, 4);
    insertNodeNth(&head, 75159, 5);

    deleteNodeNth(&head, 3);
    displayList(head);
}