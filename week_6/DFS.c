#include <stdio.h>
#include <stdlib.h>

// Structure for each node.
typedef struct node
{
	int data;
	struct node *next;
} stack;

// Global variables
stack *top = NULL;
int **graph;
int total_node;
int *visited;
int *node_name;

// int graph[100][100];
// int graph[100][100]={
//         {0,1,1,1,0},
//         {1,0,1,0,0},
//         {1,1,0,0,1},
//         {1,0,0,0,0},
//         {0,0,1,0,0}
//     };

// int graph[100][100]={
//      {0,1,0,1,0,0},
// 		{1,0,1,0,1,0},
// 		{0,1,0,0,0,0},
// 		{1,0,0,0,0,0},
// 		{0,1,0,0,0,1},
// 		{0,0,0,0,1,0}
//     };

// Function to check STACK is empty.
int is_empty()
{
	if (NULL == top)
		return 1;
	else
		return 0;
}

// Function to push item into the STACK.
void push(int input)
{
	stack *element = (stack *)malloc(sizeof(stack));
	if (NULL == element)
	{
		printf("\n\t STACK IS FULL!!");
	}
	else
	{
		element->data = input;
		if (NULL == top)
		{
			top = element;
			top->next = NULL;
		}
		else
		{
			element->next = top;
			top = element;
		}
	}
}

// Function to pop item from the STACK.
int pop()
{
	if (is_empty())
	{
		printf("\n\tSTACK IS EMPTY!\n");
		return -1;
	}
	else
	{
		int item = top->data;

		stack *del = top;
		top = top->next;
		del->next = NULL;
		free(del);

		return item;
	}
}

// Function to print visiting nodes.
void show_visiting_node(int node_index)
{
	printf("\n\t VISITING NODE : %d ", node_name[node_index]);
}

// DFS Algorithm.
void dfs(int node)
{
	// Starting node.
	visited[node] = 1;
	show_visiting_node(node);

	// If there is a adjacent node. recursively call DFS with that node.
	for (int i = 0; i < total_node; i++)
		if (1 == graph[node][i] && 0 == visited[i])
			dfs(i);
}

int main()
{
	// total_node=6;
	scanf("%d", &total_node);
	printf("\n TOTAL NUMBER OF NODES : %d",total_node);

	// Allocating memeory.
	visited = (int *)calloc(total_node, sizeof(int));
	node_name = (int *)calloc(total_node, sizeof(int));
	graph = (int **)malloc(total_node * sizeof(int *));
	for (int i = 0; i < total_node; i++)
		graph[i] = (int *)malloc(total_node * sizeof(int));

	// Name of the nodes.
	printf("\n NAME OF %d NODES : ", total_node);
	for (int i = 0; i < total_node; i++){
		scanf("%d", &node_name[i]);
		printf("%d",node_name[i]);
		printf(" ");}
    printf("\n");

	// Adjacency Matrix of given graph.
	printf("\n Adjacency Matrix \n");
	for (int i = 0; i < total_node; i++)
	{

		for (int j = 0; j < total_node; j++)
			scanf("%d", &graph[i][j]);
	}
    for (int i=0;i<total_node;i++){
	    for(int j=0;j<total_node;j++){
	       printf( "%d",graph[i][j]);
	       printf(" ");
	    }
	    printf("\n");
	}
	// DFS calling for components of graph.
	printf("\n Depth first search :\n");
	for (int node = 0; node < total_node; node++)
		if (0 == visited[node])
			dfs(node);

	printf("\n");
	return 0;
}

/*
0 1 1 1 0
1 0 1 0 0
1 1 0 0 1
1 0 0 0 0
0 0 1 0 0
0 1 0 1 0 0
1 0 1 0 1 0
0 1 0 0 0 0
1 0 0 0 0 0
0 1 0 0 0 1
0 0 0 0 1 0
*/
