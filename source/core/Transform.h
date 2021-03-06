//
// Created by Jesper on 5/12/2020.
//

#ifndef LUDVIG_TRANSFORM_H
#define LUDVIG_TRANSFORM_H

#include "glm.hpp"
#include "gtx/quaternion.hpp"

namespace Ludvig
{
    namespace Core
    {
        namespace Scene
        {
            /*
             * A transform is a transformation matrix of a Mesh.
             */
            class Transform
            {
            public:
                /*
                 * Default constructor.
                 */
                Transform();

            public:
                /*
                 * Returns the t*r*s matrix.
                 */
                glm::mat4 get_trs();

                /*
                 * Translate the position.
                 */
                void translate(float x, float y, float z);

                /*
                 * Rotate the rotation value.
                 */
                void rotate(float yaw, float pitch, float roll);

                /*
                 * Set the scale.
                 */
                void set_scale(float x, float y, float z);

                glm::vec3 get_position();
                glm::vec3 get_rotation();
                glm::vec3 get_scale();

            public:
                glm::vec3 position = glm::vec3(0.0f,0.0f,0.0f);
                //glm::quat rotation;
                glm::vec3 rotation = glm::vec3(0.0f,0.0f,0.0f);
                glm::vec3 scale = glm::vec3(1.0f,1.0f,1.0f);
            };
        }
    }
}



#endif //LUDVIG_TRANSFORM_H
