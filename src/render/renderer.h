#ifndef RENDERER_H
#define RENDERER_H

#include "shader.h"

class Renderer {
public:
    explicit Renderer(int width, int height);
    void run();
private:
    int w;
    int h;
    Shader shader;
};
#endif //RENDERER_H
