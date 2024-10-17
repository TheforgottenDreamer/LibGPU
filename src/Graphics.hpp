#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <sstream>
#include <string>
#include <fstream>
#include <filesystem>
#include <format>

#include <glm/glm.hpp>
#include <glad/glad.h>
#include <vulkan/vulkan.hpp>
#include <d3d12.h>

#include <spirv_cross/spirv_cross.hpp>
#include <spirv_cross/spirv_glsl.hpp>
#include <spirv_cross/spirv_hlsl.hpp>
#include <spirv_cross/spirv_msl.hpp>

#include <nlohmann/json.hpp>


using json = nlohmann::json;


namespace libgpu 
{

    void ClearColor(glm::vec4 Color);

    class Shader
    {
    private:

        struct ShaderJson {
            std::string Name;
            std::string output;
        };

        std::string ReadShaderFile(std::string Path);
        void CheckShader(GLuint Shader, GLenum Type);
        void CheckProgram(GLuint Prog);
        GLuint CompileOpenglShader(GLenum GlShaderType, ShaderJson MainData);

        GLuint OpenglShaderID; 
    public:
        
        Shader(std::string ShaderName);
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