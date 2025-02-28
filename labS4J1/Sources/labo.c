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

	while (s->top > 0) {
		void* tempData1 = pop(s);
		Person* person1 = (Person*)tempData1;
		void* tempData2 = pop(s);
		Person* person2 = (Person*)tempData2;

		if (person1->age > person2->age) {
			push(tempStack, person1);
			push(s, person2);
		}
		else
		{
			push(tempStack, person2);
			push(s, person1);
		}
	}

	void* tempData = pop(s);
	push(tempStack, tempData);

	while (tempStack->top > 0) {
		void* tempData1 = pop(tempStack);
		Person* person1 = (Person*)tempData1;
		void* tempData2 = pop(tempStack);
		Person* person2 = (Person*)tempData2;

		if (person1->age < person2->age) {
			push(s, person1);
			push(tempStack, person2);
		}
		else
		{
			push(s, person2);
			push(tempStack, person1);
		}
	}

	void* tempDataEnd = pop(tempStack);
	push(s, tempDataEnd);
}