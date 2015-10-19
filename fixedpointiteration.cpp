#include "fixedpointiteration.h"

//Variables
double FixedPointIteration::x_new;
double FixedPointIteration::x_old;
double FixedPointIteration::relative_error;
double FixedPointIteration::init_guess;
double FixedPointIteration::root;
int FixedPointIteration::max_trial;
double FixedPointIteration::iteration;

//Containers
QVector_double FixedPointIteration::xVals;
QVector_double FixedPointIteration::relativeErrors;
QVector_double FixedPointIteration::iterations;


double FixedPointIteration::applyFixedPointIteration(double tolerance){

    FixedPointIteration::x_old = FixedPointIteration::init_guess;
    FixedPointIteration::iteration = 0;

    do {

        FixedPointIteration::x_new = FixedPointIteration::f(FixedPointIteration::x_old);
        calculateRelativeError();
        FixedPointIteration::relativeErrors.append(FixedPointIteration::relative_error);
        FixedPointIteration::xVals.append(x_new);
        FixedPointIteration::x_old = x_new;

        FixedPointIteration::iteration++;
        FixedPointIteration::iterations.append(iteration);

    }   while (FixedPointIteration::relative_error > tolerance || iterations.size() < FixedPointIteration::max_trial);

    return FixedPointIteration::x_new;
}

//Function parser
double FixedPointIteration::f(double val){
    QString t;
    return fx(FixedPointIteration::getExpression(), t.setNum(val));
}


//Generic function parser
double FixedPointIteration::fx(std::string expression, QString val){
    QParser t;
    return t.calculateExpression(expression, val);
}

//Initialize FixedPointIteration method
void FixedPointIteration::initFixedPointIteration(std::string expr, double initial_guess, int max_try){
    FixedPointIteration::setExpression(expr);
    FixedPointIteration::init_guess = initial_guess;
    FixedPointIteration::x_old = initial_guess;
    FixedPointIteration::max_trial = qAbs(max_try);
}

//Constructors
FixedPointIteration::FixedPointIteration(QString expr){
    FixedPointIteration::setExpression(expr);
}

FixedPointIteration::FixedPointIteration(std::string expr, double initial_guess, int max_try){
    FixedPointIteration::initFixedPointIteration(expr, initial_guess, max_try);
}


FixedPointIteration::FixedPointIteration()
{

}


//Calculates error
double FixedPointIteration::calculateRelativeError(){
    double xn = FixedPointIteration::x_new;
    double xo = FixedPointIteration::x_old;
    FixedPointIteration::relative_error = qAbs((xn - xo) / xn) * 100;
    return FixedPointIteration::relative_error;
}
