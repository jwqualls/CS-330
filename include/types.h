#pragma once
#include <glm/glm.hpp>
#include <vector>
#include <numbers>



struct Vertex{
    glm::vec3 Position{ 0.f, 0.f, 0.f };
    glm::vec3 Color{ 1.f, 1.f, 1.f };
    glm::vec3 Normal{ 0.f, 0.f, 0.f };
    glm::vec2 Uv{ 1.f, 1.f };
};



struct Shapes {
    static inline std::vector<Vertex> marvelVertices {
        //front face
        {
            .Position = {1.0f, -3.0f, -4.0f},
            .Color = {0.0f, 1.0f, 0.0f},             //green
            .Normal = {0.f, 0.f, -1.f},
            .Uv = {0.f, 1.f}
        },
        {
            .Position = {-1.0f, -3.0f, -4.0f},
            .Color = {0.0f, 1.0f, 0.0f},             //green
            .Normal = {0.f, 0.f, -1.f},
            .Uv = {0.f, 0.f}
        },
        {
            .Position = {-1.0f, 3.0f, -4.0f},
            .Color = {0.0f, 1.0f, 0.0f},             //green
            .Normal = {0.f, 0.f, -1.f},
            .Uv = {0.5f, 0.f}
        },
        {
            .Position = {1.0f, 3.0f, -4.0f},
            .Color = {0.0f, 1.0f, 0.0f},             //green
            .Normal = {0.f, 0.f, -1.f},
            .Uv = {0.5f, 1.f}
        },
    //left face
        {
            .Position = {1.0f, -3.0f, 4.0f},
            .Color = {0.0f, 0.0f, 1.0f},             //blue
            .Normal = {0.f, -1.f, 0.f},
            .Uv = {0.f, 1.f}
        },
        {
            .Position = {-1.0f, -3.0f, 4.0f },
            .Color = {0.0f, 0.0f, 1.0f},             //blue
            .Normal = {0.f, -1.f, 0.f},
            .Uv = {0.f, 0.f}
        },
        {
            .Position = {-1.0f, -3.0f, -4.0f},
            .Color = {0.0f, 0.0f, 1.0f},             //blue
            .Normal = {0.f, -1.f, 0.f},
            .Uv = {0.5f, 0.f}
        },
        {
            .Position = {1.0f, -3.0f, -4.0f},
            .Color = {0.0f, 0.0f, 1.0f},             //blue
            .Normal = {0.f, -1.f, 0.f},
            .Uv = {0.5f, 1.f}
        },
    //right face
        {
            .Position = {1.0f, 3.0f, -4.0f},
            .Color = {1.0f, 0.0f, 0.0f},             //red
            .Normal = {0.f, 1.f, 0.f},
            .Uv = {0.f, 1.f}
        },
        {
            .Position = {-1.0f, 3.0f, -4.0f},
            .Color = {1.0f, 0.0f, 0.0f},             //red
            .Normal = {0.f, 1.f, 0.f},
            .Uv = {0.f, 0.f}
        },
        {
            .Position = {-1.0f, 3.0f, 4.0f},
            .Color = {1.0f, 0.0f, 0.0f},             //red
            .Normal = {0.f, 1.f, 0.f},
            .Uv = {0.5f, 0.f}
        },
        {
            .Position = {1.0f, 3.0f, 4.0f},
            .Color = {1.0f, 0.0f, 0.0f},             //red
            .Normal = {0.f, 1.f, 0.f},
            .Uv = {.5f, 1.f}
        },
    // back face
        {
            .Position = {1.0f, 3.0f, 4.0f},
            .Color = {1.0f, 0.5f, 0.0f},             //orange
            .Normal = {0.f, 0.f, 1.f},
            .Uv = {0.f, 1.f}
        },
        {
            .Position = {-1.0f, 3.0f, 4.0f},
            .Color = {1.0f, 0.5f, 0.0f},             //orange
            .Normal = {0.f, 0.f, 1.f},
            .Uv = {0.f, 0.f}
        },
        {
            .Position = {-1.0f, -3.0f, 4.0f},
            .Color = {1.0f, 0.5f, 0.0f},             //orange
            .Normal = {0.f, 0.f, 1.f},
            .Uv = {0.5f, 0.f}
        },
        {
            .Position = {1.0f, -3.0f, 4.0f},
            .Color = {1.0f, 0.5f, 0.0f},             //orange
            .Normal = {0.f, 0.f, 1.f},
            .Uv = {0.5f, 1.f}
        },
    //top face
        {
            .Position = {1.0f, -3.0f, -4.0f},
            .Color = {1.0f, 1.0f, 1.0f},             //white
            .Normal = {1.f, 0.f, 0.f},
            .Uv = {0.f, 1.f}
        },
        {
            .Position = {1.0f, 3.0f, -4.0f},
            .Color = {1.0f, 1.0f, 1.0f},             //white
            .Normal = {1.f, 0.f, 0.f},
            .Uv = {0.f, 0.f}
        },
        {
            .Position = {1.0f, 3.0f, 4.0f},
            .Color = {1.0f, 1.0f, 1.0f},             //white
            .Normal = {1.f, 0.f, 0.f},
            .Uv = {0.5f, 0.f}
        },
        {
            .Position = {1.0f, -3.0f, 4.0f},
            .Color = {1.0f, 1.0f, 1.0f},             //white
            .Normal = {1.f, 0.f, 0.f},
            .Uv = {0.5f, 1.f}
        },
        //bottom face
        {
            .Position = {-1.0f, -3.0f, 4.0f},
            .Color = {1.0f, 1.0f, 1.0f},             //white
            .Normal = {-1.f, 0.f, 0.f},
            .Uv = {0.f, 1.f}
        },
        {
            .Position = {-1.0f, -3.0f, -4.0f},
            .Color = {1.0f, 1.0f, 1.0f},             //white
            .Normal = {-1.f, 0.f, 0.f},
            .Uv = {0.f, 0.f}
        },
        {
            .Position = {-1.0f, 3.0f, -4.0f},
            .Color = {1.0f, 1.0f, 1.0f},             //white
            .Normal = {-1.f, 0.f, 0.f},
            .Uv = {0.5f, 0.f}
        },
        {
            .Position = {-1.0f, 3.0f, 4.0f},
            .Color = {1.0f, 1.0f, 1.0f},             //white
            .Normal = {-1.f, 0.f, 0.f},
            .Uv = {0.5f, 1.f}
        },
    };
    
