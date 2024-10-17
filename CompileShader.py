import json
import sys
import os
import glob

def Compile_Shaders(Resource_Path):

    Shaders = glob.glob(f"{Resource_Path}/Shaders/*.json")

    for ShaderFile in Shaders:
        with open(ShaderFile, "r") as file:
            ShaderArgv = json.load(file)

        Shader_Folder = ShaderArgv.get("ShaderFolder", "")
        Output_Folder = ShaderArgv.get("Output", "")
        Shader_Name = ShaderArgv.get("ShaderName", "")

        if not Shader_Folder or not Output_Folder or not Shader_Name:
            print(f"Skipping {ShaderFile} due to missing data")
            continue

        print(f"Compiling {Shader_Name}:")
        print(f"Shader folder: {Shader_Folder}")
        print(f"Output folder: {Output_Folder}")

        vertex_shader = glob.glob(f"{Resource_Path}/Shaders/{Shader_Folder}/*.vert")
        fragment_shader = glob.glob(f"{Resource_Path}/Shaders/{Shader_Folder}/*.frag")
        geometry_shader = glob.glob(f"{Resource_Path}/Shaders/{Shader_Folder}/*.geom")
        tessellation_control_shader = glob.glob(f"{Resource_Path}/Shaders/{Shader_Folder}/*.tesc")
        tessellation_evaluation_shader = glob.glob(f"{Resource_Path}/Shaders/{Shader_Folder}/*.tese")
        compute_shader = glob.glob(f"{Resource_Path}/Shaders/{Shader_Folder}/*.comp")

        if(not os.path.exists(f"{Resource_Path}/Shaders/{Output_Folder}/")):
            try:
                os.mkdir(f"{Resource_Path}/Shaders/{Output_Folder}/")
            except FileExistsError:
                print(f"Directory '{Resource_Path}/Shaders/{Output_Folder}/' already exists.")
                continue
            except PermissionError:
                print(f"Permission denied: Unable to create '{Resource_Path}/Shaders/{Output_Folder}/'")
            except Exception as e:
                print(f"An error occurred: {e}")


        if vertex_shader:
            os.system(f"glslang -V {vertex_shader[0]} -o {Resource_Path}/Shaders/{Output_Folder}/Spirv_{Shader_Name}_Vert.spv")
            os.system(f"spirv-cross {Resource_Path}/Shaders/{Output_Folder}/Spirv_{Shader_Name}_Vert.spv --reflect")
            os.system(f"spirv-cross {Resource_Path}/Shaders/{Output_Folder}/Spirv_{Shader_Name}_Vert.spv --output {Resource_Path}/Shaders/{Output_Folder}/{Shader_Name}_Vert.glsl --version 420")
            os.system(f"spirv-cross {Resource_Path}/Shaders/{Output_Folder}/Spirv_{Shader_Name}_Vert.spv --output {Resource_Path}/Shaders/{Output_Folder}/{Shader_Name}_Vert.hlsl --hlsl")
        if fragment_shader:
            os.system(f"glslang -V {fragment_shader[0]} -o {Resource_Path}/Shaders/{Output_Folder}/Spirv_{Shader_Name}_Frag.spv")
            os.system(f"spirv-cross {Resource_Path}/Shaders/{Output_Folder}/Spirv_{Shader_Name}_Frag.spv --reflect")
            os.system(f"spirv-cross {Resource_Path}/Shaders/{Output_Folder}/Spirv_{Shader_Name}_Frag.spv --output {Resource_Path}/Shaders/{Output_Folder}/{Shader_Name}_Frag.glsl --version 420")
            os.system(f"spirv-cross {Resource_Path}/Shaders/{Output_Folder}/Spirv_{Shader_Name}_Frag.spv --output {Resource_Path}/Shaders/{Output_Folder}/{Shader_Name}_Frag.hlsl --hlsl")
        if geometry_shader:
            os.system(f"glslang -V {geometry_shader[0]} -o {Resource_Path}/Shaders/{Output_Folder}/Spirv_{Shader_Name}_Geom.spv")
            os.system(f"spirv-cross {Resource_Path}/Shaders/{Output_Folder}/Spirv_{Shader_Name}_Geom.spv --reflect")
            os.system(f"spirv-cross {Resource_Path}/Shaders/{Output_Folder}/Spirv_{Shader_Name}_Geom.spv --output {Resource_Path}/Shaders/{Output_Folder}/{Shader_Name}_Geom.glsl --version 420")
            os.system(f"spirv-cross {Resource_Path}/Shaders/{Output_Folder}/Spirv_{Shader_Name}_Geom.spv --output {Resource_Path}/Shaders/{Output_Folder}/{Shader_Name}_Geom.hlsl --hlsl")
        if tessellation_control_shader:
            os.system(f"glslang -V {tessellation_control_shader[0]} -o {Resource_Path}/Shaders/{Output_Folder}/Spirv_{Shader_Name}_Tesc.spv")
            os.system(f"spirv-cross {Resource_Path}/Shaders/{Output_Folder}/Spirv_{Shader_Name}_Tesc.spv --reflect")
            os.system(f"spirv-cross {Resource_Path}/Shaders/{Output_Folder}/Spirv_{Shader_Name}_Tesc.spv --output {Resource_Path}/Shaders/{Output_Folder}/{Shader_Name}_Tesc.glsl --version 420")
            os.system(f"spirv-cross {Resource_Path}/Shaders/{Output_Folder}/Spirv_{Shader_Name}_Tesc.spv --output {Resource_Path}/Shaders/{Output_Folder}/{Shader_Name}_Tesc.hlsl --hlsl")
        if tessellation_evaluation_shader:
            os.system(f"glslang -V {tessellation_evaluation_shader[0]} -o {Resource_Path}/Shaders/{Output_Folder}/Spirv_{Shader_Name}_Tese.spv")
            os.system(f"spirv-cross {Resource_Path}/Shaders/{Output_Folder}/Spirv_{Shader_Name}_Tese.spv --reflect")
            os.system(f"spirv-cross {Resource_Path}/Shaders/{Output_Folder}/Spirv_{Shader_Name}_Tese.spv --output {Resource_Path}/Shaders/{Output_Folder}/{Shader_Name}_Tese.glsl --version 420")
            os.system(f"spirv-cross {Resource_Path}/Shaders/{Output_Folder}/Spirv_{Shader_Name}_Tese.spv --output {Resource_Path}/Shaders/{Output_Folder}/{Shader_Name}_Tese.hlsl --hlsl")
        if compute_shader:
            os.system(f"glslang -V {compute_shader[0]} -o {Resource_Path}/Shaders/{Output_Folder}/Spirv_{Shader_Name}_Comp.spv")
            os.system(f"spirv-cross {Resource_Path}/Shaders/{Output_Folder}/Spirv_{Shader_Name}_Comp.spv --reflect")
            os.system(f"spirv-cross {Resource_Path}/Shaders/{Output_Folder}/Spirv_{Shader_Name}_Comp.spv --output {Resource_Path}/Shaders/{Output_Folder}/{Shader_Name}_Comp.glsl --version 420")
            os.system(f"spirv-cross {Resource_Path}/Shaders/{Output_Folder}/Spirv_{Shader_Name}_Comp.spv --output {Resource_Path}/Shaders/{Output_Folder}/{Shader_Name}_Comp.hlsl --hlsl")



if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python compile_shaders.py <ResourcePath>")
        sys.exit(1)
    
    Compile_Shaders(sys.argv[1])