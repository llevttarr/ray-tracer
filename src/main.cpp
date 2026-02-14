//#include <iostream>
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "./app/window.h"
#include "./render/renderer.h"

int main(int argc, char* argv[]) {
    Window window(640, 480, "Ray tracer");
    Renderer renderer(window.get_w(),window.get_h());  // resize?
    while (!window.should_close()){
        renderer.run();
        window.swap_buffers();
        window.poll_events();
    }
    return 0;
}
