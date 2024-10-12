#include "Graphics.hpp"

void libgpu::ClearColor(glm::vec4 Color) {
#if USING_OPENGL
    glClearColor(Color.x, Color.y, Color.z, Color.w);
#endif
}

libgpu::Shader::Shader(const char* Path) {
#if USING_OPENGL

    

#endif
}

std::string libgpu::Shader::ReadShaderFile(const char* Path) {
    std::ifstream File(Path);

    if(!File.is_open()) {
        perror("File Was Not Found");
        return "";          
    }

    std::stringstream stream;
    stream << File.rdbuf();
    File.close();
    
    return stream.str();
}

template<typename DataType, GLenum BufferType>
libgpu::Buffer<DataType, BufferType>::Buffer(std::vector<DataType> Data) {
    glGenBuffers(1, &ID);
    Bind();
    glBufferData(BufferType, sizeof(Data), Data, GL_STATIC_DRAW);

    
}

template<typename DataType, GLenum BufferType>
void libgpu::Buffer<DataType, BufferType>::Bind() {
    glBindBuffer(BufferType, ID);
}

template<typename DataType, GLenum BufferType>
void libgpu::Buffer<DataType, BufferType>::Unbind() {
    glBindBuffer(BufferType, 0);
}

template<typename DataType, GLenum BufferType>
libgpu::Buffer<DataType, BufferType>::~Buffer() {
    glDeleteBuffers(1, &ID);
}