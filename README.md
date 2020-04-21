# Problem Statement
Find identically colored connected components in a triangle mesh with Open3D. An identically-colored connected component consists of spatially connected vertices with the same color.

## Algorithm 1 IdenticallyColoredConnectedComponents()
### Description
Finds the identically colored connected components in a triangle mesh

### Data structures used 
1. list\<list\<int\> \> connected_components_list    [_To store the list of connected components_]
2. list\<int\> connected_component                 [_To store one connected component_]
3. bool *visited                                 [_To keep track of visited vertices_]

### Steps
1. Compute the adjacency list from the read mesh using ComputeAdjacencyList().
2. Initialize visited[vertices_.size()] := False, i.e. mark all vertices as not visited. 
3. for v = 0 to vertices_.size() - 1:
        1. if visited[v] is false:
              1. DFSUtil(v, visited, connected_component)     [_To compute Depth First Search starting from vertex v_]
              2. add connected_component to connected_components_list
        2. clear connected_component
4. connected_components_list.sort()                [_The inner list is already sorted because of the way we are parsing the adjacency list_]

## Algorithm 2 DFSUtil(int vertex, bool vertex[], list<int>& connected_component)
### Description
Performs the Depth First Search starting from vertex

### Steps
1. visited[vertex] = true i.e. Mark vertex v as visited.
2. Add the vertex to the connected component list.
3. for list_iterator = start of adjacency_list_[vertex] to end of adjacency_list_[vertex]:
        1. if *list_iterator ((is not visited) and (has the same color as vertex)):
              1. run DFSUtil from *list_operator

## Write output to file
### Steps
1. Open a file "results.txt".
2. for outer_list_iterator = start of connected_components to end of connected_components:
        1. for inner_list_iterator = start of *outer_list_iterator to end of *outer_list_iterator:
                1. print vertices to "results.txt"
        2. print newline
