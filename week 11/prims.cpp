
#include <iostream>
using namespace std;

#define INFINITY 9999
// Number of vertices in the graph
#define v 6
void prims(int G[v][v],int startNode);
int main() {
    //adjacency matrix for the graph 
    int G[v][v] = {
        {0, 3 , 0, 0,0,1},
        {3, 0, 2, 1,10,0},
        {0, 2, 0, 3, 0,5},
        {0, 1, 3, 0,5,0},
        {0, 10, 0, 5, 0,4},
        {1, 0, 5, 0, 4, 0}
    };
    
    //calling the prims function by passing 0 as the startNode
   prims(G,0);

    
    return 0;
}

// prims algorithm to find the minimum spanning tree of the graph
void prims(int G[v][v],int startNode){
    // cost matrix stores the cost of the path from startNode to all other nodes,distance array stores the distance of each node from startNode
    // prevNodes stores the previous node of each node in the minimum spanning tree
    int cost[v][v], distance[v], prevNodes[v];
    bool visited[v];
    int visitedCount, minDistance, nextNode, i, j;
    
    //initialize cost matrix and distance array
    for(i=0; i < v; i++){
        //iterate through each column
        for(j=0; j < v; j++){
            //if there is no edge between the two nodes then the cost is infinity
            if(G[i][j] == 0){
                cost[i][j] = INFINITY;
            }
            //else the cost is the weight of the edge
            else{
                cost[i][j] = G[i][j];
            }
        }
    }
    
    //initialize distance array, prevNodes array and visited array
    for(i=0; i < v; i++){
        distance[i] = cost[startNode][i];
        prevNodes[i] = startNode;
        visited[i] = false;
    }
    
    //distance of startNode from itself is 0
    distance[startNode] = 0;
    //startNode is visited
    visited[startNode] = true;
    //visitedCount is 1 because startNode is already visited
    visitedCount = 1;
    
    //iterate till all the nodes are visited, we only go up to v-1 to find the minimum spanning tree
    while(visitedCount < v-1){
        //set the minDistance to infinity
        minDistance = INFINITY;
        //iterate through each node
        for(i=0; i < v; i++){
            //if the distance of the node is less than the minDistance and the node is not visited,update the minDistance to current distance and set the nextNode to the current node
            if(distance[i] < minDistance && !visited[i]){
                minDistance = distance[i];
                nextNode = i;
            }
        }
        //marked the next as visited in the visited array
        visited[nextNode] = true;
        //iterate through each node
        for(i=0; i < v; i++){
            //if the node is not visited and the minDistance + cost of the edge is less than the distance of the node,
                if(minDistance + cost[nextNode][i] < distance[i]){
                    //update the distance of the node to minDistance + cost of the edge and set the previous node of the node to nextNode
                    distance[i] = minDistance + cost[nextNode][i];
                    prevNodes[i] = nextNode;
                }
            }
        
        //increment the visitedCount
        visitedCount++;
    }
    
    //print the each edge in the minimum spanning tree with the weight starting from startNode
    cout << "Edge   :  Weight\n";
    //iterate through each node
    for(i = 0; i < v; i++){
        //if the node is not the startNode
        if(i!=startNode){
            //print the edge and the weight
            cout << i << " - " << prevNodes[i] << " : "<< cost[i][prevNodes[i]] << endl;
        }
    }
}
