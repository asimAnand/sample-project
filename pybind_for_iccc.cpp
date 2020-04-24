// The following needs to be added to "Open3D/src/Python/open3d_pybind/geometry/trianglemesh.cpp"

.def("identically_colored_connected_components",
                 &geometry::TriangleMesh::IdenticallyColoredConnectedComponents,
                 "Function to compute identically-colored connected components "
                 "in a triangle mesh")
