/* ROTATE A LINKED LISTS  */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

/*  ROTATE AN ARRAY  
void reverse(int arr[],int start,int end)
{   while(start<end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void rotate(int arr[],int d, int n)
{
    d = d%n;
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
}
void print(int arr[],int n){
    int i;
    for(int i=0;i<n;i++)
    {
        printf("%d", arr[i]);
    }
}
int main()
{
    int n;
    printf("ENTER THE SIZE OF AN ARRAY: ");
    scanf("%d",&n);
    int d;
    printf("ENTER THE NUMBER FOF ROTATION: ");
    scanf("%d",&d);
    printf("ENTER THE VALUES IN AN ARRAY: ");
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    rotate(arr,d,n);
    print(arr,n);
    return 0;

}
*/

/* ROTATE A LINKED LISTS */

/*  FIND THE NTH NODE FROM THE END

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

int getlength(struct node* head) {
    int length = 0;
    struct node* temp = head;
    while (temp) {
        temp = temp->next;
        length++;
    }
    return length;
}

struct node* findNthnode(struct node* head, int k) {
    int i = 1;
    while (head && i < k) {
        head = head->next;
        i++;
    }
    return head;
}

struct node* rotate(struct node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    int len = getlength(head);
    k = k % len;  
    if (k == 0) {
        return head;
    }

    struct node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }


    tail->next = head;


    struct node* newLastnode = findNthnode(head, len - k);
    head = newLastnode->next;  
    newLastnode->next = NULL;   

    return head;
}

void print(struct node* head) {
    while (head) {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node* head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(3);
    head->next->next->next = createnode(4);
    head->next->next->next->next = createnode(5);

    printf("Original list:\n");
    print(head);

    int k = 2;
    head = rotate(head, k);

    printf("Rotated list by %d:\n", k);
    print(head);

    return 0;
}
*/

/* DETECT A CYCLE 

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
void print(struct node* head)
{
    while(head){
        printf("%d",head->data);
        head = head->next;
    }
    printf("\n");
}

int detectcycle(struct node* head)
{   
    if(head==NULL) return 0;
    struct node* fast = head;
    struct node* slow = head;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    if(slow==fast)
    {   
        printf("loop is present");
        return 1;
    }
    printf("No loop present");
    return 0;
}

int main()
{
    struct node* head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(3);
    head->next->next->next = createnode(4);
    head->next->next->next->next = createnode(5);

    printf("Original list:\n");
    print(head);

    detectcycle(head);
}
*/

/* PALLINDROME LINKED LISTS 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node* next;
};

struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct node* middle(struct node* head) {
    if (head == NULL) return NULL;
    struct node* fast = head;
    struct node* slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

struct node* reverse(struct node* head) {
    struct node* prev = NULL;
    struct node* curr = head;
    struct node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool ispallindrome(struct node* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    struct node* mid = middle(head);
    struct node* second_half = reverse(mid);
    struct node* curr = head;
    struct node* second_curr = second_half;
    while (second_curr != NULL) {
        if (second_curr->data != curr->data) {
            return false;
        }
        second_curr = second_curr->next;
        curr = curr->next;
    }
    return true;
}

void print(struct node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
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
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }
    
    return 0;
}

*/


/* REVERSING A LINKED LISTS

struct node
{
    int data;
    struct node* next;
};

struct node* createnode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next=NULL;
    return newnode;
};

struct node* reverse(struct node* head)
{
    struct node* prev = NULL;
    struct node* curr = head;
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

void print(struct node* head)
{
    while(head){
        printf("%d",head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main()
{
    struct node* head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(3);
    head->next->next->next = createnode(1);

    printf("Original list:\n");
    print(head);
    printf("Reversed lined lists: ");
    struct node* temp = reverse(head);
    print(temp);

}
*/

/* REMOVING THE NTH NODE FROM THE END
struct node
{
    int data;
    struct node* next;
};

struct node* createnode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data =data;
    newnode->next = NULL;
    return newnode;
};

struct node* removeNthFromEnd(struct node* head, int n) {
    struct node* fast = head;
    struct node* slow = head;
    // Move `fast` n steps ahead
    for (int i = 0; i < n; i++) {
        if (fast == NULL) return head;  // If n is larger than the length of the list
        fast = fast->next;
    }

    // Special case: if `fast` is NULL, it means we need to remove the head node
    if (fast == NULL) {
        struct node* newHead = head->next;
        free(head);
        return newHead;
    }
    
    // Move both `fast` and `slow` until `fast` reaches the end of the list
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    // `slow->next` is the node to remove
    struct node* nodeToDelete = slow->next;
    slow->next = slow->next->next;
    free(nodeToDelete);

    return head;
}
void print(struct node* head)
{
    while(head){
        printf("%d",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node* head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(3);
    head->next->next->next = createnode(4);
    head->next->next->next->next = createnode(5);
    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);
    printf("Original list:\n");
    print(head);
    head = removeNthFromEnd(head, k);
    printf("List after removing %dth node from end:\n", k);
    print(head);
    
}
*/

