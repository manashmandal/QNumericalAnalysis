#include "numericalmainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QPointer>
#include <QLabel>

#include "bisectionmethod.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    NumericalMainWindow w;
//    w.show();

//    return a.exec();


//    std::string expr("x^3-0.165*x^2+3.993*10^-4");
//    BisectionMethod::initBisection(0, .11, expr);
//    BisectionMethod::applyBisectionMethod(.001);

//    BisectionMethod::tableWidget.show();

    QTableWidget tableWidget;
    tableWidget.show();

    return a.exec();
}
