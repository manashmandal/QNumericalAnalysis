#ifndef BISECTIONMETHOD_H
#define BISECTIONMETHOD_H
#include "qparser.h"
#include <QVector>
#include <QTableWidget>

typedef QVector <double> QVector_double;


class BisectionMethod : public QParser
{
public:
    QTableWidget tableWidget;

    static double low;
    static double high;
    static double mid;

    static void initBisection(double lo, double hi, std::string expr);

    static void setRange(double low, double high);

    static double f_low(void);
    static double f_high(void);
    static double f_mid(void);


    //Static vector data for plotting and generating data table
    static QVector_double relativeError;
    static QVector_double iterations;
    static QVector_double xl;
    static QVector_double xu;
    static QVector_double xm;
    static QVector_double fxm;

    static void applyBisectionMethod(double tolerance);

    static double fx (std::string expr, QString val);

    BisectionMethod();
    ~BisectionMethod();
};

#endif // BISECTIONMETHOD_H
