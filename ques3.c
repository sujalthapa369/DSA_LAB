#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX_SIZE 100

struct node
{
    int data;
    struct node* next;
};
struct node* createnode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
struct node* mergesortedlist(struct node* head1, struct node* head2)
{
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    
    if(head1->data>head2->data)
    {
        struct node* temp = head1;
        head1= head2;
        head2 = temp;
    }

    struct node* temp1 = head1;
    struct node* temp2 = head2;
    while(temp1 && temp2)
    {   
        while(temp1 && temp1->next->data<=temp2->data)
        {     
            temp1 = temp1->next;
        }
    
    struct node* next2 = temp2->next;
    temp2->next = temp1->next;
    temp1->next = temp2;

    temp2 = next2; 
    }
    return head1; 
}

void print(struct node* head)
{
    struct node* temp =head;
    while(temp)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node* head1 = createnode(1);
    head1->next = createnode(3);
    head1->next->next = createnode(5);

    // Create second sorted linked list: 2 -> 4 -> 6 -> NULL
    struct node* head2 = createnode(2);
    head2->next = createnode(4);
    head2->next->next = createnode(6);

    printf("List 1: ");
    print(head1);
    printf("List 2: ");
    print(head2);

    // Merge the two lists
    struct node* mergedHead = mergeSortedLists(head1, head2);
    printf("Merged List: ");
    print(mergedHead);

    return 0;
}
