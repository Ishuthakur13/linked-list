#include <stdio.h>
#include <stdlib.h>
void insertatend();
void insertatbeg();
void insertatbetloc();
void create();
void traverse();
// void reverse();
// void length();
void insert();
void delete ();
void delfrombeg();
void delfromend();
void delfrompos();
struct node
{
    int data;
    struct node *next;
} * head, *temp, *newnode, *prevnode;
void main()
{
    int ch, choice = 1;
    while (choice)
    {
        printf("press '1' for insert,'2' for delete, '3' for traversing, '4' for create, '5' for length of LL, '6' for reverse a linked list");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        // case 2:
        // delete();
        // break;
        case 3:
            traverse();
            break;
        case 4:
            create();
            break;
        // case 5:
        // length();
        // break;
        // case 6:
        // reverse();
        // break;
        default:
            printf("invalid choice");
        }
        printf("do u want to continue (0,1)");
        scanf("%d", &choice);
    }
}
void insertatend()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    temp = head;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    traverse();
}

void insertatbeg()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
    traverse();
}
void delfrompos()
{
    
}
void insertatbetloc()
{
    int pos, i = 0;
    temp = head;
    printf("enter position");
    scanf("%d", &pos);
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data");
    scanf("%d", &newnode->data);
    newnode->next = temp->next;
    temp->next = newnode;
    traverse();
}
void insert()
{
    int ch;
    printf("enter '1' for atbeg, '2' for atend, '3' for atbetloc");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        insertatbeg();
        break;
    case 2:
        insertatend();
        break;
    case 3:
        insertatbetloc();
        break;
    default:
        printf("invalid choice");
    }
}
void delete ()
{
    int ch;
    printf("press '1' for delfromend, '2' for delfrombeg, '3' for delfrompos");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        delfromend();
        break;
    case 2:
        delfrombeg();
        break;
    case 3:
        delfrompos();
        break;
    }
}
void delfrombeg()
{
    temp = head;
    head = head->next;
    free(temp);
    traverse();
}

void create()
{
    int choice = 1;
    head = 0;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter data");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (head == 0)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("do u want to enter more data (0,1)");
        scanf("%d", &choice);
    }
}
void traverse()
{
    temp = head;
    while (temp != 0)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
void delfromend()
{
    temp = head;
    while (temp->next != 0)
    {
        prevnode = temp;
        temp = temp->next;
    }
    if (temp == head)
    {
        head = 0;
    }
    else
    {
        prevnode->next = 0;
    }
    free(temp);
    traverse();
}