#ifndef GRAPHICS_H
#define GRAPHICS_H


#include <nlohmann/json.hpp>

namespace LibGPU {



    class Shader
    {
    private:

        struct GLSL {
            const char* Vertex;
            const char* TessellationControl;
            const char* TessellationEvaluation;
            const char* Geometry;
            const char* Fragment;
            const char* Compute;
        };

        struct HLSL {

        };

        struct ShaderFiles {
            const GLSL GLSLShaders;
            const HLSL HLSLShaders;
        };

        /* data */
    public:
        
        Shader(const char* Path);
        ~Shader();
    };
}

#endif