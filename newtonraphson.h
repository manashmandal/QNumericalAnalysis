#ifndef NEWTONRAPHSON_H
#define NEWTONRAPHSON_H
#include "qparser.h"

#include <QVector>

typedef QVector <double> QVector_double;

class NewtonRaphson : public QParser
{
public:
    //Variables
    static double iteration;
    static double relative_error;
    static double r;
    static double init_guess;
    static double xr_new;
    static double xr_old;


    //Containers
    static QVector_double iterations;
    static QVector_double relativeErrors;
    static QVector_double roots;


    //Initializer
    static void initNewtonRaphson(std::string expr, double initial_guess);
    //Calculates error with overloaded function too

    static double calculateRelativeError(double xrOld, double xrNew);
    static double calculateRelativeError(void);

    //Differentiator
    static double differentiate(std::string expr, double value);
    static double differentiate(double value);

    //Clears all
    static void clearAll(void);

    //Apply NewtonRaphson
    static double applyNewtonRaphson(double tolerance, int max_trial);

    //generic function parser
    static double fx(double value);
    static double fPrimeX(double value);

    NewtonRaphson();
};

#endif // NEWTONRAPHSON_H
