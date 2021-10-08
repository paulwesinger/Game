#ifndef INITGL_H
#define INITGL_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
//#include "glad/include/glad/glad.h"

class InitGL
{
public:
    InitGL();
    ~InitGL();
    bool init();

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
protected:
    GLFWwindow * window;

};

#endif // INITGL_H
