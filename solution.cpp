#include "Open3D/Open3D.h"

using namespace open3d;

void geometry::TriangleMesh::DFSUtil(int vertex, bool visited[], list<int> connected_component){
    //Mark the current vertex as visited and add to the list
    visited[vertex] = true;
    connected_component.push_back(vertex);
    
    //Loop for all vertices adjacent to this vertex having same color
    list<int>::iterator i;
    for (i = adjacency_list_[vertex].begin(); i != adjacency_list_[vertex].end(); ++i)
        if (!visited[*i] && vertex_colors_[vertex] == vertex_colors_[*i])
	    DFSUtil(*i, visited, connected_component);     
}

list<list<int> > geometry::TriangleMesh::IdenticallyColoredConnectedComponents(){
    list<list<int> > connected_components_list;   //To store the list of connected components
    list<int> connected_component                 //To store one connected component
    list<list<int> >::iterator list_itr;          //To sort the list of connected components
    int v;

    //Compute adjacency list for the given mesh
    ComputeAdjacencyList();
    
    //Mark all the vertices as not visited
    bool *visited = new bool[vertices_.size()];
    for (v = 0; v < vertices_.size(); v++)
	visited[v] = false;

    for (v = 0; v < vertices_.size(); v++){
        if (visited[v] == false){
            //All reachable vertices from v having the same color
            DFSUtil(v, visited, connected_component);
	    connected_components_list.push_back;
        }
        connected_component.clear();
    }
    
    //Sort the list by smallest number in each list

    delete[] visited;

    return connected_components;
}
	      
int main(){
    geometry::TriangleMesh mesh;i

    //Read triangle mesh "test_mesh.ply"
    io::ReadTriangleMesh("test_mesh.ply", *mesh, true);
    
    auto connected_components = mesh.IdenticallyColoredConnectedComponents();

    //Print connected_components in the specified format

    return 0;
}
