#include <stdio.h>
/*#include <d3d9.h>
#include <d3d10.h>
#include <d3d11.h>
#include <d3d12.h>*/

//#include <vulkan/vulkan.hpp>

#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <nlohmann/json.hpp>

#include "App.hpp"

App app;

int main(int, char**){
    /*GLFWwindow* window;

    if (!glfwInit()) {
        perror("Unable To Initialize Glfw");
        return 1;
    }

#if USING_OPENGL 
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#else 
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
#endif

    window = glfwCreateWindow(800,800, "Window", nullptr, nullptr);

#if USING_OPENGL
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        perror("Unable To Initialize Glad");
        return 1;
    }

    glViewport(0,0,800,800);

    printf("OpenGL");

#elif USING_VULKAN

#elif USING_DX9

#elif USING_DX10

#elif USING_DX11

#elif USING_DX12

#endif

    while (!glfwWindowShouldClose(window)) {

#if USING_OPENGL
        glClearColor(0.9f,0.294f , 0.591f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
#endif

        printf("9");

        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    glfwDestroyWindow(window);
    glfwTerminate();*/

    app.Run();
    return 0;
}
