#version 400 core

layout (location = 1) in vec3 aPosition;
layout (location = 2) in vec4 aVertexColor;
layout (location = 4) in vec2 aUvCoord;

out vec2 TextureCoords;
out vec4 VertexColor;
uniform mat4 uTranform;

void main() {
    TextureCoords = aUvCoord;
    VertexColor = aVertexColor;
    gl_Position = uTranform * vec4(aPosition, 1);
}