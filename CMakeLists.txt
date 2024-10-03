cmake_minimum_required(VERSION 3.5.0)
project(LibGPU VERSION 0.1.0 LANGUAGES C CXX)

add_executable(LibGPU main.cpp)

find_package(Vulkan REQUIRED)
find_package(wxWindows REQUIRED)

#target_include_directories(${PROJECT_NAME} PRIVATE ${VULKAN_INCLUDE})

target_link_libraries(${PROJECT_NAME} PRIVATE Vulkan::Vulkan)

include(CTest)
enable_testing()