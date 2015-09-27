#include "bisectionmethod.h"
#include <math.h>


double BisectionMethod::low;
double BisectionMethod::high;
double BisectionMethod::mid;
QVector_double BisectionMethod::relativeError;
QVector_double BisectionMethod::xl;
QVector_double BisectionMethod::xu;
QVector_double BisectionMethod::xm;
QVector_double BisectionMethod::fxm;
QVector_double BisectionMethod::iterations;

//QTableWidget BisectionMethod::tableWidget;

//Sets the range
void BisectionMethod::setRange(double low, double high)
{
    BisectionMethod::low = low;
    BisectionMethod::high = high;
    BisectionMethod::mid = (high + low) / 2;
}

void BisectionMethod::initBisection(double lo, double hi, std::string expr)
{
    BisectionMethod::setRange(lo, hi);
    BisectionMethod::setExpression(expr);
}

//Calculate function saved in variable expression
double BisectionMethod::fx(std::string expr, QString val)
{
    QParser temp_obj;
    return temp_obj.calculateExpression(expr, val);
}

double BisectionMethod::f_high(){
    QString temp;
    return fx(BisectionMethod::getExpression(), temp.setNum(high));
}

double BisectionMethod::f_low(){
    QString temp;
    return fx(BisectionMethod::getExpression(), temp.setNum(low));
}

double BisectionMethod::f_mid(){
    QString temp;
    return fx(BisectionMethod::getExpression(), temp.setNum(mid));
}

void BisectionMethod::applyBisectionMethod(double tolerance)
{
    //Initializing required vars
    double checkTolerance = 0;
    bool inside = false;
    double iteration = 1;

    //Getting the value before the bisec method
    xl.append(low);
    xu.append(high);
    xm.append(mid);
    fxm.append(f_mid());
    iterations.append(iteration);

    while (f_low() * f_mid() != 0){
        inside = true;
        iteration++;

        if (f_low() * f_mid() < 0) high = mid;
        else if (f_low() * f_mid() > 0) low = mid;


        xl.append(low);
        xu.append(high);

        iterations.append(iteration);

        double mid_old = mid;
        double mid_new =  (low + high) / 2;
        mid = mid_new;

        xm.append(mid);

        fxm.append(f_mid());

        print(mid_new);

        checkTolerance = qAbs((mid_new - mid_old) / mid_new) * 100;

        if (checkTolerance < tolerance)
        {
            print("Found root = (inside)" + QString::number(mid));
            break;
        }

        print("relative error: " + QString::number(checkTolerance));

        relativeError.append(checkTolerance);
    }
    if (inside && (f_low() * f_high() == 0)){
        print("Found root: " + QString::number(mid));
    }
    else if (!inside) print("Found Root [!inside] " + QString::number(low) );

    foreach (double d, xu) print("xu : " + QString::number(d));
}



BisectionMethod::BisectionMethod()
{

}

BisectionMethod::~BisectionMethod()
{

}

