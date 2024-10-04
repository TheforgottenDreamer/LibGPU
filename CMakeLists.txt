cmake_minimum_required(VERSION 3.5.0)
project(LibGPU VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(ThirdParty/glfw)
add_subdirectory(ThirdParty/json)

add_executable(LibGPU src/main.cpp
    src/App.hpp src/App.cpp
    src/Graphics.hpp src/Graphics.cpp
)

find_package(Vulkan REQUIRED)
#find_package(Python3 REQUIRED)

target_include_directories(${PROJECT_NAME} PRIVATE ThirdParty/glad/include ThirdParty/json/include)

target_sources(${PROJECT_NAME} PRIVATE ThirdParty/glad/src/glad.c)

target_link_libraries(${PROJECT_NAME} PRIVATE Vulkan::Vulkan glfw nlohmann_json)

add_compile_definitions(${PROJECT_NAME} PUBLIC 
    USING_VULKAN=false
    USING_OPENGL=true
    USING_DX9=false
    USING_DX10=false
    USING_DX11=false
    USING_DX12=false
)

include(CTest)
enable_testing()