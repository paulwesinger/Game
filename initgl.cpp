//#include <GL/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "logs/logs.h"
#include "utils/utils.h"
#include "initgl.h"
#include "textrenderer/textrender.h"

InitGL::InitGL()
{
}

InitGL::~InitGL(){
    glfwTerminate();
}
bool InitGL::init()
{
    if (glfwInit()) {

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,5);

        // --------------------------------------------------
        // Get Monitors
        // --------------------------------------------------
         monitors.getMonitors();

        //---------------------------------------------------
        // init window
        //---------------------------------------------------
        _ResolutionX = 3200;
        _ResolutionY = 1800;

        _Window = glfwCreateWindow(_ResolutionX,_ResolutionY,"Game",glfwGetPrimaryMonitor(), NULL);

        if (! _Window)
        {
            glfwTerminate();
            exit(EXIT_FAILURE);
        }
        loginfo("GLFW Init OK"," INITGL");

        glfwMakeContextCurrent(_Window);

        glewExperimental = GL_TRUE;
        glewInit();

        glfwSwapInterval(1);
        loginfo("GLFWindow Init OK"," INITGL");
        glfwSetKeyCallback(_Window, key_callback);
        glClearColor(0.0,0.0,1.0,1.0);

        //test !!
        sPoint sp ;
        sp.x = 1800; sp.y = 50;
        TextRender * text = new TextRender(_ResolutionX,_ResolutionY,sp);
        text->AddString("Test String");

        static int fak = 1;

        while (!glfwWindowShouldClose(_Window)) {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            // 2D - Stuff
            Prepare2D();

            text->SetTextColor(glm::vec4(0.5,0.8,0.7,0.4));
            text->SetScale(1.0);
            sp.y += fak;
            text->setPos(sp);
            text->setText(0,"irgendwas");
            text->Render();
            //Restore 3D
            Restore3D();

            // Drawing and so on
            glfwSwapBuffers(_Window);
            glfwPollEvents();
        }

        glfwDestroyWindow(_Window);
        loginfo("Destroy Window"," INITGL");

        exit(EXIT_SUCCESS);
        return true;
    }
    else
    {
        logwarn("GLFW Init fehlgeschlagen !  - Terminte","InitGL");
        return false;
    }
}

void InitGL::Prepare2D() {
    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
    glDepthMask(0);
}

void InitGL::Restore3D() {
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    glFrontFace(GL_CCW);
    glEnable(GL_BLEND);
    glDepthMask(1);
}

// ----------------------------------------
// Callbacks
// ----------------------------------------
void InitGL::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
