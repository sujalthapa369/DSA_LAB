#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<limits.h>

// ARRAY IMPLEMENTATION OF STACKS
// struct stack{
//     int top;
//     int *arr;
//     int capacity;
// };

// struct stack* createstack(int  capacity)
// {
//     struct stack *s =malloc(sizeof(struct stack));
//     s->capacity = capacity;
//     s->top = -1;
//     s->arr = malloc(s->capacity* sizeof(int));
//     if(!s){
//         return NULL;
//     }
//     return s;
// }

// int isEmpty(struct stack *s){
//     return (s->top==-1);
// }

// int isFull(struct stack *s){
//     return (s->top==s->capacity-1);
// }

// void push(struct stack *s, int data){
//     if(isFull(s)){
//         printf("heap overflow");
//         return;
//     }
//     else{
//         s->arr[++s->top] = data;
//     }
// }

// int pop(struct stack *s){
//     if(isEmpty(s)){
//         printf("Stack is empty");
//         return INT_MIN;
//     }
//     else{
//         return s->arr[s->top--];
//     }
// }

// int peek(struct stack *s){
//     if(isEmpty(s)){
//         printf("Stack is empty");
//         return INT_MIN;
//     }
//     else{
//         return (s->arr[s->top]);
//     }
// }

// int main()
// {
//     int i=0;
//     int capacity = 5;
//     struct stack *st = createstack(capacity);
//     push(st,10);
//     push(st,20);
//     push(st,30);
//     push(st,40);
//     push(st,50);
//     printf("Top elements is the stack is: %d\n",peek(st));
//     pop(st);
//     printf("Top elements is the stack is: %d\n",peek(st));

//     return 0;    
// }

// LINKED LISTS REPRESENTATION OF STACK
// struct node{
//     int data;
//     struct node* next;
// };

// struct stack{
//    struct node *top;
//    int capacity;
// };

// struct stack* createstack(){
//     struct stack *st = malloc(sizeof(struct stack));
//     st->top=NULL;
//     return st;
// };

// void push(struct stack*st ,int data)
// {
//     struct node* temp = malloc(sizeof(struct node));
//     if(!temp){
//         printf("Stack heap overflow");
//         return;
//     }
//     temp->data = data;
//     temp->next = st->top;
//     st->top = temp;
// }

// // int isEmpty(struct stack *st){
// //     return st->top==NULL;
// // }

// // int isFull(struct stack *st){
// //     return (st->top)=(st->capacity-1);
// // }

// int pop(struct stack *st){
//     if(st->top==NULL){
//         printf("stack is empty");
//         return INT_MIN;
//     }
//     else{
//         struct node* temp = st->top;
//         st->top  = temp->next;
//         free(temp);   
//     }
// }

// int main()
// {   
//     struct stack *st = createstack();
//     push(st,10);
//     push(st,20);
//     push(st,30);
//     push(st,40);
//     push(st,50);
//     printf("Top elements is the stack is: %d\n",st->top->data);
//     pop(st);
//     printf("Top elements is the stack is: %d\n",st->top->data);
//     return 0;    
// }



// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>

// struct stack {
//     int top;
//     int *arr;
//     int capacity;
// };

// struct stack* createstack(int capacity) {
//     struct stack *s = malloc(sizeof(struct stack));
//     if (!s) {
//         return NULL;
//     }
//     s->capacity = capacity;
//     s->top = -1;
//     s->arr = malloc(s->capacity * sizeof(int));
//     if (!s->arr) {
//         free(s); // Free the stack struct if array allocation fails
//         return NULL;
//     }
//     return s;
// }

// int isEmpty(struct stack *s) {
//     return (s->top == -1);
// }

// int isFull(struct stack *s) {
//     return (s->top == s->capacity - 1);
// }

// void push(struct stack *s, int data) {
//     if (isFull(s)) {
//         printf("Heap overflow\n");
//         return;
//     }
//     s->arr[++s->top] = data;
// }

// int pop(struct stack *s) {
//     if (isEmpty(s)) {
//         printf("Stack is empty\n");
//         return INT_MIN;
//     }
//     return s->arr[s->top--];
// }

// int peek(struct stack *s) {
//     if (isEmpty(s)) {
//         printf("Stack is empty\n");
//         return INT_MIN;
//     }
//     return s->arr[s->top];
// }

// int matchSymbol(char a, char b) {
//     if ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}')) {
//         return 1;
//     }
//     return 0;
// }

