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
    //------------------------
    // The main win
    //------------------------
    GLFWwindow *        _Window;

    void getMonitors();
    void showProperties(int i);

    //------------------------
    //Monitors and propertier
    //------------------------
    int                 _CountMonitors;
    int                 _CountMonitorProperties;
    GLFWmonitor **      _Monitors;
    GLFWmonitor *       _PrimaryMonitor;
private:
    void Prepare2D();
    void Restore3D();


};

#endif // INITGL_H
