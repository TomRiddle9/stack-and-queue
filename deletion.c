#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insert(struct node** head_ref, int new_data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = new_data;
    new_node-> next = (*head_ref);
    (*head_ref)= new_node;
}

void del(struct node** head_ref, int pos){
    if(*head_ref == NULL)
        return;
    struct node* temp = (*head_ref);
    if(pos== 0){
            (*head_ref) = temp->next;
             free(temp);

    }
    for(int i =0;temp!= NULL && i<pos-1;i++){
            temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
         return;
    struct node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}
void print_list(struct node* n){
    while(n!= NULL){
            printf("%d ->", n->data);
            n = n->next;
    }
}
int main(){
    struct node* head = NULL;
    insert(&head, 6);
    insert(&head, 7);
    insert(&head, 8);
    insert(&head , 9);
    insert(&head , 10);
    print_list(head);
    del(&head, 3);
    printf("\n After deleting one node the linked list is -   ");
    print_list(head);
    return 0;
}

