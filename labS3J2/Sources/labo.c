#include "labo.h"
#include <cstdbool>

void insert(Node* currNode, void* newData) {
	Node* newNode = malloc(sizeof(Node));
	newNode->data = newData;
	newNode->prev = NULL;
	newNode->next = NULL;
	if (currNode->next != NULL) {
		newNode->next = currNode->next;
		currNode->next->prev = newNode;
	}
	currNode->next = newNode;
	newNode->prev = currNode;
}

void insertTail(Node* head, void* newData) {
	if (head->data == NULL) {
		head->data = newData;
		return;
	}

	Node* newNode = malloc(sizeof(Node));
	newNode->data = newData;

	Node* tail = head->prev;

	newNode->prev = tail;
	newNode->next = head;
	tail->next = newNode;
	head->prev = newNode;
}

void insertHead(Node* head, void* newData) {
	if (head->data == NULL) {
		head->data = newData;
		return;
	}

	Node* newNode = malloc(sizeof(Node));
	newNode->data = newData;

	Node* otherNode = head->next;
	newNode->next = otherNode;
	newNode->prev = head;
	otherNode->prev = newNode;
	head->next = newNode;
}

Node* removeNode(Node* currNode) {
	Node* prev = currNode->prev;
	Node* next = currNode->next;

	next->prev = prev;
	prev->next = next;

	currNode->next = NULL;
	currNode->prev = NULL;

	return currNode;
}


void alphabetise(Node* head, char* names[]) {

	Node* pointer = head;
	int j = 0;

	do {
		Person* personne = (Person*)pointer->data;
		names[j] = personne->name;
		j++;
		pointer = pointer->next;

	} while (pointer != head);

	bool echanger = false;


	for (int i = 0; i <= j - 2; i++) {

		if (names[i][0] > names[i + 1][0]) {
			echanger = true;
			int temp = names[i];
			names[i] = names[i + 1];
			names[i + 1] = temp;
		}
		else if(names[i][0] == names[i + 1][0] && names[i][1] > names[i + 1][1])
		{
			echanger = true;
			int temp = names[i];
			names[i] = names[i + 1];
			names[i + 1] = temp;
		}


		if (i > j - 2 && echanger) {
			echanger = false;
			i = -1;
		}
	}
}