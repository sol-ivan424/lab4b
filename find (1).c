#include "func.h"

Tree *find(Tree *tree, int key) {
    Tree *cur_vertex = tree;
    while (cur_vertex != NULL) {
        if (key > cur_vertex->key) {
            cur_vertex = cur_vertex->right;
        } else if (key < cur_vertex->key) {
            cur_vertex = cur_vertex->left;
        } else {
            return cur_vertex;
        }
    }

    return NULL;
}

Tree *find_max(Tree *tree) {
    if (tree == NULL) return NULL;
    Tree *cur_vertex = tree;
    Tree *prev_vertex = tree;

    while (cur_vertex != NULL) {
        prev_vertex = cur_vertex;
        cur_vertex = cur_vertex->right;
    }

    return prev_vertex;
}