    static inline std::vector<uint32_t> marvelElements {
        0, 1, 3, 1, 2, 3,      //front
        4, 5, 7, 5, 6, 7,       //left
        8, 9, 11, 9, 10, 11,    //right
        12, 13, 15, 13, 14, 15, //back
        16, 17, 19, 17, 18, 19, //top
        20, 21, 23, 21, 22, 23,  //bottom
    };

    static inline std::vector<Vertex> GetUnitCircleVertices(uint32_t sectorCount) {
        float sectorStep = 2.f * std::numbers::pi_v<float> / static_cast<float>(sectorCount);
        float sectorAngle; //radians

        std::vector<Vertex> vertices{};

        for (auto i = 0; i <= sectorCount; i++) {
            sectorAngle = static_cast<float>(i) * sectorStep;
            vertices.push_back({
                .Position = {
                       std::cos(sectorAngle),
                       std::sin(sectorAngle),
                       0
                }
                });
        }

        return vertices;
    };

    // adapted from Songho: http://www.songho.ca/opengl/gl_cylinder.html
    static inline std::tuple<std::vector<Vertex>, std::vector<uint32_t>> BuildCylinderSmooth(uint32_t sectorCount, float baseRadius, float height) {
        std::vector<Vertex> vertices{};
        std::vector<uint32_t> indices{};

        auto unitCircleVertices = GetUnitCircleVertices(sectorCount);

        /*
         *          BUILDING VERTEX ARRAY
         */

         // Build the sides
        for (auto i = 0; i < 2; i++) { // bottom half, top half ?
            float h = -height / 2.f + static_cast<float>(i) * height;
            float t = 1.f - i;      // texCoord

            // loop over all unit circle vertices
            uint32_t vertexIndex{ 0 };
            for (auto& vertex : unitCircleVertices) {
                vertices.push_back({
                       .Position = {
                               vertex.Position.x * baseRadius,
                               vertex.Position.y * baseRadius,
                               h,
                       },
                       .Color = {
                               vertexIndex % 3 == 0 ? 1.f : 0.f,
                               vertexIndex % 3 == 1 ? 1.f : 0.f,
                               vertexIndex % 3 == 2 ? 1.f : 0.f,
                       },
                       .Normal = {
                               vertex.Position.x * baseRadius,
                               vertex.Position.y * baseRadius,
                               vertex.Position.z * baseRadius,
                       },
                       .Uv = {
                               static_cast<float>(vertexIndex) / static_cast<float>(sectorCount),
                               t
                       }
                    });

                vertexIndex++;
            }
        }
        auto baseCenterIndex = vertices.size();
        // songho has  (sector + 1) here but for some reason something was lost in the adaptation
        // doing straight songho was giving me 1 off from the top index... but this seems to work so I'll go with this.
        auto topCenterIndex = baseCenterIndex + sectorCount + 2;

        // Build the top and bottom
        for (auto i = 0; i < 2; i++) { // bottom half, top half
            float h = -height / 2.f + static_cast<float>(i) * height;
            float nz = -1.f + static_cast<float>(i) * 2;                 // z value of normal; -1 to 1

            // center point
            vertices.push_back({
                .Position = { 0, 0, h },
                .Color = {1.f, 1.f, 1.f},
                .Normal = { 0, 0, nz},
                .Uv = {0.5f, 0.5f}
                });

            // loop over all unit circle vertices
            uint32_t vertexIndex{ 0 };
            for (auto& vertex : unitCircleVertices) {
                vertices.push_back({
                    .Position = {
                        vertex.Position.x * baseRadius,
                        vertex.Position.y * baseRadius,
                        h,
                    },
                    .Color = {
                        vertexIndex % 3 == 0 ? 1.f : 0.f,
                        vertexIndex % 3 == 1 ? 1.f : 0.f,
                        vertexIndex % 3 == 2 ? 1.f : 0.f,
                    },
                    .Normal = {
                        0,
                        0,
                        nz,
                    },
                    .Uv = {
                        -vertex.Position.x * 0.5f + 0.5f,
                        -vertex.Position.y * 0.5f + 0.5f
                    }
                    });

                vertexIndex++;
            }
        }

        /*
         *          BUILDING INDEX ARRAY
         */

         // indices for side surface

        uint32_t k1 = 0;
        uint32_t k2 = sectorCount + 1;
        for (auto i = 0; i < sectorCount; i++, k1++, k2++) {
            // 2 triangles per sector
            indices.push_back(k1);
            indices.push_back(k1 + 1);
            indices.push_back(k2);

            indices.push_back(k2);
            indices.push_back(k1 + 1);
            indices.push_back(k2 + 1);
        }

        // bottom surface
        for (uint32_t i = 0, k = baseCenterIndex + 1; i < sectorCount; i++, k++) {
            if (i < sectorCount - 1) {
                indices.push_back(baseCenterIndex);
                indices.push_back(k + 1);
                indices.push_back(k);
            }
            else {
                indices.push_back(baseCenterIndex);
                indices.push_back(baseCenterIndex + 1);
                indices.push_back(k);
            }
        }

        for (uint32_t i = 0, k = topCenterIndex + 1; i < sectorCount; i++, k++) {
            if (i < sectorCount - 1) {
                indices.push_back(topCenterIndex);
                indices.push_back(k);
                indices.push_back(k + 1);
            }
            else {
                indices.push_back(topCenterIndex);
                indices.push_back(k);
                indices.push_back(topCenterIndex + 1);
            }
        }

        return { vertices, indices };
    }
};

