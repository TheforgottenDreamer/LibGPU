#include "LibGPUWindow.hpp"

LibGPUWindow::LibGPUWindow(int Width, int Height, std::string Title, WindowHint hints[]) {
    Window = glfwCreateWindow(Width, Height, Title.c_str(), glfwGetPrimaryMonitor(), NULL);
}

void LibGPUWindow::InitHints(WindowHint hints[]) {
    for(int i = 0; i <= sizeof(hints); i++) {
        glfwWindowHint(hints[i].Hint, hints[i].Argument);
    }
}

bool LibGPUWindow::IsOpen() {
    return !glfwWindowShouldClose(Window);
}

HWND LibGPUWindow::GetWindowAPiWindow() {
#if GLFW_EXPOSE_NATIVE_WIN32
    return glfwGetWin32Window();
#else
    return nullptr;
#endif
}

bool LibGPUWindow::IsFullscreen() {
    return !glfwGetWindowAttrib(Window, GLFW_MAXIMIZED);
}

void LibGPUWindow::MakeCurrentContext() {
    glfwMakeContextCurrent(Window);
}

void LibGPUWindow::SwapBuffers() {
    glfwSwapBuffers(Window);
}

LibGPUWindow::~LibGPUWindow() {
    glfwDestroyWindow(Window);
}