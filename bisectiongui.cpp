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
