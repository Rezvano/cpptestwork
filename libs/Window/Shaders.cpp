//нужно бы вывести это в другой класс по шейдерам, чтобы там разные шейдера использовать и все такое, но я тут уже игровой мать его движек сделал...

#include "Window.h"

const GLchar *vertexShaderCode = "#version 330 core\n"
                                   "layout (location = 0) in vec3 position;\n"
                                   "uniform mat4 transform;\n"
                                   "void main()\n"
                                   "{\n"
                                   "gl_Position = transform * vec4(position, 1.0f);\n"
                                   "}\0";

const GLchar *fragmentShaderCode = "#version 330 core\n"
                                     "out vec4 color;\n"
                                     "uniform vec4 col;\n"
                                     "void main()\n"
                                     "{\n"
                                     "color = col;\n"
                                     "}\n\0";

void Window::ShadersInit()
{
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderCode, NULL);
    glCompileShader(vertexShader);
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderCode, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}
