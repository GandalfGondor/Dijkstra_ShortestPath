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
	int i,j;
	MGraph G;
	G.numVertexes = 9;
	G.numEdges = 16;
	for(i=0;i<G.numVertexes;i++)
		for(j=0;j<G.numVertexes;j++)
			G.arc[i][j]=INFINITY;
	G.arc[0][1]=1;
	G.arc[0][2]=5;
	G.arc[1][2]=3;
	G.arc[1][3]=7;
	G.arc[1][4]=5;
	G.arc[2][4]=1;
	G.arc[2][5]=7;
	G.arc[3][4]=2;
	G.arc[4][5]=3;
	G.arc[3][6]=3;
	G.arc[4][6]=6;
	G.arc[4][7]=9;
	G.arc[5][7]=5;
	G.arc[6][7]=2;
	G.arc[6][8]=7;
	G.arc[7][8]=4;
	for(i=0;i<G.numVertexes;i++)
		for(j=0;j<G.numVertexes;j++)
			{
				if(G.arc[i][j]!=INFINITY)
						G.arc[j][i]=G.arc[i][j];
			}
	Patharc *P=new Patharc[MAXVEX];
	ShortPathTable *D = new ShortPathTable[MAXVEX];
	ShortestPath_Dijkstra(G,0, P, D);
	for(i=0;i<G.numVertexes;i++)
	{
		cout<<(*D)[i]<<endl;
	}
	return 1;
}