// int checkbalanced(char expression[]) {
//     struct stack *st = createstack(100); // Assume max capacity is 100
//     if (!st) {
//         printf("Memory error\n");
//         return 0;
//     }
//     char temp;
//     for (int i = 0; expression[i] != '\0'; i++) {
//         if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
//             push(st, expression[i]);
//         }
//         if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
//             if (isEmpty(st)) {
//                 printf("Unbalanced: Stack is empty\n");
//                 return 0;
//             }
//             temp = pop(st);
//             if (!matchSymbol(temp, expression[i])) {
//                 printf("Mismatched: %c and %c\n", temp, expression[i]);
//                 return 0;
//             }
//         }
//     }
//     if (isEmpty(st)) {
//         printf("Balanced\n");
//         return 1;
//     } else {
//         printf("Unbalanced: Stack not empty\n");
//         return 0;
//     }
// }

// int main() {
//     int valid = checkbalanced("(((}{})))");
//     if (valid == 1) {
//         printf("Valid expression\n");
//     } else {
//         printf("Invalid expression\n");
//     }
//     return 0;
// }


// infix to postfix
// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>

// struct stack {
//     int top;
//     char *arr;
//     int capacity;
// };

// struct stack* createstack(int capacity) {
//     struct stack *s = malloc(sizeof(struct stack));
//     if (!s) {
//         return NULL;
//     }
//     s->capacity = capacity;
//     s->top = -1;
//     s->arr = malloc(s->capacity * sizeof(char));
//     if (!s->arr) {
//         free(s); // Free the stack struct if array allocation fails
//         return NULL;
//     }
//     return s;
// }

// int isEmpty(struct stack *s) {
//     return (s->top == -1);
// }

// int isFull(struct stack *s) {
//     return (s->top == s->capacity - 1);
// }

// void push(struct stack *s, char data) {
//     if (isFull(s)) {
//         printf("Heap overflow\n");
//         return;
//     }
//     s->arr[++s->top] = data;
// }

// char pop(struct stack *s) {
//     if (isEmpty(s)) {
//         printf("Stack is empty\n");
//         return -1;
//     }
//     return s->arr[s->top--];
// }

// char peek(struct stack *s) {
//     if (isEmpty(s)) {
//         printf("Stack is empty\n");
//         return -1;
//     }
//     return s->arr[s->top];
// }

// int priority(char x) {
//     if (x == '(') {
//         return 0;
//     }
//     if (x == '+' || x == '-') {
//         return 1;
//     }
//     if (x == '*' || x == '/') {
//         return 2;
//     }
//     return -1;  // For other characters, like operands
// }

// void infixToPostfix(char expression[]) {
//     char *e, x;
//     struct stack *st = createstack(100);  // Assuming max capacity of 100
//     if (!st) {
//         printf("Memory error\n");
//         return;
//     }

//     e = expression;
//     while (*e != '\0') {
//         if (isalnum(*e)) {
//             // Operand directly added to output
//             printf("%c", *e);
//         } 
//         else if (*e == '(') {
//             push(st, *e);
//         } 
//         else if (*e == ')') {
//             // Pop till '('
//             while ((x = pop(st)) != '(') {
//                 printf("%c", x);
//             }
//         } 
//         else {  // Operator encountered
//             while (!isEmpty(st) && priority(peek(st)) >= priority(*e)) {
//                 printf("%c", pop(st));
//             }
//             push(st, *e);  // Push current operator
//         }
//         e++;
//     }

//     // Pop all remaining operators in the stack
//     while (!isEmpty(st)) {
//         printf("%c", pop(st));
//     }
//     printf("\n");
// }

// int main() {
//     infixToPostfix("(a+(b*(d+2)))");
//     return 0;
// }


// POSTFIX EVALUATION
// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>

// struct stack {
//     int top;
//     char *arr;
//     int capacity;
// };

// struct stack* createstack(int capacity) {
//     struct stack *s = malloc(sizeof(struct stack));
//     if (!s) {
//         return NULL;
//     }
//     s->capacity = capacity;
//     s->top = -1;
//     s->arr = malloc(s->capacity * sizeof(char));
//     if (!s->arr) {
//         free(s); 
//         return NULL;
//     }
//     return s;
// }

// int isEmpty(struct stack *s) {
//     return (s->top == -1);
// }

// int isFull(struct stack *s) {
//     return (s->top == s->capacity - 1);
// }

