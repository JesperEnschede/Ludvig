//
// Created by Jesper on 5/14/2020.
//

#include "VertexBufferIndexer.h"

bool Ludvig::Rendering::is_near(float vertex1, float vertex2)
{
    return fabs(vertex1 - vertex2) < 0.01f;
}

bool Ludvig::Rendering::get_similar_vertex_index(glm::vec3 &in_vertex, glm::vec2 &in_uv, glm::vec3 &in_normal,std::vector<glm::vec3> &out_vertices, std::vector<glm::vec2> &out_uvs,std::vector<glm::vec3> &out_normals, unsigned short &result)
{
    for (int i = 0; i < out_vertices.size(); ++i)
    {
        for ( unsigned int i=0; i<out_vertices.size(); i++ ){
            if (
                    is_near( in_vertex.x , out_vertices[i].x ) &&
                    is_near( in_vertex.y , out_vertices[i].y ) &&
                    is_near( in_vertex.z , out_vertices[i].z ) &&
                    is_near( in_uv.x     , out_uvs     [i].x ) &&
                    is_near( in_uv.y     , out_uvs     [i].y ) &&
                    is_near( in_normal.x , out_normals [i].x ) &&
                    is_near( in_normal.y , out_normals [i].y ) &&
                    is_near( in_normal.z , out_normals [i].z )
                    ){
                result = i;
                return true;
            }
        }
        return false;
    }
}
