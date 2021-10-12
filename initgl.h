#ifndef INITGL_H
#define INITGL_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "monitors.h"

class InitGL
{
public:
    InitGL();
    ~InitGL();
    bool init();

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
protected:
    //------------------------
    // The main win
    //------------------------
    GLFWwindow *        _Window;
    int                 _ResolutionX;
    int                 _ResolutionY        ;

    //------------------------
    //Monitors and propertier
    //------------------------
    Monitors monitors;

private:
    void Prepare2D();
    void Restore3D();


};

#endif // INITGL_H
