# Mutuals
Data Structure and Algorithm Mini-Project
OBJECTIVE
We have created a Social Media Network with the help Data Structures and Algorithms which helps in providing friend-suggestions to any specified user and has a built-in map feature which helps in giving the shortest distance from the set-location of a particular user to all other users which are directly, or indirectly are in contact with the user.
FEATURES, THEIR FUNCTIONS AND THEIR WORKING (DATA STRUCTURES AND ALGORITHMS USED)
1.	Storing the user details and connectivity: This Social-media uses Graph Data Structure to store the details of users (with the help of its nodes/vertices) and connectivity and distance, i.e., whether any two users are friends or not and if they are friends then what is the distance between their set locations (with the help of weighted undirected graph edges).
2.	Friend Suggestion: This social-media makes use of the very popular Breadth-First Search (BFS) Algorithm to traverse the network in “layers” and suggest friends by printing the names of all user which are not friends of the user but are friends of his/her friends. It uses the Queue Data Structure.
Algorithm:
Step 1: SET STATUS = 1 (ready state)
for each node in G
Step 2: Enqueue the starting node A
and set its STATUS = 2
(waiting state)
Step 3: Repeat Steps 4 and 5 until
QUEUE is empty
Step 4: Dequeue a node N. Process it
and set its STATUS = 3
(processed state).
Step 5: Enqueue all the neighbours of
N that are in the ready state
(whose STATUS = 1) and set
their STATUS = 2
(waiting state)
[END OF LOOP]
Step 6: EXIT
3.	Shortest Distance between any two users: To compute the shortest distance between any two users, the famous Dijkstra’s Shortest Path Graph Algorithm is used.
The Data structures employed wherein are: Priority-Queues or the Min-Heap Data Structure.
Algorithm:
i.	While min-heap Q is not empty, pop the node v, that is not already in set S, from Q with the smallest dist (v). In the first run, source node s will be chosen because dist (s) was initialized to 0. In the next run, the next node with the smallest dist value is chosen.
ii.	Add node v to S, to indicate that v has been visited
iii.	Update dist values of adjacent nodes of the current node v as follows: for each new adjacent node u,
if dist (v) + weight(u,v) < dist (u), there is a new minimal distance found for u, so update dist (u) to the new minimal distance value;
otherwise, no updates are made to dist (u).
iv.	The algorithm has visited all nodes in the graph and found the smallest distance to each node. dist now contains the shortest path tree from source s.

Note: The weight of an edge (u,v) is taken from the value associated with (u,v) on the graph.
