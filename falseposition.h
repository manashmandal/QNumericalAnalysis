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
    static double r;
    static size_t iteration;
    static double relativeError;

    static void initFalsePosition(double lo, double hi, std::string expr);


    static void setRange(double low, double high);

    static double f_low(void);
    static double f_r(void);
    static double f_high(void);
    static double fx(std::string expr, QString val);
    static void calculateXr(void);
    static double calculateRelativeError(double xr_new, double xr_old);

    static QVector_double relativeErrors;
    static QVector_double iterations;
    static QVector_double xl;
    static QVector_double xu;
    static QVector_double xr;
    static QVector_double fxr;

    static void applyFalsePosition(double tolerance);

    FalsePosition();
    FalsePosition(double lo, double hi, std::string expr);
};

#endif // FALSEPOSITION_H
