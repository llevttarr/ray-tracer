//#include <iostream>
//#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "./app/window.h"
#include "./render/renderer.h"

int main(int argc, char* argv[]) {
    Window window(640, 480, "Hello World");
    Renderer renderer(window);
    // raytracer
    // scene
    // camera
    while (!window.should_close())
    {
        // raytracer
        renderer.run();
        window.swap_buffers();
        window.poll_events();
    }
    return 0;
}
