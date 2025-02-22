#include "labo.h"
#include <stdbool.h>

/*
* Creer un noeud et l'ajouter apres le noeud currNode. Utiliser la fonction allocate pour allouer de la memoire.
*/
void insert(Node* currNode, void* newData) {
	Node* newNode = malloc(sizeof(Node));
	newNode->data = newData;
	newNode->next = NULL;
	if (currNode->next != NULL) {
		newNode->next = currNode->next;
	}
	currNode->next = &newNode;
}

/*
* Creer un noeud et l'ajouter apres le noeud head. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/

void insertHead(Node* head, void* newData)
{
	if (head->data == NULL) {
		head->data = newData;
		return;
	}

	Node* newNode = malloc(sizeof(Node));
	newNode->data = newData;
	newNode->next = head->next;
	head->next = newNode;
	
}


Node* removeByData(Node* head, void* rmData)
{
	Node* temp = head;
	Node* last = NULL;


	while (temp != NULL && temp->data != rmData) {
		last = temp;
		temp = temp->next;
	}
	if (temp == NULL) {
		return;
	}
	last->next = temp->next;
	memset(temp, 0, sizeof(Node));
	
	return last;
}

Node* removeByName(Node* head, char* name)
{
	Node* temp = head;
	Node* last = NULL;

	while (temp != NULL && strcmp(name, ((Person*)temp->data)->name)) {
		last = temp;
		temp = temp->next;
	}
	if (temp == NULL) {
		return;
	}
	last->next = temp->next;
	memset(temp, 0, sizeof(Node));

	return last;
}

void sort(Node* head)
{
	bool echanger = false;

	Node *pointeur = head;
	Node *lastpointeur = NULL;
	
	do{
		echanger = false;
		pointeur = head;

		while (pointeur->next != lastpointeur) {
			Person* personne1 = (Person*)pointeur->data;
			Person* personne2 = (Person*)pointeur->next->data;

			if (personne1->age > personne2->age) {
				void* temporaire = pointeur->data;
				pointeur->data = pointeur->next->data;
				pointeur->next->data = temporaire;
				echanger = true;
			}
			pointeur = pointeur->next;
		}
		lastpointeur = pointeur;
	} while (echanger);
}