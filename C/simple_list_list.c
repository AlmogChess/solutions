#include <stdio.h>
#include <stdlib.h>


struct node {
    int val;
    struct node * next;
} ;

typedef struct node node_t;


void printlist(node_t *head){
    node_t *temp = head;
    while (temp != NULL){
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("\n");

}


int main()
{
    node_t n1,n2,n3;
    node_t *head;
    n1.val = 23;
    n2.val = 24;
    n3.val = 34;
    head = &n3;
    n3.next = &n2;
    n2.next =  &n1;
    n1.next = NULL;

    printlist(head);






}


