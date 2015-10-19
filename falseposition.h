#ifndef FALSEPOSITION_H
#define FALSEPOSITION_H

#include "qparser.h"
#include <QVector>


typedef QVector <double> QVector_double;

class FalsePosition : public QParser
{
public:
    //Variables
    static double low;
    static double high;
    static double r;
    static double relative_error;
    static size_t iteration;
    static double xr_new;
    static double xr_old;

    //Containers
    static QVector_double relativeErrors;
    static QVector_double xl;
    static QVector_double xu;
    static QVector_double xr;
    static QVector_double fxr;
    static QVector_double iterations;


    //Methods
    static void setRange(double lo, double hi); // Sets range
    static double fx(std::string expr, QString val); // General Function Parser
    static double fx(double val);
    static double f_high(void); // f(high)
    static double f_low(void); // f(low)
    static double f_xr(void); // f(xr)

    static double calculate_xr(double lo, double hi); //calculates xr
    static double calculate_xr(void); //overloaded method, uses saved low and high values

    //Functions for calculating relative error
    static double calculateRelativeError(double xrOld, double xrNew);
    static double calculateRelativeError(void);

    //Function for applying false position method
    /*
     * No Need to call initFalsePosition, this will do the work of that function
     * */
    static int applyFalsePosition(double lo, double hi, std::string expression, double tolerance, int max_retry);

    //Use initFalsePosition before using this function
    static int applyFalsePosition(double tolerance, int max_retry);


    //Initializer
    static void initFalsePosition(double lo, double hi, std::string expr);

    //Debugger
    static void printALL(void);

    //Clears all variables and containers
    static void clearAll(void);


};

#endif // FALSEPOSITION_H