/* ROTATE A LINKED LISTS */

// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int data;
//     struct Node* next;
// };

// struct Node* newNode(int data) {
//     struct Node* node = (struct Node*)malloc(sizeof(struct Node));
//     node->data = data;
//     node->next = NULL;
//     return node;
// }

// struct Node* rotate(struct Node* head, int k) {
//     if (head == NULL || head->next == NULL) {
//         return head;
//     }

//     struct Node* end = head;
//     while (end->next != NULL) {
//         end = end->next;
//     }

//     end->next = head;  // yahan yeh circular linked lists bann gaya

//     struct Node* temp = head;
//     struct Node* prev = NULL;
//     int n = 0;
//     while (n < k) {
//         prev = temp;
//         temp = temp->next;
//         n++;
//     }
//     prev->next = NULL;
//     return temp;
// }

// void printList(struct Node* head) {
//     struct Node* temp = head;
//     while (temp != NULL) {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     printf("\n");
// }

// int main()
// {
//     struct Node* head = createnode(1);
//     head->next = createnode(2);
//     head->next->next = createnode(3);
//     head->next->next->next = createnode(4);
//     head->next->next->next->next = createnode(5);
//     int k;
//     printf("Enter the value of k: ");
//     scanf("%d", &k);
//     printf("Original list:\n");
//     print(head);
//     printf("Rotated lists: ");
//     rotate(head,k);
//     print(head);
// }



/* IMPLEMTATION OF STACK USING QUEUE
struct queue
{
    int *arr;
    int front , size ,capacity, rear;
};

void initQueue(struct queue* q)
{
    q->front = q->rear = -1;
}
int isEmpty(struct queue* q)
{
    return q->front==-1;
}
int isFull(struct queue* q)
{
    return q->size == q->capacity-1;
}
void enqueue(struct queue* q,int data)
{
    if(isFull(q))
    {
        printf("Queue overflow");
        return;
    }
    if(q->front==q->rear)
    {
        q->front = q->rear = -1;
    }
    q->arr[++(q->rear)] = data;
}
int dequeue(struct queue* q)
{
    if(isEmpty(q))
    {
        printf("Queue Underflow");
        return 0;
    }
    int value = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1; 
    } else {
        q->front++;
    }
    return value;
}

struct stack
{
    struct queue* q1;
    struct queue* q2;
};

void initStack(struct stack* s)
{
    initQueue(&s->q1);
    initQueue(&s->q2);
}

void push(struct stack* s)
{

}

*/

/* NTH NODE FRM THE END OF THE LINKED LISTS 
struct node
{
    int data;
    struct node* next;
};
struct node* createnode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data= data;
    newnode->next = NULL;
    return newnode;
};
int Nthnode(struct node* head,int n)
{
    struct node* fast = head;
    struct node* slow = head;
    for(int i=0;i<n;i++)
    {   
        if(fast==NULL || fast->next==NULL) return 0;
        fast = fast->next;
    }

    while(fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    
    return slow->data;
}

void print(struct node* head)
{
    while(head){
        printf("%d",head->data);
        head = head->next;
    }
}

int main()
{
    struct node* head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(3);
    head->next->next->next = createnode(4);
    head->next->next->next->next = createnode(5);
    int k=0;
    printf("Enter the value of k: ");
    scanf("%d", &k);
    printf("Original list:\n");
    print(head);
    int ele = Nthnode(head,k);
    printf("List element:  %d from the end\n",ele);
    print(head);
    
}
*/


/*  EVEN ODD LINKED LISTS: 

struct Node {
    int data;
    struct Node* next;
};

struct Node* createnode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* oddeven(struct Node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    struct Node* odd = head;
    struct Node* even = head->next;
    struct Node* evenHead = even;

    while(odd->next && even->next)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;

}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node* head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(3);
    head->next->next->next = createnode(4);
    head->next->next->next->next = createnode(5);
    oddeven(head);
    printList(head);
    return 0;
}

*/