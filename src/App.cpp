#include "App.hpp"

void App::InitWindow() {
    if (!glfwInit()) {
        perror("Unable To Initialize Glfw");
    }

#if USING_OPENGL 
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#elif USING_DX9 or USING_DX10 or USING_DX11 or USING_DX12
    #define GLFW_EXPOSE_NATIVE_WIN32
#else 
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
#endif


    Window = glfwCreateWindow(800,800, "Window", nullptr, nullptr);
}


void App::InitOpengl() {
    glfwMakeContextCurrent(Window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        perror("Unable To Initialize Glad");
    }
}

void App::Run() {
    InitWindow();
#if USING_OPENGL
    InitOpengl();
    
#endif

    libgpu::Shader mainShader("Test");

    while (!glfwWindowShouldClose(Window)) {
        WindowUpdate();
        libgpu::ClearColor(glm::vec4(0.871, 0.859, 0.153, 1));
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(Window);
    }
}

void App::WindowUpdate() {
    glfwPollEvents();
}

void App::Render() {

}