#include "Open3D/Open3D.h"
#include <fstream>
#include <vector>
//#include <pybind11/pybind11.h>

using namespace open3d;

std::vector<int> connected_component;

// Utility function to do a Depth First Search to get the connected components
void geometry::TriangleMesh::DFSUtil(int vertex, bool visited[], std::vector<int> connected_component){
    // Mark the current vertex as visited and add to the vector
    visited[vertex] = true;
    connected_component.push_back(vertex);
    
    // Loop for all vertices adjacent to this vertex having same color
    std::unordered_set<int>::iterator i;
    for (i = adjacency_list_[vertex].begin(); i != adjacency_list_[vertex].end(); ++i)
        if (!visited[*i] && vertex_colors_[vertex] == vertex_colors_[*i])
	    DFSUtil(*i, visited, connected_component);     
}

std::vector<std::vector<int> > geometry::TriangleMesh::IdenticallyColoredConnectedComponents(){
    std::vector<std::vector<int> > connected_components_vector;   // To store the vector of connected components
    std::vector<int> connected_component;                 // To store one connected component
    int v;

    // Compute adjacency vector for the given mesh
    ComputeAdjacencyList();
    
    // Mark all the vertices as not visited
    bool *visited = new bool[vertices_.size()];
    for (v = 0; v < vertices_.size(); v++)
	visited[v] = false;

    for (v = 0; v < vertices_.size(); v++){
        if (visited[v] == false){
            // All reachable vertices from v having the same color
            DFSUtil(v, visited, connected_component);
            // Add sorted connected component to the vector of connected components
	    std::sort(connected_component.begin(), connected_component.end()); 
            connected_components_vector.push_back(connected_component);
            connected_component.clear();
        }
    }
    
    // Sort the vector by smallest number in each connected component     
    std::sort(connected_components_vector.begin(), connected_components_vector.end());

    delete[] visited;

    return connected_components_vector;
}

int main(){
    geometry::TriangleMesh mesh;

    // Read triangle mesh "test_mesh.ply"
    io::ReadTriangleMesh("test_mesh.ply", mesh, true);
    
    auto connected_components = mesh.IdenticallyColoredConnectedComponents();

    // Print connected_components in the specified format
    std::ofstream outfile;
    outfile.open("results.txt");
    
    // Loop over the nested vector connected_components
    std::vector<std::vector<int> >::iterator outer_vector;
    std::vector<int>::iterator inner_vector;
    for (outer_vector = connected_components.begin(); outer_vector != connected_components.end(); outer_vector++){
        for (inner_vector = (*outer_vector).begin(); inner_vector != (*outer_vector).end(); inner_vector++){
	    outfile << *inner_vector << " ";
        }
        outfile << std::endl;
    }
   
    return 0;
}
