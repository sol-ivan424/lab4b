#include <stdio.h>
#include <string.h>
#include <malloc.h>

const char *msgs[2];
const int NMsgs;

typedef struct Tree{
    int key;
    int height;
    struct Tree *left;
    struct Tree *right;
    struct Tree *parent;
    char *info;
} Tree;

Tree *add(Tree *tree, int key, char *info);
void outputTree(char* prefix, Tree* node, int isLeft);
Tree *balance(Tree* p);
int del(Tree *tree, int key);
Tree *find(Tree *tree, int key);
Tree *find_max(Tree *tree);
void free_tree(Tree *tree);

