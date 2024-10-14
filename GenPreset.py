import shutil
import webbrowser
import json

clang_Path = shutil.which('Clang')
clang_pp_Path = shutil.which("Clang++")

compile_Config = {
    "version": 8,
    "configurePresets": [
        {
            "name": "WindowsDebug",
            "displayName": "Windows Debug",
            "description": "Using compiler clang",
            "binaryDir": "${sourceDir}/out/build/${presetName}",
            "cacheVariables": {
                "CMAKE_INSTALL_PREFIX": "${sourceDir}/out/install/${presetName}",
                "CMAKE_C_COMPILER": clang_Path,
                "CMAKE_CXX_COMPILER": clang_pp_Path,
                "CMAKE_BUILD_TYPE": "Debug"
            }
        }
    ]
}


compile_json = json.dumps(compile_Config, indent=4)

with open("CMakePresets.json", "w") as file:
    file.write(compile_json)
print(compile_json)

