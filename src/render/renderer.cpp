#include "renderer.h"
#include <GLFW/glfw3.h>
Renderer::Renderer(int width, int height){
    w=width;
    h=height;

    shader = Shader("../shaders/vs.vert","../shaders/fs.frag");

}
void Renderer::run(){
    // glClearColor(1.f,1.f,1.f,1.f);
    // glClear(GL_COLOR_BUFFER_BIT);

    shader.use();
}