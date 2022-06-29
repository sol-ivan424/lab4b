#include "func.h"

int del(Tree *tree, int key) {
    Tree *to_delete = find(tree, key);
    if (to_delete == NULL) return 1;

    Tree *replace_with = find_max(to_delete->left);
    Tree *parent = NULL;
    if (replace_with == NULL) {
        parent = to_delete->parent;
        if (parent->left != NULL && parent->left->key == to_delete->key) {
            parent->left = NULL;
        }

        if (parent->right != NULL && parent->right->key == to_delete->key) {
            parent->right = NULL;
        }
        free(to_delete);
    } else {
        parent = replace_with->parent;
        parent->right = replace_with->left;

        to_delete->info = replace_with->info;
        to_delete->key = replace_with->key;
        free(replace_with);
    }

    parent = balance(parent);

    return 0;
}