struct Pyramid {
    static inline std::vector<Vertex> pyramidVertices{
        {
            .Position = {0.f, 0.5f, 0.0f},
            .Color = {0.0f, 0.0f, 1.0f},
            .Uv = {0.5f, 1.f}
        },
        {
            .Position = {-0.5f, -0.5f, -0.5f},
            .Color = {0.0f, 0.0f, 1.0f},
            .Uv = {0.f, 0.f}
        },
        {
            .Position = {0.5f, -0.5f, -0.5f},
            .Color = {0.0f, 0.0f, 1.0f},
            .Uv = {1.f, 0.f}
        },
        //left
        {
            .Position = {0.f, 0.5f, 0.0f},
            .Color = {0.0f, 0.0f, 1.0f},
            .Uv = {0.5f, 1.f}
        },
        {
            .Position = {-0.5f, -0.5f, 0.5f},
            .Color = {0.0f, 0.0f, 1.0f},
            .Uv = {0.f, 0.f}
        },
        {
            .Position = {-0.5f, -0.5f, -0.5f},
            .Color = {0.0f, 0.0f, 1.0f},
            .Uv = {1.f, 0.f}
        },
        //right
        {
            .Position = {0.f, 0.5f, 0.0f},
            .Color = {0.0f, 0.0f, 1.0f},
            .Uv = {0.5f, 1.f}
        },
        {
            .Position = {0.5f, -0.5f, -0.5f},
            .Color = {0.0f, 0.0f, 1.0f},
            .Uv = {0.f, 0.f}
        },
        {
            .Position = {0.5f, -0.5f, 0.5f},
            .Color = {0.0f, 0.0f, 1.0f},
            .Uv = {1.f, 0.f}
        },
        //back
        {
            .Position = {0.f, 0.5f, 0.0f},
            .Color = {0.0f, 0.0f, 1.0f},
            .Uv = {0.5f, 1.f}
        },
        {
            .Position = {0.5f, -0.5f, 0.5f},
            .Color = {0.0f, 0.0f, 1.0f},
            .Uv = {0.f, 0.f}
        },
        {
            .Position = {-0.5f, -0.5f, 0.5f},
            .Color = {0.0f, 0.0f, 1.0f},
            .Uv = {1.f, 0.f}
        },
        //bottom
        {
            .Position = {-0.5f, -0.5f, -0.5f},
            .Color = {0.0f, 0.0f, 1.0f},
            .Uv = {0.f, 1.f}
        },
        {
            .Position = {-0.5f, -0.5f, 0.5f},
            .Color = {0.0f, 0.0f, 1.0f},
            .Uv = {0.f, 0.f}
        },
        {
            .Position = {0.5f, -0.5f, 0.5f},
            .Color = {0.0f, 0.0f, 1.0f},
            .Uv = {1.f, 0.f}
        },
        {
            .Position = {0.5f, -0.5f, -0.5f},
            .Color = {0.0f, 0.0f, 1.0f},
            .Uv = {1.f, 1.f}
        }
    };

