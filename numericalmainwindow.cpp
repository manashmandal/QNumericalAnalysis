#include "numericalmainwindow.h"
#include "ui_numericalmainwindow.h"

#include "qparser.h"
#define empty ""

NumericalMainWindow::NumericalMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NumericalMainWindow)
{
    ui->setupUi(this);
    connect(ui->expressionLineEdit, SIGNAL(textEdited(QString)), this, SLOT(getExpressionText(QString)));

    //Connecting push button to assignValues function
    connect(ui->calculateButton, SIGNAL(clicked()), this, SLOT(assignValues()));

}


//Catches the expression from expressionLineEdit and process it for variables
void NumericalMainWindow::getExpressionText(QString input)
{

}

//AssignValue function definition
void NumericalMainWindow::assignValues()
{


}

NumericalMainWindow::~NumericalMainWindow()
{
    delete ui;
}
