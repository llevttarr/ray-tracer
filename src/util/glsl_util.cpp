
#include <fstream>
#include <sstream>
#include "glsl_util.h"

namespace glsl_util{

    std::string read_file(const std::string& filename){
        std::ifstream instr(filename);
        if(!instr){
            throw GLSLUtilException("Could not read file");
        }
        std::stringstream ss;
        ss << instr.rdbuf();
        return ss.str();
    }
    GLuint create_shader(GLenum t,const std::string& s){
        const char* ch=s.c_str();
        GLuint shader=glCreateShader(t);
        glShaderSource(shader,1,&ch,nullptr);
        glCompileShader(shader);
        GLint status=0;
        glGetShaderiv(shader,GL_COMPILE_STATUS,&status);
        if(status==0){
            throw GLSLUtilException("could not create shader ");
        }
        return shader;
    }

    GLuint link_shaders(GLuint vert, GLuint frag){
        GLuint program =glCreateProgram();
        glAttachShader(program,vert);
        glAttachShader(program,frag); 
        glLinkProgram(program);
        GLint status=0;
        glGetProgramiv(program, GL_LINK_STATUS, &status);
        if(status==0){
            throw GLSLUtilException("could not link shaders ");
        }
        return program;
    }GLuint link_comp(GLuint comp){
        GLuint program =glCreateProgram();
        glAttachShader(program,comp); 
        glLinkProgram(program);
        GLint status=0;
        glGetProgramiv(program, GL_LINK_STATUS, &status);
        if(status==0){
            throw GLSLUtilException("could not link comp shader");
        }
        return program;
    }
}