#include <stdint.h>
#include "labo.h"


Stack* new_stack(size_t max_size) {
   	Stack* newStack = allocate(sizeof(Stack));
	newStack->max_size = max_size;
	newStack->top = -1;
	newStack->data = allocate(sizeof(Person) * newStack->max_size);
	return newStack;
}


void push(Stack* s, void* newData){
	if (s->top + 1 < s->max_size) {
		s->top += 1;
		s->data[s->top] = newData;
	}
}


void* pop(Stack* s) {
	void* out = NULL;
	if (s->top >= 0) {
		out = s->data[s->top];
		s->top -= 1;
	}
 	return out;
}


void* peek(Stack* s) {
	void* out = pop(s);
	if (out != NULL) {
		push(s, out);
	}
	return out;
}


void reverseStack(Stack* s) {
	
	int i = 0;
	
	while (i < s->max_size / 2) {
		void* temp = s->data[s->top - i];
		s->data[s->top - i] = s->data[i];
		s->data[i] = temp;
		i++;
	}
}


void sortStack(Stack* s) {

	Stack* tempStack = new_stack(s->max_size);

	while (s->top >= 0) {
		void* tempData = pop(s);
		Person* tempPerson = (Person*)tempData;

		while (tempStack->top >= 0 && ((Person*)peek(tempStack))->age > tempPerson->age) {
			push(s, pop(tempStack));
		}

		push(tempStack, tempPerson);
	}

	while (tempStack->top >= 0) {
		push(s, pop(tempStack));
	}
}