#version 460

layout(location=0) in vec3 FragColor;
layout(location=1) in vec2 FragUV;


layout(location=0) out vec4 Color;
void main() {
    Color = vec4(FragColor,1);
}