#ifndef INITGL_H
#define INITGL_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "monitors.h"
#include "mouse.h"
#include "textrenderer/textrender.h"
#include "base2d/base2d.h"
#include "shaders/shader.h"
#include "utils/utils.h"
#include "fileutils/fileutil.h"
#include "cube/cube.h"
#include "projection/projection.h"
#include "camera/camera.h"
#include "landscape/landscape.h"

class InitGL
{
public:
    InitGL();
    ~InitGL();
    bool init();
    void Draw2D();
    //------------------------
    //Callbacks
    //------------------------
    static void MousButton_callback(GLFWwindow * window, int button, int action, int mods);

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);    
protected:
    //------------------------------------
    // The main win
    //------------------------------------
    GLFWwindow  *       _Window;
    Shader      *       _Shader;

    LandScape   *       _LandScape;
    fileUtil    *       _FileUtil;
    int                 _ResolutionX;
    int                 _ResolutionY;
    double              _Elapsed;

    void                InitShaders();
    void                InitUtils();

    //-----------------------------------
    // Shader compiling
    //-----------------------------------
    GLuint cubeshaderprog_color;
    GLuint cubeshaderprog_tex;
    GLuint cubeshaderprog_normals;
    GLuint cubeshaderprog_color_normal;

    GLuint sphereshader_color;
    GLuint currentShader;

    //------------------------
    //Monitors and propertier
    //------------------------
    Monitors monitors;
    Mouse mouse;

private:
    void Prepare2D();
    void Restore3D();

    Projection  * projection;
    Camera      * camera;

    TextRender * text;
    Base2D * line;
    Base2D * test2D;

    CCube * cube;
};

#endif // INITGL_H
