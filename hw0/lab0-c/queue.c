#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    /* TODO: What if malloc returned NULL? */
    // alloc successfully
    if (q) {
        q->head = NULL;
        q->tail = NULL;
        q->size = 0;
        return q;
    }
    // alloc error
    return NULL;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    if (!q)
        return;

    list_ele_t *tmp = q->head;
    while (q->head) {
        q->head = q->head->next;
        tmp->next = NULL;
        free(tmp->value);
        free(tmp);
        tmp = q->head;
    }
   
    free(q);
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    if (!q) // if q is NULL
        return false;

    list_ele_t *newh;

    /* allocate space for list element for queue */
    newh = malloc(sizeof(list_ele_t));
    if (!newh)
        return false;

    /* allocate space for string */
    newh->value = malloc((strlen(s)+1) * sizeof(char));
    if (!newh->value) {
        free(newh);
        return false;
    }
    
    /* clear the string and copy the input string */
    memset(newh->value, '\0', strlen(s)+1);
    strncpy(newh->value, s, strlen(s));

    /* Check tail, if it is NULL, this is the first insert */
    if (q->tail==NULL)
        q->tail = newh;
    else
        while (q->tail->next)
            q->tail = q->tail->next;
    
    newh->next = q->head;
    q->size = q->size + 1;
    q->head = newh;
    return true;
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    /* TODO: You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    /* TODO: Remove the above comment when you are about to implement. */
    if (!q)
        return false;
    
    list_ele_t *newh;
    newh = malloc(sizeof(list_ele_t));
    if (!newh)
        return false;
    
    newh->value = malloc((strlen(s)+1) * sizeof(char));
    if (!newh->value) {
        free(newh);
        return false;
    }

    /* clear the string and copy the input string */
    memset(newh->value, '\0', strlen(s)+1);
    strncpy(newh->value, s, strlen(s));

    /* first time allocate */
    if (!q->head)
        q->head = newh;
    
    newh->next = NULL;
    q->tail->next = newh;
    q->tail = newh;
    return true;
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    /* TODO: You need to fix up this code. */
    /* TODO: Remove the above comment when you are about to implement. */
    /* Safety check */
    if (!q)
        return false;
    if (q->size==0)
        return false;
    
    list_ele_t *tmp = q->head;
    q->head = q->head->next;

    /* Check sp is NULL or not*/
    if (sp) {
        /* copy removed element to sp */
        strncpy(sp, tmp->value, bufsize-1);
        strcat(sp, "\0");
    }

    /* free section */
    tmp->next = NULL;
    free(tmp->value);
    free(tmp);

    return true;
}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* O(1) */
    if (q) 
        return q->size;
    return 0;
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
    if (!q)
        return;
    list_ele_t *prev=NULL, *current, *next;
    current = q->head;
    while (1)
    {
        if (!current)
            break;
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    current = q->head;
    q->head = q->tail;
    q->tail = current;
}

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}
