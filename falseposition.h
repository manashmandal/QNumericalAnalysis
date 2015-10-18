#ifndef FALSEPOSITION_H
#define FALSEPOSITION_H

#include "qparser.h"
#include <QVector>
#include <QTableWidget>

typedef QVector <double> QVector_double;

class FalsePosition : public QParser
{
public:
    QTableWidget tableWidget;

    static double low;
    static double high;
    static double mid;

    static void initFalsePosition(double lo, double hi, std::string expr);


    FalsePosition();
};

#endif // FALSEPOSITION_H
