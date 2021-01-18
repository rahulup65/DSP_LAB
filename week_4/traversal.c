#include <stdio.h>
#include <stdlib.h>

// Structure of tree node.
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} tree_node;
tree_node *insert(tree_node *root, int value)
{
    if (root == NULL)
    {
        root = (tree_node *)malloc(sizeof(tree_node));
        root->data = value;
        root->left = root->right = NULL;
    }
    else
    {
        if (value > root->data)
        {
            root->right = insert(root->right, value);
        }
        if (value < root->data)
        {
            root->left = insert(root->left, value);
        }
    }
    return root;
}
void pre(tree_node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        pre(root->left);
        pre(root->right);
    }
}

void in(tree_node *root)
{
    if (root != NULL)
    {
        in(root->left);
        printf("%d ", root->data);
        in(root->right);
    }
}

void pos(tree_node *root)
{
    if (root != NULL)
    {
        pos(root->left);
        pos(root->right);
        printf("%d ", root->data);
    }
}
int main()
{
    tree_node *root = NULL;
    int number_of_nodes;
    int node;
    scanf("%d", &number_of_nodes);
    int i;
    for (i= 0; i < number_of_nodes; i++)
    {
        scanf("%d", &node);
        root = insert(root, node);
    }

    pre(root);
    printf("\n");

    in(root);
    printf("\n");
    pos(root);


    return 0;
}
