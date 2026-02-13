#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <glad/gl.h>
#include <cstdint>
#include <stdexcept>

struct ShaderLoadException: public std::runtime_error{
    using std::runtime_error::runtime_error;
};

class Shader{
public:
    Shader() = default;
    explicit Shader(const std::string& frag_path,const std::string& vert_path);
    ~Shader();

    GLuint id() const{return progr; }
    void use();
    
private:
    GLuint progr=0;
    std::string read_file(const std::string& filename);
    GLuint create_shader(GLenum t,const std::string& s);
    GLuint create_shader_program(GLuint vert, GLuint frag);
};

#endif //SHADER_H