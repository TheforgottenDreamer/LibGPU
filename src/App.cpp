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
#else 
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
#endif

    Window = LibGPUWindow(800, 800, "my balls", nullptr);
}

void App::InitDxVersion() {
#if USING_DX9
    DxVersion = DirectxVersion::DX9;
#elif USING_DX10
    DxVersion = DirectxVersion::DX10;
#elif USING_DX11
    DxVersion = DirectxVersion::DX11;
#elif USING_DX12
    DxVersion = DirectxVersion::DX12;
#endif
}

void App::InitD3d(DirectxVersion Version) {

    switch (Version)
    {
    case DirectxVersion::DX9:

        Dx9.D3d = Direct3DCreate9(D3D_SDK_VERSION);
        Dx9.Pres.Windowed = Window.IsFullscreen();
        Dx9.D3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, Window.GetWindowAPiWindow(), D3DCREATE_SOFTWARE_VERTEXPROCESSING, &Dx9.Pres, &Dx9.D3dDevice);

        break;
    case DirectxVersion::DX10:
        break;
    case DirectxVersion::DX11:
        break;
    case DirectxVersion::DX12:
        break;
    default:
        break;
    }
}


void App::InitOpengl() {
    Window.MakeCurrentContext();

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        perror("Unable To Initialize Glad");
    }
}

void App::Run() {
    InitWindow();
#if USING_OPENGL
    InitOpengl();
#elif USING_DX9 or USING_DX10 or USING_DX11 or USING_DX12
    InitDxVersion();
    InitD3d(DxVersion);
#endif

    libgpu::Shader mainShader("Test");

    while (Window.IsOpen()) {
        WindowUpdate();
        libgpu::ClearColor(glm::vec4(0.871, 0.859, 0.153, 1));
        glClear(GL_COLOR_BUFFER_BIT);
        Window.SwapBuffers();
    }
}

void App::WindowUpdate() {
    glfwPollEvents();
}

void App::Render() {

}