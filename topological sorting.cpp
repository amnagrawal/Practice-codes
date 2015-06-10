#include<iostream>
#include<stack>
using namespace std;

int current_label = 4;
int label[4];
struct  AdjListNode
{
	int dest;
	AdjListNode * next;
};

struct AdjList
{
	AdjListNode * head;
};

struct Graph
{
	int V;
	AdjList * array;
};

AdjListNode * newAdjListNode(int dest)
{
	AdjListNode * newNode = new AdjListNode;
	newNode -> dest = dest;
	newNode -> next = NULL;
	return newNode;
}

Graph * createGraph(int V)
{
	Graph * graph = new Graph;
	graph -> V = V;

	//Create an array of adjacency lists. Size of array is V
	graph -> array = new AdjList [V];

	//Initialize each adjacency list as empty
	for(int i=0; i<V; ++i)
		graph->array[i].head = NULL;

	return graph;
}

//Adds an edge to the directed graph
void addEdge(Graph * graph, int src, int dest)
{
	AdjListNode * newNode = newAdjListNode(dest);
	newNode -> next = graph -> array[src].head;
	graph -> array[src].head = newNode;
}

void printGraph(Graph * graph)
{
	cout<<graph->V;
	for (int i = 0; i < graph -> V; ++i)
	{
		AdjListNode * pCrawl = graph ->array[i].head;
		cout<<"\n Adjacency list of vertex " <<i<<"\n head";
		while(pCrawl)
		{
			cout<<"-> "<<pCrawl->dest;
			pCrawl = pCrawl->next;
		}
		cout<<endl;
	}
}

void dfs(Graph * graph, int start , int visited[])
{
	stack <int> s;
	AdjListNode * temp;
	visited[start] = 1;
	//cout<<start;
	temp = graph->array[start].head;
	while(temp)
	{
		if(visited[temp->dest] == 0)
			dfs(graph, temp->dest, visited);

		temp = temp->next;
	}

	label[start] = current_label;
	current_label--;
}

void dfsLoop(Graph * graph, int visited[])
{
	for (int i = 0; i < graph -> V; ++i)
	{
		if(visited[i] == 0)
			dfs(graph, i, visited);
	}
}

int main()
{
	int V = 4;
	Graph * graph = createGraph(V);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 2, 3);

	//printGraph(graph);
	int visited[V];
	for (int i = 0; i < V; ++i)
	{
		visited[i] =0 ;
	}

	//dfs(graph, 0, visited);
	dfsLoop(graph, visited);
	for (int i = 0; i < V; ++i)
	{
		cout<<label[i]<<" ";
	}
	return 0;
}