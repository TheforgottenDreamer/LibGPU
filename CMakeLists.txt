cmake_minimum_required(VERSION 3.5.0)
project(LibGPU VERSION 0.1.0 LANGUAGES C CXX)

find_package(Vulkan REQUIRED)
find_package(Python REQUIRED COMPONENTS) 

set(CMAKE_CXX_STANDARD 20)
set(ENABLE_OPT=0)

add_subdirectory(ThirdParty/glfw)
add_subdirectory(ThirdParty/json)
add_subdirectory(ThirdParty/glm)

add_executable(LibGPU src/main.cpp
    src/Graphics.hpp src/Graphics.cpp
    src/App.hpp src/App.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ThirdParty/glad/include ThirdParty/json/include)

target_sources(${PROJECT_NAME} PRIVATE ThirdParty/glad/src/glad.c)

target_link_libraries(${PROJECT_NAME} PRIVATE Vulkan::Vulkan glfw nlohmann_json glm)

file(COPY "${CMAKE_SOURCE_DIR}/Resources" DESTINATION "${CMAKE_BINARY_DIR}/")

file(COPY "CompileShader.py" DESTINATION "${CMAKE_BINARY_DIR}")

execute_process(COMMAND ${Python_EXECUTABLE} CompileShader.py  Resources)

target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="${CMAKE_BINARY_DIR}/Resources/")

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