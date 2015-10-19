#include "falseposition.h"
#include "qparser.h"
#include <qmath.h>

//Initializing Containers
QVector_double FalsePosition::xl;
QVector_double FalsePosition::xu;
QVector_double FalsePosition::xr;
QVector_double FalsePosition::fxr;
QVector_double FalsePosition::relativeErrors;
QVector_double FalsePosition::iterations;

//Initializing variables
double FalsePosition::relative_error;
double FalsePosition::low;
double FalsePosition::high;
double FalsePosition::r;
size_t FalsePosition::iteration;
double FalsePosition::xr_new;
double FalsePosition::xr_old;

//Setting the range
void FalsePosition::setRange(double lo, double hi)
{
    low = lo;
    high = hi;

}

//General function parser
double FalsePosition::fx(std::string expr, QString val)
{
    QParser t;
    return t.calculateExpression(expr, val);
}

//Overloaded function parser
double FalsePosition::fx(double val){
    QParser t;
    return t.calculateExpression(FalsePosition::getExpression(), QString::number(val));
}

//Calculates f(high)
double FalsePosition::f_high(){
    QString t;
    return fx(FalsePosition::getExpression(), t.setNum(FalsePosition::high));
}

//Calculates f(low)
double FalsePosition::f_low(){
    QString t;
    return fx(FalsePosition::getExpression(), t.setNum(FalsePosition::low));
}


//Initializer
void FalsePosition::initFalsePosition(double lo, double hi, std::string expr){
    FalsePosition::setRange(lo, hi);
    FalsePosition::setExpression(expr);
}


//Calculate the value of xr
double FalsePosition::calculate_xr(double lo, double hi){
    double fxl = fx(lo);
    double fxu = fx(hi);
    double xl = lo;
    double xu = hi;
    FalsePosition::r = xu - ((fxu * (xl - xu)) / (fxl - fxu));
    return r;
}

//Overloaded function of xr
double FalsePosition::calculate_xr(){
    double fxl = f_low();
    double fxu = f_high();
    double xl = FalsePosition::low;
    double xu = FalsePosition::high;
    FalsePosition::r = xu - ((fxu * (xl - xu)) / (fxl - fxu));
    return r;
}

//Relative Error calculating method
double FalsePosition::calculateRelativeError(double xrOld, double xrNew){
    FalsePosition::xr_old = xrOld;
    FalsePosition::xr_new = xrNew;
    FalsePosition::relative_error = qAbs((xr_new - xr_old) / xr_new) * 100;
    //Adding the error in the stack [uncomment if necessary]
//    FalsePosition::relativeErrors.push_back(relative_error);
    return relative_error;
}

//Overloaded calculating method
double FalsePosition::calculateRelativeError(){
    FalsePosition::relative_error = qAbs((xr_new - xr_old) / xr_new) * 100;
    //Adding the error in the stack [uncomment if necessary]
//    FalsePosition::relativeErrors.push_back(relative_error);
    return relative_error;
}

//False position method applier

/*================== ALGORITHM ============
 *1. Estimate the root xr by the formula , xr = (xu * fxl - xl * fxu) / (fxl - fxu)
 * 2. if (fxl * fxr) < 0 set xu = xr
 * 3. if (fxl * fxr) > 0 set xl = xr
 * 4. if (fxl * fxr) == 0 root is xr and stop the algorithm
 * 5. find the absolute relative error for each trial using, ea = | xr_new - xr_old / xr_new | * 100*/

