#ifndef __SLIST_EX_H__
#define __SLIST_EX_H__

typedef struct node
{
    void *data;
    struct node *next;
} node_t;

/* Reverses the order of a given single list */
node_t *Flip(node_t *head);
/*Tells whether a given single list has a loop, 1 true, 0 false*/
int HasLoop(const node_t *head);
/* Return a pointer to the first node mutual to both lists,
 * otherwise, return null*/
node_t *FindIntersection(node_t *head1, node_t *head2);
/* allocate memory to a new node
 * Return null if allocation failed */
node_t *CreateNode(void *data);
/* push node to the start of the list,
 * a new node will be the next head,
 * return null if allocation failed. */
node_t *PushNode(node_t *head, void *data);
/* free all list allocations of one single list */
void Destroy(node_t *head);

#endif  /*  __SLIST_EX_H__    */

