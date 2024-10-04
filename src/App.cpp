#include "App.hpp"

void App::InitWindow() {
    if (!glfwInit()) {
        perror("Unable To Initialize Glfw");
    }

#if USING_OPENGL 
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#else 
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
#endif

    Window = glfwCreateWindow(800,800, "Window", nullptr, nullptr);
}

void App::InitGraphics() {
#if USING_OPENGL
    glfwMakeContextCurrent(Window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        perror("Unable To Initialize Glad");
    }

#elif USING_VULKAN

#elif USING_DX9

#elif USING_DX10

#elif USING_DX11

#elif USING_DX12

#endif
}

void App::Run() {
    InitWindow();
    InitGraphics();

    while (!glfwWindowShouldClose(Window)) {
        WindowUpdate();
    }
}

void App::WindowUpdate() {
    glfwPollEvents();
}

void App::Render() {


}