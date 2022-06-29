#include "func.h"

Tree* add(Tree* tree, int key, char *info) {
	if (!tree) {
        Tree *new_node = malloc(sizeof(Tree));
        new_node->key = key;
        new_node->info = info;
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->height = 1;
        return new_node;
    }
	if (key < tree->key)
		tree->left = add(tree->left, key, info);
	else if (key > tree->key)
		tree->right = add(tree->right, key, info);
    else
        tree->info = info;

	return balance(tree);
}


