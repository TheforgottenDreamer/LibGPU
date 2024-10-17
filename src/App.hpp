#ifndef APP_H
#define APP_H

#include <stdio.h>
#include <thread>
#include <mutex>

#include <d3d9.h>
#include <d3d10.h>
#include <d3d11.h>
#include <d3d12.h>

#include <vulkan/vulkan.hpp>

#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#include <glm/glm.hpp>

#include "Graphics.hpp"

class App
{
private:
    enum DirectxVersion {
        DX9,
        DX10,
        DX11,
        DX12
    };

    void InitWindow();
    void InitDxVersion();
    void InitD3d(DirectxVersion Version);
    void InitOpengl();
    void InitVulkan();
public:
    DirectxVersion DxVersion;

    void Run();
    void WindowUpdate();
    void Update();
    void FixedUpdate();
    void Render();
    void Stop();

    GLFWwindow* Window;
};
#endif