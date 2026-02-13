#include "shader.h"

#include <fstream>
#include <sstream>

Shader::Shader(const std::string& vert_path, const std::string& frag_path){
    const std::string vert=read_file(vert_path);
    const std::string frag=read_file(vert_path);
    if (vert=="" || frag==""){
        throw ShaderLoadException("frag or vert shader couldn't be read");
    }
    GLuint vert_s=create_shader(GL_VERTEX_SHADER,vert);
    GLuint frag_s=create_shader(GL_VERTEX_SHADER,frag);
    progr=create_shader_program(vert_s,frag_s);

    glDeleteShader(vert_s);
    glDeleteShader(frag_s);
}
Shader::~Shader(){
    if(progr==0){
        return;
    }
    glDeleteProgram(progr);
    progr=0;
}
std::string Shader::read_file(const std::string& filename){
    std::ifstream instr(filename);
    if(!instr){
        return "";
    }
    std::stringstream ss;
    ss << instr.rdbuf();
    return ss.str();
}
GLuint Shader::create_shader(GLenum t,const std::string& s){
    const char* ch=s.c_str();
    GLuint shader=glCreateShader(t);
    glShaderSource(shader,1,&ch,nullptr);
    glCompileShader(shader);
    GLint status=0;
    glGetShaderiv(shader,GL_COMPILE_STATUS,&status);
    if(status==0){
        throw ShaderLoadException("could not create shader "+t);
    }
    return shader;
}
GLuint Shader::create_shader_program(GLuint vert, GLuint frag){
    GLuint program =glCreateProgram();
    glAttachShader(program,vert);
    glAttachShader(program,frag); 
    glLinkProgram(program);
    GLint status=0;
    glGetProgramiv(program, GL_LINK_STATUS, &status);
    if(status==0){
        throw ShaderLoadException("could not link shaders ");
    }
    return program;
}
void Shader::use(){
    if (progr==0){
        throw ShaderLoadException("could not use shader");
    }
    return glUseProgram(progr);
}
