#include "newtonraphson.h"
#include <iostream>
using namespace std;

//Initializing all vars
double NewtonRaphson::xr_new;
double NewtonRaphson::xr_old;
double NewtonRaphson::iteration;
double NewtonRaphson::r;
double NewtonRaphson::relative_error;
double NewtonRaphson::init_guess;

//Initializing containers
QVector_double NewtonRaphson::iterations;
QVector_double NewtonRaphson::relativeErrors;
QVector_double NewtonRaphson::roots;

//Apply newton raphson
double NewtonRaphson::applyNewtonRaphson(double tolerance, int max_trial){
    NewtonRaphson::xr_old = NewtonRaphson::init_guess;
    NewtonRaphson::iteration = 0;

    cout << "initial guess " << init_guess << endl;

    do {

        NewtonRaphson::xr_new = NewtonRaphson::xr_old - (NewtonRaphson::fx(NewtonRaphson::xr_old) / NewtonRaphson::fPrimeX(NewtonRaphson::xr_old));

        cout << "root: " << xr_new << endl;

        calculateRelativeError();


        NewtonRaphson::relativeErrors.append(NewtonRaphson::relative_error);
        NewtonRaphson::roots.append(NewtonRaphson::xr_new);
        NewtonRaphson::xr_old = NewtonRaphson::xr_new;

        NewtonRaphson::iteration++;
        NewtonRaphson::iterations.append(iteration);

        if (iterations.size() > max_trial) break;

        cout << "error : " << relative_error << endl;

    }   while (NewtonRaphson::relative_error > tolerance || iterations.size() < max_trial);

    return NewtonRaphson::xr_new;
}


//Initializer
void NewtonRaphson::initNewtonRaphson(std::string expr, double initial_guess){
    NewtonRaphson::setExpression(expr);
    NewtonRaphson::init_guess = initial_guess;
}

//Differentiator
double NewtonRaphson::differentiate(std::string expr, double value){
    NewtonRaphson::setExpression(expr);
    QParser t;
    t.setValues(expr, QString::number(value));

    return Lepton::Parser::parse(NewtonRaphson::getExpression()).differentiate(t.getVar()[0].toStdString()).optimize().evaluate(t.getStdMap());
}

//overloaded method
double NewtonRaphson::differentiate(double value){
    QParser t;
    t.setValues(NewtonRaphson::getExpression(), QString::number(value));

    return Lepton::Parser::parse(NewtonRaphson::getExpression()).differentiate(t.getVar()[0].toStdString()).optimize().evaluate(t.getStdMap());
}

//Calculate error
double NewtonRaphson::calculateRelativeError(double xrOld, double xrNew){
    NewtonRaphson::xr_new = xrNew;
    NewtonRaphson::xr_old = xrOld;
    NewtonRaphson::relative_error = qAbs((xr_new - xr_old) / xr_new) * 100;
    return NewtonRaphson::relative_error;
}

//Overloaded
double NewtonRaphson::calculateRelativeError(void){
    NewtonRaphson::relative_error = qAbs((NewtonRaphson::xr_new - NewtonRaphson::xr_old) / NewtonRaphson::xr_new) * 100;
    return NewtonRaphson::relative_error;
}

//Clears all
void NewtonRaphson::clearAll(void){
    NewtonRaphson::xr_new = 0;
    NewtonRaphson::xr_old = 0;
    NewtonRaphson::clear();
    NewtonRaphson::iteration = 0;
    NewtonRaphson::iterations.clear();
    NewtonRaphson::relativeErrors.clear();
    NewtonRaphson::roots.clear();
    NewtonRaphson::init_guess = 0;
}

//Generic function parser
double NewtonRaphson::fx(double value){
    QParser t;
    return t.calculateExpression(NewtonRaphson::getExpression(), QString::number(value));
}

//after differentiation
double NewtonRaphson::fPrimeX(double value){
    return NewtonRaphson::differentiate(value);
}

NewtonRaphson::NewtonRaphson(){}

