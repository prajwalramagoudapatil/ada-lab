#include<stdio.h>
#include<stdlib.h>


typedef struct node {
 struct node *next;
 int vertex;
}node;
node *G[20]; 
//heads of linked list
int visited[20];
int n;
int q[20], f=0, r=-1;



void read_graph(); 
//create adjacency list
void insert(int
,int); 
//insert an edge(vi,vj) in the adjacency list
void DFS(int);
void BFS(int);
void printAdjList();

int stack[20], top=-1, v[20];
void topologicalSort(int v) {
  node *p, *q;
  
  p=G[v];
  visited[v] = 1;
  while( !v[p->vertex] ) {
    topologicalSort(p->vertex);
  }
  
  stack[++top] = v;
  
}

void main() {
 int i;
 read_graph();
 //initialised visited to 0
 
 for(i=0;i<n;i++)
 visited[i]=0;
 printf("adj list : \n");
 printAdjList();
 

 DFS(0);
 printf("\nafter dfs bef BFS\n");
 for(i=0;i<n;i++)
 visited[i]=0;
 BFS(0);
 printf("rama rama hare hare hare krishna hare krishna krishna krishna hare krishna");
}

void DFS(int i)
{
 node *p;
 
 printf("\n%d",i);
 p=G[i];
 visited[i]=1;
 while(p!=NULL)
 {
 i=p->vertex;
 
 if(!visited[i])
 DFS(i);
 p=p->next;
 }
}


void read_graph()
{
 int i,vi,vj,no_of_edges;
 printf("Enter number of vertices:");
 
 scanf("%d",&n);
 //initialise G[] with a null
 
 for(i=0;i<n;i++)
 {
 G[i]=NULL;
 //read edges and insert them in G[]
 
 printf("Enter number of edges:");
 scanf("%d",&no_of_edges);
 for(i=0;i<no_of_edges;i++)
 {
 printf("Enter an edge(u,v):");
 scanf("%d%d",&vi,&vj);
 insert(vi,vj);
 }
 }
}

void insert(int vi,int vj)
{
 node *p,*q;
 
 //acquire memory for the new node
 q=(node*)malloc(sizeof(node));
 q->vertex=vj;
 q->next=NULL;
 //insert the node in the linked list number vi
 

 if(G[vi]==NULL)
 G[vi]=q;
 else
 {
 //go to end of the linked list
 p=G[vi];
 
 while(p->next!=NULL)
 p=p->next;
 p->next=q;
 }
}

void printAdjList() {
  printf("\n in print Adjacency list () : \n");
  node *p;
  for(int i=0; i<n ; i++) {
    p = G[i];
    printf("node %d linked to: ",i);
    while(p != NULL) {
      printf("%d, ", p->vertex);
      p = p->next;
    }
    printf("\n");
  }
}