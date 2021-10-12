#ifndef MONITORS_H
#define MONITORS_H


#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <vector>

class Monitors
{
public:
    Monitors();

    void getMonitors();
    void showProperties(int monitorindex, int propertyindex);

protected:
    //------------------------
    //Monitors and propertier
    //------------------------
    int                 _CountMonitors;
    int                 _CountMonitorProperties;
    GLFWmonitor **      _Monitors;
    GLFWmonitor *       _PrimaryMonitor;

    std::vector<const GLFWvidmode *> videoprops;
};

#endif // MONITORS_H
