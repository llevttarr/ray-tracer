#ifndef RENDERER_H
#define RENDERER_H

#include "shader.h"

class Renderer {
public:
    explicit Renderer(int width, int height);
    ~Renderer();
    void run();
    void resize(int nw, int nh);
private:
    int w;
    int h;
    Shader shader;
    GLuint vao = 0;
    GLuint vbo = 0;
};
#endif //RENDERER_H
