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
//    QParser::setValues(input.toStdString(), ui->varValueLineEdit->text());
    QParser::clear();

    QParser::setExpression(input);
    printStdString(QParser::getExpression()); // Debugging purpose

    QString variable_list;

    foreach(QString s, QParser::getVar()){
        variable_list.append(s);
        variable_list.append(',');
        variable_list.append(' ');
    }

    ui->variableDetectLineEdit->setText(variable_list);

}

//AssignValue function definition
void NumericalMainWindow::assignValues()
{
    QParser temp;

   qDebug() << temp.calculateExpression(QParser::getExpression(), ui->varValueLineEdit->text());

}

NumericalMainWindow::~NumericalMainWindow()
{
    delete ui;
}
