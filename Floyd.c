#include<iostream>
#include"MGraph.h"
using namespace std;

typedef int Pathmatrix[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];

void ShorttestPath_Floyd(MGraph G, Pathmatrix *P, ShortPathTable *D)
{
	int v,w,k;
	for(v=0;v<G.numVertexes;v++)
		for(w=0;w<G.numVertexes;w++)
		{
			(*D)[v][w]=G.arc[v][w];
			(*P)[v][w]=w;
		}
	for(k=0;k<G.numVertexes;k++)
		for(v=0;v<G.numVertexes;v++)
			for(w=0;w<G.numVertexes;w++)
			{
				if((*D)[v][w]>(*D)[v][k]+(*D)[k][w])
				{
					(*D)[v][w]=(*D)[v][k]+(*D)[k][w];
					(*P)[v][w]=(*P)[v][k];
				}
			}

}

int main()
{
	Pathmatrix *P = new Pathmatrix[MAXVEX];
	ShortPathTable *D = new ShortPathTable[MAXVEX];
	MGraph G;
	int i,j,k,w;
	cout<<"Please input numVertexes and numEdges: ";
	cin>>G.numVertexes>>G.numEdges;
	cout<<"please input vexs name: "<<endl;
	for(i=0;i<G.numVertexes;i++)
		cin>>G.vexs[i];
	for(i=0;i<G.numVertexes;i++)
		for(j=0;j<G.numVertexes;j++)
		{
			if(i==j)
				G.arc[i][j]=0;
			else
				G.arc[i][j]=INFINITY;
		}
	for(k=0;k<G.numEdges;k++)
	{	
		cout<<"please input i,j,w: "<<endl;
		cin>>i>>j>>w;
		G.arc[i][j]=w;
		G.arc[j][i]=w;
	}
	
	ShorttestPath_Floyd(G, P, D);
	cout<<"The Following is P:"<<endl;
	for(i=0;i<G.numVertexes;i++)
	{
		for(j=0;j<G.numVertexes;j++)
		{
			cout<<(*P)[i][j]<<" ";
		}
		cout<<"\n";
	}
	delete []P;
	delete []D;
	return 1;
}
