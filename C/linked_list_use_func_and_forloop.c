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

node_t *creat_new_node(int val){
    node_t *result = malloc(sizeof(node_t));
    result->val = val;
    result->next = NULL;
    return result;

}


int main()
{
    node_t *head = NULL;
    node_t *temp;


    for (int i = 11; i>0; i--){
        temp = creat_new_node(i);
        temp->next = head;
        head = temp;
    };




    printlist(head);


    return 0;



}


