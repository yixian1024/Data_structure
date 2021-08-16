1.Dijkstra
(1)If you want to start the execution,you muxt give the start and end point.
(2)Choose the least distance vertex to start.
(3)Save the least cost in the distace.
(4)Refresh the distance,if there have less distace for the vertex.

2.Kruskal
(1)Enter the adjacency matrix.
(2)Create the structure to save the edges in elist,and sort them.
(3)Choose the edges in elist inorder
(4)If their team leader are not the same,span the two team.
	Else discard the edge,since they form a circle.
(5)Print out the edges that were chosen.
(6)Print the input of BFS

3.BFS
(1)Input the file that Kruskal make.
(2)Like level order,insert the vertex didn't visit in queue.
(3)Insert -1 to know which level to be print.
(4)Print out the vertex that we are execute,and mark them as visited vertex.