// void push(struct stack *s, char data) {
//     if (isFull(s)) {
//         printf("Heap overflow\n");
//         return;
//     }
//     s->arr[++s->top] = data;
// }

// char pop(struct stack *s) {
//     if (isEmpty(s)) {
//         printf("Stack is empty\n");
//         return -1;
//     }
//     return s->arr[s->top--];
// }

// char peek(struct stack *s) {
//     if (isEmpty(s)) {
//         printf("Stack is empty\n");
//         return -1;
//     }
//     return s->arr[s->top];
// }

// int postfixeval(char expression[])
// {
//     struct stack *st = createstack(100);
//     int i;
//     for(int i=0;expression[i];++i)
//     {
//         if(isdigit(expression[i])){
//             push(st , expression[i] - '0');
//         }
//         else{
//             int topelement = pop(st);
//             int secondelement = pop(st);
//             switch(expression[i]){
//                 case '+':
//                     push(st, secondelement + topelement);
//                     break;
//                 case '-':
//                     push(st,secondelement-topelement);
//                     break;
//                 case '*':
//                     push(st, secondelement*topelement);
//                     break;
//                 case '/':
//                     push(st, secondelement/topelement);
//                     break;
//             }
//         }
//     }
//     return pop(st);
// }


// int main() {
//     printf("The postfix evaluation result is : %d",postfixeval("123*+5-"));
//     return 0;
// }


// pallindrome or not

// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>

// struct stack {
//     int top;
//     char *arr;
//     int capacity;
// };

// struct stack* createstack(int capacity) {
//     struct stack *s = malloc(sizeof(struct stack));
//     if (!s) {
//         return NULL;
//     }
//     s->capacity = capacity;
//     s->top = -1;
//     s->arr = malloc(s->capacity * sizeof(char));
//     if (!s->arr) {
//         free(s); 
//         return NULL;
//     }
//     return s;
// }

// int isEmpty(struct stack *s) {
//     return (s->top == -1);
// }

// int isFull(struct stack *s) {
//     return (s->top == s->capacity - 1);
// }

// void push(struct stack *s, char data) {
//     if (isFull(s)) {
//         printf("Heap overflow\n");
//         return;
//     }
//     s->arr[++s->top] = data;
// }

// char pop(struct stack *s) {
//     if (isEmpty(s)) {
//         printf("Stack is empty\n");
//         return -1;
//     }
//     return s->arr[s->top--];
// }

// char peek(struct stack *s) {
//     if (isEmpty(s)) {
//         printf("Stack is empty\n");
//         return -1;
//     }
//     return s->arr[s->top];
// }

// int isPallindrome(char expression[])
// {   int i=0;
//     struct stack *st = createstack(100);
//     while(expression[i] && expression[i]!='X')
//     {
//         push(st,expression[i]);
//         i++;
//     }
//     i++;
//     while (expression[i]) {
//         if (isEmpty(st) || expression[i] != pop(st)) {
//             printf("Not pallindrome\n");
//             return 0;
//         }
//         i++;
//     }
//     printf("Pallindrome\n");
//     return 1;
// }

// int main(void) {
//     isPallindrome("ababaXababa");
//     return 0;
// }


// implementation of two stacks in one array
// #include<stdio.h>
// #include<limits.h>
// #include<stdlib.h>
// #include<string.h>

// struct stack
// {
//     int top1;
//     int top2;
//     int capacity;
//     char *arr;
// };

// struct stack* createstack(int capacity) {
//     struct stack* st = malloc(sizeof(struct stack));
//     st->capacity = capacity; 
//     st->top1 = -1;
//     st->top2 = capacity;
//     st->arr = malloc(st->capacity * sizeof(int)); 
//     if (!st->arr) {
//         return NULL;
//     }
//     return st;
// }


// int isEmpty(struct stack* st, int stNumber){
//     if(stNumber==1){
//         return (st->top1==-1);
//     }
//     else{
//         return (st->top2 == st->capacity);
//     }
// }

// int size(struct stack *st, int stNumber){
//     if(stNumber==1)
//     {
//         return (st->top1 + 1);
//     }
//     else{
//         return (st->capacity - st->top2);
//     }
// }

// int isFull(struct stack *st){
//     return (size(st,1)+ size(st,2)== st->capacity);
// }

// void push(struct stack *st, int stNumber , char data)
// {
//     if(isFull(st)){
//         printf("stack is full");
//         return ;
//     }
//     else{
//         if(stNumber==1){
//             st->arr[++st->top1] = data;
//         }
//         else{
//             st->arr[--st->top2] =data;
//         }
//     }
// }

