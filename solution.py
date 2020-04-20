import open3d as o3d
import connComp

#Read triangle mesh "test_mesh.ply"
mesh = o3d.io.read_triangle_mesh('test_mesh.ply')

#get connected components
connected_components = mesh.identically_colored_connected_components()

#Print in the specified format
outfile = open("results.txt","w")
for comp in connected_components:
    outfile.write(comp)

