#include<iostream>
#include<queue>
#include<stack>
using namespace std;

//A structure to represent adjacency list node
struct AdjListNode
{
	int dest;
	AdjListNode * next;
};

//A structure to represent an adjacency list
struct AdjList
{
	AdjListNode * head; //pointer to head node of the list
};

//A structure to represent a graph. A graph is an array of adjacency
//Size of array will be V (no. of vertices in graph)
struct Graph
{
	int V;
	AdjList * array;
};

//A utility fxn to create a new adjacency list node
AdjListNode * newAdjListNode(int dest)
{
	AdjListNode * newNode = new AdjListNode;
	newNode -> dest = dest;
	newNode -> next = NULL;
	return newNode;
}

//A utility fxn that creates a graph of V vertices
Graph * createGraph(int V)
{
	Graph * graph = new Graph;
	graph -> V = V;

	//Create an array of adjacency lists. Size of array will be V
	graph -> array = new AdjList [V];

	//Initialize each adjacency list as empty by making head as NULL
	for (int i = 0; i < V; ++i)
	{
		graph -> array[i].head = NULL;
	}

	return graph;
}

//Adds an edge to an undirected graph
void addEdge(Graph * graph, int src, int dest)
{
	//Add an edge from src to dest. A new node is added to the adjacency
	//list of src. The node is added at the beginning
	AdjListNode * newNode = newAdjListNode(dest);
	newNode -> next  = graph -> array[src].head;
	graph -> array[src].head = newNode;

	//Since graph is undirected, add an edge from dest to src also
	newNode = newAdjListNode(src);
	newNode -> next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}

//A utility function to print the adjacency list representation of graph
void printGraph(Graph * graph)
{
	cout<<graph->V;	
	for (int v = 0; v < graph -> V; ++v)
	{
		AdjListNode *pCrawl = graph ->array[v].head;
		cout<<"\n Adjacency list of vertex "<<v<<"\n head ";
		while(pCrawl)
		{
			cout<<"-> "<<pCrawl -> dest;
			pCrawl = pCrawl->next;
		}
		cout<<endl;
	}
}

//Fxn to perform bfs on the graph
void bfs(Graph * graph, int start)
{
	queue <int> q;
	AdjListNode * temp;
	int visited[graph->V];
	for (int i = 0; i < graph->V; ++i)
	{
		visited[i] = 0;
	}

	cout<<"bfs ordering of the graph from vertex"<<start<<"is: ";
	q.push(start);
	visited[start] = 1;

	while(!q.empty())
	{
		temp = graph->array[q.front()].head;
		while(temp)
		{
			if(visited[temp->dest] == 0)
			{
				q.push(temp->dest);
				visited[temp->dest] = 1;
			}
			temp = temp->next;
		}

		cout<<q.front();
		q.pop();
	}

}

void dfs(Graph * graph, int start)
{
	stack <int> s;
	AdjListNode * temp;
	int visited[graph -> V];
	for (int i = 0; i < graph-> V; ++i)
	{
		visited[i] = 0;
	}

	//cout<<"dfs ordering of the graph from vertex"<<start<<"is: ";
	s.push(start);
	visited[start] = 1;

	while(!s.empty())
	{
		temp = graph->array[start].head;
		while(temp)
		{
			if(visited[temp->dest] == 0)
			{
				visited[temp->dest] = 1;
				cout<<temp->dest;
				s.push(temp->dest);
				start = temp->dest;
				break;
			}
			else
			{
				temp= temp->next;
			}

			if(temp==NULL)
			{
				start = s.top();
				s.pop();
			}
		}
	}
}

void dfs_recurse(Graph * graph, int start, int visited[])
{
	AdjListNode * temp;
	visited[start] = 1;
	cout<<start;
	temp = graph->array[start].head;
	while(temp)
	{
		if(visited[temp->dest] == 0)
			dfs_recurse(graph, temp->dest, visited);

		temp= temp->next;
	}
}

int main()
{
	int V = 5;
	Graph * graph = createGraph(V);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);

	//Print the adjacency list representation of the graph
	//printGraph(graph);
	
	//Print bfs implementation of the graph
	//bfs(graph, 1);

	//Print the dfs implementation of the graph
	//Non-recursive implementation of bfs
	//dfs(graph, 0);

	int visited[V];
	for (int i = 0; i < V; ++i)
	{
		visited[i] = 0;
	}
	//recursive implementation of bfs
	dfs_recurse(graph, 0, visited);
	return 0;
}