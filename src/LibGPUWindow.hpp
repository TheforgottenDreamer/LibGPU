#ifndef WINDOW_H
#define WINDOW_H

#include <string>

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#include<d3d11.h>
#if USING_DX9 or USING_DX10 or USING_DX11 or USING_DX12
#define GLFW_EXPOSE_NATIVE_WIN32
#endif

class LibGPUWindow
{
private:
    GLFWwindow* Window;
public:
    struct WindowHint {
        int Hint;
        int Argument;
    };
    void InitHints(WindowHint hints[]);
    LibGPUWindow(int Width, int Height, std::string Title, WindowHint Hints[]);
    ~LibGPUWindow();
    bool IsOpen();
    bool IsFullscreen();
    void MakeCurrentContext();
    void SwapBuffers();

    HWND GetWindowAPiWindow();
};
#endif