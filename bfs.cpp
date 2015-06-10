#include<iostream>
using namespace std;

int main()
{
	int n, m, cost[10][10], v, visited[10], visit[10], front=0, rear=0, i, j, k, qu[10];
	cout<<"Enter no. of vertices: ";
	cin>>n;
	cout<<"Enter no. of edges: ";
	cin>>m;
	
	cout<<"Enter EDGES: ";
	for(int k=0; k<m; k++)
	{
		cin>>i>>j;
		cost[i][j] = 1;
		cost[j][i] = 1;
	}
	
	cout<<"Enter initial vertex: ";
	cin>>v;
	cout<<"Visited vertices\n";
	cout<<v;
	
	visited[v] =1;
	k=1;
	while(k<n)
	{
		for(j=0; j<n; j++)
		{
			if(cost[v][j] != 0 && visited[v] != 1 && visit[v] != 1)
			{
				visit[v] = 1;
				qu[rear++] = j;
			}
		}
		
		v = qu[front++];
		cout<<v<<" ";
		k++;
		visit[v]=0;
		visited[v] =1;
	}
	return 0;
}
