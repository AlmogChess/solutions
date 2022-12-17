#include <stdlib.h> /*malloc, free  */
#include <string.h> /*memcpy        */
#include <assert.h> /*assert        */

#include "slist_ex.h"


/* in case of head->next = NULL;
will return head */
node_t *Flip(node_t *head)
{
    node_t *prev = NULL;
    node_t *curr = NULL;
    node_t *next = NULL;

    assert(head);

    next = NULL;
    /* starting from the head,
    prev is the new head of the list */
    prev = head;
    curr = head->next;
 
    while (NULL != curr)
    {
        /* increment next */
        next = curr->next;
        /* curr point to the prev*/
        curr->next = prev;
        /* increment prev */
        prev = curr;
        /* increment curr */
        curr = next;
    }
    /* last head(which is the tail now) will point to NULL */
    head->next = NULL;

    return prev; 
}

int HasLoop(const node_t *head)
{
    node_t *head_t = NULL;
    node_t *head_org = NULL;

    assert(head);

    head_t = (node_t *)head;
    head_org = (node_t *)head;

    while(head_t)
    {
        head_t = head_t->next;
        if (head_t == head_org)
        {
            return 1;
        }
    }
    return 0;
}

/*return a pointer to the first node mutual to both list,
otherwise return null*/
node_t *FindIntersection(node_t *head1, node_t *head2)
{
    node_t *first_list_head = NULL;
    node_t *second_list_head = NULL;

    assert(head1); 
    assert(head2);

    first_list_head = head1;
    second_list_head = head2;

    while((first_list_head) && (second_list_head))
    {
        if(first_list_head == second_list_head)
        {
            return first_list_head;
        }

        first_list_head = first_list_head->next;
        second_list_head = second_list_head->next;
    }

    return NULL;
}

node_t *CreateNode(void *data)
{
    node_t *new_node;

    new_node = (node_t *)malloc(sizeof(node_t));
    
    if (new_node == NULL)
    {
        return NULL;
    }

    new_node->next = NULL;

    new_node->data = data;

    return new_node; 
}

node_t *PushNode(node_t *head, void *data)
{

    node_t *new_head = NULL;

    assert(data);

    new_head = CreateNode(data);

    if (new_head == NULL)
    {
        return NULL;
    }

    new_head->next = head;

    return new_head;
}

void Destroy(node_t *head)
{
    node_t *temp = NULL;
    node_t *to_delete = NULL;
    temp = head;

    while(temp != NULL)
    {
        to_delete = temp;
        temp = temp->next;
        free(to_delete);
    }
}






