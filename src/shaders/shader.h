#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader{
public:
    Shader(const std::string& frag_path,const std::string& vert_path);
    ~Shader();
    
private:
};

#endif //SHADER_H