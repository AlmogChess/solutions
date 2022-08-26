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

node_t *insert_at_head(node_t **head, node_t *node_to_insert){
    node_to_insert->next = *head;
    return node_to_insert;
}

node_t *find_node(node_t *head, int val)
{
    node_t *temp =head;
    while (temp != NULL){
        if (temp->val == val) return temp;
        temp = temp->next;

    }
    return NULL;
}

int main()
{
    node_t *head = NULL;
    node_t *temp;


    for (int i = 20; i>0; i--){
        temp = creat_new_node(i);
        head = insert_at_head(&head, temp);
    };
    printlist(head);

    temp = find_node(head, 14);
    printf("found %d\n" ,temp->val);




    return 0;



}


