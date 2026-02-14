#include "renderer.h"
#include <glad/gl.h> 
Renderer::Renderer(int width, int height)

  : w(width), h(height),
    shader("assets/shaders/vs.vert", "assets/shaders/fs.frag")
{
    // w=width;
    // h=height;

    // shader = Shader("assets/shaders/vs.vert", "assets/shaders/fs.frag");

    float temp[] = {-0.25f,-0.25f,0.0f,
         0.25f,-0.25f,0.0f,
         0.0f,0.25f,0.0f};

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(temp), temp, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
Renderer::~Renderer() {
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
}
void Renderer::run(){
    glViewport(0, 0, w, h);
    glClearColor(0.1f,0.1f,0.2f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    shader.use();
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
void Renderer::resize(int nw, int nh){
    h=nh;
    w=nw;
}
