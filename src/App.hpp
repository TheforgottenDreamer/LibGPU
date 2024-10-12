#ifndef APP_H
#define APP_H

#include <stdio.h>
#include <thread>
#include <mutex>

/*#include <d3d9.h>
#include <d3d10.h>
#include <d3d11.h>
#include <d3d12.h>*/

#include <vulkan/vulkan.hpp>

#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "Graphics.hpp"

class App
{
private:
    void InitWindow();
    void InitGraphics();
public:
    void Run();
    void WindowUpdate();
    void Update();
    void FixedUpdate();
    void Render();
    void Stop();

    GLFWwindow* Window;
};
#endif