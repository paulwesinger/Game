#include "monitors.h"
#include "utils/utils.h"
#include "logs/logs.h"

Monitors::Monitors()
{

}

// ----------------------------------------
// Monitor properties
//-----------------------------------------
void Monitors::getMonitors()
{
    _Monitors = glfwGetMonitors(&_CountMonitors);
    if (_Monitors != nullptr)
    {
        _PrimaryMonitor = _Monitors[0];
        for (int i = 0; i < _CountMonitors; i++)
        {
            logimage("Video modes Monitor " + IntToString(i));
            //const GLFWvidmode * modes = glfwGetVideoModes(_Monitors[i],&_CountMonitorProperties);
            videoprops.push_back( glfwGetVideoModes(_Monitors[i],&_CountMonitorProperties));
            for (int j = 0; j < _CountMonitorProperties; j++ )
            {
                logimage("X-Res: " + IntToString(videoprops.at(i)[j].width) + "  " + "Y-Res: " + IntToString(videoprops.at(i)[j].height) );
            }
        }
    }
}

void Monitors::showProperties(int i) {
    if (i < _CountMonitorProperties )
        logimage("X-Res: " + IntToString(videoprops.at(i)->width) + "  " + "Y-Res: " + IntToString(videoprops.at(i)->height) );
}
