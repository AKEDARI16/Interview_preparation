
#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node *link;
}Node;

Node *createNode (int data) {
    Node *newNode  = ( Node *)malloc(sizeof(Node));
    if ( newNode == NULL ) {
        printf ("Memory Allocation Failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

void append (Node **headRef, int data) {
    Node *newNode = createNode (data);
    if ( *headRef == NULL ) {
        *headRef = newNode;
        return;
    }
    Node *temp = *headRef;
    while ( temp->link != NULL)
        temp = temp->link;
    temp->link = newNode;
}

void printList (Node **headRef) {
    Node *ptr = *headRef;
    while (ptr != NULL) {
        printf ("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf ("\n");
}

int lenList (Node *headRef) {
    Node *ptr = headRef;
    int count = 0;
    while (ptr != NULL) {
        count++;
        ptr = ptr->link;
    }
    return count;
}

int findMidList(Node *headRef) {
    int len = lenList(headRef);
    int mid = len / 2;
    Node *ptr = headRef;
    while (mid--) {
            ptr = ptr->link;
    }
    return ptr->data;
}

int middleElementinList(Node *head) {
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->link != NULL) {
        fast = fast->link->link;
        slow = slow->link;
    }
    return slow->data;
}


int main()
{
    Node *head = NULL;
    Node *reerse = NULL;
    append (&head, 10);
    append (&head, 20);
    append (&head, 30);
    append (&head, 40);
    append (&head, 50);
    append (&head, 60);
    append (&head, 70);

    printList (&head);

    int midVal = findMidList(head);

    printf("Mid Value: %d\n", midVal);

    int mid = middleElementinList(head);
    printf("Mid Value: %d\n", mid);

 //   reverseOfList(&head);
 //   printList();

/*
//struct node *head1 = NULL;
head = (Node *)malloc(sizeof(Node));
if (head == NULL)
{
    printf(" Memory is not allocated for the struct");
}

head->data = 53;
head->link = NULL;

head->link = (Node *)malloc(sizeof(Node));

head->link->data = 35;
head->link->link = NULL;


printf("The data is : %d\n",head->data);
printf("The data is : %d\n",head->link->data);
*/
    return 0;
}


