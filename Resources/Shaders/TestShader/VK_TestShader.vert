#version 460

layout(location=0) in vec3 aPosition;
layout(location=1) in vec3 aColor;
layout(location=2) in vec2 aUV;

layout(binding=0) uniform UniformBuffer {
    mat4 ViewMat;
    mat4 ModelMat;
} UniformObject;

layout(location=0) out vec3 FragColor;
layout(location=1) out vec2 FragUV;

void main() {
    gl_Position = UniformObject.ViewMat * UniformObject.ModelMat * vec4(aPosition,1);
    FragColor = aColor;
    FragUV = aUV;
}