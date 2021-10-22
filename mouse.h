#ifndef MOUSE_H
#define MOUSE_H

#include "defines.h"

 static int _State;    /// From glfw states

class Mouse
{
public:
    Mouse();
    static void setState(int state);

    static void setLftBtnClkState();
    static void setRightBtnClkState();

    int getState();

protected:


private:
    sPoint startDrag;
    sPoint DragPos;
};

#endif // MOUSE_H
