#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} tree_node;

tree_node *insert(tree_node *root, int x)
{
    if (root == NULL)
    {
        root = (tree_node *)malloc(sizeof(tree_node));
        root->data = x;
        root->left = root->right = NULL;
    }
    else
    {
        if (x > root->data)
            root->right = insert(root->right, x);
        if (x < root->data)
            root->left = insert(root->left, x);
    }
    return root;
}
int max(int x, int y) { return (x < y ? y : x); }

int height(tree_node *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

int main()
{
    tree_node *root = NULL;
    int n;
    int node;

    printf(" number of nodes ");
    scanf("%d", &n);

    printf("insert nodes : ");
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &node);
        root = insert(root, node);
    }

    printf("height is : ");
    printf("%d",height(root));

    printf("\n");

    return 0;
}

