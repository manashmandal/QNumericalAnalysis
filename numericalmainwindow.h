#ifndef NUMERICALMAINWINDOW_H
#define NUMERICALMAINWINDOW_H


#define ENDLINE qDebug() << "\n"
#define print(input) qDebug() << input
#define printStdString(input) qDebug() << QByteArray::fromStdString(input)


#include <QMainWindow>
#include <QMap>
#include <QDebug>
#include <QMapIterator>
#include <QByteArray>
#include <iostream>
#include <QList>
#include <map>
#include "Lepton.h"


typedef QMap <std::string, double> map;
typedef QMapIterator <std::string, double> mapIterator;


namespace Ui {
class NumericalMainWindow;
}

class NumericalMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NumericalMainWindow(QWidget *parent = 0);
    ~NumericalMainWindow();

public slots:
    void getExpressionText(QString);
    void assignValues(void);

private:
    Ui::NumericalMainWindow *ui;
    map variableMap;
//    QByteArray variableList;
    QList <char> variableList;
    QList <QString> temp;

    mapIterator *variableMapIterator;


};

#endif // NUMERICALMAINWINDOW_H
