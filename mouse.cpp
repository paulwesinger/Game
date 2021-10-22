#include "mouse.h"
#include <GLFW/glfw3.h>
#include "defines.h"

Mouse::Mouse()
{
//    _State = 0;
}

void Mouse::setState(int state)
{
    _State  = state;
}
void Mouse::setLftBtnClkState()
{

}

void Mouse::setRightBtnClkState()
{

}

int Mouse::getState()
{
    return _State;
}
