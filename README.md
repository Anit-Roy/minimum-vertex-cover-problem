# minimum-vertex-cover-problem

The minimum vertex cover problem is a classic problem in computer science that deals with finding the smallest set of vertices in an undirected graph such that all edges in the graph are covered by at least one of the selected vertices. In other words, a vertex cover of a graph is a subset of its vertices such that each edge of the graph is incident to at least one vertex in the subset.

Formally, given an undirected graph G = (V, E), the minimum vertex cover problem asks to find a vertex cover C ⊆ V such that |C| is minimized. The problem is known to be NP-complete, which means that there is no known efficient algorithm that can solve this problem exactly for all instances. However, there exist approximation algorithms that can provide solutions that are close to the optimal solution.

One such algorithm is the greedy algorithm for the minimum vertex cover problem. The algorithm works as follows:

Initialize an empty set C = {}.
For each edge (u, v) in E, add either u or v (or both) to C.
Remove all edges covered by the vertices in C.
Repeat steps 2-3 until no more edges are left in E.
Output the set C as the minimum vertex cover.
It can be shown that the size of the vertex cover produced by the greedy algorithm is at most twice the size of the optimal vertex cover. Therefore, the greedy algorithm is a 2-approximation algorithm for the minimum vertex cover problem.



This C program implements a greedy algorithm to find a minimum vertex cover of an undirected graph given as an adjacency list. The input graph is represented as a 2D array where each row contains the adjacency list for a vertex.

The function getinputgraph() prompts the user to enter the number of vertices in the graph, and for each vertex, the user inputs the number of adjacent vertices and their indices. The function stores the graph as an adjacency list in a 2D array called graph.

The function greedyvcover() implements the greedy algorithm to find a minimum vertex cover. It starts by initializing an array called degree that stores the degree of each vertex (i.e., the number of adjacent vertices). Then, it repeatedly selects the vertex with the maximum degree, adds it to the vertex cover, and updates the degrees of its adjacent vertices. The algorithm terminates when all vertices have degree 0.

The function prints the vertex cover and its size.

Note that the program frees the memory allocated for the graph and degree arrays at the end of the execution.
