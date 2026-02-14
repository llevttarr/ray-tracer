#pragma once

#include <string>
#include <glad/gl.h>
#include <cstdint>
#include <stdexcept>

struct GLSLUtilException: public std::runtime_error{
    using std::runtime_error::runtime_error;
};

namespace glsl_util{
    std::string read_file(const std::string& filename);
    GLuint create_shader(GLenum t,const std::string& s);
    GLuint link_shaders(GLuint vert, GLuint frag);
    GLuint link_comp(GLuint comp);
}