int FalsePosition::applyFalsePosition(double lo, double hi, std::string expression, double tolerance, int max_retry){
    FalsePosition::initFalsePosition(lo, hi, expression);

    //Estimating root
    double fxr = calculate_xr();
    //Function value for low and high
    double fxu = f_high();
    double fxl = f_low();

    //Setting the iteration to 1
    FalsePosition::iteration = 1;
    FalsePosition::iterations.append(iteration);

    //Pushing the value to the stack
    FalsePosition::xu.append(FalsePosition::high);
    FalsePosition::xl.append(FalsePosition::low);
    FalsePosition::xr.append(FalsePosition::r);

    //Making sure the number of retry is positive
    max_retry = qAbs(max_retry);

    //Loop for finding the root
    while ((fxl * fxr) != 0){

        //Saving the old root
        FalsePosition::xr_old = fxr;

        if ((fxl * fxr) < 0){
            FalsePosition::high = r;
            print("less than");

        } else if ((fxl * fxr) > 0){
            FalsePosition::low = r;
            print("greater than");
        }

        //After applying condition, again estimating the value
        fxu = f_high();
        fxl = f_low();
        fxr = calculate_xr();

        //Saving new root
        FalsePosition::xr_new = FalsePosition::r;

        //Adding the value to the stack
        FalsePosition::xu.append(FalsePosition::high);
        FalsePosition::xl.append(FalsePosition::low);
        FalsePosition::xr.append(FalsePosition::r);

        //Increasing iteration
        FalsePosition::iteration++;
        FalsePosition::iterations.append(iteration);

        //Calculating error and adding it to the stack
        FalsePosition::calculateRelativeError();
        FalsePosition::relativeErrors.append(FalsePosition::relative_error);

        print("Root: " + QString::number(FalsePosition::r));

        if (relative_error < tolerance) { return 2; break; }
        else if (iterations.size() > max_retry){
            print("Use modified false position");
            return 3;
        }
    }
    return 1;
}

//Overloaded method
int FalsePosition::applyFalsePosition(double tolerance, int max_retry){

    //Estimating root
    double fxr = calculate_xr();
    //Function value for low and high
    double fxu = f_high();
    double fxl = f_low();

    //Setting the iteration to 1
    FalsePosition::iteration = 1;
    FalsePosition::iterations.append(iteration);

    //Pushing the value to the stack
    FalsePosition::xu.append(FalsePosition::high);
    FalsePosition::xl.append(FalsePosition::low);
    FalsePosition::xr.append(FalsePosition::r);

    //Making sure the number of retry is positive
    max_retry = qAbs(max_retry);

    //Loop for finding the root
    while ((fxl * fxr) != 0){

        //Saving the old root
        FalsePosition::xr_old = fxr;

        if ((fxl * fxr) < 0){
            FalsePosition::high = r;
            print("less than");

        } else if ((fxl * fxr) > 0){
            FalsePosition::low = r;
            print("greater than");
        }

        //After applying condition, again estimating the value
        fxu = f_high();
        fxl = f_low();
        fxr = calculate_xr();

        //Saving new root
        FalsePosition::xr_new = FalsePosition::r;

        //Adding the value to the stack
        FalsePosition::xu.append(FalsePosition::high);
        FalsePosition::xl.append(FalsePosition::low);
        FalsePosition::xr.append(FalsePosition::r);

        //Increasing iteration
        FalsePosition::iteration++;
        FalsePosition::iterations.append(iteration);

        //Calculating error and adding it to the stack
        FalsePosition::calculateRelativeError();
        FalsePosition::relativeErrors.append(FalsePosition::relative_error);

        print("Root: " + QString::number(FalsePosition::r));

        if (relative_error < tolerance) { return 2; break; }
        else if (iterations.size() > max_retry){
            print("Use modified false position");
            return 3;
        }
    }
    return 1;
}


//Clears all variables and containers
void FalsePosition::clearAll(){
    FalsePosition::xl.clear();
    FalsePosition::xu.clear();
    FalsePosition::xr.clear();
    FalsePosition::xr_new = 0;
    FalsePosition::xr_old = 0;
    FalsePosition::high = 0;
    FalsePosition::low = 0;
    FalsePosition::iterations.clear();
    FalsePosition::relativeErrors.clear();
    FalsePosition::relative_error = 0;
}
