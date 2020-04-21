#Problem Statement: 
Find identically colored connected components in a triangle mesh with Open3D. An identically-colored connected component consists of spatially connected vertices with the same color.

#[I] Algorithm 1 IdenticallyColoredConnectedComponents()
Data structures used: 
(a) list<list<int> > connected_components_list    //To store the list of connected components
(b) list<int> connected_component                 //To store one connected component
(c) bool *visited                                 //To keep track of visited vertices

Steps:
1. Compute the adjacency list from the read mesh using ComputeAdjacencyList().
2. Initialize visited[vertices_.size()] := False, i.e. mark all verticess as not visited. 
3. for v = 0 to vertices_.size() - 1:
	if visited[v] is false:
		DFSUtil(v, visited, connected_component)     //To compute Depth First Search starting from vertex v
		add connected_component to connected_components_list
	clear connected_component
4. connected_components_list.sort()                //The inner list is already sorted because of the way we are parsing the adjacency list

#[II] Algorithm 2 DFSUtil(int vertex, bool vertex[], list<int>& connected_component)
Steps:
1. visited[vertex] = true i.e. Mark vertex v as visited.
2. Add the vertex to the connected component list.
3. for list_iterator = start of adjacency_list_[vertex] to end of adjacency_list_[vertex]:
	if *list_iterator ((is not visited) and (has the same color as vertex)):
		run DFSUtil from *list_operator

#[III] Write output to file
Steps:
1. Open a file "results.txt".
2. for outer_list_iterator = start of connected_components to end of connected_components:
	for inner_list_iterator = start of *outer_list_iterator to end of *outer_list_iterator:
		print vertices to "results.txt"
	print newline

