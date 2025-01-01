#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*Q1  WRITE A C PROGRAM TO SEARCH FOR AN EXISTING ELEMNET IN A SINGLY LINKED LISTS 

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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
};
bool issearch(struct node* head, int key) {
    struct node* temp = head;
    while (temp) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
void print(struct node* head)
{
    while(head){
        printf("%d",head->data);
        head = head->next;
    }
    printf("\n");
}
int main()
{
    struct node* head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(3);
    head->next->next->next = createnode(4);
    head->next->next->next->next = createnode(5);
    int key;
    printf("Enter the value to be searched: ");
    scanf("%d", &key);
    if(issearch(head,key)){
        printf("Element is found");
        return 0;
    }
    else{
        printf("Elemnet not found");
        return 0;
    }
}

*/

/*Q2 FIND THE KEY VALUE DELETE IT AND GIVE OUT THE UPDATED LINKED LISTS 

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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
};
bool issearch(struct node* head, int key) {
    struct node* temp = head;
    while (temp) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
struct node* deleteNode(struct node* head, int key) {
    struct node* temp = head;
    struct node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        head = temp->next; 
        free(temp);        
        return head;       
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Unsuccessful search\n");
        return head; 
    }
    prev->next = temp->next;
    free(temp); 

    return head; 
}
void print(struct node* head)
{
    while(head){
        printf("%d",head->data);
        head = head->next;
    }
    printf("\n");
}
int main()
{
    struct node* head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(3);
    head->next->next->next = createnode(4);
    head->next->next->next->next = createnode(5);
    int key;
    printf("Enter the value to be searched: ");
    scanf("%d", &key);
    if(issearch(head,key)){
        printf("Element is found");
        head = deleteNode(head,key);
        printf("The updated list: ");
        print(head);
        return 0;
    }
    else{
        printf("Elemnet not found");
        return 0;
    }
}*/


/*Q3  MERGE TWO SORTED LINKED LISTS 
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
};

struct node* merge(struct node* list1, struct node* list2)
{   
    struct node* mergedhead =NULL;
    if(list1==NULL) return list2;
    if(list2==NULL) return list1;
    while(list1 && list2){
    if(list1->data<list2->data)
    {
        mergedhead = list1;
        list1 = list1->next;
    }
    if(list1->data>list2->data){
        mergedhead = list2;
        list2= list2->next;
    }

    struct node* current = mergedhead;
    while(list1 && list2)
    {
    if (list1->data < list2->data) {
            current->next = list1; // Link the smaller node
            list1 = list1->next; // Move the pointer forward
        } else {
            current->next = list2; // Link the smaller node
            list2 = list2->next; // Move the pointer forward
        }
        current = current->next; // Move the current pointer forward
    }
    if(list1!=NULL){
        current->next = list1;
    }
    else{
        current->next =list2;
    }
    return mergedhead;
    }

};
void print(struct node* head)
{
    while(head){
        printf("%d",head->data);
        head = head->next;
    }
    printf("\n");
}
int main()
{
    struct node* head = NULL;
    struct node* list1 =NULL;
    struct node* list2=NULL;
    list1 = createnode(1);
    list1->next = createnode(2);
    list1->next->next = createnode(3);
    list1->next->next->next = createnode(4);

    // Creating second sorted linked list: 5 -> 6 -> 7
    list2 = createnode(5);
    list2->next = createnode(6);
    list2->next->next = createnode(7);

    printf("List 1: ");
    print(list1);
    
    printf("List 2: ");
    print(list2);

    // Merging the two sorted linked lists
    struct node* mergedList = merge(list1, list2);

    printf("Merged List: ");
    print(mergedList);

    return 0;
    
}
*/

// WEEK 6

/*Q4   TO CREATE AND DISPLAY A DOUBLY LL
struct node
{
    struct node* prev;
    int data;
    struct node* next;
};

struct node* createnode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->data = data;
    newnode->next=NULL;
    return newnode;
};
void insertatbegin(struct node** head,int data)
{
    struct node* new = createnode(data);
    if((*head)==NULL)
    {
        *head = new;
        return;
    }
    new->next = (*head);
    (*head)->prev = new;
    (*head) = new;
}
void insertatend(struct node** head,int data)
{
    struct node* new= createnode(data);
    struct node* temp = (*head);
    if((*head)==NULL)
    {
        (*head) = new;
        return;
    }
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->prev = temp;

}
void display(struct node* head) {
    struct node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next; 
    }
    printf("\n");
}
int main()
{
    struct node* head = NULL;
    insertatbegin(&head,1);
    insertatbegin(&head,2);
    insertatbegin(&head,3);
    insertatend(&head,4);
    insertatend(&head,5);
    display(head);
    return 0;
}
*/

/*Q5  , Q6 begin , middle and end of the linked lists 
struct node
{
    struct node* prev;
    int data;
    struct node* next;
};

struct node* createnode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->data = data;
    newnode->next=NULL;
    return newnode;
};
void insertatbegin(struct node** head,int data)
{
    struct node* new = createnode(data);
    if((*head)==NULL)
    {
        *head = new;
        return;
    }
    new->next = (*head);
    (*head)->prev = new;
    (*head) = new;
}
void insertatend(struct node** head,int data)
{
    struct node* new= createnode(data);
    struct node* temp = (*head);
    if((*head)==NULL)
    {
        (*head) = new;
        return;
    }
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->prev = temp;

}
void insertAtPosition(struct node** head, int data, int position) {
    struct node* new = createnode(data);
    if (position == 0) {
        // If inserting at the beginning
        new->next = *head;
        if (*head != NULL) {
            (*head)->prev = new; // Update the previous head's prev pointer
        }
        *head = new; // Update the head to the new node
        return;
    }

    struct node* temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next; // Traverse to the position
    }

    if (temp == NULL) {
        // If position is greater than the length of the list, insert at the end
        free(new);
        return;
    }

    // Insert the new node in the middle
    new->next = temp->next; // Link the new node to the next node
    new->prev = temp; // Link the new node to the previous node
    temp->next = new; // Link the previous node to the new node

    if (new->next != NULL) {
        new->next->prev = new; // Update the next node's previous pointer
    }
}
void display(struct node* head) {
    struct node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next; 
    }
    printf("\n");
}
int main()
{
    struct node* head = NULL;
    insertatbegin(&head,1);
    insertatbegin(&head,2);
    insertatbegin(&head,3);
    insertatend(&head,4);
    insertatend(&head,5);
    int pos;
    printf("Enter the position : ");
    scanf("%d",&pos);
    insertAtPosition(&head,9,pos);
    display(head);
    return 0;
}

*/


/* Q7 SEARCH A KEY AND DELETE IT 
struct node
{
    struct node* prev;
    int data;
    struct node* next;
};

struct node* createnode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->data = data;
    newnode->next=NULL;
    return newnode;
};
void insertatbegin(struct node** head,int data)
{
    struct node* new = createnode(data);
    if((*head)==NULL)
    {
        *head = new;
        return;
    }
    new->next = (*head);
    (*head)->prev = new;
    (*head) = new;
}
void insertatend(struct node** head,int data)
{
    struct node* new= createnode(data);
    struct node* temp = (*head);
    if((*head)==NULL)
    {
        (*head) = new;
        return;
    }
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->prev = temp;

}
void display(struct node* head) {
    struct node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next; 
    }
    printf("\n");
}
bool issearch(struct node** head,int key)
{
    struct node* temp = *head;
    while(temp)
    {   if(temp->data==key)
        {
            return true;
        }
        else{
            return false;
        }
    }
    temp = temp->next;
}
int main()
{
    struct node* head = NULL;
    int key;
    printf("Enter the key: ");
    scanf("%d",&key);
    insertatbegin(&head,1);
    insertatbegin(&head,2);
    insertatbegin(&head,3);
    insertatend(&head,4);
    insertatend(&head,5);
    display(head);
    if(issearch(&head,key))
    {
        printf("Key is found");
        return 0;
    }
    else{
        printf("Key not found");
        return 0;
    }
    return 0;
}

*/


