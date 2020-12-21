#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insert(struct node** head_ref,int data){

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void reverse(struct node** head_ref){

    struct node* current = *head_ref;
    struct node* next = NULL;
    struct node* prev = NULL;
    while(current != NULL){
            next = current->next;
            current->next = prev;

            prev = current;
            current = next;
    }
    (*head_ref) = prev;
}

void print_list(struct node* n){
    while(n!= NULL){
            printf("%d->",n->data);
            n = n->next;
    }
}

int main(){

    struct node* head = NULL;
    insert(&head, 7);
    insert(&head,8);
    insert(&head, 9);
    insert(&head,10);
    insert(&head,11);
    print_list(head);
    reverse(&head);
    printf("\n After reversing the linked list is -   ");
    print_list(head);
    return 0;
}
