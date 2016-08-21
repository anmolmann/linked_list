// adding 2 numbers using linked list
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node* push(struct node *list, int data) {
    struct node *new1 = (struct node *)malloc(sizeof(struct node));
    new1 -> data = data;
    new1 -> next = list;
    return new1;
}
struct node* add(struct node *list1, struct node *list2) {
    struct node *temp1 = list1, *temp2 = list2, *res = (struct node *)malloc(sizeof(struct node));
    res = NULL;
    int bit = 0;    // stores carry
    while(temp1 && temp2) {
        if(bit)
            temp1 -> data = temp1 -> data + 1;
        struct node *new1 = (struct node *)malloc(sizeof(struct node));
        if(temp1 -> data + temp2 -> data > 9) {
            bit = 1;
            new1 -> data = (temp1 -> data + temp2 -> data) % 10;
        }
        else {
            new1 -> data = temp1 -> data + temp2 -> data;
            bit = 0;
        }
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
        new1 -> next = res;
        res = new1;
    }
    if(bit) {
        struct node *new1 = (struct node *)malloc(sizeof(struct node));
        new1 -> data = bit;
        new1 -> next = res;
        res = new1;
    }
    return res;
};
int main() {
    int n, i;
    printf("Enter total number of elements:\t");
    scanf("%d", &n);
    struct node *list1 = NULL, *list2 = NULL;
    for(i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        list1 = push(list1, num);
    }
    for(i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        list2 = push(list2, num);
    }
    struct node *res = add(list1, list2);
    printf("\n-------------OUTPUT---------------");
    while(res) {
        printf("%d", res -> data);
        res = res -> next;
    }
    return 0;
}
