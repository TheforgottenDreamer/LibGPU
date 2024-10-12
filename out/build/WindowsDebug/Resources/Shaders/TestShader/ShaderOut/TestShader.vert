#version 460

uniform vec4 UniformBuffer[8];
layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec3 aColor;
layout(location = 2) in vec2 aUV;
layout(location = 0) out vec3 FragColor;
layout(location = 1) out vec2 FragUV;

void main()
{
    gl_Position = (mat4(UniformBuffer[0], UniformBuffer[1], UniformBuffer[2], UniformBuffer[3]) * mat4(UniformBuffer[4], UniformBuffer[5], UniformBuffer[6], UniformBuffer[7])) * vec4(aPosition, 1.0);
}

