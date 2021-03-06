// kruskal's algo on finding min span tree
// done
#include<stdio.h>
#include<stdlib.h>

typedef struct Edge{
	int src;
	int des;
	int weight;
}Edge;

typedef struct Graph{
	int V;
	int E;
	Edge *edges;
}Graph;

Graph *create(int V, int E){
	Graph *g = (Graph*)malloc(sizeof(Graph));
	g->V = V;
	g->E = E;
	g->edges = (Edge*)malloc(E*sizeof(Edge));
	int i;	
	for(i = 0; i < E; i++){
		Edge hlp;
		scanf("%d%d%d",&hlp.src,&hlp.des,&hlp.weight);
		*(g->edges+i) = hlp;
	}
	return g;
}
// sort:: qsort() in stdlib.h; we can try merge sort
// or just implement minheap to lower time complexity
int comp(const void* a, const void* b){
	Edge *aa = (Edge*)a;
	Edge *bb = (Edge*)b;
	
	return aa->weight - bb->weight; // this works as well, should be 1,0,-1 tho
}

void swap(int *a, int *b){
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int *heap;

// collapsing find:: make root(height<0) the only parent in a tree/heap
// heap:
// 	idx:     0 1  2 3 ...
// 	height:  1 2 -3 0 .. 
// after find(): 2 2 -3 2
int Find(int tar){
	/* if parent != Find(tar)
	 	path compression
	   return parent
	*/
	
	int parent = *(heap+tar);
	// int height = Find(parent);
	// if height < 0:: root node, so return
	if (parent < 0){
		return tar;
	}
	// else: path compression
	parent = Find(parent); // find recursively
	*(heap+tar) = parent; // fill in

	return parent;
}

// height rule (weight rule is fine tho)
void united(int a, int b){
	// maintain a >= b
	if(a < b){
		swap(&a,&b);
	}

	// increase height by 1, height < 0
	if(Find(a) == Find(b)){
		*(heap+a) -= 1;
	}

	*(heap+b) = a; // united
}

void MST(Graph *graph){
	/*
	kruskal:
	 start with vertices and no edges
	 if ith edge cost the least and not form a cycle
	 , then build edge
			
	while(i < V && graph not empty()){
		// parent of src and des for each edge
		x = find(*(g->edges+i)->src)
		y = find(*(g->edges+i)->des)
		
		if not from a cycle
			merge(x,y)
		else 
			discard the edge
	}
	*/
	
	// init heap:: init height as -1 
	// and keep it negative if it's a root node
	int i;
	int V = graph->V;
	heap = (int*)malloc(V*sizeof(int));
	for(i = 0; i < V; i++){
		*(heap+i) = -1;
	}

	qsort(graph->edges,graph->E,sizeof(Edge),comp);

	// can init result array :: type Edge* or int*
	int totalcost = 0;
	int E = graph->E;
	i = 0;
	int idx = 0;
	while(idx < V && i < E-1){ // a bit faster than i < E-1 && idx < V
		printf("epoch: %d%3d%3d%4d;",i,(*(graph->edges+i)).src, (*(graph->edges+i)).des,(*(graph->edges+i)).weight);
		int x = Find((*(graph->edges+i)).src);
		int y = Find((*(graph->edges+i)).des);
		printf("  x: %d  y: %d\n",x,y);
		if(x != y){
			idx += 1;
			totalcost += (*(graph->edges+i)).weight;
			united(x,y);
		}

		i += 1;
	}

	printf("\ntotal cost: %d\n",totalcost);
}

/*
input:
7 9
0 1 28
0 5 10
1 2 16
5 4 25
6 4 24
1 6 14
3 4 22
2 3 12
3 6 18

output:
99
*/

int main(void){
	int V, E;
	scanf("%d%d",&V,&E);
	Graph *g = create(V,E);
	MST(g);
	return 0;
}
