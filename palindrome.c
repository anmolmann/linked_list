// whether the linked list is a palindrome or not
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
}*first = NULL;
void push(int data) {
    struct node *new1 = (struct node *)malloc(sizeof(struct node));
    new1 -> data = data;
    new1 -> next = first;
    first = new1;
}
int check_Palindrome(int n) {
    struct node *temp = first, *copy_list = NULL;
    int i;
    while(first) {
        struct node *new1 = (struct node *)malloc(sizeof(struct node));
        new1 -> data = first -> data;
        new1 -> next = copy_list;
        copy_list = new1;
        first = first -> next;
    }
    for(i = 0; i < n / 2; i++) {
        if(copy_list -> data != temp -> data)
            return 0;
        copy_list = copy_list -> next;
        temp = temp -> next;
    }
    return 1;
}
int main() {
    int n, i;
    printf("Enter total number of elements:\t");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        push(num);
    }
    if(check_Palindrome(n))
        printf("\n--------YES--------\n");
    else
        printf("\n--------NO--------\n");
    return 0;
}
