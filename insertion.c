#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insertion(struct node** head_ref, int new_data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printlist(struct node* n){
    while(n!= NULL){
            printf("%d -> ", n->data);
            n = n->next;
    }
}

int main(){

    struct node* head = NULL;
    insertion(&head, 6);
    insertion(&head,7);
    insertion(&head, 8);
    insertion(&head, 9);
    insertion(&head,10);

    printlist(head);
    return 0;
}
