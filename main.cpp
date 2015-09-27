#include "numericalmainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QPointer>
#include <QLabel>

#include "bisectionmethod.h"
#include "bisectiongui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::string expr("x^3-0.165*x^2+3.993*10^-4");
    BisectionGUI::initBisection(0, .11, expr);
    BisectionGUI::applyBisectionMethod(.001);

    BisectionGUI gui;
    gui.getStaticValues();
    print("START");
    foreach(double d, gui.get_xl()){
        print(d);
    }

    return a.exec();
}
