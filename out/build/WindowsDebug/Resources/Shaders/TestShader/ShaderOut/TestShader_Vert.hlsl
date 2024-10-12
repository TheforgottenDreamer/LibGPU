cbuffer UniformBuffer : register(b0)
{
    row_major float4x4 UniformObject_ViewMat : packoffset(c0);
    row_major float4x4 UniformObject_ModelMat : packoffset(c4);
};

uniform float4 gl_HalfPixel;

static float4 gl_Position;
static float3 aPosition;
static float3 aColor;
static float2 aUV;
static float3 FragColor;
static float2 FragUV;

struct SPIRV_Cross_Input
{
    float3 aPosition : TEXCOORD0;
    float3 aColor : TEXCOORD1;
    float2 aUV : TEXCOORD2;
};

struct SPIRV_Cross_Output
{
    float3 FragColor : TEXCOORD0;
    float2 FragUV : TEXCOORD1;
    float4 gl_Position : POSITION;
};

void vert_main()
{
    gl_Position = mul(float4(aPosition, 1.0f), mul(UniformObject_ModelMat, UniformObject_ViewMat));
    gl_Position.x = gl_Position.x - gl_HalfPixel.x * gl_Position.w;
    gl_Position.y = gl_Position.y + gl_HalfPixel.y * gl_Position.w;
}

SPIRV_Cross_Output main(SPIRV_Cross_Input stage_input)
{
    aPosition = stage_input.aPosition;
    aColor = stage_input.aColor;
    aUV = stage_input.aUV;
    vert_main();
    SPIRV_Cross_Output stage_output;
    stage_output.gl_Position = gl_Position;
    stage_output.FragColor = FragColor;
    stage_output.FragUV = FragUV;
    return stage_output;
}
