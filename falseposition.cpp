#include "falseposition.h"
#include <math.h>

double FalsePosition::low;
double FalsePosition::high;
double FalsePosition::r;

QVector_double FalsePosition::relativeErrors;
QVector_double FalsePosition::xl;
QVector_double FalsePosition::xu;
QVector_double FalsePosition::xr;
QVector_double FalsePosition::fxr;
QVector_double FalsePosition::iterations;

size_t FalsePosition::iteration = 0;
double FalsePosition::relativeError = 0;

//Setting the range
void FalsePosition::setRange(double low, double high)
{
    FalsePosition::low = low;
    FalsePosition::high = high;

    calculateXr();

    //Adding the first value of r, hi and low
    xr.append(r);
    xu.append(high);
    xl.append(low);

    fxr.append(f_r()); // Adding value calculated by the expression r valued

    FalsePosition::iteration++;

    //Iteration is being added at first
    iterations.append(iteration);

    qDebug() << r;
}

//updates the value of xr according to low and high
void FalsePosition::calculateXr(){
    FalsePosition::r = high - ((f_high() * (low - high)) / (f_low() - f_high()));
}

//Constructor
FalsePosition::FalsePosition(double lo, double hi, std::string expr){
    FalsePosition::initFalsePosition(lo, hi, expr);
}


//Initialize Bisection Method
void FalsePosition::initFalsePosition(double lo, double hi, std::string expr)
{
    FalsePosition::setRange(lo, hi);
    FalsePosition::setExpression(expr);
}

//Calculate functions
double FalsePosition::fx(std::string expr, QString val){
    QParser t;
    return t.calculateExpression(expr, val);
}

//Calculates fx(high)
double FalsePosition::f_high(){
    QString t;
    return fx(FalsePosition::getExpression(), t.setNum(high));
}

//Calculates fx(low)
double FalsePosition::f_low(){
    QString t;
    return fx(FalsePosition::getExpression(), t.setNum(low));
}

//Calculates fx(r)
double FalsePosition::f_r()
{
    QString t;
    return fx(FalsePosition::getExpression(), t.setNum(r));
}

FalsePosition::FalsePosition()
{

}

//Calculates relative error and append the error in the relativeError stack
double FalsePosition::calculateRelativeError(double xr_new, double xr_old){
    relativeError = qAbs(((xr_new - xr_old) / xr_new) * 100);
    qDebug() << "Relative error: " << relativeError;
    relativeErrors.push_back(relativeError);
    return relativeError;
}


void FalsePosition::applyFalsePosition(double tolerance)
{
    //Init required values
    double checkTolerance = 0;
    bool inside  = false;
    double xr_old = 0;
    double xr_new = 0;

    while (f_low() * f_r() != 0){

        //Saving previous xr value
        xr_old = FalsePosition::r;

        inside = true;
        iteration++;

        if (f_low() * f_r() < 0) {
            low = low;
            high = r;
        } else if (f_low() * f_r() > 0){
            low = r;
            high = high;
        }

        //Calculating xr value
        calculateXr();

        //Assigining new calculated xr value
        xr_new = FalsePosition::r;

        qDebug() << "root : " << xr_new;

        //Calculating error
        calculateRelativeError(xr_new, xr_old);

        //Terminating operation if relative error is less than tolerance
        if (relativeError < tolerance) break;

    }

}

