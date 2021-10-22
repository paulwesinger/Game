//#include <GL/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "logs/logs.h"
#include "utils/utils.h"
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

        test2D = new Base2D(_ResolutionX, _ResolutionY,"../Game/images/button_green.png");
        line = new Base2D(_ResolutionX, _ResolutionY);
        line->initLine(_ResolutionX, _ResolutionY);

        glfwSetKeyCallback(_Window, key_callback);
        glfwSetMouseButtonCallback(_Window,MousButton_callback);


        glClearColor(0.0,0.0,1.0,1.0);

        sPoint sp ;
        sp.x = 1800; sp.y = 50;
        text = new TextRender(_ResolutionX,_ResolutionY,sp);
        text->AddString("Nix ");


        while (!glfwWindowShouldClose(_Window)) {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            // 2D - Stuff
            Draw2D();

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

// ******************************************
// Utils
// ------------------------------------------
void InitGL::InitUtils() {
    _FileUtil = new fileUtil();
    if (_FileUtil == NULL) {
        logwarn ("Konnte Util FileStream nicht erstellen !!","InitGL::InitUtils");
    }
    else
        loginfo("Erstelle FileUtil...... DEone","InitGL::InitUtils");
}

void InitGL::InitShaders() {
    //================================================================
    //Test für CustomShader

    _Shader = new Shader();

    // Vertex Shader
    // ------------------------------------------------------------------------
    std::string v_source ="ShaderSources/cubevertexshader.vex";
    int vs = _Shader ->compileVertexShaderFromFile(v_source,_FileUtil);
    //Fragment Shader Color
    v_source ="ShaderSources/colorshader.frg";
    int fs_Color = _Shader ->compileFragmentShaderFromFile(v_source,_FileUtil);
    // Fragment Shader Texture
    v_source ="ShaderSources/cubefragmentshaderMulti.frg";
    int fs_Tex = _Shader ->compileFragmentShaderFromFile(v_source,_FileUtil);
    // ColorCubeShader
    loginfo("Erstelle Cube Color Shader.................done");
    _Shader->CreateCustomShader(cubeshaderprog_color);
    _Shader->AttachCustomShader(cubeshaderprog_color,vs);
    _Shader->AttachCustomShader(cubeshaderprog_color,fs_Color);
    _Shader->CreateCustomProgram(cubeshaderprog_color);

    //Texture CubeShader
    loginfo("Erstelle Cube Texture Shader ..............done");
    _Shader->CreateCustomShader(cubeshaderprog_tex);
    _Shader->AttachCustomShader(cubeshaderprog_tex,vs);
    _Shader->AttachCustomShader(cubeshaderprog_tex,fs_Tex);
    _Shader->CreateCustomProgram(cubeshaderprog_tex);

    // Shader für lightning
    loginfo("Erstelle Cube Lightning Shader ..............done");
    v_source ="ShaderSources/cubevertexnormalshader.vex";
    int vsn = _Shader ->compileVertexShaderFromFile(v_source,_FileUtil);
    //Fragment Shader Color
    v_source ="ShaderSources/cubefragmentshaderMultinormals.frg";
    int fsn = _Shader ->compileFragmentShaderFromFile(v_source,_FileUtil);
    _Shader->CreateCustomShader(cubeshaderprog_normals);
    _Shader->AttachCustomShader(cubeshaderprog_normals,vsn);
    _Shader->AttachCustomShader(cubeshaderprog_normals,fsn);
    _Shader->CreateCustomProgram(cubeshaderprog_normals);

    // Shader für colorlightning
    loginfo("Erstelle Cube Color Light Shader ..............done");
    v_source ="ShaderSources/vertexnormalcolorshader.vex";
    int vscn = _Shader ->compileVertexShaderFromFile(v_source,_FileUtil);    //Fragment Shader Color
    v_source ="ShaderSources/fragmentnormalcolorshader.frg";
    int fscn = _Shader ->compileFragmentShaderFromFile(v_source,_FileUtil);
    _Shader->CreateCustomShader(cubeshaderprog_color_normal);
    _Shader->AttachCustomShader(cubeshaderprog_color_normal,vscn);
    _Shader->AttachCustomShader(cubeshaderprog_color_normal,fscn);
    _Shader->CreateCustomProgram(cubeshaderprog_color_normal);

    glDetachShader(cubeshaderprog_color,vs);
    glDetachShader(cubeshaderprog_color,vscn);
    glDetachShader(cubeshaderprog_color,fscn);
    glDetachShader(cubeshaderprog_color,fs_Color);
    glDetachShader(cubeshaderprog_tex,fs_Tex);
    glDetachShader(cubeshaderprog_normals,fsn);
    glDetachShader(cubeshaderprog_normals,vsn);

    //------------------------------------------------------------------------
    // Sphere Shader color:
    //------------------------------------------------------------------------
    v_source = "ShaderSources/spherevertexshader.vex";
    vs = _Shader->compileVertexShaderFromFile(v_source,_FileUtil);
    // Fragment sHader
    v_source ="ShaderSources/spherefragmentshader.frg";
    fs_Color = _Shader->compileVertexShaderFromFile(v_source,_FileUtil);
    //Alles zusammenfügen:
    loginfo("Erstelle Sphere Color Shader ..............done");
    _Shader -> CreateCustomShader(sphereshader_color);
    _Shader -> AttachCustomShader(sphereshader_color,vs);
    _Shader -> AttachCustomShader(sphereshader_color,fs_Color);
    _Shader ->CreateCustomProgram(sphereshader_color);
    // ========================================================================
    //delete binares
    _Shader->deleteShader(vs);
    _Shader->deleteShader(fs_Color);
    _Shader->deleteShader(fs_Tex);

    _Shader->deleteShader(vsn);
    _Shader->deleteShader(fsn);
    // ========================================================================
    currentShader = cubeshaderprog_normals;
}

void InitGL::Draw2D() {

    static int fak = 1;
    //test !!
    sPoint sp ;
    sp.x = 1800; sp.y = 50 + fak++;

    Prepare2D();

    line->RenderLine(100,200, 2100, 500);
    test2D->setPos(1700,300);

    text->SetTextColor(glm::vec4(1.0,1.0,1.0,1.0));
    text->SetScale(1.0);
    sp.y += fak;
    text->setPos(sp);


    if (mouse.getState() == MOUSE_BTN_Left_Clk)
        text->setText(0,"Left Btn Click");

    if (mouse.getState() == MOUSE_BTN_Right_Clk) {
        text-> setText(0,"Right Btn Click");
        line->RenderLine(100,100,2000,1000);
    }
    if (mouse.getState() == MOUSE_NO_EVENT)
        text-> setText(0,"Nix click");

    text->Render();
    test2D->Render();


    //Restore 3D
    Restore3D();
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
// Mouse Callbacks
// ----------------------------------------
void InitGL::MousButton_callback(GLFWwindow * window, int button, int action, int mods)
{
    if (action == GLFW_PRESS && button == GLFW_MOUSE_BUTTON_LEFT  )
    {
       Mouse::setState(MOUSE_BTN_Left_Clk);

    }
    else
        if (action == GLFW_PRESS && button == GLFW_MOUSE_BUTTON_RIGHT)
        {
            Mouse::setState(MOUSE_BTN_Right_Clk);
        }
        else
            if (action == GLFW_PRESS && button == GLFW_MOUSE_BUTTON_MIDDLE)
            {
                Mouse::setState(MOUSE_BTN_MiddLe_Clk);
            }
            else
                Mouse::setState(MOUSE_NO_EVENT);
}

// ----------------------------------------
// KEY Callbacks
// ----------------------------------------
void InitGL::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
