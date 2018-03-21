#include<iostream>
#include"MGraph.h"

typedef int Patharc[MAXVEX];
typedef int ShortPathTable[MAXVEX];

using namespace std;

void ShortestPath_Dijkstra(MGraph G,int v0, Patharc *P, ShortPathTable *D)
{
	int v, w,k,min;
	int final[MAXVEX];
	for(v=0;v<G.numVertexes;v++)
	{
		final[v] = 0;
		(*D)[v] = G.arc[v0][v];
		(*P)[v] = 0;		

	}
	(*D)[v0] = 0;
	final[v0] = 1;

	for(v=1;v<G.numVertexes;v++)
	{
		min = INFINITY;
		for(w=0;w<G.numVertexes;w++)
		{
			if(!final[w]&&(*D)[w]<min)
			{
				k=w;
				min = (*D)[w];
			}
			
		}
		final[k]=1;
		for(w=0;w<G.numVertexes;w++)
		{
			if(!final[w]&& min+G.arc[k][w]<(*D)[w])
			{
				(*D)[w] = min+G.arc[k][w];
				(*P)[w] = k;
			}	
		
		}
		
	}
	
	
}

int main()
{
	int i,j,k,w;
	MGraph G;
	cout<<"Input NumVertexes: ";
	cin>>G.numVertexes;
	cout<<"Input NumEdges: ";
	cin>>G.numEdges;
	for(i=0;i<G.numVertexes;i++)
		for(j=0;j<G.numVertexes;j++)
			G.arc[i][j]=INFINITY;
	for(i=0;i<G.numVertexes;i++)
	{
		cout<<"Please input Vertexes "<<i<<" name :";
		cin>>G.vexs[i];
	}
	for(k=0;k<G.numEdges;k++)
	{
		cout<<"Please input i j and w"<<endl;
		cin>>i>>j>>w;
		G.arc[i][j]=w;
		G.arc[j][i]=w;
	}
	Patharc *P=new Patharc[MAXVEX];
	ShortPathTable *D = new ShortPathTable[MAXVEX];
	ShortestPath_Dijkstra(G,0, P, D);
	cout<<"\nthis is shortest table: ";
	for(i=0;i<G.numVertexes;i++)
	{
		
		cout<<(*D)[i]<<" ";
	}
	cout<<endl;
	return 1;
}
