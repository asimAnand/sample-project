#include "Open3D.h"
using namespace open3d;

int main(){
    //Read triangle mesh "tesh_mesh.ply"
    geometry::TriangleMesh mesh;
    
    auto connected_components = mesh.IdenticallyColoredConnectedComponents();

    //Print connected_components in the specified format

    return 0;
}
