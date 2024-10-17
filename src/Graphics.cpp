#include "Graphics.hpp"

void libgpu::ClearColor(glm::vec4 Color) {
#if USING_OPENGL
    glClearColor(Color.x, Color.y, Color.z, Color.w);
#endif
}

libgpu::Shader::Shader(std::string ShaderName) {
#if USING_OPENGL

    OpenglShaderID = glCreateProgram();

    std::ifstream File(std::format("{0}/Shaders/{1}.json", RESOURCES_PATH, ShaderName));
    json JsonData = json::parse(File);
    ShaderJson Data;

    Data.Name = JsonData["ShaderName"];
    Data.output = JsonData["Output"];

    GLuint Vertexshader = CompileOpenglShader(GL_VERTEX_SHADER, Data);
    GLuint TessellationControlShader = CompileOpenglShader(GL_TESS_CONTROL_SHADER, Data);
    GLuint TessellationEvaluationShader = CompileOpenglShader(GL_TESS_EVALUATION_SHADER, Data);
    GLuint GeometryShader = CompileOpenglShader(GL_GEOMETRY_SHADER, Data);
    GLuint FragmentShader = CompileOpenglShader(GL_FRAGMENT_SHADER, Data);
    GLuint ComputeShader = CompileOpenglShader(GL_COMPUTE_SHADER, Data);

    glLinkProgram(OpenglShaderID);
    CheckProgram(OpenglShaderID);

    if(Vertexshader != 0) {glDeleteShader(Vertexshader);}
    if(TessellationControlShader != 0) {glDeleteShader(TessellationControlShader);}
    if(TessellationEvaluationShader != 0) {glDeleteShader(TessellationEvaluationShader);}
    if(GeometryShader != 0) {glDeleteShader(GeometryShader);}
    if(FragmentShader != 0) {glDeleteShader(FragmentShader);}
    if(ComputeShader != 0) {glDeleteShader(ComputeShader);}
#endif
}

GLuint libgpu::Shader::CompileOpenglShader(GLenum GlShaderType, ShaderJson MainData) {
    const char* Source = "";

    GLuint Shader = 0;
        
    switch (GlShaderType)
    {
    case GL_VERTEX_SHADER:
        printf("Vert");
        Source = ReadShaderFile(std::format("{0}/Shaders/{1}/{2}_Vert.glsl", RESOURCES_PATH, MainData.output, MainData.Name)).c_str();
        break;
    case GL_TESS_CONTROL_SHADER:
        printf("Tess Control");
        Source = ReadShaderFile(std::format("{0}/Shaders/{1}/{2}_Tesc.glsl", RESOURCES_PATH, MainData.output, MainData.Name)).c_str();
        break;
    case GL_TESS_EVALUATION_SHADER:
        printf("Tess Eval");
        Source = ReadShaderFile(std::format("{0}/Shaders/{1}/{2}_Tese.glsl", RESOURCES_PATH, MainData.output, MainData.Name)).c_str();
        break;
    case GL_GEOMETRY_SHADER:
        printf("Geom"); 
        Source = ReadShaderFile(std::format("{0}/Shaders/{1}/{2}_Geom.glsl", RESOURCES_PATH, MainData.output, MainData.Name)).c_str();
        break;
    case GL_FRAGMENT_SHADER:
        printf("Frag");
        Source = ReadShaderFile(std::format("{0}/Shaders/{1}/{2}_Frag.glsl", RESOURCES_PATH, MainData.output, MainData.Name)).c_str();
        break;
    case GL_COMPUTE_SHADER:
        printf("Comp");
        Source = ReadShaderFile(std::format("{0}/Shaders/{1}/{2}_Comp.glsl", RESOURCES_PATH, MainData.output, MainData.Name)).c_str();
        break;
    }
    //printf(Source);

    if(Source != "") {
        Shader = glCreateShader(GlShaderType);
        glShaderSource(Shader, 1, &Source, NULL);
        glCompileShader(Shader);
        CheckShader(Shader, GlShaderType);
    }

    return Shader;
}


void libgpu::Shader::CheckShader(GLuint Shader, GLenum Type) {
    int success;
    char infoLog[512];
    glGetShaderiv(Shader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(Shader, 512, NULL, infoLog);
        perror("ERROR::SHADER::COMPILATION_FAILED\n");
        perror(infoLog);
    }
}

void libgpu::Shader::CheckProgram(GLuint Prog) {
    int success;
    char infoLog[512];
    glGetProgramiv(Prog, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(Prog, 512, NULL, infoLog);
        printf("ERROR::SHADER::COMPILATION_FAILED\n");
        printf(infoLog);
    }
}

libgpu::Shader::~Shader() {

}

std::string libgpu::Shader::ReadShaderFile(std::string Path) {
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