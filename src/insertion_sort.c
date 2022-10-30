#include "insertion_sort.h"

#include <stdio.h>

#include "linked_list.h"

void sort(linked_list *llPtr) {
    // the "left" part of the list is always sorted, therefore the first node
    // must be sorted. Three node pointers are created, one for the current node
    // to be inserted, one for the next to be inserted in the sorted list, and a
    // temporary, which the currNode wille be inserted after

    node_t *currNode = llPtr->head;
    node_t *nextNode = llPtr->head->next;
    node_t *temp;

    // The first node is correct
    currNode->next = NULL;

    // The outerloop runs through the entire list, as we need to sort it all
    while (nextNode != NULL) {
        // "Incrementing" or rather updating the nodes to be the next nodes
        currNode = nextNode;
        nextNode = nextNode->next;
        // If the currNode to be inserted is smaller than the head, we need
        // to assign it as head
        // Otherwise we find the node, where we insert the currNode
        if (currNode->data < llPtr->head->data) {
            currNode->next = llPtr->head;
            llPtr->head = currNode;
        } else {
            temp = llPtr->head;
            while (temp->next != NULL && temp->next->data < currNode->data) {
                temp = temp->next;
            }
            // Inserting the current node, in its correct position
            currNode->next = temp->next;
            temp->next = currNode;
        }
    }
}
