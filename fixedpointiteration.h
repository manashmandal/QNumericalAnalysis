#ifndef FIXEDPOINTITERATION_H
#define FIXEDPOINTITERATION_H
#include "qparser.h"
#include <QString>
#include <QVector>

typedef QVector <double> QVector_double;

class FixedPointIteration : public QParser
{
public:

    //Variables
    static double x_new;
    static double x_old;
    static double iteration;
    static double relative_error;
    static double init_guess;
    static double root;
    static int max_trial;

    //Containers
    static QVector_double xVals;
    static QVector_double iterations;
    static QVector_double relativeErrors;

    //Function parser
    static double f(double val);

    //generic function parser
    static double fx(std::string expression, QString val);

    //Apply FixedPoint Iteration
    static double applyFixedPointIteration(double tolerance);

    //Initialize FixedPointIteration
    static void initFixedPointIteration(std::string expr, double initial_guess, int max_try);

    //Calculate relative error
    static double calculateRelativeError(void);

    //Constructors
    FixedPointIteration();
    FixedPointIteration(std::string expr, double initial_guess, int max_try);
    FixedPointIteration(QString expr);
};

#endif // FIXEDPOINTITERATION_H