    static inline std::vector<uint32_t> pyramidElements{
        0, 1, 2,
        3, 4, 5,
        6, 7, 8,
        9, 10, 11,
        12, 13, 14, 12, 14, 15
    };
};

struct Light {
    static inline std::vector<Vertex> lightVertices{
        {
            .Position = {-0.1f, -0.1f,  0.1f},
            .Color = {0.f, 0.f, 0.f}
        },
        {
            .Position = {-0.1f, -0.1f, -0.1f},
            .Color = {0.f, 0.f, 0.f}
        },
        {
            .Position = {0.1f, -0.1f, -0.1f},
            .Color = {0.f, 0.f, 0.f}
        },
        {
            .Position = {0.1f, -0.1f,  0.1f},
            .Color = {0.f, 0.f, 0.f}
        },
        {
            .Position = {-0.1f,  0.1f,  0.1f},
            .Color = {0.f, 0.f, 0.f}
        },
        {
            .Position = {-0.1f,  0.1f, -0.1f},
            .Color = {0.f, 0.f, 0.f}
        },
        {
            .Position = {0.1f,  0.1f, -0.1f},
            .Color = {0.f, 0.f, 0.f}
        },
        {
            .Position = {0.1f,  0.1f,  0.1f},
            .Color = {0.f, 0.f, 0.f}
        },
    };

    static inline std::vector<uint32_t> lightElements{
        0, 1, 2,
        0, 2, 3,
        0, 4, 7,
        0, 7, 3,
        3, 7, 6,
        3, 6, 2,
        2, 6, 5,
        2, 5, 1,
        1, 5, 4,
        1, 4, 0,
        4, 5, 6,
        4, 6, 7
    };
};

