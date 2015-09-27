#ifndef BISECTIONGUI_H
#define BISECTIONGUI_H

#include <QDialog>
#include "bisectionmethod.h"


namespace Ui {
class BisectionGUI;
}

class BisectionGUI : public QDialog, public BisectionMethod
{
    Q_OBJECT

public:
    explicit BisectionGUI(QWidget *parent = 0);
    ~BisectionGUI();

    void getStaticValues(void);

    //Returns xl, xu, xm, fxm, relativeError, iterations,
    QVector_double get_xl  (void) {     return _xl      ;}
    QVector_double get_xm  (void) {     return _xm      ;}
    QVector_double get_xu  (void) {     return _xu      ;}
    QVector_double get_fxm (void) {     return _fxm     ;}
    QVector_double get_iterations (void) { return iterations; }
    QVector_double get_relativeError (void) { return _relativeError; }

    void addItems(QVector_double vec, int column);
private slots:

    void on_graphButton_clicked();

private:
    Ui::BisectionGUI *ui;
    QVector_double _xl;
    QVector_double _xu;
    QVector_double _xm;
    QVector_double _fxm;
    QVector_double _iterations;
    QVector_double _relativeError;
};

#endif // BISECTIONGUI_H
