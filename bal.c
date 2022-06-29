#include "func.h"

void fix_height(Tree *tree) {
    int lheight, rheight;

    if (tree->left != NULL)  lheight = tree->left->height;
    else lheight = 0;

    if (tree->right != NULL)  rheight = tree->right->height;
    else rheight = 0;

    if (lheight > rheight) tree->height = lheight + 1;
    else tree->height = rheight + 1;
}

Tree* rotate_right(Tree* tree){
        Tree* p = tree->left;
        tree->left = p->right;
        p->right = tree;
    p->parent = NULL;
    p->right->parent = p;
    if (p->right->left != NULL) {
        p->right->left->parent = p->right;
    }
        fix_height(tree);
        fix_height(p);
        return p;
}

Tree* rotate_left(Tree* tree)
{
        Tree* p = tree->right;
        tree->right = tree->left;
        p->left = tree;
    p->parent = NULL;
    p->left->parent = p;
    if (p->left->right != NULL) {
        p->left->right->parent = p->left;
    }
        fix_height(tree);
        fix_height(p);
        return p;
}

int balance_factor(Tree* p) {
    int lheight, rheight;

    if (p->left != NULL)  lheight = p->left->height;
    else lheight = 0;

    if (p->right != NULL)  rheight = p->right->height;
    else rheight = 0;

        return rheight - lheight;
}

Tree *balance(Tree* p) {
    fix_height(p);
        if (balance_factor(p) == 2) {
                if (balance_factor(p->right) < 0) {
                        p->right = rotate_right(p->right);
        }
                p = rotate_left(p);
        return p;
        }

        if (balance_factor(p) == -2) {
                if (balance_factor(p->left) > 0 ) {
                        p->left = rotate_left(p->left);
        }
                p = rotate_right(p);
        return p;
        }
    return p;
}

