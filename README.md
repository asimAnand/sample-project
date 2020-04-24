# Problem Statement
Find identically colored connected components in a triangle mesh with Open3D. An identically-colored connected component consists of spatially connected vertices with the same color.

## Algorithm 1: IdenticallyColoredConnectedComponents()
### Description
Finds the identically colored connected components in a triangle mesh.

### Data structures used 
1. list\<list\<int\> \> connected_components_list    [_To store the list of connected components_]
2. list\<int\> connected_component                 [_To store one connected component_]
3. bool *visited                                 [_To keep track of visited vertices_]

### Steps
1. Read triangle mesh "test_mesh.ply".
2. Compute the adjacency list from the read mesh using ComputeAdjacencyList().
3. Initialize visited[vertices_.size()] := False, i.e. mark all vertices as not visited. 
4. *for* v = 0 *to* vertices_.size() - 1:
    * *if* visited[v] is false:
        * DFSUtil(v, visited, connected_component)     [_To compute Depth First Search starting from vertex v_]
        * add sorted connected_component to connected_components_list
        * clear connected_component
5. Sort connected_components_list                
6. Return connected_components_list        

## Algorithm 2: DFSUtil(int vertex, bool vertex[], list<int>& connected_component)
### Description
Performs the Depth First Search starting from vertex.

### Steps
1. visited[vertex] = true i.e. Mark vertex v as visited.
2. Add the vertex to the connected component list.
3. *for* list_iterator = start of adjacency_list_[vertex] *to* end of adjacency_list_[vertex]:
    * *if* \*list_iterator is not visited and has the same color as vertex:
        * run DFSUtil from \*list_iterator

## Write output to file
### Steps
1. Open a file "results.txt".
2. *for* outer_list_iterator = start of connected_components *to* end of connected_components:
    * *for* inner_list_iterator = start of *outer_list_iterator *to* end of *outer_list_iterator:
        * *print* vertices to "results.txt"
    * *print* newline

## Steps to build and run
### Build
1. git clone --recursive https://github.com/intel-isl/Open3D
2. Copy solutions.cpp to "Open3D/examples/Cpp/".
3. Open "Open3D/examples/Cpp/CMakeLists.txt" and add "EXAMPLE_CPP(solution                  ${CMAKE_PROJECT_NAME})".
4. cd Open3D
5. mkdir build
6. cd build
7. cmake ..
8. make -j

### Run
1. cd Open3D/build/bin
2. ./bin/examples/solution

