// The following test needs to be added in "Open3D/src/UnitTest/Geometry/TriangleMesh.cpp"

TEST(TriangleMesh, IdenticallyColoredConnectedComponents) {
    geometry::TriangleMesh mesh;
    std::vector<std::vector<int> > connected_components_vector;
    std::vector<int> connected_component;

    mesh.vertices_ = {
            {0.521248, 0.377170, 0.000000}, {0.017178, 0.000000, 0.946382},
            {0.972485, 0.000000, 0.431460}, {0.000000, 0.093962, 0.028012},
            {0.164379, 0.516339, 1.000000}, {0.700868, 0.648112, 1.000000}};
    mesh.triangles_ = {
            {0, 2, 3}, {0, 3, 1}, {1, 3, 4}, {2, 5, 3}, {3, 5, 6}, {3, 6, 4}};
    mesh.vertex_colors_ = {
            {1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {1, 0, 0}, {0, 1, 0}, {1, 0, 0}, {1, 0, 0}};

    // Actual
    auto connected_components = mesh.IdenticallyColoredConnectedComponents();

    // Expected
    connected_component.push_back(0);
    connected_component.push_back(3);
    connected_component.push_back(5);
    connected_component.push_back(6);

    connected_components_vector.push_back(connected_component);

    connected_component.clear();
    connected_component.push_back(1);
    connected_component.push_back(4);

    connected_components_vector.push_back(connected_component);

    connected_component.clear();
    connected_component.push_back(2);

    connected_components_vector.push_back(connected_component);

    ExpectEQ(connected_components_vector, connected_components);
}

