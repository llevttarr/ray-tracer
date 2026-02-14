#ifndef COMP_SHADER_H
#define COMP_SHADER_H

#include <string>
#include <glad/gl.h>
#include <stdexcept>
#include "../util/glsl_util.h"

struct CShaderUseException: public std::runtime_error{
    using std::runtime_error::runtime_error;
};

class ComputeShader{
public:
    ComputeShader() = default;
    explicit ComputeShader(const std::string& filename);
    ~ComputeShader();

    GLuint id() const{return progr; }
    void use();
    
private:
    GLuint progr=0;
};

#endif //COMPSHADER_H