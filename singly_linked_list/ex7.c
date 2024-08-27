// Write a program in C to delete the first node of a Singly Linked List.

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
        *head = NULL;
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

void deleteNodeNth(struct Node **head, int position)
{
    if (*head == NULL)
    {
        return;
    }
    struct Node *temp = *head;
    if (position == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    // find the previous before the node to be deleted
    for (int i = 0; temp != NULL && position - 1; i++)
    {
        temp = temp->next;
    }

    if (temp != NULL || temp->next != NULL)
    {
        return;
    }

    // Node to temp.next is the node to be deleted
    struct Node *next = temp->next->next;

    // unlink the node from the list
    free(temp->next);
    temp->next = next;
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
        current = prev;
        prev = next;
    }
    *head = prev;
}

void displayList(struct Node **head)
{
    struct Node *temp = *head;
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
    insertNodeNth(&head, 5, 1);
    insertNodeNth(&head, 50, 2);
    insertNodeNth(&head, 511, 3);
    insertNodeNth(&head, 1521, 4);
    insertNodeNth(&head, 2315, 5);

    reverseNode(&head);
    displayList(&head);
}