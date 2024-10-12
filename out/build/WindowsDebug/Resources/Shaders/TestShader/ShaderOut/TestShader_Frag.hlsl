static float3 FragColor;
static float2 FragUV;

struct SPIRV_Cross_Input
{
    float3 FragColor : TEXCOORD0;
    float2 FragUV : TEXCOORD1;
};

void frag_main()
{
}

void main(SPIRV_Cross_Input stage_input)
{
    FragColor = stage_input.FragColor;
    FragUV = stage_input.FragUV;
    frag_main();
}
