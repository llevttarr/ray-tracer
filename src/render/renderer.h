#ifndef RENDERER_H
#define RENDERER_H

#include "shader.h"

class Renderer {
public:
    explicit Renderer(int width, int height);
    ~Renderer();
    void run();
private:
    int w;
    int h;
    Shader shader;
    GLuint vao = 0;
    GLuint vbo = 0;
};
#endif //RENDERER_H
