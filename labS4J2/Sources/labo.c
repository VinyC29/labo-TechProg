#include "labo.h"


void push(Queue* q, Node* n) {
	if (q->next == NULL) {
		q->next = q->prev = n;
	}
	else
	{
		Node* last = q->next;
		n->next = last;
		last->prev = n;
		q->next = n;
	}
}


Node* pop(Queue* q) {
	Node* n = q->prev;
	if (q->prev != NULL) {
		if (q->prev == q->next) {
			q->next = q->prev = NULL;
		}
		else {
			q->prev = q->prev->prev;
		}
	}
	return n;
}


Node* peek(Queue* q) {
	return q->prev;
}


void pushAsPriorityQueue(Queue* q, Node* n) {
    Queue tempQueue = { NULL, NULL }; 

    while (q->next != NULL && ((Person*)peek(q)->data)->age <= ((Person*)n->data)->age) {
        push(&tempQueue, pop(q));
    }

    push(&tempQueue, n);

    while (q->next != NULL) {
        push(&tempQueue, pop(q));
    }

    while (tempQueue.next != NULL) {
        push(q, pop(&tempQueue));
    }
}


void sortQueue(Queue* q) {
    Queue tempQueue = { NULL, NULL }; 

    while (q->next != NULL) {
        Node* minNode = pop(q);
        Node* current = pop(q);
        Node* tempStack = NULL;

        while (current != NULL) {
            if (((Person*)current->data)->age < ((Person*)minNode->data)->age) {
                if (tempStack) push(q, tempStack);
                tempStack = minNode;
                minNode = current;
            }
            else {
                push(q, current);
            }
            current = pop(q);
        }

        push(&tempQueue, minNode);

       
        while (tempStack) {
            push(q, tempStack);
            tempStack = pop(q);
        }
    }

    while (tempQueue.next != NULL) {
        push(q, pop(&tempQueue));
    }
}