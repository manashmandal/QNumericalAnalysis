#include "qcustomplot.h"
#include "bisectiongui.h"
#include "ui_bisectiongui.h"
#include <QTableWidgetItem>
#include <QStringList>




BisectionGUI::BisectionGUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BisectionGUI)
{
    ui->setupUi(this);
    getStaticValues();
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Iterations" << "xl" << "xu" << "xm" << "Relative Error (%)" << "f(x_m)");

    ui->tableWidget->setRowCount(_iterations.size());

    addItems(_iterations, 0);
    addItems(_xl, 1);
    addItems(_xu, 2);
    addItems(_xm, 3);
    addItems(_relativeError, 4);
    addItems(_fxm, 5);

}

BisectionGUI::~BisectionGUI()
{
    delete ui;
}

void BisectionGUI::addItems(QVector_double vec, int column)
{
    int index = 0;
    foreach(double var, vec){
        ui->tableWidget->setItem(index, column, new QTableWidgetItem(QString::number(var)));
        index++;
    }
}

void BisectionGUI::getStaticValues()
{
    _iterations = BisectionGUI::iterations;
    _fxm = BisectionGUI::fxm;
    _xl = BisectionGUI::xl;
    _xm = BisectionGUI::xm;
    _xu = BisectionGUI::xu;
    _fxm = BisectionGUI::fxm;
    _relativeError = BisectionGUI::relativeError;
}


