#ifndef APP_H
#define APP_H

#include <stdio.h>
#include <thread>
#include <mutex>

#pragma region
#include <d3d9.h>
#include <d3d10_1.h>
/*🤬 this 🤬 WHY NOT INCLUDE D3D10 AND NOT ADD D3D10_1, THIS PROJECT ONLY LINKS TO D3D10.lib AND NOT D3D10_1.lib AND IT WORKS WTF MICROSOFT
I HAVE TO INCLUDE THIS 🤬 IN EVERY HEADER? THIS IS A MESS, 🤬 YOU MICROSOFT. THIS IS THE ONLY D3D VERSION THAT DOES THIS NOT EVEN D3D9
WHAT DOES THIS HEADER EVEN DO DEFINE A LOAD OF 🤬 THAT YOU COULD IN THE ORIGNAL HEADER, OR 🤬 INCLUDE IT IN THE D3D10 HEADER 🤬*/
#include <d3d10.h>
#include <d3d11.h>
#include <d3d12.h>
#include <vulkan/vulkan.hpp>
#include <glad/glad.h>
#pragma endregion

#include <GLFW/glfw3.h>
#include "LibGPUWindow.hpp"
#pragma region
#if USING_DX9 or USING_DX10 or USING_DX11 or USING_DX12
#define GLFW_EXPOSE_NATIVE_WIN32
#endif
#pragma endregion

#include <GLFW/glfw3native.h>

#include <glm/glm.hpp>

#include "Graphics.hpp"

class App
{
private:
#pragma region

    struct Directx9Data
    {
        LPDIRECT3D9 D3d;
        LPDIRECT3DDEVICE9 D3dDevice;
        D3DPRESENT_PARAMETERS Pres;
        
    };

    struct Directx10Data
    {
        ID3D10Device *D3dDevice;
    };

    struct Directx11Data {
        ID3D11Device *D3dDevice;
        ID3D11DeviceContext *D3dContext;
        IDXGISwapChain *SwapChain;
    };

    struct Directx12Data
    {
        ID3D12Device *D3dDevice;
    };

    struct VulkanData
    {
    };
#pragma endregion

    enum DirectxVersion
    {
        DX9,
        DX10,
        DX11,
        DX12
    };

#pragma region
#if USING_DX9 or USING_DX10 or USING_DX11 or USING_DX12
    HWND WinApiWindow;
#endif
#pragma endregion

    void InitWindow();
    void InitDxVersion();
    void InitD3d(DirectxVersion Version);
    void InitOpengl();
    void InitVulkan();

public:
    DirectxVersion DxVersion;
#pragma region
#if USING_DX9 or USING_DX10 or USING_DX11 or USING_DX12 
    Directx9Data Dx9;
    Directx10Data Dx10;
    Directx11Data Dx11;
    Directx12Data Dx12;
#elif USING_VULKAN
    VulkanData Vulkan;
#endif
#pragma endregion

    void Run();
    void WindowUpdate();
    void Update();
    void FixedUpdate();
    void Render();
    void Stop();
    void GlfwMaximizedCallback(GLFWwindow *window, int maximize);

    LibGPUWindow Window;
};
#endif