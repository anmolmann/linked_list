#include<stdio.h>
#include<stdlib.h>
struct node {
    int item;
    struct node *next;
}*first = NULL;
void push(int item) {
    struct node *new1 = (struct node *)malloc(sizeof(struct node));
    new1 -> item = item;
    new1 -> next = first;
    first = new1;
}
int isEmpty(struct node *new1) {
    return new1 == NULL;
}
struct node* reverse(struct node *new1) {
    struct node *ptr = new1;
    struct node *ptr1 = NULL, *ptr2 = NULL;
    while(ptr) {
        ptr2 = ptr1;
        ptr1 = ptr;
        ptr = ptr -> next;
        ptr1 -> next = ptr2;
    }
    new1 = ptr1;
    return new1;
}
void main() {
    int n, i, num;
    struct node *new1;
    new1 = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &num);
        push(num);
    }
    new1 = first;
    printf("\n----------INPUT------------");
    while(first) {
        printf("%d ", first -> item);
        first = first -> next;
    }
    printf("\n");
    struct node *rev = reverse(new1);
    printf("\n----------OUTPUT------------");
    while(rev) {
        printf("%d", rev -> item);
        rev = rev -> next;
    }
    printf("\n");
}
/*
while(first) {
        struct node *new1 = (struct node *)malloc(sizeof(struct node));
        new1 -> data = first -> data;
        new1 -> next = copy_list;
        copy_list = new1;
        first = first -> next;
    }
    while(copy_list) {
        printf("%d ", copy_list -> data);
        copy_list = copy_list -> next;
    }
*/
