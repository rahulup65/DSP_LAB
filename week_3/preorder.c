#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *left, *right;
    int data;
} *root = NULL;
int *in, *post, size;
int findnextnode(int start, int end)
{
    int i, j;
    for (i = size - 1; i >= 0; i--)
    {
        for (j = start; j <= end; j++)
        {
            if (post[i] == in[j])
                return j;
        }
    }
    return -1;
}

struct node *buildtree(struct node *root, int start, int end)
{
    if (start > end)
        return NULL;
    root = (struct node *)malloc(sizeof(struct node));
    root->left = root->right = NULL;
    int index = findnextnode(start, end);
    root->data = in[index];
    if (start == end)
        return root;
    root->left = buildtree(root->left, start, index - 1);
    root->right = buildtree(root->right, index + 1, end);
    return root;
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    int i;
    scanf("%d", &size);
    in = (int *)malloc(sizeof(int) * size);
    post = (int *)malloc(sizeof(int) * size);
    for (i = 0; i < size; i++)
        scanf("%d", &in[i]);
    for (i = 0; i < size; i++)
        scanf("%d", &post[i]);
    root = buildtree(root, 0, size - 1);
    preorder(root);
    return 0;
}
