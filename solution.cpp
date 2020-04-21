#include "Open3D/Open3D.h"
#include <fstream>
#include <pybind11/pybind11.h>

using namespace open3d;

//Utility function to do a Depth First Search to get the connected components
void geometry::TriangleMesh::DFSUtil(int vertex, bool visited[], list<int>& connected_component){
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
	    connected_components_list.push_back(connected_component); 
        }
        connected_component.clear();
    }
    
    /* Sort the list by smallest number in each list. Here each connected component in the
     * list of connected components is already sorted ascendingly by the vertex because of
     * the way we are traversing the adjacency list.
     */ 
    connected_components_list.sort();

    delete[] visited;

    return connected_components_list;
}

/*
 * This is the same pybind_trianglemesh present in 
 * Open3D/src/Python/open3d_pybind/geometry/trianglemesh.cpp
 */
void pybind_trianglemesh(py::module &m){
    m.def("identically_colored_connected_components", 
          &geometry::TriangleMesh::IdenticallyColoredConnectedComponents,
          "Function to compute identically-colored connected components in a triangle mesh");
}
	      
int main(){
    geometry::TriangleMesh mesh;

    //Read triangle mesh "test_mesh.ply"
    io::ReadTriangleMesh("test_mesh.ply", *mesh, true);
    
    auto connected_components = mesh.IdenticallyColoredConnectedComponents();

    //Print connected_components in the specified format
    ofstream outfile;
    outfile.open("results.txt");
    
    //Loop over the nested list connected_components
    list<list<int> >::iterator outer_list;
    list<int>::iterator inner_list;
    for (outer_list = connected_components.begin(); outer_list != connected_components.end(); outer_list++){
        for (inner_list = (*outer_list).begin(); inner_list != (*outer_list).end(); inner_list++){
	    outfile << *inner_list << " ";
        }
        outfile << std::endl;
    }
   
    return 0;
}
