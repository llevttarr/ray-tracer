#ifndef RENDERER_H
#define RENDERER_H

class Window;
class Renderer {
public:
    explicit Renderer(Window& window): wind(window){};
    void run();
private:
    Window& wind;
};
#endif //RENDERER_H
