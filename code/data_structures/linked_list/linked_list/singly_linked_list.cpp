#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

/*
 * Prints linked list in reverse order using recursion.
 * Does not modify the original list.
 */
void printReverse(struct Node* head)
{
    if (head == NULL)
        return;

    printReverse(head->next);

    printf("%d ", head->data);
}

/*
 * CHANGE 1:
 * Changed new_data type from char to int
 * because Node::data is an int.
 */
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = malloc(sizeof(struct Node));

    if (new_node == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

/*
 * CHANGE 2:
 * Added function to free allocated memory
 * and prevent memory leaks.
 */
void freeList(struct Node* head)
{
    while (head != NULL)
    {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    struct Node* head = NULL;

    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("Linked List in Reverse:\n");
    printReverse(head);

    printf("\n");

    /*
     * CHANGE 3:
     * Free dynamically allocated memory
     * before program exits.
     */
    freeList(head);

    return 0;
}
