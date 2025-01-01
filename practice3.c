/*LINKED LISTS */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>

/* rotate a linked lists 

struct node {
    int data;
    struct node* next;
};

struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
};

struct node* rotate(struct node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    struct node* end = head;
    int length = 1;
    while (end->next) {
        end = end->next;
        length++;
    }

    end->next = head;
    k = k % length;
    int steps = length-k;
    struct node* temp = head;
    struct node* prev = NULL;
    int n = 0;
    for(int i=0;i<steps;i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    return temp;
};

void print(struct node* head) {
    struct node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = createnode(10);
    head->next = createnode(20);
    head->next->next = createnode(30);
    head->next->next->next = createnode(40);
    int k;
    printf("The number of rotations: ");
    scanf("%d", &k);
    printf("Original list:\n");
    print(head);
    head = rotate(head, k);
    printf("Rotated list:\n");
    print(head);
    return 0;
}
*/

/* PALLINDROME A LINKED LISTS 
struct node {
    int data;
    struct node* next;
};

struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
};

struct node* getmiddle(struct node* head)
{
    struct node* fast = head;
    struct node* slow = head;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow= slow->next;
    }
    return slow;
}

struct node* reverse(struct node* head)
{
    struct node* curr = head;
    struct node* prev = NULL;
    struct node* next = NULL;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool ispallindrome(struct node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return true;
    }
    struct node* mid = getmiddle(head);
    struct node* second_half = reverse(head);
    struct node* curr =head;
    struct node* second_curr = second_half;
    while(second_curr)
    {
        if(second_curr->data!=curr->data)
        {
            return false;
        }
        second_curr = second_curr->next;
        curr = curr->next;
    }
    return true;
} 


void print(struct node* head) {
    struct node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(2);
    head->next->next->next = createnode(1);
    printf("Original list:\n");
    print(head);
    if (ispallindrome(head)) {
        printf("Palindrome\n");
    } else {
        printf("Not palindrome\n");
    }
    print(head);
    
    return 0;
}

*/

/* Y INTERSECTION OF LINKED LISTS 

struct node {
    int data;
    struct node* next;
};

struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
};

int length(struct node* head)
{
    int len = 0;
    struct node* temp = head;
    while(temp)
    {
        temp = temp->next;
        len++;
    }
    return len;
}
struct node* intersection(struct node* head1,struct node* head2)
{
    int len1 = length(head1);
    int len2 = length(head2);

    int diff = len1 - len2;
    if(len1>len2)
    {
        for(int i=0;i<diff;i++)
        {
            head1 = head1->next;
        }
    }
    else{
       for(int i=0;i<diff;i++)
        {
            head2 = head2->next;
        }
    }
    struct node* temp1 = head1;
    struct node* temp2 = head2;
    
    while(temp1 && temp2)
    {
        if(temp1==temp2)
        {
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return NULL;
}

void print(struct node* head) {
    struct node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node* head1 = createnode(1);
    head1->next = createnode(3);
    head1->next->next = createnode(4);
    struct node* head2 = createnode(2);
    head2->next = createnode(3);
   struct node* intersect_node = createnode(5);
    head1->next->next->next = intersect_node;
    head2->next = intersect_node;
    intersect_node->next = createnode(6);

    print(head1);
    print(head2);

    struct node* result = intersection(head1, head2);
    if (result) {
        printf("Intersection at node with data: %d\n", result->data);
    } else {
        printf("No intersection\n");
    }
    return 0;
}

*/

