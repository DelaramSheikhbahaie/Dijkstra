#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h>

int V;
// spt = shortest path tree 
 
  
int printResult(int distance[], int n) 
{ 
    printf("Vertex   Distance from Source\n"); 
    for (int i = 0; i < V; i++) 
        printf("vertex: %d - distance: %d\n", i, distance[i]); 
} 
int minimum(int distance[],bool sptSet[]){
	
	int min = INT_MAX , minIndex;
		
	for(int i=0 ; i<V; i++){
		if(sptSet[i]==false &&distance[i]<=min){
			min = distance[i];
			minIndex=i;
		}	
	}
	return minIndex;
}

int count;
void Solve(int **graph, int distance[], bool sptSet[],  int start , int end){
	
	
	if(start == end)
			printResult(distance, V);
				
	else{
			
		for (count = 0; count < V ; count++) {
		
   		 if(graph[start][count]!=0){
   		 
   			if(sptSet[count] == false){
   			if(graph[start][count]+ distance[start]<distance[count])
   				distance[count]=graph[start][count]+ distance[start];
   			
			}
		}
	}
				int nextStart = minimum(distance , sptSet);
   				sptSet[nextStart] = true; 	
   				
			  
				
   	 Solve(graph, distance, sptSet, nextStart , end);
   }
}
void dijkstra( int **graph, int start , int end){ 
    int distance[V]; 
  
    bool sptSet[V];

  
   
    for (int i = 0; i < V; i++) 
        distance[i] = INT_MAX, sptSet[i] = false; 
        
        distance[start] = 0; 
  		sptSet[start] = true;
  		
  		
  		
  	Solve(graph, distance ,sptSet ,start , end);
    } 
void showMatrix(int**graph) {
   	
   	printf("Matrix:\n");
  	for (int i = 0; i < V; i++) { 
  
        for (int j = 0; j <V; j++) { 
        
        	printf("%d\t" , graph[i][j]);
   		 }
   		 printf("\n");
	}
}
int main() {
	
	 printf("number of vertex: ");
     scanf("%d" , &V);
    
	int ** graph = (int**)malloc(sizeof(int*)*V);
	for(int i=0 ; i<V ; i++)
	*(graph+i) = (int*)malloc(sizeof(int)*V);
	
    int data;
  	printf("enter the data \n");
  	
  	  for(int i=0 ; i<V ; i++){
         for(int j=0 ; j<V ; j++){
           scanf("%d" , &data);
            graph[i][j] = data;
        }
	}
	int start , end;
	printf("Start vertex: ");
	scanf("%d" , &start);
	printf("End vertex: ");
	scanf("%d" , &end);
    dijkstra(graph, start , end);
    showMatrix(graph);
    return 0; 
} 
