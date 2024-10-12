#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <sstream>
#include <string>
#include <fstream>

#include <glm/glm.hpp>
#include <glad/glad.h>
#include <vulkan/vulkan.hpp>

#include <spirv_cross/spirv_cross.hpp>
#include <spirv_cross/spirv_glsl.hpp>
#include <spirv_cross/spirv_hlsl.hpp>
#include <spirv_cross/spirv_msl.hpp>

#include <nlohmann/json.hpp>

namespace libgpu 
{
    void ClearColor(glm::vec4 Color);

    class Shader
    {
    private:

        std::string ReadShaderFile(const char* Path);

        struct HLSL {

        };

        struct ShaderFiles {
            HLSL HLSLShaders;
        };

        /* data */
    public:
        
        Shader(const char* Path);
        ~Shader();
    };

    template<typename DataType, GLenum BufferType>
    class Buffer
    {
    private:
        GLint ID;
    public:
        Buffer(std::vector<DataType> Data);
        ~Buffer();
        void Bind();
        void Unbind();
    };
    
    
}

#endif