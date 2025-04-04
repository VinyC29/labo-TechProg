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
	return 0;
}

int bfs(TreeNode* root, void* key)
{
	Queue* frontier = allocate(sizeof(Queue));
	queue_init(frontier);
	queue_push(frontier, root);
	int nodeVisited = 0;
	int nbNode = 1;

	while (frontier->count < nbNode)
	{
		Node* node = queue_pop(frontier);
		TreeNode* currentNode = node->data;
		nodeVisited++;
		if (currentNode->data == key) {
			break;
		}

		if (currentNode->left != NULL) {
			queue_push(frontier, currentNode->left);
			nbNode++;
		}

		if (currentNode->right != NULL) {
			queue_push(frontier, currentNode->right);
			nbNode++;
		}
 	
	}

	return nodeVisited;
}

	


