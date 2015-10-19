
#include <QApplication>


#include <QWidget>
#include <QPointer>
#include <QLabel>

#include "bisectionmethod.h"
#include "bisectiongui.h"
#include "numericalmainwindow.h"
#include "falseposition.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    NumericalMainWindow w;
    w.show();



//    std::string expr("x^3-0.165*x^2+3.993*10^-4");
//    BisectionGUI::initBisection(0, .11, expr);
//    BisectionGUI::applyBisectionMethod(.001);

//    BisectionGUI gui;
////    gui.getStaticValues();
//    gui.show();

    return a.exec();
}
