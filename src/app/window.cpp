#include "window.h"
#include <stdexcept>
Window::Window(int w, int h, const std::string& title)
    : width(w), height(h),glfw_window(nullptr)
{
    if (!glfwInit()){
        throw std::runtime_error("glfwInit fail");
    }

    glfw_window = glfwCreateWindow(w, h,title.c_str(), NULL, NULL);
    if (!glfw_window) {
        glfwTerminate();
        throw std::runtime_error("glfw_window creation fail");
    }
    glfwMakeContextCurrent(glfw_window);
    glfwSwapInterval(1);
}

Window::~Window() {
    glfwDestroyWindow(glfw_window);
    glfwTerminate();
}
bool Window::should_close() const{
    return glfwWindowShouldClose(glfw_window);
}
void Window::poll_events(){
    glfwPollEvents();
}
void Window::swap_buffers(){
    glfwSwapBuffers(glfw_window);
}
int Window::get_h(){
    return height;
}
int Window::get_w(){
    return width;
}