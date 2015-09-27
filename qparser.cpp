#include "qparser.h"

std::string QParser::expression;
QList <double> QParser::varValList;
QList <QString> QParser::varList;
QMap <std::string, double> QParser::varValMap;
QString QParser::varValExpr;

QList <double> QParser::getVal()
{
    QStringList valList = varValExpr.split(',');
    foreach(QString s, valList ){
        varValList.append(s.toDouble());
//        print(s.toDouble()); //Debugging
    }
    return varValList;
}


QList <double> QParser::_get_val()
{
    QStringList valList = _value_expression.split(',');
    foreach(QString s, valList ){
        _value.append(s.toDouble());
//        print(s.toDouble()); //Debugging
    }
    return _value;
}

std::map <std::string, double> QParser::getStdMap(void)
{
    return getVarValMap().toStdMap();
}

QList <QString> QParser::getVar()
{
    /*
     * Expression must be formatted and shouldn't have any whitespace
     * */
    std::string exp = expression;
    exp.append(";;");
    exp.insert(exp.begin(), '_');
    int i = 0;
    while(exp[i] != ';'){
        if (isalpha(exp[i])){
            if (isalpha(exp[i+1])){
                while (!isalpha(exp[i+1])){
                    i++;
                }
            } else {
                if (!varList.contains(QString(exp[i])) && !isalpha(exp[i-1])) varList.append(QString(exp[i]));
            }
        }
        i++;
    }
//    //Debugging purpose
//    foreach(QString a, varList){
//        print(a);
//    }
    return varList;
}


QList <QString> QParser::_get_var()
{
    /*
     * Expression must be formatted and shouldn't have any whitespace
     * */
    std::string exp = _expression;
    exp.append(";;");
    exp.insert(exp.begin(), '_');
    int i = 0;
    while(exp[i] != ';'){
        if (isalpha(exp[i])){
            if (isalpha(exp[i+1])){
                while (!isalpha(exp[i+1])){
                    i++;
                }
            } else {
                if (!_variable.contains(QString(exp[i])) && !isalpha(exp[i-1])) _variable.append(QString(exp[i]));
            }
        }
        i++;
    }
//    //Debugging purpose
//    foreach(QString a, varList){
//        print(a);
//    }
    return _variable;
}


QMap <std::string, double> QParser::_get_map()
{
    try {
        if (_variable.size() == _value.size()){
            int index = 0;
            foreach(QString s, _variable){
                _map.insert(s.toStdString(), _value.at(index));
                index++;
            }
            return _map;
        }

    }       catch (std::bad_alloc &e){
        print(QString(e.what()));
        std::exit(EXIT_FAILURE);
    }
    return _map;
}

QMap <std::string, double> QParser::getVarValMap()
{
    try {
        if (chk_size_var_val()){
            int index = 0;
            foreach(QString s, varList){
                varValMap.insert(s.toStdString(), varValList.at(index));
                index++;
            }
            return varValMap;
        }

    }       catch (std::bad_alloc &e){
        print(QString(e.what()));
        std::exit(EXIT_FAILURE);
    }
    return varValMap;
}



//Print out the saved variable map
void QParser::printMap(void)
{
    QMap<std::string, double>::iterator iter = varValMap.begin();
    while (iter != varValMap.end()){
        QString temp;
        printStdString(iter.key() + " ----> "  + temp.setNum(iter.value()).toStdString());
        iter++;
    }
}

void QParser::_print_map(void){
    QMap <std::string, double>::iterator iter = _map.begin();
    while(iter != _map.end()){
        QString _t;
        printStdString(iter.key() + " -- > " + _t.setNum(iter.value()).toStdString());
        iter++;
    }
}



std::string QParser::getExpression() {
    return expression;
}

void QParser::setExpression(QString expr){
    expression = expr.toStdString();
}

void QParser::setExpression(std::string expr){
    expression = expr;
}

void QParser::_set_expression(QString in){
    _expression = in.toStdString();
}

void QParser::_set_expression(std::string in){
    _expression = in;
}



bool QParser::chk_size_var_val()
{
    return varValList.size() == varList.size();
}

//Clear up the static variables
void QParser::clear()
{
    varValExpr.clear();
    expression.clear();
    varList.clear();
    varValMap.clear();
    varList.clear();
}

void QParser::_clear()
{
    _value.clear();
    _expression.clear();
    _variable.clear();
    _map.clear();
    _value_expression.clear();
}

double QParser::calculateExpression(std::string ex, QString value){
    this->_set_values(ex, value);
    return Lepton::Parser::parse(ex).evaluate(this->_std_map());
}



void QParser::setValues(std::string inp_ex, QString inp_val_ex){
    expression = inp_ex;
    varValExpr = inp_val_ex;
    getVal();
    getVar();
    getVarValMap();
}

void QParser::_set_values(std::string input_expression, QString input_value_expression)
{
    this->_expression = input_expression;
    this->_value_expression = input_value_expression;
    this->_get_val();
    this->_get_var();
    this->_get_map();
}

std::map<std::string, double> QParser::_std_map(){
    return _map.toStdMap();
}

QParser::QParser()
{

}

QParser::QParser(std::string input_expr, QString value_expr)
{
    this->_set_values(input_expr, value_expr);
}

QParser::~QParser()
{

}

