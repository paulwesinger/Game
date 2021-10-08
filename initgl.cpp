#include <GL/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "logs/logs.h"
#include "initgl.h"

InitGL::InitGL()
{
}

InitGL::~InitGL(){
    glfwTerminate();
}
bool InitGL::init()
{
    if (glfwInit()) {

        //---------------------------------------------------
        // init window
        //---------------------------------------------------
        window = glfwCreateWindow(1024,800,"Game",NULL, NULL);

        if (! window)
        {
            glfwTerminate();
            exit(EXIT_FAILURE);
        }
        loginfo("GLFW Init OK"," INITGL");

        glfwMakeContextCurrent(window);
   //     gladLoadGL(glfwGetProcAddress);
        glfwSwapInterval(1);

        loginfo("GLFWindow Init OK"," INITGL");

        glfwSetKeyCallback(window, key_callback);

        glClearColor(0.0,0.0,1.0,1.0);
        while (!glfwWindowShouldClose(window)) {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            // Drawing and so on
            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        glfwDestroyWindow(window);
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

// ----------------------------------------
// Callbacks
// ----------------------------------------
void InitGL::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