struct Plane {
    static inline std::vector<Vertex> planeVertices{
        {
            .Position = {-50.0f, 0.0f, 50.0f},
            .Color = {0.0f, 0.0f, 1.0f},
            .Normal = {1.f, 0.f, 0.f},
            .Uv = {0.5f, 0.5f}
        },
        {
            .Position = {-50.0f, 0.0f, -50.0f},
            .Color = {0.0f, 0.0f, 1.0f},
            .Normal = {1.f, 0.f, 0.f},
            .Uv = {0.5f, 0.f}
        },
        {
            .Position = {50.0f, 0.0f, -50.0f},
            .Color = {0.0f, 0.0f, 1.0f},
            .Normal = {1.f, 0.f, 0.f},
            .Uv = {1.f, 0.f}
        },
        {
            .Position = {50.0f, 0.0f, 50.0f},
            .Color = {0.0f, 0.0f, 1.0f},
            .Normal = {1.f, 0.f, 0.f},
            .Uv = {1.f, 0.5f}
        },
    };

    static inline std::vector<uint32_t> planeElements{
        0, 1, 2,
        0, 2, 3
    };
};

struct Sphere {
    static std::pair<std::vector<Vertex>, std::vector<uint32_t>> GenerateSphere(float radius = 1.f, uint32_t sectors = 50, uint32_t stacks = 50) {
        std::vector<Vertex> vertices{};
        std::vector<uint32_t> indices{};
        uint32_t k1, k2;
        float x, y, z, xy;                              // vertex position
        float nx, ny, nz, lengthInv = 1.0f / radius;    // vertex normal
        float s, t;                                     // vertex texCoord

        float sectorStep = 2 * std::numbers::pi / sectors;
        float stackStep = std::numbers::pi / stacks;
        float sectorAngle, stackAngle;

        for (uint32_t i = 0; i <= stacks; ++i)
        {
            stackAngle = std::numbers::pi / 2 - i * stackStep;        // starting from pi/2 to -pi/2
            xy = radius * cosf(stackAngle);             // r * cos(u)
            z = radius * sinf(stackAngle);              // r * sin(u)

            k1 = i * (sectors + 1);     // beginning of current stack
            k2 = k1 + sectors + 1;
            // add (sectorCount+1) vertices per stack
            // the first and last vertices have same position and normal, but different tex coords
            for (uint32_t j = 0; j <= sectors; ++j, ++k1, ++k2)
            {
                sectorAngle = static_cast<float>(j) * sectorStep;           // starting from 0 to 2pi

                // vertex position (x, y, z)
                x = xy * cosf(sectorAngle);             // r * cos(u) * cos(v)
                y = xy * sinf(sectorAngle);             // r * cos(u) * sin(v)

                // normalized vertex normal (nx, ny, nz)
                nx = x * lengthInv;
                ny = y * lengthInv;
                nz = z * lengthInv;

                // vertex tex coord (s, t) range between [0, 1]
                s = (float)j / static_cast<float>(sectors);
                t = (float)i / static_cast<float>(stacks);

                vertices.push_back(Vertex{
                    .Position = {x, y, z},
                    .Normal = {nx, ny, nz},
                    .Uv = {s, t},
                    });


            }
        }

        for (uint32_t i = 0; i < stacks; ++i)
        {
            k1 = i * (sectors + 1);     // beginning of current stack
            k2 = k1 + sectors + 1;      // beginning of next stack

            for (uint32_t j = 0; j < sectors; ++j, ++k1, ++k2)
            {
                // 2 triangles per sector excluding first and last stacks
                // k1 => k2 => k1+1
                if (i != 0)
                {
                    indices.push_back(k1);
                    indices.push_back(k1 + 1);
                    indices.push_back(k2);
                }

                // k1+1 => k2 => k2+1
                if (i != (stacks - 1))
                {
                    indices.push_back(k1 + 1);
                    indices.push_back(k2 + 1);
                    indices.push_back(k2);
                }
            }
        }

        return { vertices, indices };
    }
};