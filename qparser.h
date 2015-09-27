/*
 * DESCRIPTION:
 * ===========
 * call setValues (std::string, QString) / _set_values(std::string, QString) to generate map
 * use the map for parsing using Lepton
 */

#ifndef QPARSER_H
#define QPARSER_H
#include "Lepton.h"

#include <QDebug>
#include <QByteArray>
#include <QString>
#include <QList>
#include <QMap>

#define print(input) qDebug() << input
#define printStdString(input) qDebug() << QByteArray::fromStdString(input)

class QParser
{
private:
    static std::string expression; //Expression var
public:

    static QList <QString> varList; // Variable List var
    static QList <double> varValList; // Value for variable [in order]
    static QMap <std::string, double> varValMap; //Map for variable and values
    static QString varValExpr; //Variable value expression (e.g 1, 2, 3, 4)


    static QList <QString> getVar(void); // Get Variable List
    static QList <double> getVal(void); // Get Value List
    static QMap <std::string, double> getVarValMap(void); // Map variable with value


    double calculateExpression(std::string expression, QString value);
    static void setExpression(std::string); // Set Expression
    static void setExpression(QString); // Overloaded Set Expression

    static std::string getExpression(); // Returns expression
    static bool chk_size_var_val(); // Check size of variable list and value list
   static std::map<std::string, double> getStdMap(); // returns std::map of QMap
    static void printMap(void); //print out the map

    static void clear(void); //clear the variables
    static void setValues(std::string inp_ex, QString inp_val_ex); //Sets everything on calling


    double parseExpression();

    //Object Variables
    std::string _expression;
    QList <QString> _variable;
    QList <double> _value;
    QMap <std::string, double> _map;
    QString _value_expression;

    std::map <std::string, double> _std_map(void);

    //Object Methods
     QList <QString> _get_var(void); // Get Variable List
     QList <double> _get_val(void); // Get Value List
     QMap <std::string, double> _get_map(void); // Map variable with value

     void _print_map(void);
     void _clear(void);
     void _set_expression(QString);
     void _set_expression(std::string);
     void _set_values(std::string input_expression, QString input_value_expression);

    QParser(std::string input_expr, QString value_expr);
    ~QParser();
    QParser();


};

#endif // QPARSER_H
