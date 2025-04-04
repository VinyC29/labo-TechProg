#include "labo.h"

long long fibonacci(int n)
{
	static long long number[512];

	if (n <= 1) { return n; }

	if (number[n] != 0) {
		return number[n];
	}
	number[n] = fibonacci(n - 1) + fibonacci(n - 2);

	return number[n];
	
}


TreeNode* tree_create_node(void* data)
{
	TreeNode* newNode = allocate(sizeof(TreeNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void tree_add_node(TreeNode* root, TreeNode* node) {
	if (root->left == NULL) {
		root->left = node;
		return;
	}

	if (root->right == NULL) {
		root->right = node;
		return;
	}
}

int dfs(TreeNode* root, void* key)
{
	Stack* frontier = allocate(sizeof(Stack));
	stack_init(frontier);
	TreeNode* currNode = root;
	int nodeVisited = 1;

	while (currNode->data != key)
	{
		if (currNode->right != NULL) {
			stack_push(frontier, currNode->right);
		}

		if (currNode->left != NULL) {
			stack_push(frontier, currNode->left);
		}

		Node* node = stack_pop(frontier);
		currNode = node->data;
		nodeVisited++;
	}

	return nodeVisited;
}

int bfs(TreeNode* root, void* key)
{
	Queue* frontier = allocate(sizeof(Queue));
	queue_init(frontier);
	TreeNode* currNode = root;
	int nodeVisited = 1;

	while (currNode->data != key && currNode != NULL)
	{
		if (currNode->right != NULL) {
 			queue_push(frontier, currNode->right);
		}

		if (currNode->left != NULL) {
			queue_push(frontier, currNode->left);
		}

 		Node* node = queue_pop(frontier);
		currNode =  node->data;
		nodeVisited++;
	}

	return nodeVisited;
}

	


