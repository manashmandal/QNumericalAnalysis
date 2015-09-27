#include "bisectiongui.h"
#include "ui_bisectiongui.h"

BisectionGUI::BisectionGUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BisectionGUI)
{
    ui->setupUi(this);
}

BisectionGUI::~BisectionGUI()
{
    delete ui;
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
