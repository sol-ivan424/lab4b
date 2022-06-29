#include "func.h"

int main() {
    Tree *tree = NULL;
    tree = add(tree, 20, "Vasya");
    tree = add(tree, 16, "Vanya");
    tree = add(tree, 14, "Petya");
    tree = add(tree, 13, "Vova");
    tree = add(tree, 12, "Sanya");
    tree = add(tree, 9, "Lexa");
    tree = add(tree, 8, "Kostya");
    tree = add(tree, 5, "Timofey");
    tree = add(tree, 2, "Misha");

    del(tree, 8);

    printf("Find! : %s\n\n", find(tree,5)->info);
    printf("Max node : %d %s\n\n", find_max(tree)->key, find_max(tree)->info);

    outputTree("", tree, 0);
    free_tree(tree);
    return 0;
}