// char pop(struct stack *st,int stNumber){
//     if(isEmpty(st,stNumber))
//     {
//         printf("stack is empty");
//         return '\0';
//     }
//     if(stNumber==1){
//         return (st->arr[st->top1--]);
//     }
//     else{
//         return (st->arr[st->top2++]);
//     }
// }

// int peek(struct stack *st , int stNumber)
// {
//     if(isEmpty(st,stNumber))
//     {
//         printf("stack is empty");
//         return 0 ;


// #include <stdlib.h>

// // Definition for singly-linked list node.
// struct ListNode {
//     int val;
//     struct ListNode* next;
// };

// // Function to find the length of the list

// int getLength(struct ListNode* head) {
//     int length = 0;
//     struct ListNode* temp = head;
//     while (temp != NULL) {
//         length++;
//         temp = temp->next;
//     }
//     return length;
// }

// // Function to rotate the list to the right by k places

// struct ListNode* rotateRight(struct ListNode* head, int k) {
//     if (head == NULL || head->next == NULL || k == 0) {
//         return head;
//     }

//     // Get the length of the list
//     int length = getLength(head);

//     // Adjust k to be within the bounds of the list length
//     k = k % length;
//     if (k == 0) {
//         return head;
//     }

//     // Find the new tail: (length - k - 1)th node
//     struct ListNode* temp = head;
//     for (int i = 1; i < length - k; i++) {
//         temp = temp->next;
//     }

//     // New head will be the next node
//     struct ListNode* newHead = temp->next;
//     temp->next = NULL;

//     // Find the end of the new list and connect it to the old head
//     struct ListNode* end = newHead;
//     while (end->next != NULL) {
//         end = end->next;
//     }
//     end->next = head;

//     return newHead;
// }

// // Helper function to create a new node
// struct ListNode* newNode(int val) {
//     struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
//     node->val = val;
//     node->next = NULL;
//     return node;
// }

// // Helper function to print the list
// void printList(struct ListNode* head) {
//     while (head != NULL) {
//         printf("%d -> ", head->val);
//         head = head->next;
//     }
//     printf("NULL\n");
// }

// // Main function to test the rotateRight function
// int main() {
//     struct ListNode* head = newNode(1);
//     head->next = newNode(2);
//     head->next->next = newNode(3);
//     head->next->next->next = newNode(4);
//     head->next->next->next->next = newNode(5);

//     printf("Original list: ");
//     printList(head);

//     int k = 2;
//     head = rotateRight(head, k);

//     printf("Rotated list by %d: ", k);
//     printList(head);

//     return 0;
// }

// // Function to rotate the list to the right by k places
// struct ListNode* rotateRight(struct ListNode* head, int k) {
//     if (head == NULL || head->next == NULL || k == 0) {
//         return head;
//     }

//     // Get the length of the list
//     int length = getLength(head);

//     // Adjust k to be within the bounds of the list length
//     k = k % length;
//     if (k == 0) {
//         return head;
//     }

//     // Find the new tail: (length - k - 1)th node
//     struct ListNode* temp = head;
//     for (int i = 1; i < length - k; i++) {
//         temp = temp->next;
//     }

//     // New head will be the next node
//     struct ListNode* newHead = temp->next;
//     temp->next = NULL;

//     // Find the end of the new list and connect it to the old head
//     struct ListNode* end = newHead;
//     while (end->next != NULL) {
//         end = end->next;
//     }
//     end->next = head;

//     return newHead;
// }

// // Helper function to create a new node
// struct ListNode* newNode(int val) {
//     struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
//     node->val = val;
//     node->next = NULL;
//     return node;
// }

// // Helper function to print the list
// void printList(struct ListNode* head) {
//     while (head != NULL) {
//         printf("%d -> ", head->val);
//         head = head->next;
//     }
//     printf("NULL\n");
// }

// // Main function to test the rotateRight function
// int main() {
//     struct ListNode* head = newNode(1);
//     head->next = newNode(2);
//     head->next->next = newNode(3);
//     head->next->next->next = newNode(4);
//     head->next->next->next->next = newNode(5);

//     printf("Original list: ");
//     printList(head);

//     int k = 2;
//     head = rotateRight(head, k);
//     printf("Rotated list by %d: ", k);
//     printList(head);
//     return 0;
// }




