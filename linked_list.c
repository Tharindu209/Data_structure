#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node* next;
}node;

void insert(node** head,int value);

void print(node* head);
int main(void){
    node* head = NULL;
    for (int x = 0 ; x <5 ; x++){
        int number;
        printf("enter your number: ");
        scanf("%d",&number);
        insert(&head,number);
    }
    print(head);
    return 0;
}

void insert(node** head,int value){
    node* p = malloc(sizeof(node));
    p->number = value;
    p->next = NULL;

    if (*head != NULL){
        p->next = *head;
    }
    *head = p;
}


void print(node* head){
    for (node* tmp = head ; tmp != NULL ; tmp = tmp->next){
        printf("%i\t",tmp->number);
    }
}
