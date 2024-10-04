Texture2D Tex1;

struct VertexInput {
    float3 position : POSITION;
    float2 texturecoords : TEXCOORD;
};

float4 main(VertexInput : Inputs) : SV_Position {
    return float4(0.4,0.3,1,1);
};