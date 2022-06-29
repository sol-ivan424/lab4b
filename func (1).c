#include "func.h"

const char *msgs[] = { "0. Quit", "1. Add"};
const int NMsgs = sizeof(msgs) / sizeof(msgs[0]);

void outputTree(char* prefix, Tree* node, int isLeft) {

    if (node) {
        printf("%s", prefix);
        if (isLeft) printf("├──");
        else printf("└──");

        printf("%d(%s)\n", node->key, node->info);

        char* addition;
        if (isLeft) addition = "│   ";
        else addition = "    ";

        int srclen = (int) strlen(prefix);
        int dstlen = (int) strlen(addition);
        char* m = (char*) calloc(srclen+dstlen+1, sizeof(char));
        memcpy(m, prefix, srclen+1);
        memcpy(m+srclen, addition, dstlen+1);

        outputTree(m, node->left, 1);
        outputTree(m, node->right, 0);

        free(m);
    }
}

void free_tree(Tree *tree) {
    if (tree == NULL) return;
    free_tree(tree->left);
    free_tree(tree->right);
    free(tree);
}

int getInt(int *pn)
{
	const char *errmsg = "";
	int n;
	do{
		puts(errmsg);
		errmsg = "Illegal integer; enter once more";
		n = scanf("%d", pn);
		if (n < 0)
			return 0;
		scanf("%*[^\n]");
		scanf("%*c");
	} while (n == 0);
	return 1;
}


int dialog(const char *msgs[], int N)
{
	const char *errmsg = "";
	int rc;
	int i, n;

	do{
		puts(errmsg);
		errmsg = "You are wrong. Repeat, please!";

		for (i = 0; i < N; ++i)
			puts(msgs[i]);
		puts("Make your choice: --> ");

		n = getInt(&rc);
		if (n == 0)
			rc = 0;
	} while (rc < 0 || rc >= N);

	return rc;
}

