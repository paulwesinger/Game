#include <QCoreApplication>
#include "initgl.h"


int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);
    InitGL * initGL = new InitGL();

    initGL->init();
}
