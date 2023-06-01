

#include <iostream>
using namespace std;

#define max 6
#define INFINITY 9999
float dijkstra(int G[max][max], int n, int startNode);


int main() {
    //adjacency matrix for the graph which represent the time between each two cities
    int G[max][max] = {
        {0, 10 , 0, 0,15,5},
        {10, 0, 10, 30,0,0},
        {0, 10, 0, 12, 5,0},
        {0, 30, 12, 0, 0,20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };
    //n is the number of nodes in the graph(cities)
    int n = 6;
    float smallest_average_time[max];
    //calling the dijkstra function for each node and store the smallest average time in an array
    for(int i = 0; i < n;i++){
        smallest_average_time[i] = dijkstra(G,n,i);
        cout << endl;
    }

    //finding the smallest average time
    float smallest = smallest_average_time[0];
    for(int i=0;i<n;i++){
        if(smallest_average_time[i] < smallest){
            smallest = smallest_average_time[i];
        }
    }

    //printting all the cities that have the smallest average time
    cout << "Following city/cities have the smallest average time:" << endl;
    for(int i=0;i<n;i++){
        if(smallest_average_time[i] == smallest){
            cout<<"City "<< i << endl;
        }
    }
    
    return 0;
}

// Dijkstra's algorithm to find the shortest path from a node to all other nodes in the graph
float dijkstra(int G[max][max], int n, int startNode) {
    // costArray stores the cost of the path from startNode to all other nodes
    // timeArray stores the time of the path from startNode to all other nodes
    // prevNodes stores the previous node of each node in the shortest path
    int costArray[max][max], timeArray[max], prevNodes[max];
    // visited array stores whether a node has been visited or not
    bool visited[max];
    // count gives the number of nodes seen so far
    // mintime gives the minimum time of the path
    // nextNode gives the next node to be visited
    int count, mintime, nextNode, i, j;

    // Creating costArray from adjacency matrix
    for (i = 0; i < n; i++) {
        // If there is no edge between two nodes, cost is infinity
        for (j = 0; j < n; j++) {
            if (G[i][j] == 0)
                costArray[i][j] = INFINITY;
            // If there is an edge between two nodes, cost is the time of the edge
            else
                costArray[i][j] = G[i][j];
        }
    }

    // Initialize time array, prevNodes array and visited array
    for (i = 0; i < n; i++) {
        timeArray[i] = costArray[startNode][i];
        prevNodes[i] = startNode;
        visited[i] = false;
    }

    // Distance of startNode from itself is 0
    timeArray[startNode] = 0;
    // Start node has been visited
    visited[startNode] = true;
    // Count is 1 as startNode has been visited
    count = 1;

    // Loop to find the shortest path for all nodes
    while (count <= n - 1) {
        // Initializing mintime to infinity
        mintime = INFINITY;

        // Next node gives the node at minimum time
        for (i = 0; i < n; i++) {
            // If the node has not been visited and the time is less than mintime
            if (timeArray[i] < mintime && !visited[i]) {
                // mintime is updated
                mintime = timeArray[i];
                nextNode = i;
            }
        }
        // Checking if there is a better path
        visited[nextNode] = true;

        // Updating the time[] array
        for (i = 0; i < n; i++) {
            // If there is no edge between two nodes, cost is infinity
            if (!visited[i] && costArray[nextNode][i] != INFINITY && timeArray[nextNode] + costArray[nextNode][i] < timeArray[i]) {
                // Updating the time of the node
                timeArray[i] = timeArray[nextNode] + costArray[nextNode][i];
                // Updating the previous node of the node
                prevNodes[i] = nextNode;
            }
        }
        // Incrementing count
        count++;
    }

    // Printing the shortest path and time of each node from the start node
    for (i = 0; i < n; i++) {
        // If the node is not the start node
        if (i != startNode) {
            // Printing the time and path
            cout << "time from node " << startNode << " to node " << i << ": " << timeArray[i] << endl;
            cout << "Path: " << i;

            j = i;
            do {
                // Updating j to the previous node of j
                j = prevNodes[j];
                // Printing the path
                cout << " <- " << j;
            // Looping till the start node is reached
            } while (j != startNode);

            cout << endl;
        }
    }

    // Get the average time of the path from startNode to all other nodes
    int sum = 0;
    for (i = 0; i < n; i++) {
        if (i != startNode) {
            sum += timeArray[i];
        }
    }
    float avg = (float)sum / (n - 1);
    return avg;
}
